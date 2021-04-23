# SWITCHING-ON-LED-S-WITH-A-BUTTON-WITH-HELP-OF-IOT-USING-ARDUINO-AND-PYTHON
In this project you all will learn about how we can switch on/off a led with a button from anywhere using IOT. 
In this project I have used Arduino and Python Programming languages to build the software part.
When a user will click a button then signal will go into Nodemcu which is a microcontroller. Nodemcu will pass this data to a Thingspeak server where this data will be presented and stored. Now our python program will read this raw data and then usefull data from the raw data will be fetched out. Now our python program will send the data to our Arduino uno which will switch on the led.
This process is not a very fast process. It will take some seconds to perform this operation.
I just want to show that we can also send data from Nodemcu to another controller by taking Thingspeak as a medium.

BUTTON IOT File :- This file is for Nodemcu and from this you will pass signals using buttons.
GET INPUT File :- This file is for Arduino Uno. This will receive commands from Python and will act upon it.
IOT BUTTON.PY File :- This file is a Python file.

For more Information about this project go to my YouTube channel
My YouTube channel link :- https://youtube.com/channel/UCsKfPerC5SseOFjiZ5Zy7Xg

Tutorial link for this project :- https://youtu.be/Nc6tki9MGIY
