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
  dxl.addMotor(2,M_XL430);
  dxl.addMotor(3,M_XL430);
  dxl.torqueOff(DXL_ALL_ID);
  dxl.setJointMode(0xFE);
  dxl.torqueOn(0xFE);
  velocity(0xFE,100);
  dxl.setGoalPosition(0xFE,2048);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  dxl.setGoalPosition(0xFE,1024);
  delay(1500);
  dxl.setGoalPosition(0xFE,3072);
  delay(3000);
  dxl.setGoalPosition(1,2048);
  delay(500);
  dxl.setGoalPosition(2,2048);
  delay(500);
  dxl.setGoalPosition(3,2048);
  delay(2000);
  
}
