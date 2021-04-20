String background;                                                                       // Declaring background as a string 
int led1 = 8;                                                                            // Declaring led1 as an integer at Digital pin 8
int led2 = 9;                                                                            // Declaring led2 as an integer at Digital pin 9 


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);                                                                 
pinMode(led1, OUTPUT);                                                                  // Declaring led1 as OUTPUT.                
pinMode(led2, OUTPUT);                                                                  // Declaring led2 as OUTPUT.   
digitalWrite(led1, LOW);                                                                // Making led1 LOW.
digitalWrite(led2, LOW);                                                                // Making led2 LOW.
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available() >0)
{
  background = Serial.readStringUntil('\n');                                             // Reading data from Python.
  if(background == "led one on")                                                         // If arduino will get a command "led one on" then it will execute the following lines. 
  {
    digitalWrite(led1,HIGH);                 
    Serial.write("Led 1 one is on");                                                     // Communication of arduino with python.
  }
  else if(background == "led one off"){
    digitalWrite(led1, LOW);
    Serial.write("Led 1 is off");                                                        // Communication of arduino with python.
    
  }
  if(background == "led two on")
  {
    digitalWrite(led2,HIGH);
    Serial.write("led 2 is on");                                                        // Communication of arduino with python.
  }
  else if(background == "led two off"){
    digitalWrite(led2, LOW);
    Serial.write("led 2 is off");                                                       // Communication of arduino with python.
  }
}
}
