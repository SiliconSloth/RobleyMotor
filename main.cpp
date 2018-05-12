// Author: SiliconSloth 18/1/2018

#include <Arduino.h>
#include <Wire.h>
#include <PRIZM.h>

PRIZM prizm;
int lastLine;

/*
 * This code runs on the Tetrix Prizm controller and is soley responsible
 * for receiving motor powers sent from a laptop
 * and setting the powers of the motors accordingly.
 */

/*
 * Power serialization format:
 *
 * Motor powers can range between -100 and 100.  If a special value of 101 is received for either motor
 * RobleyMotor shuts down and restarts, which also causes the robot to stop moving.
 *
 * In order to send motor powers over USB, they must first be converted into bytes, which can
 * store integers ranging between 0 and 255.  RobleyMotor receives bytes in the range 0 to 201
 * and subtracts 100 from them to yield values between -100 and 101.
 */

 // Runs once when the controller turns on.
 void setup() {
   // Initialize the controller.
   prizm.PrizmBegin();
   prizm.setMotorInvert(1,1);

   // Clear any bytes left in the serial buffer from the last run.
   // Keeps reading the next byte until there are none left.
   while (Serial.read() != -1) {}

   // Get ready to receive messages over USB.
   Serial.begin(9600);
   Serial.setTimeout(100000);
}

// Runs repeatedly in a loop.
void loop() {
  // Keep trying to read the next byte until there is actually one available.
  int powerLeft = -1;
  while (powerLeft == -1) {
    powerLeft = Serial.read();
  }
  int powerRight = -1;
  while (powerRight == -1) {
    powerRight = Serial.read();
  }

  // Print the bytes received for debugging purposes.
  // String output = String(powerLeft) + ", " + String(powerRight);
  // Serial.println(output);

  // Deserialize the bytes as explained above.
  powerLeft -= 100;
  powerRight -= 100;

  // If either of the powers are the 101 stop command stop the program,
  // otherwise set the motor powers.
  if (powerLeft == 101 || powerRight == 101) {
    prizm.PrizmEnd();
  } else {
    prizm.setMotorPowers(powerLeft, powerRight);
  }
}
