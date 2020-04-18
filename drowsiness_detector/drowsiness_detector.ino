/***************************************************************************
 * DROWSINESS DETECTION USING IR SENSOR
 * Author : Amrathesh
 * 
 * Code:
  • It takes care of counting the blinks and storing it in a counter
  • After certain delay blink rate calculated and compared with standard rates and corresponding decision is taken.
  • It drives Buzzer and LED if Drowsiness is detected.
  • Print statements are added to get serial monitor output.

 * Circuit:
  • IR sensor output connected to Digital pin 5
  • Buzzer connected to Analog pin A0
  • RGB connected to Digital pin 4 3 2 respectively

***************************************************************************/

#define Blink 5 
#define red 4 
#define blue 2 
#define green 3 
int count=0; 
int sum=0; 
float avg=0;
 
void setup()
 
{  
  Serial.begin(9600); 
  pinMode(Blink,INPUT); 
  pinMode(A0,OUTPUT); 
  pinMode(red,OUTPUT); 
  pinMode(green,OUTPUT); 
  pinMode(blue,OUTPUT); 
  delay(10); 
  digitalWrite(red,LOW); 
  digitalWrite(blue,LOW); 
  digitalWrite(green,LOW); 
} 
void loop()
{ 
  int i; 
  sum=0; 
  Serial.println("-----------------------------------------------"); 
  Serial.println("| DROWSINESS DETECTOR |"); 
  Serial.println("| BY:AMRATHESH        |"); 
  Serial.println("-----------------------------------------------"); 
  for(i=1;i<=25;i++) 
   {
    count++; 
    if(!(count%5)) 
    Serial.println(" "); 
    sum=sum+digitalRead(Blink); 
    if(digitalRead(Blink)==0) //eye status from IR 
    Serial.print("OPEN "); 
    else 
    Serial.print("CLOSE "); 
    delay(200); 
    } 
  avg=sum/7.5; 
  Serial.print("Blink rate in per second: "); 
  Serial.println(avg); 
  delay(100); 
if(avg<0.5) 
  { digitalWrite(red,LOW); 
  digitalWrite(blue,LOW); 
  digitalWrite(green,HIGH); 
  delay(10); 
  } 
else if(avg>1) 
  { i=0; 
  digitalWrite(green,LOW); 
  digitalWrite(blue,LOW); 
  digitalWrite(red,HIGH); 
  delay(10); 
  Serial.println("\n"); 
  Serial.println("--------------------------------------------"); 
  Serial.println("| YOU ARE DROWSY!!! STOP FOR SAFETY |"); 
  Serial.println("--------------------------------------------"); 
    while(i<25) 
    {  analogWrite(A0,130); 
       delay(400); 
       i++; 
      if(i==10) 
      { 
        analogWrite(A0,0); 
        digitalWrite(red,LOW); 
        delay(10); 
        break;
      } 
    }
  }
   else 
   { 
    digitalWrite(green,LOW); 
    digitalWrite(red,LOW); 
    digitalWrite(blue,HIGH); 
      for(i=0;i<10;i++) 
      { analogWrite(A0,130); 
        delay(10); 
        analogWrite(A0,0); 
        delay(100); 
      } 
  } 
}
