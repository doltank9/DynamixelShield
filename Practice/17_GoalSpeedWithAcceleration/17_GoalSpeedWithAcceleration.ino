//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void acceleration(uint8_t id,uint32_t acc)
{
  dxl.write(id, 108, (uint8_t *)&acc, 4, 100);
}

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
  acceleration(1,100);
  dxl.setGoalSpeed(1,150);
  delay(2000);
  acceleration(1,10);
  dxl.setGoalSpeed(1,-150);
  delay(2000);
}
