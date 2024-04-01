
#define PORTBUZZER PORTC
#define LED1 18
#define LED2 3
#define BUZZER 21
uint8_t stsled=0;
void setup() {
  // put your setup code here, to run once:
  DDRA= 0xff;

  PORTA =0xff;
  pinMode(LED1,OUTPUT); //led1
  pinMode(LED2,OUTPUT); //led 2
  pinMode(BUZZER,OUTPUT); //BUZZZER
  
  Serial.begin(115200);
  Serial.println("RESET");
}

void loop() {
  // put your main code here, to run repeatedly:
 
  for(uint8_t aa=0x80;aa>0;)
    {
        //aa=aa>>1;       
        PORTA = aa ^ 0xff;      ///    aa=  !aa //    aa=0  ->> aa= 1          aa=1     aa ^ 0xff =                0b000000001  0xb1111 1110  0xfe 
         Serial.print("PORT A: ");
        Serial.print(PORTA,HEX);
        buzzersound(246,500);
       // beepshort();
        delay(200);
        aa=aa>>1; 
        if (stsled==1)  
        {
            digitalWrite(LED1,HIGH);
            digitalWrite(LED2,LOW);
             Serial.print("   LED1:HIGH");
             Serial.println("   LED2:LOW ");
        }  
        else
        {
           digitalWrite(LED1,LOW);
            digitalWrite(LED2,HIGH);
             Serial.print("   LED1:LOW ");
             Serial.println("   LED2:HIGH");
        }  
         stsled=stsled ^ 1;
         delay(200);
        
    }
    //  delay(300);
     PORTA =  0xff;      //
     beep();
      Serial.println("  BEEP ");
       delay(300);
}


void buzzersound(int freq , int pnj)
{

  for (int u = 0 ; u < pnj;  u++)
  {
    //digitalWrite(11, HIGH);
    PORTBUZZER |= 0x20;
    
    delayMicroseconds(freq);

    //digitalWrite(11, LOW);
    PORTBUZZER &= 0xdf;
    
    delayMicroseconds(freq);
  }

}




void nobuzzersound(int freq , int pnj)
{

  for (int u = 0 ; u < pnj;  u++)
  {
    //digitalWrite(11, LOW);
    PORTBUZZER &= 0xdf; //PB5
   
    delayMicroseconds(freq);

    //digitalWrite(11, LOW);
    PORTBUZZER &= 0xdf;
  
    delayMicroseconds(freq);
  }

}





void beep()
{

  buzzersound(246, 200); //buzzersound(623,300);
  nobuzzersound(246, 200);
  buzzersound(246, 200); //buzzersound(623,300);
  nobuzzersound(246, 200);
  buzzersound(246, 200); //buzzersound(623,300);
}

void beepshort()
{

  buzzersound(246, 50); //buzzersound(623,300);
  nobuzzersound(246, 50);
  buzzersound(246, 50); //buzzersound(623,300);
  nobuzzersound(246, 50);
  buzzersound(246, 50); //buzzersound(623,300);
  nobuzzersound(246, 50);
  buzzersound(246, 50); //buzzersound(623,300);
  nobuzzersound(246, 50);
  buzzersound(246, 50); //buzzersound(623,300);
}
