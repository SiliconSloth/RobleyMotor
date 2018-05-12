# RobleyMotor

RobleyMotor is a simple program to be run on  a [Tetrix Prizm](https://www.tetrixrobotics.com/PRIZM) controller, which allows a pair of motors to be controlled via USB.  It receives pairs of motor powers from the serial port and relays them to the motors.  It is intended for use with [RobleyVision](https://github.com/SiliconSloth/RobleyVision) running on a laptop.

When using RobleyMotor I highly recommend adding something to your robot to keep the green button on the Prizm controller held down, so that you don’t need to press it every time the program restarts.

The easiest way to install RobleyMotor is probably to copy/paste the contents of `main.cpp` into the main source file of a blank Prizm project.  See [this](https://www.tetrixrobotics.com/prizmdownloads) for help setting up a Prizm project in the Arduino IDE.

RobleyVision: https://github.com/SiliconSloth/RobleyVision
