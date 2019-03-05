//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(2,M_XL430);
  dxl.torqueOff(DXL_ALL_ID);
  dxl.setID(0xFE,2);
  dxl.reset(2);
  delay(1000);
  dxl.begin(57600);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  dxl.setJointMode(1);
  dxl.torqueOn(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  dxl.setGoalAngle(1,-450);
  delay(1000);
  dxl.setGoalAngle(1,450);
  delay(1000);
}
