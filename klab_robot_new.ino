int left_motor_speed = 10; //pwm1
int left_dir=11;//dir1
int right_motor_speed=8;//pwm2
int right_dir=9;//dir2
int rx,ry;
void setup() {
Serial.begin(9600);
Serial1.begin(9600);
pinMode(left_motor_speed, OUTPUT);
pinMode(left_dir, OUTPUT);
pinMode(right_motor_speed, OUTPUT);
pinMode(right_dir, OUTPUT);
}

/*
 0 - левый стик X  
 1 - левый стик Y
 2 - правый стик X
 3 - правый стик Y
 4 - А
 5 - В
 6 - X
 7 - Y
 8 - левый триггер
 9 - правый триггер
 */
byte buffer[10];
void loop() {
   Serial1.readBytes(buffer,10);
      
   ry=-map((int)buffer[3],0,255,-255,255);
   rx=map((int)buffer[2],0,255,-255,255);
   if ((ry>=-2)&&(ry<=2)) ry=0;
   if((rx>=-2)&&(rx<=2)) rx=0;
  
   if ((ry==0)&&(rx==0)) //стоим на месте
   {
   analogWrite(left_motor_speed,0);
   analogWrite(right_motor_speed,0);
   }
   else if ( (ry>0)&&(rx==0))//движение вперед
   { 
   analogWrite(left_motor_speed,ry);
   analogWrite(right_motor_speed,ry);
   digitalWrite(left_dir,HIGH);
   digitalWrite(right_dir,HIGH);
   }
   else if ( (ry<0)&&(rx==0))//движение назад
   { 
   analogWrite(left_motor_speed,abs(ry));
   analogWrite(right_motor_speed,abs(ry));
   digitalWrite(left_dir,LOW);
   digitalWrite(right_dir,LOW);
   }
   
   if ((rx<0)&&(ry>0))//поворот налево
   {analogWrite(right_motor_speed,constrain((ry+rx),0,255));
   analogWrite(left_motor_speed,abs(rx));
    digitalWrite(left_dir,HIGH);
   digitalWrite(right_dir,HIGH);
   } 

   
  if ((rx>0)&&(ry>0))//поворот  направо
   {analogWrite(right_motor_speed,abs(rx));
   analogWrite(left_motor_speed,constrain((ry-rx),0,255));
    digitalWrite(left_dir,HIGH);
   digitalWrite(right_dir,HIGH);
   } 

if ((ry==0)&&(rx<0))//поворот на месте левым колесом
{
     analogWrite(left_motor_speed,abs(rx));
   analogWrite(right_motor_speed,abs(rx));
   digitalWrite(left_dir,LOW);
   digitalWrite(right_dir,HIGH);
}
if ((ry==0)&&(rx>0))//поворот на месте правым колесом
{
     analogWrite(left_motor_speed,abs(rx));
   analogWrite(right_motor_speed,abs(rx));
   digitalWrite(left_dir,HIGH);
   digitalWrite(right_dir,LOW);
}

//Serial.println(rx);
////Serial.println(ry);

  }

