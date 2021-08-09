// 8xRelais-Steuerung via Bluetooth Modul DSD Tech HM10


int rel1=37;
int rel2=39;
int rel3=41;
int rel4=43;
int rel5=45;
int rel6=47;
int rel7=49;
int rel8=51;

int Received=0;
int Auto=0;
bool bew = false;

int rel1_state = 1;
int rel2_state = 1;
int rel3_state = 1;
int rel4_state = 1;
int rel5_state = 1;
int rel6_state = 1;
int rel7_state = 1;
int rel8_state = 1;

int MinWait = 0; 
int MinBew = 0;
String MW = "";
String MB = "";
int zeit = 0;

void setup(){
  
  Serial1.begin(9600);

  pinMode(rel1,OUTPUT);
  pinMode(rel2,OUTPUT);
  pinMode(rel3,OUTPUT);
  pinMode(rel4,OUTPUT);
  pinMode(rel5,OUTPUT);
  pinMode(rel6,OUTPUT);
  pinMode(rel7,OUTPUT);
  pinMode(rel8,OUTPUT);
//  pinMode(A1, INPUT);
//  pinMode(A2, INPUT);
  zeit = millis();

digitalWrite(rel1,HIGH);
digitalWrite(rel2,HIGH);
digitalWrite(rel3,HIGH);
digitalWrite(rel4,HIGH);
digitalWrite(rel5,HIGH);
digitalWrite(rel6,HIGH);
digitalWrite(rel7,HIGH);
digitalWrite(rel8,HIGH);

}


void loop(){
if (Auto == 1)
  {
 if (millis()/60000 > zeit + MinWait && !bew)
  {
  bew = true;
  Serial1.print("11111");
  digitalWrite(rel7,LOW);
  delay(1000); 
  digitalWrite(rel8,LOW); 
  }
 if (millis()/60000 > zeit + MinWait + MinBew && bew)
  {
  bew = false;
  digitalWrite(rel8,HIGH);
  delay(5000); 
  digitalWrite(rel7,HIGH);
  zeit = millis()/60000;
  MinWait = 1440 - MinBew; 
  Serial1.print("22222");
  }
  }

 
 if(Serial1.available())
 { 
    Received = Serial1.read();
    
 }


/////////Reset Auto Timer//////////////
  if (Received == 'r')
  {
    Received=0;
    Auto=0;  
    MinWait = 0; 
    MinBew = 0; 
  }
  if (Received == 'i')
  {
    Received=0;
    Auto=1;  
    MinWait = 0; 
    MinBew = 0; 
    zeit = millis()/60000;
  }

  if (Received == 'w')
  {
    Received=0;  
    MinWait = MinWait + 1;
  }

    if (Received == 'b')
  {
    Received=0;  
    MinBew = MinBew + 1;
  }

    if (Received == 'g')
  {
    Received=0;  
    if (Auto == 1)
    {
    MB = "000" + String(MinBew);
    MB = MB.substring(MB.length()-3, MB.length());
    Serial1.print(MB);
    delay(1000);
    MW = "0000" + String(MinWait);
    MW = MW.substring(MW.length()-4, MW.length());
    Serial1.print(MW);
    }
  }

////////////////Relais 1/////////////////////
if (rel1_state == 0 && Received == '1')
  {
    digitalWrite(rel1,HIGH);
    rel1_state=1;
    Received=0;  
    delay(100);
    Serial1.print("11");
  }
if (rel1_state ==1 && Received == '1')
  {
    digitalWrite(rel1,LOW);
    rel1_state=0;
    Received=0;
    delay(100);
    Serial1.print("10");
  }
///////////////////////////////////////////

////////////////Relais 2/////////////////////
if (rel2_state == 0 && Received == '2')
  {
    digitalWrite(rel2,HIGH);
    rel2_state=1;
    Received=0;  
    delay(100);
    Serial1.print("21");
  }
if (rel2_state ==1 && Received == '2')
  {
    digitalWrite(rel2,LOW);
    rel2_state=0;
    Received=02;
    delay(100);
    Serial1.print("20");
  }
///////////////////////////////////////////

////////////////Relais 3/////////////////////
if (rel3_state == 0 && Received == '3')
  {
    digitalWrite(rel3,HIGH);
    rel3_state=1;
    Received=0;  
    delay(100);
    Serial1.print("31");
  }
if (rel3_state ==1 && Received == '3')
  {
    digitalWrite(rel3,LOW);
    rel3_state=0;
    Received=0;
    delay(100);
    Serial1.print("30");
  }
///////////////////////////////////////////

////////////////Relais 4/////////////////////
if (rel4_state == 0 && Received == '4')
  {
    digitalWrite(rel4,HIGH);
    rel4_state=1;
    Received=0;  
    delay(100);
    Serial1.print("41");
  }
if (rel4_state ==1 && Received == '4')
  {
    digitalWrite(rel4,LOW);
    rel4_state=0;
    Received=0;
    delay(100);
    Serial1.print("40");
  }
///////////////////////////////////////////

////////////////Relais 5/////////////////////
if (rel5_state == 0 && Received == '5')
  {
    digitalWrite(rel5,HIGH);
    rel5_state=1;
    Received=0;  
    delay(100);
    Serial1.print("51");
  }
if (rel5_state ==1 && Received == '5')
  {
    digitalWrite(rel5,LOW);
    rel5_state=0;
    Received=0;
    delay(100);
    Serial1.print("50");
  }
///////////////////////////////////////////

////////////////Relais 6/////////////////////
if (rel6_state == 0 && Received == '6')
  {
    digitalWrite(rel6,HIGH);
    rel6_state=1;
    Received=0;  
    delay(100);
    Serial1.print("61");
  }
if (rel6_state ==1 && Received == '6')
  {
    digitalWrite(rel6,LOW);
    rel6_state=0;
    Received=0;
    delay(100);
    Serial1.print("60");
  }
///////////////////////////////////////////

////////////////Relais 7/////////////////////
if (rel7_state == 0 && Received == '7')
  {
    digitalWrite(rel7,HIGH);
    rel7_state=1;
    Received=0;
    delay(100);
    Serial1.print("71");  
  }
if (rel7_state ==1 && Received == '7')
  {
    digitalWrite(rel7,LOW);
    rel7_state=0;
    Received=0;
    delay(100);
    Serial1.print("70");
  }
///////////////////////////////////////////

////////////////Relais 8/////////////////////
if (rel8_state == 0 && Received == '8')
  {
    digitalWrite(rel8,HIGH);
    rel8_state=1;
    Received=0;
    delay(100);
    Serial1.print("81");  
  }
if (rel8_state ==1 && Received == '8')
  {
    digitalWrite(rel8,LOW);
    rel8_state=0;
    Received=0;
    delay(100);
    Serial1.print("80");
  }
///////////////////////////////////////////

if (Received == '9')
  {
    delay(100);  
if (rel1_state == 0)
  {
    Serial1.print("10"); 
    delay(100); 
  }
if (rel1_state == 1)
  {
    Serial1.print("11"); 
    delay(100); 
  }
if (rel2_state == 0)
  {
    Serial1.print("20"); 
    delay(100); 
  }
if (rel2_state == 1)
  {
    Serial1.print("21"); 
    delay(100); 
  }
if (rel3_state == 0)
  {
    Serial1.print("30"); 
    delay(100); 
  }
if (rel3_state == 1)
  {
    Serial1.print("31"); 
    delay(100); 
  }
if (rel4_state == 0)
  {
    Serial1.print("40"); 
    delay(100); 
  }
if (rel4_state == 1)
  {
    Serial1.print("41"); 
    delay(100); 
  }
if (rel5_state == 0)
  {
    Serial1.print("50"); 
    delay(100); 
  }
if (rel5_state == 1)
  {
    Serial1.print("51"); 
    delay(100); 
  }
if (rel6_state == 0)
  {
    Serial1.print("60"); 
    delay(100); 
  }
if (rel6_state == 1)
  {
    Serial1.print("61"); 
    delay(100); 
  }
if (rel7_state == 0)
  {
    Serial1.print("70"); 
    delay(100); 
  }
if (rel7_state == 1)
  {
    Serial1.print("71"); 
    delay(100); 
  }
if (rel8_state == 0)
  {
    Serial1.print("80"); 
    delay(100); 
  }
if (rel8_state == 1)
  {
    Serial1.print("81"); 
    delay(100); 
  }
if (Auto == 1)
    {
      if (bew)
      {
       Serial1.print("11111"); 
      }
      else
      {
    MB = "000" + String(MinBew);
    MB = MB.substring(MB.length()-3, MB.length());
    Serial1.print(MB);
    delay(1000);
    MW = "0000" + String(MinWait- millis()/60000 + zeit);
    MW = MW.substring(MW.length()-4, MW.length());
    Serial1.print(MW);
      }

    delay(100);
      }
    Received=0; 
    } 
}
