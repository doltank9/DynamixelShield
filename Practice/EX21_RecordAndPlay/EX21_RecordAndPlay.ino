//소스코드
#include <DynamixelShield.h>
DynamixelShield dxl;

unsigned int pos1[9];
unsigned int seq_count = 0;
unsigned int max_count = 0;

int bt1 = 14;
int bt2 = 15;
int sbt1 = 0;
int sbt2 = 1;
int lbt1 = 0;
int lbt2 = 1;

int spd1 = 100;

bool playing = false;
bool recording = true;


void Speed_Calc(int count)
{
  if( dxl.getCurPosition(1) >= pos1[count] )  {    spd1 = dxl.getCurPosition(1) - pos1[count];  }
  else  {    spd1 = pos1[count] - dxl.getCurPosition(1);  }
}

void Blink()
{
  digitalWrite(13,HIGH);  delay(50);
  digitalWrite(13,LOW);  delay(50);
  digitalWrite(13,HIGH);  delay(50);
  digitalWrite(13,LOW);  delay(50);
  digitalWrite(13,HIGH);  delay(50);
  digitalWrite(13,LOW);  delay(50);
}


void setup() {
  // put your setup code here, to run once:
  dxl.begin(1000000);
  delay(1000);
  pinMode(13,OUTPUT);
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  dxl.addMotor(1,M_AX12);
  dxl.torqueOff(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  if ( digitalRead(bt1) == HIGH )  {    sbt1 = 1;  }
  else  {    sbt1 = 0;  }
  if ( digitalRead(bt2) == LOW )  {    sbt2 = 1;  }
  else  {    sbt2 = 0;  }

  if( recording == true)
  {
    if( sbt1 == 1 && lbt1 == 0 )
    {
      pos1[seq_count] = dxl.getCurPosition(1);
      max_count=seq_count;
      seq_count++;
      Blink();
      
    }
  }

  if( sbt2 == 0 && lbt2 == 1 )
  {
    if( playing == false)
    {
      playing = true;
      recording = false;
      seq_count--;
    }
    Blink();
  }
  
  
  if( playing == true )
  {
    dxl.torqueOn(1);
    for(int i=0;i<=max_count;i++)
    {
      Speed_Calc(i);
      dxl.setGoalSpeed(1,spd1/2+50);
      dxl.setGoalPosition(1,pos1[i]);
      delay(2000);
    }
    playing = false;
    seq_count = 0;
    dxl.torqueOff(1);
  }
  
  lbt1 = sbt1;
  lbt2 = sbt2;
}
