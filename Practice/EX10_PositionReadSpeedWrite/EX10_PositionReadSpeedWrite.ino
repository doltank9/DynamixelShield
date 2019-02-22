//소스코드
//
#include <DynamixelShield.h>
DynamixelShield dxl;
  
void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  dxl.addMotor(1,M_XL430);
  dxl.torqueOff(DXL_ALL_ID);
  dxl.setWheelMode(1);
  dxl.torqueOn(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int spd = ( dxl.getCurPosition(2) - 2048 ) / 2;
  if( spd > 10 || spd < -10 )
  {
    dxl.setGoalSpeed(1,spd);
  }
  else
  {
    dxl.setGoalSpeed(1,0);
  }
  delay(20);
}
