#include <DynamixelShield.h>
DynamixelShield dxl;

void setup()
{
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(10);
  dxl.addMotor(1, M_XL430);// M_AX12, M_AX18, M_MX28, M_XL430 .....
  dxl.torqueOff(1);
  dxl.setJointMode(1);
  dxl.torqueOn(1);
  
}

void loop()
{
  dxl.setAcceleration(1,2);
  dxl.setVelocity(1,100); //0~600
  dxl.setGoalPosition(1,1023);
  delay(2000);
  dxl.setVelocity(1,100);
  dxl.setGoalPosition(1,3071);
  delay(2000);
  dxl.setVelocity(1,200);
  dxl.setGoalPosition(1,1023);
  delay(2000);
  dxl.setVelocity(1,200);
  dxl.setGoalPosition(1,3071);
  delay(2000);
}

