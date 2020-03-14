//
// Created by user on 2020-03-14.
//

#ifndef BUGGY_CONTROL_H
#define BUGGY_CONTROL_H

#endif //BUGGY_CONTROL_H

#include <stdio.h>
#include <math.h>

const int noSensor = 6
const float radius = 0.07;
int latestNum = 0;
int noErrorBuf = 20;
float Kp, Ki, Kd;
float SKp, SKi, SKd;
float latestError;
float error[noErrorBuf] = 0;
float leftSpeedError[noErrorBuf] = 0;
float rightSpeedError[noErrorBuf] = 0;
float change;
float desiredSpdVal = 100;
float LSpd, RSpd;
float prevRSpd[20], prevLSpd[20];
float leftSpeedChange = 0;
float rightSpeedChange = 0;



void isLineBroken(float sensorVal,float* prevRspeed,float* prevLspeed){};
void calError() {};
void calSpdError(){};
void PID(){};
void spdPID(){};
void setMotorSpeed(int change){};
void calSpeedLeft(){};
void calSpeedRight(){};
int isLineMid(int sensorVal, int* LED){};
float errorIntegral(){};
float errorDif(){};
float leftSpeedErrorIntegral(){};
float leftSpeedErrorDif(){};
float rightSpeedErrorIntegral(){};
float rightSpeedErrorDif(){};
void setMotorSpeedRight(int Rspeed){};
void setMotorSpeedLeft(int Lspeed){};
void onLineBreak(float* prevRspeed, float* prevLspeed){};





void getLeftEncValue();
void getRightEncValue();
