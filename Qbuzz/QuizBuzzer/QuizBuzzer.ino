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


 //Global Variable Decalartion
int StopVar=0;
int i=0;

int team[5];
float duration[5];
int ai=0; // Array Incrementer

unsigned long time;    //Stores Time Value
unsigned long tim;     
unsigned long past;

const int RedLed=2;    //LED Pins
const int BlueLed=3;
const int GreenLed=4;
const int OrangeLed=5;

const int Buzzer=10;     // PWM Pin

const int Red=6;       // Arcade Button Pin
const int Blue=7;
const int Green=8;
const int Orange=9;

//Input Buttons
const int Start=A0;
const int Stop=A1;
const int Correct=A2;       
const int Incorrect=A3;


String tnames[6]={"ND","ND","RED","BLUE","GREEN","ORANGE"};   //Team Names

void setup() {

  Serial.begin(9600);

 pinMode( RedLed,OUTPUT);
 pinMode( BlueLed,OUTPUT);
 pinMode( GreenLed,OUTPUT);
 pinMode( OrangeLed,OUTPUT);
 pinMode( Buzzer,OUTPUT);

 pinMode( Red,INPUT);
 pinMode( Blue,INPUT);
 pinMode( Green,INPUT);
 pinMode( Orange,INPUT);
 pinMode( Start,INPUT);
 pinMode( Stop,INPUT);

 pinMode( Correct,INPUT);  //OLED Blinks /, Speaker Beep f1
 pinMode( Incorrect,INPUT);//OLED Blinks X , Speaker Beep f2


 //Begin State
 digitalWrite(RedLed,LOW);
 digitalWrite(BlueLed,LOW);
 digitalWrite(GreenLed,LOW);
 digitalWrite(OrangeLed,LOW);

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
  bool ri=false;
  bool bi=false;
  bool gi=false;
  bool oi=false; 

do
{
if( digitalRead(Start)==HIGH)
{
   past = millis();  //Past time
  if(digitalRead(Red)==HIGH && ri==false)
  {
    digitalWrite(RedLed,HIGH);
    team[ai]=2;
    duration[ai]=getTime(past);
    Serial.println(String(tnames[team[ai]])+"  "+String(duration[ai]));
    ai++; //Increment
    ri=true;
  }
  if(digitalRead(Blue)==HIGH && bi==false)
  {
    digitalWrite(BlueLed,HIGH);
    team[ai]=3;
    duration[ai]=getTime(past);
    Serial.println(String(tnames[team[ai]])+"  "+String(duration[ai]));
    ai++; //Increment
    bi=true;
  }
  if(digitalRead(Green)==HIGH && gi==false)
  {
    digitalWrite(GreenLed,HIGH);
    team[ai]=4;
    duration[ai]=getTime(past);
    Serial.println(String(tnames[team[ai]])+"  "+String(duration[ai]));
    ai++;  //Increment
    gi=true;
  }
  if(digitalRead(Orange)==HIGH && oi==false)
  {
    digitalWrite(OrangeLed,HIGH);
    team[ai]=5;
    duration[ai]=getTime(past);
    Serial.println(String(tnames[team[ai]])+"  "+String(duration[ai]));
    ai++;  //Increment
    oi=true;
  }
  if( digitalRead(Stop)==HIGH )
  {
    StopVar=1;   
  }
  
}
}while(StopVar==0);

}

void checkAnswer()
{
  ai=0;
  digitalWrite(RedLed,LOW); //Turn Off All Lights
  digitalWrite(BlueLed,LOW);
  digitalWrite(GreenLed,LOW);
  digitalWrite(OrangeLed,LOW);
do{  
  i=0; //Condition Variable
  delay(1000);

  digitalWrite(team[ai],HIGH);
  
if(digitalRead(Correct)==HIGH)
{
  //OLED Print Correct
  i=1;
  break;
}

if(digitalRead(Incorrect)==HIGH)
{
  //OLED Print Incorrect
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

for(int j=0;j<6;j++)
{
  duration[j]=0.0;
  team[j]=0;
}
//duration[5]={0,0,0,0,0};   //Clear Time error-initialize manually
//team[5]={0,0,0,0,0};
}

long getTime(long p)
{
 tim=millis();
 time=round(tim/1000-(p/1000));
 return time;
}

