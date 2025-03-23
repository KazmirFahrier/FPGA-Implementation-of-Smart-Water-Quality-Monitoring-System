int mq7Pin = A2;
int waterLevelPin = A0;
int lm35tempin= A4;
int values[] = {0,0,0,0,0,0,0,0,0};

void setup() {
  Serial.begin(9600); // initialize serial communication
 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  int waterLevel = analogRead(waterLevelPin); // Read the analog water level value
  Serial.println(waterLevel);
  waterLevel = (waterLevel*10)/800;

  
 Serial.print("Water Level: ");
  Serial.print(waterLevel);
    Serial.println("0%");
    
  int mq7Value = analogRead(mq7Pin);
  Serial.println(mq7Value);
  mq7Value = (mq7Value*10)/500;

  Serial.print("CO level: ");
  Serial.print(mq7Value);
  Serial.println("");
  
int tempLevel = analogRead(lm35tempin);
 float voltage = tempLevel * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float temperatureC = voltage  * 100 ;  
                                               
 Serial.print(temperatureC); Serial.println(" degrees C");
 

  Serial.println(tempLevel);
  if(temperatureC> 30) values[8]=1;
  else values[8]=0;
  Serial.println(values[8]);
  
 
  for (int i = 0; i < 8; i++) {
    if (i<4) values[i]=bitRead(waterLevel, i);
    else values[i]= bitRead(mq7Value, (i-4));
  }
  for (int i = 7; i >= 0; i--) {
    Serial.print(values[i]);
  }
  Serial.println("done");
  Output();
  delay(1000);

}

void Output(){
  digitalWrite(2, values[3]);
  digitalWrite(3, values[2]);
  digitalWrite(4, values[1]);
  digitalWrite(5, values[0]);
  digitalWrite(6, values[7]);
  digitalWrite(7, values[6]);
  digitalWrite(8, values[5]);
  digitalWrite(9, values[4]);
  digitalWrite(10, values[8]);
  }


