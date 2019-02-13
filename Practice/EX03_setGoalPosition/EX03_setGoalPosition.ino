// Source Code
// modified from example "goalPosition" & "goalAngle"
// by doltank9

#include <DynamixelShield.h>
DynamixelShield dxl;
  
void setup() {
  // put your setup code here, to run once:
  dxl.begin(57600);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  dxl.torqueOff(DXL_ALL_ID);
  dxl.setJointMode(1);
  dxl.torqueOn(DXL_ALL_ID);
}

void loop() {
  // put your main code here, to run repeatedly:
  dxl.setGoalPosition(1,0);
  delay(1000);
  for(int i=511;i<=4095;i+=512)
  {
    dxl.setGoalPosition(1, i);
    delay(500);
  }
  delay(1000);
  
}
