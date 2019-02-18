//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  dxl.addMotor(2,M_XL430);
  dxl.torqueOff(1);
  dxl.torqueOff(2);
  dxl.setJointMode(1);
  dxl.setJointMode(2);
  dxl.torqueOn(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pos = dxl.getCurPosition(2);
  dxl.setGoalPosition(1, pos);
  delay(10);
}
