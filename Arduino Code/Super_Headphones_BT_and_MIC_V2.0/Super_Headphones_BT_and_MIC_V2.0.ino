#include <Wire.h>
#include <SparkFun_WM8960_Arduino_Library.h>  //Click here to get the library: http://librarymanager/All#SparkFun_WM8960
WM8960 codec1;

#include "BluetoothA2DPSink.h"
BluetoothA2DPSink a2dp_sink;

//// Iot Redboard
//#define I2S_WS 16
//#define I2S_SD 25
//#define I2S_SDO 17
//#define I2S_SCK 14

// ESP32 Thing Plus C
#define I2S_WS 13
#define I2S_SD 27
#define I2S_SDO 14
#define I2S_SCK 32

// Use I2S Processor 0
#define I2S_PORT I2S_NUM_0

// Define input buffer length
#define bufferLen 64
int16_t sBuffer[bufferLen];

int pgaGain1 = 25;

int pgaGain1_prev = 0;

#define NUM_OF_READINGS 20
long userInputA0;
int userInputArray[NUM_OF_READINGS] = {};  // used to make a rolling average of readings on ADC input
int arrayPos = 0;
#define PGA_GAIN_SETTING_MAX 32 // don't really need more than this on the PGA, so let's put a max on it so no one gets too crazy.

void setup() {
  Serial.begin(115200);
  Serial.println(" ");

  Wire.begin();
  Wire.setClock(100000);

  if (codec1.begin() == false)  //Begin communication over I2C
  {
    Serial.println("The codec 1 did not respond. Please check wiring.");
    while (1)
      ;  //Freeze
  }
  Serial.println("Codec1 is connected properly.");

  codec1_setup();

  // Set up I2S
  i2s_install();
  i2s_setpin();

  a2dp_sink.start("PetePhones");
}

void loop() {

  // take a reading of volume on the 8878 MEMs mics (the low SPL)
  // if the signal is clipping, that means that something loud is causing it to clip.
  // this clipping threshold will be the volume when we switch over to the 2020 MEMs mics (High SPL).
  // Note, we don't want to just always use the 2020s because they are less sensative and don't pick up
  // on the quieter things without a huge amount of gain, and thus more hiss.
  // ideally, we can use the 8878s for low volume stuff, and the 2020s for louder stuff.
  // When one mic is "active", the other is muted.
  // We will control the "muting" and "un-muting" by using the pga gains with zero-crossover activated.
  // I have "" around muting and un-muting, because in reality we may not totally mute, maybe we will
  // just bring down the gain to an in-audable amount. I'm worried that a full mute command might be too
  // slow and/or clunky. We need fast smoth switching between mics.

  // every loop, take a reading and put it into the array
  // increment position
  // loop back position to start of array, when we reach the end
  // take all readings in array, and create a rolling average.

  userInputArray[arrayPos] = analogRead(A0);
  arrayPos += 1;
  if (arrayPos > NUM_OF_READINGS) arrayPos = 0;
  int total = 0;
  for (int i = 0; i < NUM_OF_READINGS; i++) total += userInputArray[i];
  userInputA0 = total / NUM_OF_READINGS;
  // map it from 0-4096, to a value that is acceptable in the pga gain (0-63)
  // 0-63, (0 = -17.25dB) <<-- 0.75dB steps -->> (23 = +0dB)...(63 = +30dB)
  pgaGain1 = map(userInputA0, 0, 4096, PGA_GAIN_SETTING_MAX, 0);

  if (pgaGain1 != pgaGain1_prev) {
    codec1.setLINVOL(pgaGain1);
    codec1.setRINVOL(pgaGain1);
    Serial.print("pgaGain1: ");
    Serial.println(pgaGain1);
  }

  pgaGain1_prev = pgaGain1;
  delay(10);
}


void codec1_setup() {
  // General setup needed
  codec1.enableVREF();
  codec1.enableVMID();

  //codec1.enableMicBias();

  // WM8960_MIC_BIAS_VOLTAGE_0_9_AVDD (0.9*AVDD) or
  // WM8960_MIC_BIAS_VOLTAGE_0_65_AVDD (0.65*AVDD)
  //codec1.setMicBiasVoltage(WM8960_MIC_BIAS_VOLTAGE_0_9_AVDD);

  // setup signal flow to the ADC

  codec1.enableLMIC();
  codec1.enableRMIC();

  // connect from INPUT1 to "n" (aka inverting) inputs of PGAs.
  codec1.connectLMN1();
  codec1.connectRMN1();

  // disable mutes on PGA inputs (aka INTPUT1)
  codec1.disableLINMUTE();
  codec1.disableRINMUTE();

  // set input boosts to get inputs 1 to the boost mixers
  codec1.setLMICBOOST(WM8960_MIC_BOOST_GAIN_0DB);  // 0 = 0dB
  codec1.setRMICBOOST(WM8960_MIC_BOOST_GAIN_0DB);  // 0 = 0dB

  codec1.pgaLeftNonInvSignalSelect(WM8960_PGAL_VMID);   // for single ended input on LIN1
  codec1.pgaRightNonInvSignalSelect(WM8960_PGAL_VMID);  // for single ended input on RIN1

  //codec1.enablePgaZeroCross();

  codec1.connectLMIC2B();
  codec1.connectRMIC2B();

  // enable boost mixers
  codec1.enableAINL();
  codec1.enableAINR();

  // enable output mixers
  codec1.enableLOMIX();
  codec1.enableROMIX();

  // Enable bypass connection from Left INPUT3 to Left output mixer, note, the
  // default gain on this input (LI2LOVOL) is -15dB
  codec1.enableLI2LO();
  codec1.enableRI2RO();

  // Sets volume control between "left input" to "left output mixer"
  codec1.setLI2LOVOL(WM8960_OUTPUT_MIXER_GAIN_0DB);
  codec1.setRI2ROVOL(WM8960_OUTPUT_MIXER_GAIN_0DB);


  //  LB2LO (booster to output mixer (analog bypass)
  codec1.enableLB2LO();
  codec1.enableRB2RO();

  // connect from DAC outputs to output mixer
  codec1.enableLD2LO();
  codec1.enableRD2RO();

  // set gainstage between booster mixer and output mixer
  // for this loopback example, we are going to keep these as low as they go
  codec1.setLB2LOVOL(WM8960_OUTPUT_MIXER_GAIN_0DB);  // 0 = -21dB
  codec1.setRB2ROVOL(WM8960_OUTPUT_MIXER_GAIN_0DB);  // 0 = -21dB

  // CLOCK STUFF, These settings will get you 44.1KHz sample rate, and class-d freq at 705.6kHz
  codec1.enablePLL();  // needed for class-d amp clock
  codec1.setPLLPRESCALE(WM8960_PLLPRESCALE_DIV_2);
  codec1.setSMD(WM8960_PLL_MODE_FRACTIONAL);
  codec1.setCLKSEL(WM8960_CLKSEL_PLL);
  codec1.setSYSCLKDIV(WM8960_SYSCLK_DIV_BY_2);
  codec1.setBCLKDIV(4);
  codec1.setDCLKDIV(WM8960_DCLKDIV_16);
  codec1.setPLLN(WM8960_DCLKDIV_16);
  codec1.setPLLK(0x86, 0xC2, 0x26);  // PLLK=86C226h
  //codec1.set_ADCDIV(0); // default is 000 (what we need for 44.1KHz), so no need to write this.
  //codec1.set_DACDIV(0); // default is 000 (what we need for 44.1KHz), so no need to write this.
  codec1.setWL(WM8960_WL_16BIT);

  codec1.enablePeripheralMode();
  //codec1.enableMasterMode();
  //codec1.set_ALRCGPIO(); // note, should not be changed while ADC is enabled.

  // enable ADCs and DACs
  codec1.enableAdcLeft();
  codec1.enableAdcRight();
  codec1.enableDacLeft();
  codec1.enableDacRight();
  codec1.disableDacMute();

  //codec1.enableLoopBack(); // Loopback sends ADC data directly into DAC
  codec1.disableLoopBack();
  codec1.disableDacMute();  // default is "soft mute" on, so we must disable mute to make channels active

  codec1.enableHeadphones();
  //codec1.enableSpeakers();
  codec1.enableOUT3MIX();  // provides VMID as buffer for headphone ground
  //codec1.enableSpeakerZeroCross();

  Serial.println("Volume set to +0dB");
  //codec1.setSpeakerVolume(120);
  codec1.setHeadphoneVolumeDB(0.00);
  //codec1.enable3d();

  Serial.println("Codec 1 Setup complete. Listen to left/right INPUT1 on Speaker outputs.");
  delay(10);

  codec1.setLINVOL(23);
  codec1.setRINVOL(23);
}

void i2s_install() {
  // Set up I2S Processor configuration
  static i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = 44100,  // Updated automatically by A2DP
    .bits_per_sample = (i2s_bits_per_sample_t)16,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_STAND_I2S),
    .intr_alloc_flags = 0,  // Default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = true,
    .tx_desc_auto_clear = true  // Avoiding noise in case of data unavailability
  };
  a2dp_sink.set_i2s_config(i2s_config);
}

void i2s_setpin() {
  // Set I2S pin configuration
  i2s_pin_config_t my_pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_SDO,
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  a2dp_sink.set_pin_config(my_pin_config);
}
