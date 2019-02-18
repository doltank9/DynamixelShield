//SourceCode
//
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
  dxl.setGoalPosition(1,1023+analogRead(15)*2);
  delay(20);
}
