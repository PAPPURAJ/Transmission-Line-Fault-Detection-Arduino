#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int calValue=50,a=0,b=0,c=0;
int minVal=300;

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 

  pinMode(2,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);

  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  scrDis("Welcome to","Our Project");

}

void loop() {

   a=analogRead(A0)-150;
   b=analogRead(A1)-150;
   c=analogRead(A2)-122;

   a=abs(a);
   b=abs(b);
   c=abs(c);
  
  
 1?runProject():runTest();

  
  delay(150);
  
}



void runTest(){
  String x="A:"+String(a)+"|B:"+String(b);
  String y=" C: "+String(c);
  dis(x,y);
 
}

String llg2Line="";

void runProject(){
  
 llg2Line="";

 if(a<minVal)
  llg2Line=llg2Line+" R ";
  
 if(b-20<minVal)
  llg2Line=llg2Line+" G ";


  if(c<minVal)
  llg2Line=llg2Line+" Y "; 

  if(llg2Line!=""){
     dis("L2G Fault",llg2Line);
     beep2();
     power(0);
  }
   

  
 else if (abs(a-b)<=calValue && abs(b-c)<=calValue){
   beep1();
    dis("L2L Fault on","R G Y");
    power(0);
 }
  
 else if(abs(a-b)<=calValue){
    beep1();
    dis("L2 Fault on","R G");
    power(0);
  }else if(abs(a-c)<=calValue){
   beep1();
    dis("L2L Fault on","R Y");
    power(0);
  }else if (abs(b-c)<=calValue){
   beep1();
    dis("L2L Fault on","G Y");
    power(0);
    }
   
  
  else{ 
  dis("Everything"," is Normal");
    power(1);
  }

  
  
}


void dis(String a, String b){
  lcd.setCursor(2,0);
  lcd.print(a+"               ");
  
  lcd.setCursor(2,1);
  lcd.print(b+"                ");
  
}

void scrDis(String a, String b){  
  lcd.setCursor(2,0);
  for(int i=0;i<sizeof(a);i++){
    lcd.print(a[i]);
    delay(30);
  }

  
  lcd.setCursor(2,1);
    for(int i=0;i<sizeof(b);i++){
    lcd.print(b[i]);
    delay(30);
  }

  
}



void beep1(){
  digitalWrite(2,1);
  delay(30);
  digitalWrite(2,0);
  delay(30);
  digitalWrite(2,1);
  delay(30);
  digitalWrite(2,0);
  delay(30);
  
}


void beep2(){
  digitalWrite(2,1);
  delay(30);
  digitalWrite(2,0);
  delay(30);
  digitalWrite(2,1);
  delay(30);
  digitalWrite(2,0);
  delay(30);
    digitalWrite(2,1);
  delay(30);
  digitalWrite(2,0);
  delay(30);
  digitalWrite(2,1);
  delay(30);
  digitalWrite(2,0);
  delay(30);
  
}


void power(int val){
  digitalWrite(3,val);
  digitalWrite(4,val);
  digitalWrite(5,val);
}
