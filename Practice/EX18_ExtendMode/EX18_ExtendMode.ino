//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void velocity(uint8_t id,uint32_t spd)
{
  dxl.write(id, 112, (uint8_t *)&spd, 4, 100);
}

void acceleration(uint8_t id,uint32_t acc)
{
  dxl.write(id, 108, (uint8_t *)&acc, 4, 100);
}

void extend(uint8_t id)
{
  uint8_t ext = 4;
  dxl.write(id, 11, (uint8_t *)&ext, 1, 100);
}

void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  dxl.torqueOff(1);
  extend(1);
  dxl.torqueOn(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  velocity(1,110);
  acceleration(1,40);
  delay(100);
  dxl.setGoalPosition(1,2047);
  delay(2000);
  for(int i=0;i<=8;i++)
  {
    dxl.setGoalPosition(1,512+1024*i);
    delay(1000);
  }
  dxl.setGoalPosition(1,2048);
  delay(3000);
}
