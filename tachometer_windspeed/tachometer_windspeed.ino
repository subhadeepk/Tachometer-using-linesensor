//Tachometer using linesensor
//Developer: Subhadeep Koley
//last updated:28/05/2022
int signalPin =  3; // 
unsigned long start1=0;
unsigned long start2 = 0;
unsigned long start0 = 0;
int q = 2;
int p;
int g=0;
float P_ambient;
int r=1;
unsigned long rpmsum=0;
unsigned long counter=1;
unsigned long avgrpm;
void setup()   {
  while (r<=3)
   {// read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0); //read voltage
  P_ambient=1000*(5*voltage/5-5/2); //calculate differential pressure
  r++;
  delay(1000);
   }
  pinMode(signalPin, INPUT); // initialize the digital pin as an output:
  Serial.begin(57600);  // initialize serial communications at 57600 bps:
}
// the loop() method runs over and over again,
// as long as the Arduino has power
//uncomment lines in void loop to get instantaneos rpm

void loop()
{
  if (HIGH == digitalRead(signalPin))
  { p = 1;
    if (q == 0)
      start0 = millis();
  }
  else
    p = 0;
    
  q=p;
  
  if (start0 == 0)
    g++;
  else if (start1 == 0)
    start1 = start0;
  else if ((start2 == 0)&&(start0 != start1))
    start2 = start0;

 if (start2 > start1)
  { unsigned long rpm = 60000 / (start2 - start1);
    //Serial.print("RPM=");
    //Serial.println(rpm);
    start1 = start2;
    start2 = 0;
    rpmsum=rpmsum+rpm;
    avgrpm=rpmsum/counter;
    if (counter%20==0)
//    {Serial.print("avgrpm=");
//     Serial.print(avgrpm);
//     Serial.print(":");
     {rpmsum=0;
     counter=0;}
     counter++;}
 // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0); //read voltage
  float dP=(1000*(5*voltage/5-5/2))-P_ambient; //calculate differential pressure
  float velocity=sqrt(2*dP/1.225); //calulate velocity
//   Serial.print("dP=");
//  Serial.print(dP);
//  Serial.print(",windspeed=");
  Serial.print(avgrpm);
  Serial.print(",");
  Serial.println(velocity);
  
  //delay(1);                  
}
