//Angle Test
#include <M5StickC.h>
int sensorPin = 33; // set the input pin for the potentiometer. 
int ServoPin = 26;

int last_sensorValue = 100; // Stores the value last read by the sensor
int cur_sensorValue = 0;  // Stores the value currently read by the sensor. 

void setup() 
{
  M5.begin(); //Init M5StickC.
  M5.Lcd.setRotation(3);  // Rotate the screen.  
  M5.Lcd.setTextSize(2);  // Set the font size to 2.  
  pinMode(sensorPin, INPUT);  // Sets the specified pin to input mode.  
  dacWrite(25, 0); 
  M5.Lcd.print("the value of ANGLE: ");// print text
}

void loop() 
{
  cur_sensorValue = analogRead(sensorPin);  // read the value from the sensor.  
  M5.Lcd.setCursor(0, 40);  //Place the cursor at (0,40).  
  if(abs(cur_sensorValue - last_sensorValue) > 10){ // If the difference is more than 10.  
    M5.Lcd.fillRect(0, 40, 100, 25, BLACK); // fill a rectangle with a specified color. (X, Y, WIDTH, HIGH, COLOR) 
    M5.Lcd.print(cur_sensorValue); //print the value
    last_sensorValue = cur_sensorValue;
  if (cur_sensorValue > 500)
  dacWrite(ServoPin,30); // digital to analog conversion 
  }
  delay(50);
}
