#include <iostream>
#include <math.h>


const float radius = 0.07;

void getEncoderLeft();
void getEncoderRight();
void calSpeedLeft();
void calSpeedRight();
void getSensor();
void speedPID();
void directionPID();
void breakSensing();
void PID();
void setMotorSpeedRight();
void setMotorSpeedLeft();



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}