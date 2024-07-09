.TL
Notes on work done 
.AU
Lucas Standen + Nigel Standen
.AI
29/5/24
.NH 1
How the current of an LED can effect the wavelength of the output
.NH 2 
The experiment
.LP
In the experiment we measured how the wavelength of an LED is effected by the current passed through
it. The results lead one to believe that as current increases the wavelength does too.

We made sure to measure using a pulse, rather than a continuous current, this is to ensure that the 
thermal energy that the LED gives off, does not effect its results; however we believe our pulse
was still to long and that it did effect the results.

The pulse is generated by an Arduino with a simple script running, allowing me to press a button
that triggers the power supply and the spectrometer (tool used to measure wavelengths). Before 
starting the experiment, we took a reading of ambient temperature, as we were looking at 
current (which effects temperature) against wavelength.

We found the temperature to be 
.B "20 deg C".

.NH 3
Triggering circuit
.LP
The triggering circuit was kept simple, with most things being done in code, one thing of note 
however is that the push button used as a trigger is in a push to make configuration.

To wire the circuit follow these steps:

1) Attach a button between pin 2, and ground.

2) Attach pin 7 to the spectroscope's live input, and attach its ground to a ground rail on the
bread board.

3) Attach pin 8 to the PSU's live input and its ground to a shared ground.

4) Using the Arduino ide, flash the code (can be found on the USB you gave me).

5) Set up the program on the PSU to have a pulse duration as long as you need, and then press the
button.

.LP
The code for this can be seen here as well:
.LP
.B1
const int instrument1Pin = 7; // Pin for instrument 1 (0V to 5V) Spectroscope

const int instrument2Pin = 8; // Pin for instrument 2 (5V to 0V) PSU

const int triggerPin = 2; // the pin the button is connected too (active high)

// Configure pulses
const int pulseDurationInMs = 100;
const int psuDelayInMs = 30;

void setup() {
        // Configure pins
        pinMode(instrument1Pin, OUTPUT);
        pinMode(instrument2Pin, OUTPUT);
        pinMode(triggerPin, INPUT_PULLUP);

        // Initialize pins
        digitalWrite(instrument1Pin, LOW); // LOW corresponds to 0V (min value)
        digitalWrite(instrument2Pin, HIGH); // HIGH corresponds to 5V (max value)

}


void loop() {
        if (digitalRead(triggerPin) == LOW){
                // Create pulses
                digitalWrite(instrument2Pin, LOW);
                delay(psuDelayInMs);
                digitalWrite(instrument1Pin, HIGH);

                delay(pulseDurationInMs - psuDelayInMs);


                digitalWrite(instrument2Pin, HIGH);
                delay(psuDelayInMs);
                digitalWrite(instrument1Pin, LOW);
                delay(1000);
        }

}
.B2
.LP
It is relatively simple in function, when the switch on pin 2 goes high, it will send a low to the 
PSU (the PSU is active low in this case) and a high to the spectrometer (active high). The setup
function (defined in the first set of {}) is used to initialise the pins, and the loop function
will be run as fast as the microcontroller can. It constantly checks if the trigger pin goes low 
(the button has shorted pin 2) and if it does it sends a pulse of pulseDurationInMS down
each wire. The variable psuDelayInMs is used to set how much sooner the PSU will trigger compared 
to the spectrometer.

.NH 2 
The results
.LP
We measured results using a green LED, and our pulse's had a width of 450ms

A graph of results can be found below:
.PSPIC graph.ps
.LP
.I "y axis = wavelength (nm), x axis = current (mA)"
.LP
I modelled a line of best fit for this graph to be y = 1/9x + 568.4, with X being the current in mA, 
and Y being the wavelength in nm; however this is just by eye. From this one can assume the 
temperature coefficient to be 1/9 nm/mA.

The results show that as the LED had more current flowing through it, the colour of the light it
produced changed to a higher wavelength (towards red).

It is worth noting that when we reduced the pulse duration to 300ms instead of 450ms, at 30mA
the wavelength fell to 570.61nm, which suggests that even on a pulse as small as 450ms the heating 
of the LED has effected its wavelength.

Of note we found that there was a tiny delay between when the when the spectrometer went high, and
the PSU went low, we found it to be around 6us, we believe this to be because the spectrometer is
set to go high first.

This effect can be seen in this oscilloscope:
.PSPIC scope.ps
.I "The yellow traces is the spectrometer, the blue is the PSU"

.NH 2 
Takeaways
.LP
From this experience I think I should takeaway that, first LED's are effected by temperature very
slightly, and that the equipment resolution/accuracy is important to note, my results may be wrong,
however the trend shown by that graph is correct, I find this interesting and important.

I've believe this work will help me in further life, it really has been my first glimpse into a real
working world with electronics, I look forward to working more on it.

.NH 1
Building LED's
.LP
The process consists of taking the die which is made from silicon and a handful of other metals
that decide the wavelength of the light emitted. The die is placed on a package with apoxy, that
contains silver, then a wire is bonded to the top (see pictures), to the other part of the package.

Here is some images of the process or wire bonding LED's:
.PSPIC wirebonds.ps
.I "A view of the die on the package, and the machine"
.PSPIC wirebonds2.ps
.I "A view through the lens"
.LP
This was a very interesting process to see, I always imagined an LED as one bit of metal that did
the job, I had never through how much precision work went into it. The LED's we worked on 
were 280um x 280um.