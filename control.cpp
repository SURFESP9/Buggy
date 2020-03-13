#include <iostream>
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


void isLineBroken(float sensorVal,float* prevRspeed,float* prevLspeed)                            //interrupt ticker
{
    int cnt;
    for(int i=0; i<=noSensor - 1;i++) {
         if(LL_GPIO_read(i) > 2000)
             cnt++;
    }

    if(cnt < 1)
    {
         onLineBreak();
    }
}

void calError() {
    latestError =
            1000x(1 * LL_GPIO_read1 + 2 * LL_GPIO_read2 + 3 * LL_GPIO_read3 + 4 * LL_GPIO_read4 + 5 * LL_GPIO_read5 +
                  6 * LL_GPIO_read6) /
            (LL_GPIO_read1 + LL_GPIO_read2 + LL_GPIO_read3 + LL_GPIO_read4 + LL_GPIO_read5 + LL_GPIO_read6)-3500;
    for (int i = 0; i < noErrorBuf-1; i++) {
        error[i+1]=error[i];                                                             // address shifting
    }
    error[latestNum] = latestError;
}

void calSpdError(){
    for (int i = 0; i < noErrorBuf-1; i++) {
        leftSpeedError[i+1]=leftSpeedError[i];
        rightSpeedError[i+1] = rightSpeedError[i];
    }
    leftSpeedError[latestNum] = LSpd - desiredSpdVal;
    rightSpeedError[latestNum] = RSpd - desiredSpdVal;

}


void PID(){
    change = (Kp*error[latestNum])+Ki*(errorIntegral())+(Kd*errorDif());
}



void spdPID(){
    leftSpeedChange = (SKp*leftSpeedError[latestNum])+(SKi*leftSpeedErrorIntegral())+(SKd*leftSpeedErrorDif());
    rightSpeedChange = (SKp*rightSpeedError[latestNum])+(SKi*rightSpeedErrorIntegral())+(SKd*rightSpeedErrorDif());



    //float speedChange = (Kp*error[noErrorBuf-1])+Ki*(ErrorIntegral())+(Kd*ErrorDif());
}

void setMotorSpeed(int change){
    if(change<0)
        RDutyCycle -= abs(change)+leftSpeedChange;
    else
        LDutyCycle -= change+rightSpeedChange;
}
///////////////////////////////////////////////////////////////////////////////above main function
///////////////////////////////////////////////////////////////////////////////below sub function
void calSpeedLeft(){
    int RPS =  getLeftEncValue()*(2*M_PI/1000);
    int MPS = RPS * radius;
}
void calSpeedRight(){
    int RPS =  getRightEncValue()*(2*M_PI/1000);
    int MPS = RPS * radius;
}
int isLineMid(int sensorVal, int* LED)                          //ticker
{
    if(latestError<=500 && sensorVal>=-500){
        LED = 1;
    }
}


float errorIntegral(){
    float value=0;
    for(int i=0; i<noErrorBuf; i++){
        value += error[i];
    }
    return value;
}

float errorDif(){
    return (error[latestNum]-error[latestNum+1]);
}

float leftSpeedErrorIntegral(){
    float value=0;
    for(int i=0; i<noErrorBuf; i++){
        value += leftSpeedError[i];
    }
    return value;
}

float leftSpeedErrorDif(){
    return (leftSpeedError[latestNum]-leftSpeedError[latestNum+1]);
}

float rightSpeedErrorIntegral(){
    float value=0;
    for(int i=0; i<noErrorBuf; i++){
        value += rightSpeedError[i];
    }
    return value;
}

float rightSpeedErrorDif(){
    return (rightSpeedError[latestNum]-rightSpeedError[latestNum+1]);
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


///m/s 알았으니까 4cm 가는데 몇초 걸리는지 계산하고 난뒤 처음 라인 브레이크 후에 몇초뒤에 센싱하는지 계산



int main() {
    std::cout << "Hello, World!" << std::endl;


    1. read sensor values
    2. check exceptions
        2.1 whether values are similar
            (1f similar then motor speed = previous motor speed)

    3. sensor values goes to calError()
    4. error[20] value goes to PID() andd error[0-19] used forr. integral
    5. change value from PID() goes to setMotorSpeed()



















    return 0;
}
