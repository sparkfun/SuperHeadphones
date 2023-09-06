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
to eventually dissasemble all of the parts. 

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
this by the end of this project, as I ended up taking mine apart nearly 50 times 
as I dialed in the wiring and finally chose the perfect microphones for the job. 
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
the right amount of pressure, it can be done. Maybe there is a tiny right angled 
screw driver that someone knows... if you do, please comment below! 

When the inner screws are removed, the cans come apart, and 
then you have access to the inner electronics. As you wire things up, I would advise 
to keep your wires fairly short, as it all has to fit under the hood when you put 
it back together.