This tutorial will guide you through how to build your own wireless and/or wired
headphones with ambient microphones. We start with some off-the-shelf headphones 
intended for use while lawn mowing, and then hack in some new electroncis to allow
bluetooth, wired input, and stereo ambient microphones. The original purpose of 
this project was to make it easy and safe to play loud music with a rock band in 
the basement, however, the inclusion of the natural sounds around you into your 
listening experiece can be useful in many other use-cases.

<div class="grid cards" markdown align="center">

-   <a href="../assets/img/Image-52.jpeg">
	<figure markdown>
	![Headphones](../assets/img/Image-52.jpeg)
	</figure>
    </a>

    ---
        
    **Headphones with Ambient Mics**</a>

-   <a href="https://www.youtube.com/embed/NvHIXSyEeDA?start=499">
    <iframe width="560" height="315" src="https://www.youtube.com/embed/NvHIXSyEeDA?start=499" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
    
    ---
    
    **Project Demo Video**</a>

</div>

### Headphones

For this project, we chose "over-the-ear" headphone that provide a large amount of 
sound dapening (30dB). These types of headphones are also called "ear muffs" and are 
often marketed for use during loud construction work or lawn mowing. 

The exact headphones we chose to start with were the following:

[Smoostart Am/Fm Radio Hearing Protector, Noise Reduction Safety Ear Muffs, 30db Noise Cancelling Ear Protection](https://www.amazon.com/Smoostart-Cancelling-Protection-Snowblowing-Construction/dp/B08M95FP4X)

When using this type of lawn-mowing headphones without any modification, they 
provide adaquate sound dampening to protect your ears in extremely loud places.
However, with this benefit, you also lose the ability to hear your natural 
surroundings clearly. Usually, it is described as sounding a bit like two pillows 
are held to either ear. This is because the passive sound dampening is blocking 
most of the high frequencies. 

In order to get the sound clarity back, we need to use ambient microphones. The 
correct type of microphone can accept the loud sound sources without distortion. 
This type of microphone is said to have a high acoustic overload point, or AOP.
We can send that clean audio signal from the microphones into the headphones at 
a safe listening level. In addition to a high AOP, the microphones also need to 
have a large signal to noise ratio (SNR), which helps avoid having too much "hiss" in 
the audio signal. More on this later.

### The Modification

In addition to sound dampening, the headphones also included the ability to listen 
to FM radio and plug in a TRS 3.5mm audio cable. In this tutorial, we will remove 
the stock electronics and replace them with the SparkFun ESP32 Thing Plus and the 
WM8960 Audio Codec.

<div class="grid cards" markdown align="center">

-   <a href="../assets/img/hp6.jpg">
	<figure markdown>
	![Headphones](../assets/img/hp6.jpg)
	</figure>
    </a>

    ---
        
    **Topside**</a>

-   <a href="../assets/img/hp7.jpg">
	<figure markdown>
	![Headphones](../assets/img/hp7.jpg)
	</figure>
    </a>

    ---
    
    **Backside**</a>

</div>

Using the WM8960 Audio Codec Breakout, we can mix together sound sources. In 
this use case, we are mixing together three sound sources:

(1) Wireless (aka "BT") audio from the ESP32 to the codec via I2S audio.

(2) Wired Audio from a 3.5mm TRS audio jack (common headphone cable connector)

(3) Ambient microphones mounted to either sides of each "ear can", to provide a 
stereo "room mic" to your listening experience. In a way, these microphones are 
"giving you your ears back". Most importantly, doing so at a safe volume to 
prevent hearing loss.

### Required Materials

To follow along with this tutorial, you will need the following materials. You may not need everything though depending on what you have. Add it to your cart, read through the guide, and adjust the cart as necessary.

* 1x [SparkFun Thing Plus - ESP32 WROOM (USB-C) [WRL-20168]](https://www.sparkfun.com/products/20168)
* 1x USB-C cable
    * Our [USB 2.0 A to C Cable [CAB-15092]](https://www.sparkfun.com/products/15092) will do nicely
    * Our [USB 3.1 A to C Cable [CAB-14743]](https://www.sparkfun.com/products/14743) is a good choice too
* 1x [SparkFun Audio Codec Breakout - WM8960 (Qwiic) [BOB-21250]](https://www.sparkfun.com/products/21250)
* 1x [Hook-Up Wire - Assortment (Stranded, 22 AWG) [PRT-11375]](https://www.sparkfun.com/products/11375)
* 2x [Break Away Male Headers - Right Angle [PRT-00553]](https://www.sparkfun.com/products/553)
* 1x Set of "Mowing" Headphones aka "ear muffs"
    * [Smoostart Am/Fm Radio Hearing Protector, Noise Reduction Safety Ear Muffs, 30db Noise Cancelling Ear Protection](https://www.amazon.com/Smoostart-Cancelling-Protection-Snowblowing-Construction/dp/B08M95FP4X)
    * [PROTEAR Digital AM FM Radio Headphones, 25dB NRR Ear Protection Safety Ear Muffs](https://www.amazon.com/dp/B09ZPBM9F2/)   
* 2x [Ambient Microphones [PUI-AOM-5053L-HD3-LW100-R]](https://www.digikey.com/en/products/detail/pui-audio-inc/AOM-5035L-HD3-LW100-R/16585488) 
* 1x [PET Expandable Braided Sleeving](https://www.amazon.com/Aibole-Black%EF%BC%86Blue-Automotive-Expandable-Sleeving/dp/B07FTPZ7T3/)


### Tools

For a secure connection when using the advanced configuration, you will need to solder two wires between your microcontroller and the breakout board. This requires some assembly and soldering. You may already have a few of these items but if not, the tools and hardware below help with that assembly.

* [Hook-Up Wire - Assortment (Stranded, 22 AWG) [PRT-11375]](https://www.sparkfun.com/products/11375)
* [Wire Stripper - 20-30 AWG Solid (22-32 AWG Stranded) [TOL-22263]](https://www.sparkfun.com/products/22263)
* [Soldering Iron [TOL-14456]](https://www.sparkfun.com/products/14456)
* [Solder Lead Free - 15-gram Tube [TOL-9163]](https://www.sparkfun.com/products/9163)
* Hot Glue Gun and Hot Glue
* Dremel or similar tool for cutting out holes for ambien mics

<div class="grid cards hide col-4" markdown>

-   <a href="https://www.sparkfun.com/products/11375">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/7/1/2/0/11375-Hook-Up_Wire_-_Assortment__Solid_Core__22_AWG_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Hook-Up Wire - Assortment (Stranded, 22 AWG)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11375">
      <b>Hook-Up Wire - Assortment (Stranded, 22 AWG)</b>
      <br />
      PRT-11375
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/22263">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/2/2/2/0/1/22263-_TOL_Wire_Stripper-_01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Wire Stripper - 20-30 AWG Solid (22-32 AWG Stranded)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/22263">
      <b>Wire Stripper - 20-30 AWG Solid (22-32 AWG Stranded)</b>
      <br />
      TOL-22263
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/14456">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/2/4/9/0/14456-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Soldering Iron - 60W (Adjustable Temperature)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/14456">
      <b>Soldering Iron - 60W (Adjustable Temperature)</b>
      <br />
      TOL-14456
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/9163">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/2/5/8/7/09162-02-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Solder Lead Free - 15-gram Tube">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/9163">
      <b>Solder Lead Free - 15-gram Tube</b>
      <br>
      TOL-09163
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
</div>



### Suggested Reading

If you aren't familiar with the Qwiic Connection System, we recommend reading [here for an overview](https://www.sparkfun.com/qwiic).

<div style="text-align: center">
  <table style="border-style:none">
    <tr>
     <td style="text-align: center; vertical-align: middle;">
     <div style="text-align: center"><a href="https://www.sparkfun.com/qwiic"><img src="../assets/Qwiic-registered-updated.png" alt="Qwiic Connection System" title="Click to learn more about the Qwiic Connection System!"></a>
     </div>
    </td>
    </tr>
    <tr>
      <td style="text-align: center; vertical-align: middle;"><div style="text-align: center"><i><a href="https://www.sparkfun.com/qwiic">Qwiic Connection System</a></i></div></td>
    </tr>
  </table>
</div>

If you aren’t familiar with the following concepts, we also recommend checking out a few of these tutorials before continuing.

<div class="grid cards hide col-4" markdown>

-   <a href="https://learn.sparkfun.com/tutorials/gyroscope">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/d/6/5/6/a/5112ed4ece395f2f2a000003.gif" style="width:264px; height:148px; object-fit:contain;" alt="Gyroscope">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/gyroscope">
      <b>Gyroscope</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/accelerometer-basics">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/600-600/assets/6/7/e/5/a/516c6b6ece395f0f49000000.jpeg" style="width:264px; height:148px; object-fit:contain;" alt="Accelerometer Basics">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/accelerometer-basics">
      <b>Accelerometer Basics</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/serial-communication">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/c/264-148/assets/7/d/f/9/9/50d24be7ce395f1f6c000000.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Serial Communication">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/serial-communication">
      <b>Serial Communication</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/i2c">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/8/2/I2C-Block-Diagram.jpg" style="width:264px; height:148px; object-fit:contain;" alt="I2C">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/i2c">
      <b>I2C</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/terminal-basics">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/1/1/2/terminalThumb.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Serial Terminal Basics">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/terminal-basics">
      <b>Serial Terminal Basics</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/installing-an-arduino-library">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/b/e/4/b/2/50f04b99ce395fd95e000001.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Installing an Arduino Library">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/installing-an-arduino-library">
      <b>Installing an Arduino Library</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/6/9/ArdPro.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Connecting Arduino to Processing">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing">
      <b>Connecting Arduino to Processing</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/5/Soldering_Action-01.jpg"style="width:264px; height:148px; object-fit:contain;" alt="How to Solder: Through Hole Soldering">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all">
      <b>How to Solder: Through Hole Soldering</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
</div>