//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  dxl.torqueOff(1);
  dxl.setWheelMode(1);
  dxl.torqueOn(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  dxl.setGoalSpeed(1,120);
  delay(3000);
  dxl.setGoalSpeed(1,-120);
  delay(1000);
}
