//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;
  
void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  dxl.addMotor(2,M_XL430);
  dxl.torqueOff(DXL_ALL_ID);
  dxl.setJointMode(1);
  dxl.torqueOn(1);
  pinMode(15,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int spd = ( dxl.getCurSpeed(2) ) * 10;
  if( spd > 2 || spd < -2 )
  {
    dxl.setGoalPosition(1,2048+spd);
  }
  else
  {
    dxl.setGoalSpeed(1,2048);
  }
  delay(20);
}
