//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  dxl.torqueOff(DXL_ALL_ID);
  dxl.setID(1,2);
  dxl.setJointMode(2);
  dxl.torqueOn(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  dxl.setGoalAngle(2,-450);
  delay(1000);
  dxl.setGoalAngle(2,0);
  delay(1000);
