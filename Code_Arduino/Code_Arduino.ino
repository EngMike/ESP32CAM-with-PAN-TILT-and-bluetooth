#include<Servo.h> // include servo library
Servo serx; // create servo object to control a servo
Servo sery; // create servo object to control a servo
int poserx = 90;// initial position of servo x
int posery = 90;// initial position of servo y
int valx; // initial value of input for servo x
int valy; // initial value of input for servo y

void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
  serx.attach(9);// serverx is connected at pin 9
  sery.attach(10);// servery is connected at pin 10
}

void loop() {
  // horizontal
  if (Serial.available()) // if serial value is available 
  {
    valx = Serial.read();// then read the serial value
    if (valx == 'a') //if value input is equals to d
    {
      poserx += 1; //than position of servo motor increases by 1 ( anti clockwise)
      serx.write(poserx);// the servo will move according to position 
      delay(15);//delay for the servo to get to the position
     }
    if (valx == 'd') //if value input is equals to a
    {
      poserx -= 1; //than position of servo motor decreases by 1 (clockwise)
      serx.write(poserx);// the servo will move according to position 
      delay(15);//delay for the servo to get to the position
    }
   }
   {
  // vertical
  valy = Serial.read();// then read the serial value
    if (valy == 's') //if value input is equals to d
    {
      posery += 1; //than position of servo motor increases by 1 ( anti clockwise)
      sery.write(posery);// the servo will move according to position 
      delay(15);//delay for the servo to get to the position
     }
    if (valy == 'w') //if value input is equals to a
    {
      posery -= 1; //than position of servo motor decreases by 1 (clockwise)
      sery.write(posery);// the servo will move according to position 
      delay(15);//delay for the servo to get to the position
    }
  }
}
