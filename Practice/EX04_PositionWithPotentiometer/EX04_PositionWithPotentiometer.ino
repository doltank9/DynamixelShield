//소스코드
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
  pinMode(15,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pos = map(analogRead(15), 0, 1023, -1800, 1800);
  dxl.setGoalAngle(1,pos);
  delay(20);
}
