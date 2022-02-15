#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>


SoftwareSerial BluetoothSerial(10, 11); // TX | RX
LiquidCrystal_I2C lcdekranim(0x3f,16,2);

int ledPin = 3;
int buzzer = 7;
int risksiz;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(buzzer,OUTPUT); 
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  BluetoothSerial.begin(9600);

   lcdekranim.init();
  lcdekranim.backlight();
  
  lcdekranim.setCursor(0,0);
  lcdekranim.print("HES Kodu Kontrol ");
  lcdekranim.setCursor(0,1);
  lcdekranim.print("Ediliyor...");
  
 

  digitalWrite(2, HIGH);
  delay(2000);
  digitalWrite(2, LOW);
  delay(1000);

  digitalWrite(5, HIGH);
  delay(2000);
  digitalWrite(5, LOW);
  delay(1000);

  digitalWrite(4, HIGH);
  delay(2000);
  digitalWrite(4, LOW);
  delay(1000);

  lcdekranim.clear();
  lcdekranim.setCursor(0,0);
  lcdekranim.print("Kontrol Tamam ");
  lcdekranim.setCursor(0,1);
  lcdekranim.print("Durum : Risksiz ");
  digitalWrite(2, HIGH);
  
  delay(10000);
  lcdekranim.clear();

  

  lcdekranim.setCursor(0,0);
  lcdekranim.print("Bluetooth Bag. ");
  lcdekranim.setCursor(0,1);
  lcdekranim.print("Araniyor.. ");
  delay(2000);
  
  
  
}

void loop() {
  if (BluetoothSerial.available() > 0) {

    risksiz = BluetoothSerial.read();

    if (risksiz == 1 ) {

      lcdekranim.clear();
      lcdekranim.setCursor(3,0);
      lcdekranim.print("UYARI !  ");
      lcdekranim.setCursor(0,1);
      lcdekranim.print("Baglanti Hazir!");

      delay(5000);
      lcdekranim.clear();
      lcdekranim.setCursor(0,0);
      lcdekranim.print("HES Kodu Kontrol ");
      lcdekranim.setCursor(0,1);
      lcdekranim.print("Ediliyor...");

      delay(5000);
      
      lcdekranim.clear();
      lcdekranim.setCursor(0,0);
      lcdekranim.print("HES Kodu Kontrol ");
      lcdekranim.setCursor(0,1);
      lcdekranim.print("Edildi, GUVENLI");
      
      delay(1000);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(2, HIGH);
      
    }

    else if (risksiz == 2) {

      lcdekranim.clear();
      lcdekranim.setCursor(3,0);
      lcdekranim.print("UYARI !  ");
      lcdekranim.setCursor(0,1);
      lcdekranim.print("Baglanti Hazir!");

      delay(5000);
      lcdekranim.clear();
      lcdekranim.setCursor(0,0);
      lcdekranim.print("HES Kodu Kontrol ");
      lcdekranim.setCursor(0,1);
      lcdekranim.print("Ediliyor... ");

      delay(5000);

      lcdekranim.clear();
      lcdekranim.setCursor(0,0);
      lcdekranim.print("HES Kodu Kontrol");
      lcdekranim.setCursor(0,1);
      lcdekranim.print("Edildi,TEMASLI !");

      digitalWrite(buzzer,HIGH); 
      delay(750);                 
      digitalWrite(buzzer,LOW);
      delay(750);
   
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);

      
      
    }

    else if (risksiz == 3) {

      lcdekranim.clear();
      lcdekranim.setCursor(3,0);
      lcdekranim.print("UYARI !  ");
      lcdekranim.setCursor(0,1);
      lcdekranim.print("Baglanti Hazir!");

      delay(5000);
      lcdekranim.clear();
      lcdekranim.setCursor(0,0);
      lcdekranim.print("HES Kodu Kontrol ");
      lcdekranim.setCursor(0,1);
      lcdekranim.print("Ediliyor... ");

      delay(5000);

      lcdekranim.clear();
      lcdekranim.setCursor(0,0);
      lcdekranim.print("HES Kodu Kontrol   ");
      lcdekranim.setCursor(0,1);
      lcdekranim.print("Edildi,RISKLI !");
      
      delay(1000);

      digitalWrite(buzzer,HIGH); 
      delay(2000);                 
      digitalWrite(buzzer,LOW);
             
      digitalWrite(2, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, HIGH);
      delay(1000);
      digitalWrite(4, LOW);
      delay(1000);
      digitalWrite(4, HIGH);
      
      digitalWrite(buzzer,HIGH); 
      delay(1000);                 
      digitalWrite(buzzer,LOW);
      delay(1000);
      digitalWrite(buzzer,HIGH); 
      delay(1000);
      digitalWrite(buzzer,LOW);
      delay(1000);
      digitalWrite(buzzer,HIGH); 
      delay(1000);
      digitalWrite(buzzer,LOW);
      delay(1000);
      digitalWrite(buzzer,HIGH); 
      delay(1000);
      digitalWrite(buzzer,LOW);
      
      
    }

  }
}
