//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  pinMode(14,INPUT);
  dxl.torqueOff(1);
  dxl.torqueOff(2);
  dxl.setJointMode(1);
  dxl.torqueOn(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pos = analogRead(14)*4;
  dxl.setGoalPosition(1, pos);
  delay(10);
}
