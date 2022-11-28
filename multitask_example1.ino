#include<WiFi.h>


const int ledPin5 = 5;
const int ledPin15 = 15;

const int trigPin1 = 22;  //D22
const int echoPin1=  23;  //D23

const int pin19=19; 
int tunnel_width=20;
int distance1;

/*int measureDistance(int trigPin,int echoPin){
         bool t;
          int tunnel_width=60;
  
         digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
         digitalWrite(trigPin, LOW);

           long duration = pulseIn(echoPin, HIGH);
          int distance= duration*0.034/2;
         return distance;
                                             //Serial.print("Distance: ");Serial.println(distance);  
           }
*/
           
void setup() {
  // setup pin 5 as a digital output pin
  pinMode (ledPin5, OUTPUT);
  pinMode (ledPin15, OUTPUT);
  pinMode(pin19,OUTPUT);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input

  Serial.begin(115200); // Starts the serial communication
   xTaskCreate(pin5task, "pin 5 Task", 10000, NULL, 1, NULL);//Function name,"Taskname",Stack size,Task parameter,Task priority,Task handle
  xTaskCreate(pin15task, "pin 15 Task", 10000, NULL, 1, NULL);
   xTaskCreate(distancemeasuretask, "distancemeasure", 10000, NULL, 1, NULL);
}
void loop() {
 
}

void distancemeasuretask(void *parameter){

    //  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
      //pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
 while(1){
            int people_Count=0;
             bool t;
             
            distance1=measureDistance(trigPin1,echoPin1);
                                                         //Serial.println(distance1);
         Serial.printf("Sensor1 reading: %d\n", distance1);
         if (distance1<tunnel_width){
      
              t=true; 
           }
    else {
              t=false;
          }
          if(t==true){
            digitalWrite(pin19,HIGH);
            }
            else{
              digitalWrite(pin19,LOW);
            }
 }}
      
void pin5task(void *parameter){

 // const int ledPin5 = 5;
 // pinMode(ledpin,OUTPUT); 
 
   while(1){
  //  const int ledPin5 = 5;
 digitalWrite (ledPin5, HIGH);  // turn on the LED
  delay(500); // wait for half a second or 500 milliseconds
  digitalWrite (ledPin5, LOW); // turn off the LED
  delay(500); // wait for half a second or 500 milliseconds
   }}

   void pin15task(void *parameter){

 // const int ledPin5 = 5;
 // pinMode(ledpin,OUTPUT); 
 
   while(1){
  //  const int ledPin15 = 15;
 digitalWrite (ledPin15, HIGH);  // turn on the LED
  delay(200); // wait for half a second or 500 milliseconds
  digitalWrite (ledPin15, LOW); // turn off the LED
  delay(200); // wait for half a second or 500 milliseconds
   }}



   int measureDistance(int trigPin,int echoPin){
         bool t;
          int tunnel_width=60;
  
         digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
         digitalWrite(trigPin, LOW);

           long duration = pulseIn(echoPin, HIGH);
          int distance= duration*0.034/2;
         return distance;
                                             //Serial.print("Distance: ");Serial.println(distance);  
           }
