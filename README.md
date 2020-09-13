# Appliance-Control-System
- LM35 is an analog, linear temperature sensor whose output voltage varies linearly with change in temperature. 
- LM35 is three terminal linear temperature sensor from National semiconductors. 
- It can measure temperature from-55 degree celsius to +150 degree celsius. 
- The voltage output of the LM35 increases 10mV per degree Celsius rise in temperature. 
- LM35 can be operated from a 5V supply and the stand by current is less than 60uA. 
# Steps
- Microcontrollers dont accept analog signals as their input directly.
- We need to convert this analog output signal to digital before we can feed it to a microcontroller’s input. 
- For this purpose, we can use an ADC( Analog to Digital Converter).If we are using a basic microcontroller like 8051, we need to use an external ADC to convert analog output from LM35 to digital. 
- We then feed the output of ADC ( converted digital value) to input of 8051. 
- But modern day boards like Arduino and most modern day micro controllers come with inbuilt ADC. 
- Our arduino uno has an in built 10 bit ADC (6 channel). 
- We can make use of this in built ADC of arduino to convert the analog output of LM35 to digital output. 
- Since Arduino uno has a 6 channel inbuilt ADC, there are 6 analog input pins numbered from A0 to A5. 
- Connect analog out of LM35 to any of these analog input pins of arduino.

- Connect the +5v for LM35 can be taken from the +5v out pin of arduino uno. 
- Also the ground pin of LM35 can be connected to GND pin of arduino uno. 
- Connect Vout (the analog out of LM35) to any of the analog input pin of arduino uno.
