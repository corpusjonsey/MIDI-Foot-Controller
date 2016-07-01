MIDI Foot Controller firmware for Elektron Octatrack Pickup Machine control.

  v1.1 - Update to Bounce2 library
  v1.2 - Change switch 1 to Combo rec #60, TODO: Expression control

Use this firmware at your own risk!

I wanted to customize the firmware for my Disaster Area DMC-6 MIDI pedal to control the
Pickup Machines on the Elektron Octatrack.
The included .ino sketch contains the C code so it can be modified to be used in other models of
DMC MIDI pedals or other AVR based MIDI controllers. 

The firmware configures the output of the pedal as follows:

MIDI channel 9 (Octatrack default auto channel).

Bottom row: Switch 1 = MIDI note #61-INAB rec, SW 2 = #64-Pickup Play/Stop, SW 3 = #69-Active Track down

Top row: Switch 4 = #34-seq start/stop, Switch 5 = #71-Toggle sync seq+start, Switch 6 = #68-Active Track up

Upload firmware as you would any other firmware for your particular pedal. 
I don’t provide any support to get you up and running so only use this if you know what you are doing.
I just uploaded the hex file using the manufacturers firmware upload tool on their website
and it works great for me. 

Happy hacking!