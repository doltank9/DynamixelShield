//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

void velocity(uint8_t id,uint32_t spd)
{
  dxl.write(id, 112, (uint8_t *)&spd, 4, 100);
}

void multiPosition(int pos1, int pos2, int pos3)
{
  if( pos1 != -1 )  {    dxl.setGoalPosition(1, pos1);  }
  if( pos2 != -1 )  {    dxl.setGoalPosition(2, pos2);  }
  if( pos3 != -1 )  {    dxl.setGoalPosition(3, pos3);  }
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
  dxl.setGoalPosition(0xFE,2048);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

  multiPosition(512, 512, 512);
  delay(1500);
  multiPosition(3072, 3072, 3072);
  delay(3000);
  multiPosition(0, 3072, 3072);
  delay(500);
  multiPosition(0, 0, 3072);
  delay(500);
  multiPosition(0, 0, 0);
  delay(2000);
  
}
