# IR-Morse
Morse coding and decoding based on FSK

Morse transmitter is a purely 555 timer based analog circuit.It has two stages, both being astable multivibrators.The first stage is the encoder which changes the frequency of the output of first stage depending on the button press (by changing the equivalent resistance across the discharge and threshold pin),this then drives the second stage which has a frequency of 38kHz and hence the output is product modulated.
On the receiver side we have a TSOP0038 IR receiver which receives information in form of 38kHz burst cycles,this then sends the demodulated signal to arduino for further analysis and the received data is displayed on an 16x2 LCD.
This is not exactly a morse type receiver, but almost one with a few minor changes.

It also has an Easter Egg :p  
Project by RD Jain and Varun Kumar Srivastav
