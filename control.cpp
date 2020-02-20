#include <iostream>
#include <math.h>


const float radius = 0.07;

void getEncoderLeft();
void getEncoderRight();
void isLineBroken(float sensorVal,float* prevRspeed,float* prevLspeed)                            //interrupt
{
    if(sensorVal <= 100)                    //100 is temporary value. later change with calculated line value
    {
         onLineBreak();
    }
}

void calSpeedLeft();
void calSpeedRight();
int isLineMid(int sensorVal, int* LED)
{
    if(sensorVal<=5000 && sensorVal>=3000){
        LED = 1;
    }
}
void spdPID();
void dirPID();
void breakSensing();
void PID();
void setMotorSpeedRight(int Rspeed){
    RDutyCycle = Rspeed;
}
void setMotorSpeedLeft(int Lspeed){
    LDutyCycle = Lspeed;
}

void onLineBreak(float* prevRspeed, float* prevLspeed){            //interrupt (isLineBroken()==1)
                                                        
        setMotorSpeedRight(*prevRspeed);
        setMotorSpeedLeft(*prevLspeed); 
}






int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
