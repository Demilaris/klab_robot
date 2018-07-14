int left_motor_speed = 11; 
int orange=10;
int right_motor_speed=9;
int yellow=6;
int rx,ry;
void setup() {
Serial.begin(9600);
Serial1.begin(9600);
pinMode(left_motor_speed, OUTPUT);
pinMode(orange, OUTPUT);
pinMode(right_motor_speed, OUTPUT);
pinMode(yellow, OUTPUT);
}
byte buffer[10];
void loop() {
//  while(Serial1.available()>0){
   Serial1.readBytes(buffer,10);
   
   ry=-map((int)buffer[3],0,255,-255,255);
   rx=map((int)buffer[2],0,255,-255,255);
   if ((ry>=-2)&&(ry<=2)) ry=0;
   if((rx>=-2)&&(rx<=2)) rx=0;
   if ((ry==0)&&(rx==0)) 
   {
   analogWrite(left_motor_speed,0);
   analogWrite(right_motor_speed,0);
   }
   else
   { 
   analogWrite(left_motor_speed,abs(ry));
   analogWrite(right_motor_speed,abs(ry));
   }
   if ((rx<0)&&(ry>0))
   {analogWrite(right_motor_speed,constrain(abs((ry-rx)),0,255));
   analogWrite(left_motor_speed,rx);
   } 

   if 
   
   
//     Serial.println(rx);
//Serial.println(ry);

//analogWrite(GREEN,constrain(255-i,128,255));
  }
//}
