/*
 * Algorithm-- 
 * + On Off Switch
 * + PushButton
 * - Reset Button
 * - Correct-Button
 * - Incorrect Button
 * - Red/Blue/Green/Orange/White
 * 
 * + OLED Display
 * + 7 Rocker Switch
 * + 6 LEDs
 * + 6 Resistors
 *  
 * tone( pin number, frequency in hertz,duration_in_ms);  
 * 
 * 
 */

//Function Declarion
long getTime(long p);
void resetAll();
void startGame();
void checkAnswer();

int var=0;
int ri=0;
int bi=0;
int gi=0;
int oi=0; 
int yi=0;


 //Global Variable Decalartion
int StopVar=0;
int i=0;

int team[6];
float duration[6];
int ai=0; // Array Incrementer

float time;    //Stores Time Value
float tim;     
float past;

const int RedLed=2;    //LED Pins
const int BlueLed=3;
const int GreenLed=4;
const int OrangeLed=5;
const int YellowLed=6;

const int Buzzer=13;     // PWM Pin

const int Red=7;       // Arcade Button Pin
const int Blue=8;
const int Green=9;
const int Orange=10;
const int Yellow=11;

//Input Buttons
const int Start=A0;
const int Stop=A1;
const int Correct=A2;       
const int Incorrect=A3;


String tnames[7]={"ND","ND","RED","BLUE","GREEN","ORANGE","YELLOW"};   //Team Names

void setup() {

  Serial.begin(9600);
  //Serial.println("All Fine");

 pinMode( RedLed,OUTPUT);
 pinMode( BlueLed,OUTPUT);
 pinMode( GreenLed,OUTPUT);
 pinMode( OrangeLed,OUTPUT);
 pinMode( YellowLed,OUTPUT);
 pinMode( Buzzer,OUTPUT);

 pinMode( Red,INPUT);
 pinMode( Blue,INPUT);
 pinMode( Green,INPUT);
 pinMode( Orange,INPUT);
 pinMode( Yellow,INPUT);
 
 pinMode( Start,INPUT);
 pinMode( Stop,INPUT);

 pinMode( Correct,INPUT);  //OLED Blinks /, Speaker Beep f1
 pinMode( Incorrect,INPUT);//OLED Blinks X , Speaker Beep f2

 delay(500);
 digitalWrite(RedLed,HIGH);
 digitalWrite(BlueLed,HIGH);
 digitalWrite(GreenLed,HIGH);
 digitalWrite(OrangeLed,HIGH);
 digitalWrite(YellowLed,HIGH);
 delay(2000);
 //Begin State
 digitalWrite(RedLed,LOW);
 digitalWrite(BlueLed,LOW);
 digitalWrite(GreenLed,LOW);
 digitalWrite(OrangeLed,LOW);
 digitalWrite(YellowLed,LOW);

}

void loop() {

 startGame();  //Game Begins
 checkAnswer();  // Check the Answer
 resetAll();   //Reset's

}


void startGame()
{
  //Give a turn on Alert
  //Condition Variable
  
 // Serial.println(" Function startGame() ");


do{
  
if( digitalRead(Start)==HIGH)
{
  past = millis();  //Past time
  var==0 ? Serial.println(" Game has Started"):var=1;
  var=1;

  ri=0;
  bi=0;
  gi=0;
  oi=0;
  yi=0;
  
  while(true)
  {
  
  
  if(digitalRead(Red)==HIGH && ri==0)
  {
    //Serial.println(" RED ");
    digitalWrite(RedLed,HIGH);
    team[ai]=2;
    duration[ai]=getTime(past);
    //Serial.println(String(tnames[team[ai]])+"  "+String(duration[ai]));
    ai++; //Increment
    ri=1;
    
  }
  if(digitalRead(Blue)==HIGH && bi==0)
  {
    //Serial.println(" BLUE ");
    digitalWrite(BlueLed,HIGH);
    team[ai]=3;
    duration[ai]=getTime(past);
    //Serial.println(String(tnames[team[ai]])+"  "+String(duration[ai]));
    ai++; //Increment
    bi=1;
  }
  if(digitalRead(Green)==HIGH && gi==0)
  {
    //Serial.println(" GREEN ");
    digitalWrite(GreenLed,HIGH);
    team[ai]=4;
    duration[ai]=getTime(past);
    //Serial.println(String(tnames[team[ai]])+"  "+String(duration[ai]));
    ai++;  //Increment
    gi=1;
  }
  
  if(digitalRead(Orange)==HIGH && oi==0)
  {
    //Serial.println(" Orange ");
    digitalWrite(OrangeLed,HIGH);
    team[ai]=5;
    duration[ai]=getTime(past);
    //Serial.println(String(tnames[team[ai]])+"  "+String(duration[ai]));
    ai++;  //Increment
    oi=1;

  }
  
  if(digitalRead(Yellow)==HIGH && yi==0)
  {
    //Serial.println(" Yellow ");
    digitalWrite(YellowLed,HIGH);
    team[ai]=6;
    duration[ai]=getTime(past);
    //Serial.println(String(tnames[team[ai]])+"  "+String(duration[ai]));
    ai++;  //Increment
    yi=1;

  }
  
  if(digitalRead(Stop)==HIGH)
  {
    StopVar=1;
    //Serial.println(" Game Stopped");
    break;   
  }
  }
  
}
}while(StopVar==0);

}

void checkAnswer()
{
  //Serial.println(" Function checkAnswer()");
  ai=0;
  digitalWrite(RedLed,LOW); //Turn Off All Lights
  digitalWrite(BlueLed,LOW);
  digitalWrite(GreenLed,LOW);
  digitalWrite(OrangeLed,LOW);
  digitalWrite(YellowLed,LOW);

for(int k=0;k<=4;k++)
  Serial.println("        "+String(tnames[team[k]])+"  "+String(duration[k])+" ms");
  
do{  
  i=0; //Condition Variable
  delay(1000);

  digitalWrite(team[ai],HIGH);
  //Serial.println(team[ai]);
  
if(digitalRead(Correct)==HIGH)
{
  //OLED Print Correct
  Serial.println("Correct");
  Serial.println(String(tnames[team[ai]])+" You have Won ");
  i=1;
  break;
}

if(digitalRead(Incorrect)==HIGH)
{
  //OLED Print Incorrect
  Serial.println(" Incorrect ");
  digitalWrite(team[ai],LOW);
  ai++;
  
}

}while(i==0);

}


void resetAll()
{
digitalWrite(RedLed,LOW);
digitalWrite(BlueLed,LOW);
digitalWrite(GreenLed,LOW);
digitalWrite(OrangeLed,LOW);
digitalWrite(YellowLed,LOW);
Serial.println("Resets");
delay(1000);

StopVar=0;
var=0;

for(int j=0;j<=4;j++)
{
  duration[j]=0.0;
  team[j]=0;
}
//duration[5]={0,0,0,0,0};   //Clear Time error-initialize manually
//team[5]={0,0,0,0,0};
}

float getTime(float p)
{
  //Serial.println("Function getTime");
 tim=millis();
 time=tim-p;
 //Serial.println(time);
 //Serial.println("ms");
 return time;
}

