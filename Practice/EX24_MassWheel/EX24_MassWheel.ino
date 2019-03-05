//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  dxl.addMotor(2,M_XL430);
  dxl.addMotor(3,M_XL430);
  dxl.torqueOff(DXL_ALL_ID);
  dxl.setJointMode(0xFE);
  dxl.torqueOn(0xFE);
  dxl.setGoalPosition(0xFE,2048);
  delay(2000);

  dxl.torqueOff(DXL_ALL_ID);
  dxl.setWheelMode(0xFE);
  dxl.torqueOn(0xFE);
}

void loop() {
  // put your main code here, to run repeatedly:

  dxl.setGoalSpeed(0xFE,40);
  delay(5000);
  dxl.setGoalSpeed(0xFE,80);
  delay(5000);
}
