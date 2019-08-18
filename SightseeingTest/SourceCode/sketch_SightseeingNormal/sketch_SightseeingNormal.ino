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

//动作: 1-Forward;2-Left;3-Right;4-Arrive,5-AROUND
const int FORWARD = 1;
const int LEFT = 2;
const int RIGHT = 3;
const int ARRIVE = 4;
const int AROUND = 5;
//动作数组
int action[] = {LEFT,RIGHT,ARRIVE,AROUND,RIGHT,LEFT,ARRIVE,AROUND,LEFT,LEFT,ARRIVE,AROUND,LEFT,LEFT,ARRIVE,AROUND,LEFT,RIGHT,RIGHT,RIGHT,ARRIVE,AROUND,RIGHT,LEFT,ARRIVE,AROUND,LEFT,LEFT,LEFT,FORWARD,ARRIVE,AROUND,FORWARD,FORWARD,ARRIVE,AROUND,LEFT,LEFT,LEFT,ARRIVE,AROUND,FORWARD,LEFT,ARRIVE,AROUND,LEFT,RIGHT,LEFT};
//动作步骤号
static int i = 0;
//到达地LED颜色
int k = 0;

//蜂鸣器接口
const int bee = A0;

//LED
const int rgbB = 9;
const int rgbG = 10;
const int rgbR = 11;


//小车动作轨迹
void carRoute(int stepp)
{
  if(stepp == 1)
  {
    //FORWARD
    turnRight(45);
    delay(20);
  }
  else if(stepp == 2)
  {
    delay(15);
    cicleLeft(90);
    delay(430);
  }
  else if(stepp == 3)
  {
    delay(15);
    cicleRight(85);
    delay(390);
  }
  else if(stepp == 4) //到达
  {
    //停车
    brake();
    k++;//LED颜色序号
    //蜂鸣器
    digitalWrite(bee, HIGH);
    digitalWrite(bee, LOW);
    //led灯
    color(k);
    delay(500);//亮灯和发声共半秒
    back(50);//后退
    //关蜂鸣器
    digitalWrite(bee,HIGH);
    //关灯
    digitalWrite(rgbG,LOW);
    digitalWrite(rgbB, LOW);
    digitalWrite(rgbR, LOW);
//    delay(1250);
//    while(!(digitalRead(leftOutside) == HIGH&&digitalRead(leftInside) == LOW&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == HIGH));
  }
  else if(stepp = 5) // 转身掉头
  {
    cicleRight(80);
    delay(920);
    brake();
    forward(40);
    delay(100);
  }
}

void color(int colour)
{
  //第一个点红色
  if(colour ==  1)
  {
    analogWrite(rgbG,0);
    analogWrite(rgbB, 0);
    analogWrite(rgbR, 255);
  }
  //第二个点绿色
  else if(colour == 2)
  {
    analogWrite(rgbG,255);
    analogWrite(rgbB, 0);
    analogWrite(rgbR, 0);
  }
  //第三个点浅蓝色
  else if(colour == 3)
  {
    analogWrite(rgbG,210);
    analogWrite(rgbB, 240);
    analogWrite(rgbR, 193);
  }
  //第四个点深蓝色
  else if(colour == 4)
  {
    analogWrite(rgbG,0);
    analogWrite(rgbB, 255);
    analogWrite(rgbR, 0);
  }
  //第五个点黄色
  else if(colour == 5)
  {
    analogWrite(rgbG,255);
    analogWrite(rgbB, 0);
    analogWrite(rgbR, 255);
  }
  //第六个点绿色
  else if(colour == 6)
  {
    analogWrite(rgbG,255);
    analogWrite(rgbB, 0);
    analogWrite(rgbR, 0);
  }
  //第七个点浅蓝色
  else if(colour == 7)
  {
    analogWrite(rgbG, 102);
    analogWrite(rgbB, 205);
    analogWrite(rgbR, 51);
  }
  //第八个点红色
  else if(colour == 8)
  {
    analogWrite(rgbG,0);
    analogWrite(rgbB, 0);
    analogWrite(rgbR, 255);
  }
  //第九个点深蓝色
  else if(colour == 9)
  {
    analogWrite(rgbG,0);
    analogWrite(rgbB, 255);
    analogWrite(rgbR, 0);
  }
  //第十个点紫色
  else if(colour == 10)
  {
    analogWrite(rgbG, 0);
    analogWrite(rgbB, 128);
    analogWrite(rgbR, 128);
  }
}


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
  pinMode(bee, OUTPUT);
  digitalWrite(bee, HIGH);
  pinMode(rgbB, OUTPUT);
  pinMode(rgbG, OUTPUT);
  pinMode(rgbR, OUTPUT);
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
  if(digitalRead(leftOutside) == HIGH&&digitalRead(leftInside) == LOW&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == HIGH)
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

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btnPin) == LOW)//startup by btn
   {
     delay(200);
     //RouteController-The type of amount which amount to 13 
     //旋转速度小延迟高
     while(1)
     {
      //————————————————基本情况判断
      if(isStraight())//直走 xoox
      {
        forward(90);
      }
      else if(isLeftAngleTurn())//向左直角触发步骤 ooox
      {
        forward(65);
        delay(130);
        brake();
        carRoute(action[i++]);
      }
      else if(isRightAngleTurn())//向右直角触发步骤 xooo
      {
        forward(65);
        delay(130);
        brake();
        carRoute(action[i++]);
      }
      else if(isSmallAngleTurnLeft())//小幅度左转 xoxx （大钝角）
      {
        turnLeft(50);
//        delay(50);
      }
      else if(isSmallAngleTurnRight())//小幅度右转 xxox （大钝角）
      {
        turnRight(50);
//        delay(50);
      }
//      else if(digitalRead(leftInside) == HIGH&&digitalRead(leftOutside) == LOW&&digitalRead(rightInside) == HIGH&&digitalRead(rightOutside) == HIGH)
//      {
//        turnRight(45);
////        delay(20);
//      }
//      else if(digitalRead(leftInside) == HIGH&&digitalRead(leftOutside) == HIGH&&digitalRead(rightInside) == HIGH&&digitalRead(rightOutside) == LOW)
//      {
//        turnLeft(45);
////        delay(20);
//      }
//      else if(digitalRead(leftInside) == LOW&&digitalRead(leftOutside) == LOW&&digitalRead(rightInside) == HIGH&&digitalRead(rightOutside) == HIGH)
//      {
//        cicleRight(45);
//        delay(20);
//      }
//      else if(digitalRead(leftInside) == HIGH&&digitalRead(leftOutside) == HIGH&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == LOW)
//      {
//        cicleLeft(45);
//        delay(20);
//      }
       //4黑 触发步骤 oooo
       else if(digitalRead(leftInside) == LOW&&digitalRead(leftOutside) == LOW&&digitalRead(rightInside) == LOW&&digitalRead(rightOutside) == LOW)
       {
        forward(65);
        delay(130);
        brake();
        carRoute(action[i++]);
       }
//       else if(digitalRead(leftInside) == HIGH&&digitalRead(leftOutside) == HIGH&&digitalRead(rightInside) == HIGH&&digitalRead(rightOutside) == HIGH)
//       {
//        forward(65);
//       }
     }
   }
}
