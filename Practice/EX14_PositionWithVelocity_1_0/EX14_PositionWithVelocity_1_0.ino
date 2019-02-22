//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;


void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_AX12);
  dxl.torqueOn(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  dxl.setGoalSpeed(1,400);
  dxl.setGoalAngle(1,-450);
  delay(1000);
  dxl.setGoalAngle(1,0);
  delay(1000);
  dxl.setGoalSpeed(1,100);
  dxl.setGoalAngle(1,450);
  delay(1000);
  dxl.setGoalAngle(1,0);
  delay(1000);
}
