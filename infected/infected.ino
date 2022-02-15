#include <SoftwareSerial.h>
#include <Keypad.h>

SoftwareSerial BTSerial(10, 11); // TX | RX


const byte satir = 4;
const byte sutun = 4;

char tus;
char tus_takimi[satir][sutun] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte satir_pinleri[satir] = {9, 8, 7, 6};
byte sutun_pinleri[satir] = {5, 4, 3, 2};

Keypad mahmut = Keypad(makeKeymap(tus_takimi) , satir_pinleri , sutun_pinleri , satir , sutun);


 
void setup()
{
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  Serial.begin(9600); 
  BTSerial.begin(9600);  
}
 
void loop(){


tus = mahmut.getKey();
if (tus)
{
  if(tus=='1')
  {
    int risksiz = 1;
    Serial.println(risksiz);
    BTSerial.write(risksiz);
    
   }

    if(tus=='2')
  {
    int risksiz = 2;
    Serial.println(risksiz);
    BTSerial.write(risksiz);
    
   }

   if(tus=='3')
  {
    int risksiz = 3;
    Serial.println(risksiz);
    BTSerial.write(risksiz);
    
   }

   
 

}

}
