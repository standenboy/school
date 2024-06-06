.TL
Notes from work experience day 2
.AU
Lucas Standen
.AI
30/5/24
.NH 1
The voltage over an LED
.NH 2
The experiment
.LP
Continuing on from yesterdays study of The wavelength of LEDs and how it change as the current was 
increased, today I have taken results showing how time effects the voltage across the LED.

I would predict that the LED's voltage will fall over time as the temperature increases, which will
cause the die to "slow down" so to say, or stop behaving as once intended.

My results were taken on a green LED with a 10mA current provided at 2.2V. A multimeter was used to
capture data from the LED, it takes 2000 readings and outputs them in a csv file (my results can be 
found in results.csv).

I found it took on average 45 seconds for the multimeter to take 2000 results.
The data was taken at 1 nplc (1 nplc = 1/50hz)

.NH 2
Results
.LP
As expected the voltage over the LED fell slightly over time, the graph of these results can be seen
bellow.
.PSPIC graph.ps
.LP
Another graph showing the first 450ms can be seen here, this relates to how our pulse mesurements
from yesterday
.PSPIC graph2.ps
.LP
As you can see, this is experiencing exponential decay, falling quickly at first and then levelling
out. This was about as expected. The voltage falls, as the LED is too hot, then it reaches closer
and closer to equilibrium, where the total thermal output is the same as the power input.
.NH 2
Takeaways
.LP
From my data I can take away that LED's are definitely thermally limited, one can see this from
today's data and yesterdays data. I have found it interesting how the LED can heat up so slightly
and yet it still have an effect on the voltage input. One would suppose there is a formula to model
this decay in voltage.

