//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void setWheelMode1_0(uint8_t id)
{
  uint16_t ccw = 0;
  dxl.write(id, 8, (uint8_t *)&ccw, 2, 100);
}

void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_AX12);
  dxl.torqueOff(1);
  setWheelMode1_0(1);
  dxl.torqueOn(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  dxl.setGoalSpeed(1,200);
  delay(3000);
  dxl.setGoalSpeed(1,1200);
  delay(1000);
}
