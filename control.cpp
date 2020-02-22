#include <iostream>
#include <math.h>

const int noSensor = 6
const float radius = 0.07;
int noErrorBuf = 20;
float Kp, Ki, Kd;
float latestError;
float error[noErrorBuf] = 0;
float change;



void getLeftEncValue();
void getRightEncValue();

void isLineBroken(float sensorVal,float* prevRspeed,float* prevLspeed)                            //interrupt ticker
{
    int cnt;
    for(int i=1; i<=noSensor;i++) {
         if(LL_GPIO_read(i) > 500)
             cnt++;
    }

    if(cnt < 2)                    //100 is temporary value. later change with calculated line value
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
        error[i-1]=error[i];                                                             // address shifting
    }
    error[noErrorBuf-1] = latestError;
}

void PID(){
    change = (Kp*error[20])+Ki*(ErrorIntegral())+(Kd*ErrorDif());
}

void setMotorSpeed(int change){
    if(change<0)
        RDutyCycle -= abs(change);
    else
        LDutyCycle -= change;
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

void spdPID();
void dirPID();

float ErrorIntegral(){
    float value=0;
    for(int i=0; i<noErrorBuf; i++){
        value += error[i];
    }
    return value;
}

float ErrorDif(){
    return (error[noErrorBuf-1]-error[noErrorBuf-2]);
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
