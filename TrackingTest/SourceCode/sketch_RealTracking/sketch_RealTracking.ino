//DC
const int Left_motor_forward = 8;
const int Left_motor_back = 7;
const int Right_motor_forward = 2;
const int Right_motor_back = 4;

//speed
const int Left_motor_pwm = 6;
const int Right_motor_pwm = 5;


//Startup Button
const int btnPin = A0;

//Infrared Sensor
const int leftOutside = A2;
const int leftInside = A1;
const int rightInside = A3;
const int rightOutside = A4;


void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  pinMode(btnPin, INPUT);
  pinMode(Left_motor_forward, OUTPUT);
  pinMode(Left_motor_back, OUTPUT);
  pinMode(Right_motor_forward, OUTPUT);
  pinMode(Right_motor_back, OUTPUT);
  pinMode(Left_motor_pwm, OUTPUT);
  pinMode(Right_motor_pwm, OUTPUT);
}

void back(int fspeed) 
{
  digitalWrite(Left_motor_forward, LOW);
  digitalWrite(Left_motor_back, HIGH);
  analogWrite(Left_motor_pwm, fspeed);
  digitalWrite(Right_motor_forward, LOW);
  digitalWrite(Right_motor_back, HIGH);
  analogWrite(Right_motor_pwm, fspeed);
}

void forward(int fspeed)
{
  digitalWrite(Left_motor_forward, HIGH);
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_pwm, fspeed);
  digitalWrite(Right_motor_forward, HIGH);
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_pwm, fspeed);
}

void brake()
{
  digitalWrite(Left_motor_forward, LOW);
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_pwm, 0);
  digitalWrite(Right_motor_forward, LOW);
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_pwm, 0);
}

void turnLeft(int rpwm_speed)//转角小
{
  digitalWrite(Left_motor_forward, LOW);
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_pwm, 0);
  digitalWrite(Right_motor_forward, HIGH);
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_pwm, rpwm_speed);
}

void turnRight(int lpwm_speed)//转角小
{
  digitalWrite(Left_motor_forward, HIGH);
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_pwm, lpwm_speed);
  digitalWrite(Right_motor_forward, LOW);
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_pwm, 0);
}

void cicleLeft(int fspeed)//转角大
{
  digitalWrite(Left_motor_forward, LOW);
  digitalWrite(Left_motor_back, HIGH);
  analogWrite(Left_motor_pwm, fspeed);
  digitalWrite(Right_motor_forward, HIGH);
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_pwm, fspeed);
}

void cicleRight(int fspeed)//转角大
{
  digitalWrite(Left_motor_forward, HIGH);
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_pwm, fspeed);
  digitalWrite(Right_motor_forward, LOW);
  digitalWrite(Right_motor_back, HIGH);
  analogWrite(Right_motor_pwm, fspeed);
}

int isStraight()
{
  if(digitalRead(leftInside) == LOW&&digitalRead(leftOutside) == HIGH&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == HIGH)
    return 1;
   return 0;
}

//小幅度左转
int isSmallAngleTurnLeft()
{
  if(digitalRead(leftInside) == LOW&&digitalRead(leftOutside) == HIGH&&digitalRead(rightInside) == HIGH&&digitalRead(rightOutside) == HIGH)
    return 1;
   return 0;
}

//小幅度右转
int isSmallAngleTurnRight()
{
  if(digitalRead(leftInside) == HIGH&&digitalRead(leftOutside) == HIGH&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == HIGH)
    return 1;
   return 0;
}
//中幅度左转
int isMediumAngleTurnLeft()
{
  if(digitalRead(leftInside) == HIGH&&digitalRead(leftOutside) == LOW&&digitalRead(rightInside) == HIGH&&digitalRead(rightOutside) == HIGH)
    return 1;
   return 0;
}

//中幅度右转
int isMediumAngleTurnRight()
{
  if(digitalRead(leftInside) == HIGH&&digitalRead(leftOutside) == HIGH&&digitalRead(rightInside) == HIGH&&digitalRead(rightOutside) == LOW)
    return 1;
   return 0;
}

//向左直角转弯
int isLeftAngleTurn()
{
  if(digitalRead(leftInside) == LOW&&digitalRead(leftOutside) == LOW&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == HIGH)
    return 1;
   return 0;
}

//向右直角转弯
int isRightAngleTurn()
{
  if(digitalRead(leftInside) == LOW&&digitalRead(leftOutside) == HIGH&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == LOW)
    return 1;
   return 0;
}

//向左锐角转弯分解动作1
int isLeftAcuteTurn1()
{
  if(digitalRead(leftInside) == LOW&&digitalRead(leftOutside) == LOW&&digitalRead(rightInside) == HIGH&&digitalRead(rightOutside) == HIGH)
    {
     return 1;
    }
   return 0;
}

//向左锐角转弯分解动作2
int isLeftAcuteTurn2()
{
  if(digitalRead(leftInside) == HIGH&&digitalRead(leftOutside) == LOW&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == HIGH)
    {
     return 1;
    }
   return 0;
}

//向右锐角转弯分解动作1
int isRightAcuteTurn1()
{
  if(digitalRead(leftInside) == LOW&&digitalRead(leftOutside) == HIGH&&digitalRead(rightInside) == HIGH&&digitalRead(rightOutside) == LOW)
    {
     return 1;
    }
   return 0;
}

//向右锐角转弯分解动作2
int isRightAcuteTurn2()
{
  if(digitalRead(leftInside) == HIGH&&digitalRead(leftOutside) == HIGH&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == LOW)
    {
     return 1;
    }
   return 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btnPin) == LOW)//startup by btn
   {
     delay(200);
     //RouteController-The type of amount which amount to 13 
     while(1)
     {
      //————————————————基本情况判断
      if(isStraight())//直走 xoox
      {
        forward(115);
      }
      else if(isSmallAngleTurnLeft())//小幅度左转 xoxx （大钝角）
      {
        cicleLeft(115);
//        turnLeft(150);
//        delay(50);
      }
      else if(isSmallAngleTurnRight())//小幅度右转 xxox （大钝角）
      {
        cicleRight(115);
//        turnLeft(150);
//        delay(50);
      }
      else if(isMediumAngleTurnLeft())//中幅度左转 oxxx（小钝角）
      {
        cicleLeft(115);
//        delay(200);
      }
      else if(isMediumAngleTurnRight())//中幅度右转 xxxo（小钝角）
      {
        cicleRight(115);
//        delay(200);
      }
      else if(isLeftAngleTurn())//向左直角转弯 ooox
      {
        delay(30);
        cicleLeft(115);
//        delay(100);
      }
      else if(isRightAngleTurn())//向右直角转弯 xooo
      {
        delay(30);
        cicleRight(115);
      }
      else if(isLeftAcuteTurn1())//向左锐角转弯1  o oxx
      {
        delay(30);
        cicleLeft(115);
      }
      else if(isRightAcuteTurn1())//向右锐角转弯1 xoxo
      {
        delay(30);
        cicleRight(115);
      }
      else if(isLeftAcuteTurn2())//向左锐角转弯2  oxox
      {
        delay(30);
        cicleLeft(115);
      }
      else if(isRightAcuteTurn2())//向右锐角转弯2 xxoo
      {
        delay(30);
        cicleRight(115);
//        delay(60);
//        cicleRight(75);
//        delay(600);
      }
      //————————————其他特殊情况判断
       //中间十字交叉线判断（统一向左转） oooo
       else if(digitalRead(leftInside) == LOW&&digitalRead(leftOutside) == LOW&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == LOW)
       {
         forward(115);
//        delay(200);
//        cicleLeft(90);
//        delay(280);
       }
       else //xxxx
       {
//        brake();
//          back(60);
//          forward(40);

       }
     }
   }
}
