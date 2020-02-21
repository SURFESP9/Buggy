#include <iostream>
#include <math.h>


const float radius = 0.07;
float Kp, Ki, Kd;
float latestError;
float error[20] = 0;
float change;


void getLeftEncValue();
void getRightEncValue();

void calError(){
    latestError= 1000x(1*LL_GPIO_read1+2*LL_GPIO_read2+3*LL_GPIO_read3+4*LL_GPIO_read4+5*LL_GPIO_read5+6*LL_GPIO_read6)/(LL_GPIO_read1+LL_GPIO_read2+LL_GPIO_read3+LL_GPIO_read4+LL_GPIO_read5+LL_GPIO_read6);
    ...        // address shifting
}



void isLineBroken(float sensorVal,float* prevRspeed,float* prevLspeed)                            //interrupt
{
    if(sensorVal <= 100)                    //100 is temporary value. later change with calculated line value
    {
         onLineBreak();
    }
}

void calSpeedLeft(){
    int RPS =  getLeftEncValue()*(2*M_PI/1000);
    int MPS = RPS * 2*M_PI*radius;
}
void calSpeedRight(){
    int RPS =  getRightEncValue()*(2*M_PI/1000);
    int MPS = RPS * 2*M_PI*radius;
}
int isLineMid(int sensorVal, int* LED)
{
    if(sensorVal<=5000 && sensorVal>=3000){
        LED = 1;
    }
}

void spdPID();
void dirPID();
void breakSensing();

float ErrorIntegral(){
    float value=0;
    for(int i=0; i<20; i++){
        value += error[i];
    }
    return value;
}

float ErrorDif(){
    return (error[20]-error[19]);
}


void PID(){
    change = (Kp*error[20])+Ki*(ErrorIntegral())+(Kd*ErrorDif());
}

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
