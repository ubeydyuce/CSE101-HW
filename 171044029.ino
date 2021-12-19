int Mydata=0;
int number;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
}


void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()>0){
    Mydata=Serial.read()-48;
    Serial.println(Mydata+48);
    if(Mydata==1){
      Led_on();
    }
    else if(Mydata==2) Led_off();
    else if(Mydata==3) flash();
    else if(Mydata==0) Exit();
    else if(Mydata==4) square();
    
  }
  
  
}
void Led_on(){
  digitalWrite(LED_BUILTIN,HIGH);
}
void Led_off(){
  digitalWrite(LED_BUILTIN,LOW);
}
void flash(){
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);  
}
void Exit(){
  Serial.println("Program bitirildi");
  while(1){
  }
}
void square(){
  Serial.println("Getting a value");
  while(Serial.available()==0){
 Serial.read();
 }
  if(Serial.available()>0){  
    number=Serial.read()-48;
    number=number*number;
    Serial.println("Square:");
    Serial.println(number);
  }
}
