import urllib.request                                                      # Importing url library to open thingspeak url and to fedge data.
import pyttsx3                                                             # Importing pyttsx3 library to make our assistant to speak.
import re                                                                  # Importing regex library to read data coming from ThingSpeak and executing some task on this data.
import time                                                                # Importing time library.
import serial                                                              # Importing serial library to get connected with Arduino.

arduinoData = serial.Serial('com6',9600)                                   # Setting up port of Arduino.
arduinoData.timeout = 1

engine = pyttsx3.init('sapi5')                                             # Setting up voice type, speech rate and other necessary things related to speech.
voices = engine.getProperty('voices')
rate = engine.getProperty('rate')
engine.setProperty('rate', rate-10)
engine.setProperty('voice',voices[0].id)  

def speak(audio):                                                          # Defining a speak function to make our work easy in upcoming lines of code.
    engine.say(audio)
    engine.runAndWait()

if __name__=="__main__":

    while True:
        
        data = urllib.request.urlopen("https://api.thingspeak.com/channels/725014/feeds.json?api_key=FNPWD33TAFGXC4KJ&results=1")   # Requesting for url to get open. 
        data =repr(data.read())                                                                                                     # Making the data coming from the url to read.
                                                                                                            
                                                                                                        
        
        find1 = data.find("field1", 200)                                     # Finding the field1 or button1 value from the raw data.
        find1 = find1 + 9  
        
        find2 = data.find("field2", 200)                                     # Finding the field2 or button2 value from the raw data.
        find2 = find2 + 9    

        button1 = data[find1:]                                                # Making the field1 value or button1 value to be readable.
        buttonvalue1 = button1[:1]

        button2 = data[find2:]                                                # Making the field2 value or button2 value to be readable.
        buttonvalue2 = button2[:1]

        print("Button 1 value :" + buttonvalue1)                       # Printing button1 value. 
        print("Button 2 value :" + buttonvalue2)                       # Printing button2 value.

        if int(buttonvalue1) == 1:
            speak("I received signal to tell arduino to switch on led one")
            led = ("led one on")                                               # IN LED KEYWORD WE WILL PUT (LED ONE ON) COMMAND. 
            arduinoData.write(led.encode())                                    # NOW THIS VALUE(LED ONE ON) WILL BE SEND TO ARDUINO AND ARDUINO WILL EXECUTE ALL THE COMMANDS RELATED TO IT.
            time.sleep(0.5)                                                    # THIS SLEEP TIME IS GIVEN SO THAT ARDUINO AND PYTHON WILL WORK PROPERLY WITHOUT ANY ERRORS. 
            print(arduinoData.readline().decode('ascii'))                      # WHEN THE COMMAND WILL BE EXECUTED THE ARDUINO WILL SEND THE COMMAND THAT IT HAS DONE THE GIVEN TASK.

        else :
            print("No signal received to switch on led 1")
            led = ("led one off")                                             # IN LED KEYWORD WE WILL PUT (LED ONE OFF) COMMAND. 
            arduinoData.write(led.encode())                                   # NOW THIS VALUE(LED ONE OFF) WILL BE SEND TO ARDUINO AND ARDUINO WILL EXECUTE ALL THE COMMANDS RELATED TO IT.
            time.sleep(0.5)                                                   # THIS SLEEP TIME IS GIVEN SO THAT ARDUINO AND PYTHON WILL WORK PROPERLY WITHOUT ANY ERRORS. 
            print(arduinoData.readline().decode('ascii'))                     # WHEN THE COMMAND WILL BE EXECUTED THE ARDUINO WILL SEND THE COMMAND THAT IT HAS DONE THE GIVEN TASK.

        if int(buttonvalue2) == 1:
            speak("I received signal to tell arduino to switch on led two")
            led = ("led two on")                                              # IN LED KEYWORD WE WILL PUT (LED TWO ON) COMMAND.
            arduinoData.write(led.encode())                                   # NOW THIS VALUE(LED TWO ON) WILL BE SEND TO ARDUINO AND ARDUINO WILL EXECUTE ALL THE COMMANDS RELATED TO IT.
            time.sleep(0.5)                                                   # THIS SLEEP TIME IS GIVEN SO THAT ARDUINO AND PYTHON WILL WORK PROPERLY WITHOUT ANY ERRORS. 
            print(arduinoData.readline().decode('ascii'))                     # WHEN THE COMMAND WILL BE EXECUTED THE ARDUINO WILL SEND THE COMMAND THAT IT HAS DONE THE GIVEN TASK.

        else :
            print("No signal received to switch on led 2")
            led = ("led two off")                                             # IN LED KEYWORD WE WILL PUT (LED TWO OFF) COMMAND. 
            arduinoData.write(led.encode())                                   # NOW THIS VALUE(LED TWO OFF) WILL BE SEND TO ARDUINO AND ARDUINO WILL EXECUTE ALL THE COMMANDS RELATED TO IT.
            time.sleep(0.5)                                                   # THIS SLEEP TIME IS GIVEN SO THAT ARDUINO AND PYTHON WILL WORK PROPERLY WITHOUT ANY ERRORS. 
            print(arduinoData.readline().decode('ascii'))                     # WHEN THE COMMAND WILL BE EXECUTED THE ARDUINO WILL SEND THE COMMAND THAT IT HAS DONE THE GIVEN TASK.

        print("***********************************************************************************************************************")
