//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void velocity(uint8_t id,uint32_t spd)
{
  
  dxl.write(id, 112, (uint8_t *)&spd, 4, 100);
}

void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  dxl.torqueOff(1);
  dxl.setJointMode(1);
  dxl.torqueOn(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  velocity(1,200);
  dxl.setGoalAngle(1,-450);
  delay(1000);
  dxl.setGoalAngle(1,0);
  delay(1000);
  velocity(1,50);
  dxl.setGoalAngle(1,450);
  delay(1000);
  dxl.setGoalAngle(1,0);
  delay(1000);
}
