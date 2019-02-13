//Source Code
//modified from example "addMotor "
// - by doltank9 -

#include <DynamixelShield.h>
DynamixelShield dxl;
  
void setup() {
  // put your setup code here, to run once:
  dxl.begin(57600);
  delay(1000);
  dxl.addMotor(1,  M_XL430);
  dxl.torqueOn(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (dxl.getDxlCount() > 0)
  {
    dxl.setGoalAngle(1,  0);
    delay(1000);
    dxl.setGoalAngle(1,  900);
    delay(1000);
    dxl.setGoalAngle(1,  0);
    delay(1000);
    dxl.setGoalAngle(1, -900);
    delay(1000);    
  }
}
