Now that we have our libraries installed, we can compiile and upload the Arduino code 
to the ESP32 Thing Plus.

### SuperHeadphones Arduino Code

Below is the Arduino sketch INO for this project. Copy and paste the code below in your Arduino IDE.

??? code "Example 1: ENS160 and BME280 Combined Examples"
    === "Ex1_Combined_Basic_Example_ENS160_BME280.ino"
        ``` c++ linenums="1"
        --8<-- "https://raw.githubusercontent.com/sparkfun/SparkFun_Environmental_Combo_Breakout_ENS160_BME280_QWIIC/main/Firmware/Ex1_Combined_Basic_Example_ENS160_BME280/Ex1_Combined_Basic_Example_ENS160_BME280.ino"
        ```

Select your board in the Tools menu (in our case **ESP32 Thing Plus**) and the correct Port it enumerated on and click "Upload". After uploading the code, open the [Serial Monitor](https://learn.sparkfun.com/tutorials/terminal-basics) or terminal emulator of your choice with the baud rate set to **115200**. You should see the following message pop up. And then as you turn the volume potentiometer, the setting value will be printed to the terminal.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle;"><a href="../assets/img/Arduino_Terminal_Print_Out.png"><img src="../assets/img/Arduino_Terminal_Print_Out_600wide.png" height="600px" width="600px" alt="Output to the terminal"></a></td>
    </tr>
  </table>
</div>

