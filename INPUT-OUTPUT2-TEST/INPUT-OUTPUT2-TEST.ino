

#define RELAYOUTPUT1 19
#define RELAYOUTPUT2 20
#define LED2          3
#define INPUT1        0
#define INPUT2        2
uint8_t stsAlarm=0;
void setup() {
  // put your setup code here, to run once:

  pinMode(LED2,OUTPUT); //led1
  pinMode(RELAYOUTPUT1,OUTPUT); //led1
  pinMode(RELAYOUTPUT2,OUTPUT); //led 2
  pinMode(INPUT2,INPUT_PULLUP); //BUZZZER
  
  Serial.begin(115200);
  Serial.println("RESET");
}

void loop() {
  // put your main code here, to run repeatedly:
 
 //Serial.print(digitalRead(INPUT1));
 //Serial.println(digitalRead(INPUT2));

if (digitalRead(INPUT2))
   digitalWrite(LED2,HIGH);
else
   digitalWrite(LED2,LOW);

 
 if (digitalRead(INPUT2) && stsAlarm==0 && digitalRead(INPUT1)) 
 {
    Serial.print("INPUT1-(button):");
    Serial.print(digitalRead(INPUT1));
    Serial.print("   ");
    Serial.print("INPUT2-(doorswitch):");
    Serial.print(digitalRead(INPUT1));
    Serial.print("   ");
    Serial.println(" ALARM ACTIVATED  ");
   
    
    stsAlarm=1;
    digitalWrite(RELAYOUTPUT1,HIGH);
 }
 
 if (!digitalRead(INPUT2) && stsAlarm==1 && !digitalRead(INPUT1)) 
 {
    stsAlarm=0;
    Serial.print("INPUT1-(button):");
    Serial.print(digitalRead(INPUT1));
    Serial.print("   ");
    Serial.print("INPUT2-(doorswitch):");
    Serial.print(digitalRead(INPUT1));
    Serial.print("   ");
    Serial.println(" ALARM DEACTIVATED  ");
    digitalWrite(RELAYOUTPUT1,LOW);
 }
  delay(300);


}
