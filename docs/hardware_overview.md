<!-- This section goes into detail about the various components on the product, solder jumpers as well as the board dimensions with a dimensional drawing exported from Eagle. -->

## Block Diagram

Here is a high-level block diagram of the sound system inside the headphones. The 
Audio Codec is central to this design. It handles all of the sound
inputs and outputs. The ESP32 Thing Plus is still the "brain", and it is necessary 
to setup and control the codec with I2C. The ESP32 also receives the wireless audio (BT), 
and then sends that to the codec, digitally, with I2S audio data lines.

<figure markdown>
[![Headphones](../assets/img/Super_Headphones_Block_Diagram_v01_600wide.jpg){ width="600" }](../assets/img/Super_Headphones_Block_Diagram_v01.jpg "Click to enlarge")
<figcaption markdown>
High level block diagram of the headphone system.
</figcaption>
</figure>

## Exploded View

Here is an exploded view of the heapdhones. It took a little experimenting and tinkering 
to eventually dissasemble all of the parts. In this section, we will share a few
techniques we learned along the way during this hack.

<figure markdown>
[![Headphones](../assets/img/superheadphones_exploded_600wide.jpg){ width="600" }](../assets/img/superheadphones_exploded.jpg "Click to enlarge")
<figcaption markdown>
Exploded view of the headphone system.
</figcaption>
</figure>

## Foam Removal

Removing the foam was pretty straight forward. 
You can use a flat head screw driver or pliers, but be careful. As you can see, 
I accidentally ripped the foam apart when I pulled a bit too hard. 

<figure markdown>
[![Headphones](../assets/img/foam_ripped_600wide.jpg){ width="600" }](../assets/img/foam_ripped.jpg "Click to enlarge")
<figcaption markdown>
Oops! I accidentally ripped the foam.
</figcaption>
</figure>

It's really best to take it slowly and pull it gently, little-by-little. I really got the hang of 
this by the end of this project. I must have taken mine apart nearly 50 times 
as I fine tuned the wiring and swapped out microphones during testing. 
Hopefully, by reading this tutorial, you can keep this dis-assembly and re-assembly 
cycle to a minimum :). 

## Screws

After you remove the foam, this will expose the screws that hold the outer and inner parts 
of each can together. 

<figure markdown>
[![Headphones](../assets/img/hp_screws_600wide.jpg){ width="600" }](../assets/img/hp_screws.jpg "Click to enlarge")
<figcaption markdown>
Two small screws hold the cans together.
</figcaption>
</figure>

The screws are located back behind the black plastic. Because of the angle, they 
can be a little difficult to access, but with a small phillips screw driver and 
the right amount of pressure, it can be done.

## Knob and PCB removal

When the inner screws are removed, the cans come apart, and 
then you will see the original electronics (blue). The volume knob is simply 
pressure fitted onto the potentiometer shaft, so you can pull that directly off. 
Unscrew the potentiometer mounting nut and the four mounting screws, and you will 
then be able to remove the original electronics.

<figure markdown>
[![Headphones](../assets/img/knob_removal_600wide.jpg){ width="600" }](../assets/img/knob_removal.jpg "Click to enlarge")
<figcaption markdown>
Knob, nut, and 4 mounting screws removed.
</figcaption>
</figure>

## Wiring Diagram

Once everything is opened up, you can begin wiring up the necessary connections. 
Here is a wiring diagram to show all the connections in one place. 

<figure markdown>
[![Headphones](../assets/img/SuperHeadphones_Wiring_Diagram_600wide.jpg){ width="600" }](../assets/img/SuperHeadphones_Wiring_Diagram.jpg "Click to enlarge")
<figcaption markdown>
Wiring Diagram. Lots to hook up!
</figcaption>
</figure>

Three important things to remember:

* Use 26 guage wire for most of the connections, as it can get fairly tight in there. 
I used an old ethenet cable which had 8 conductors. If you open those up, the resulting 
hookup wire is quite nice to work with, and has great coloring to keep things strait.

* The left microphone signal and its ground connection must use a shielded cable. If you 
wire it up with bare hook-up wire, then you will be prone to picking up strange 
sounds like distant radio stations and creeping whining noises with varying frequencies. 
Kind of fun, but not ideal for every listening experience.

* The microphones we ultimately chose require a specific power and signal circuit (see below). 

## Microphone Circuit

Here is the required circuit from the datasheet of the PUI Audio AOM-5035L.

<figure markdown>
[![Headphones](../assets/img/mic_circuit_600wide.png){ width="600" }](../assets/img/mic_circuit.png "Click to enlarge")
<figcaption markdown>
AOM-5035L Microphone Signal & Power Circuit
</figcaption>
</figure>

Note, the capacitor is already included on the WM8960 input, and so we 
only need to wire up the pull-down resistor of 5.6K on the signal. Put this pull-down 
resistor as close to the microphone as possible. The left microphone is the only 
one that is more suseptable to picking up noise, and so we found that having the 
pull-down in that ear-can (and using a sheilded mic cable) elliminated any unwanted 
noise.

As a side note, the proximity of the pull-down resistor to the microphone also 
had an effect on the acoustic overload point (AOP). Strangely, if the the resistor 
was placed too far away, then the mics begin clipping at lower sound source volumes. 
During my early testing, I would hear clipping in my left ear when I really played 
hard on the hi-hats (which are probably the loudest and closest drum instrument to that 
microphone). But as soon as I moved the pull-down closer to the mic, the clipping 
went away!

Here is some close up shots of where I ended up hacking in the final position of 
each pull-down resistor. Note, I didn't have the exact 5.6K resistors required, so 
for the left ear, I used two 2.2Ks in series. And for the right, I used a 4.7K. 

<div class="grid cards" markdown align="center">

-   <a href="../assets/img/left_pull_down.jpg">
	<figure markdown>
	![Headphones](../assets/img/left_pull_down_600wide.jpg)
	</figure>
    </a>

    ---
        
    **Left mic pull-down resistor**</a>

-   <a href="../assets/img/right_pull_down.jpg">
	<figure markdown>
	![Headphones](../assets/img/right_pull_down_600wide.jpg)
	</figure>
    </a>

    ---
    
    **Right mic pull-down resistor**</a>

</div>