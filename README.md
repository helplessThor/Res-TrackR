# Res-TrackR
The Res-TrackR is Proof-of-Concept (PoC) demonstration of how Internet of Things can bring revolution in our society.
In today's world, already IoT has become a technological key player in multiple solution. Taking this one step higher, to solve one of the burning
problems of the society, IoT based Women Safety SOS System has been demonstrated in this project. As the name suggests, it is basically a Rescue Tracker Device,
incorporated with IoT, which can report user's location upon user's consent. The workflow can be discussed in following segments.
Let's come to its hardware components--

1. Main Microcontroller Arduino UNO Board (ATmega328P)
2. GPS Transponder Module (NEO 6M)
3. Generic Touch Sensor Module
4. GSM Module (SIM 900A)

Here is the block diagram of the system--
![GitHub Logo](https://github.com/helplessThor/Res-TrackR/blob/main/touch_gps/images/IMG_20210419_180712.jpg)


Pin Connection between Arduino and GPS:
Arduino UNO | GPS Module
----------- | -----------
Digital Pin 2 | TX
Digital Pin 3 | RX
3.3 V | VCC
GND | GND

Pin Connection between Arduino and GSM:
Arduino UNO | GSM Module
----------- | -----------
Digital Pin 9 | TX
Digital Pin 10 | RX

Pin Connection between Arduino and Touch Module:
Arduino UNO | Touch Module
----------- | -----------
Digital Pin 7 | Signal/Data
GND | GND
3.3 V | VCC

Basically, this system runs on a simple workflow of **Trigger-Fetch-Respond**. The user provides a trigger by touching into the touch sensor. It serves as an Interrupt to 
the normalcy of the system. As an interrupt requires ISR (Intterupt Service Routine), in a similar fashion, this trigger asks the device to fetch current **Location 
Co-ordinates**. If a valid set of coordinates fetched, then the system calls the GSM Module to send an SMS to a registered mobile number with the location details with 
a Google Map Link.
In this way, this system can potentially be used as a Women-Saafety SOS Device, as this IoT device uses the bandwidth of Cellular Communication, it can be used in remote 
areas also, where internet connectivity is little. Thus, not only as a Women's Safety device, it can be potentially used for any rescue location device also. Such device 
can be used by campers, and even by rescue officials.
Although the project has been made using GSM Module, as LTE Bandwidth has become affordable, it can easily be upgraded with an LTE module, as most of the SIM cards today 
do not support 2G and hence incompatible with GSM Module.

---

## Project Makers

- Kuntal Paul     <kuntalpauloriginal@gmail.com>
- Ishan Chaudhari <ishanchdhr2@gmail.com>
- Arpan Mukherjee <arpanjonty@gmail.com>

---

## License

&copy; Kuntal Paul, Res-TrackR
