WM//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void setPWM(uint8_t id,uint32_t pwm)
{
  dxl.write(id, 100, (uint8_t *)&pwm, 2, 100);
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
  setPWM(1,200);
  dxl.setGoalAngle(1,-450);
  delay(4000);
  dxl.setGoalAngle(1,-900);
  delay(4000);
  setPWM(1,50);
  dxl.setGoalAngle(1,-450);
  delay(4000);
  dxl.setGoalAngle(1,-900);
  delay(4000);
}
