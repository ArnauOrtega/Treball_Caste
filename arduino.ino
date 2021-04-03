byte Inputs[6];
byte input;
byte level = 1;
byte pass_1 [6]={2,2,1,2,0,0};
byte pass_2 [6]={7,8,9,0,0,9};
byte pass_3 [6]={8,7,6,5,4,3};
byte pass_4 [6]={2,1,2,3,4,5};
bool pressed = false;
#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(6);
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  Serial.begin(9600);
}

void loop() {
  input = read_buttons(analogRead(A1));
  if (!pressed){
    input = read_buttons2(analogRead(A0));
  }
  if (pressed){
    Serial.print(input);
  pass_check(input);
  pressed = false;
  }
  delay(50);
}
byte read_buttons(int button_read){
  byte n;
  //Serial.println(button_read);
  if (button_read >= 1015 && button_read <= 1023){
    n = 1;
  }
  else if (button_read >= 995 && button_read <= 1005){
    n = 2;
  }
  else if (button_read >= 965 && button_read <= 975){
    n = 3;
  }
  else if (button_read >= 925 && button_read <= 935){
    n = 4;
  }
  else if (button_read >= 690 && button_read <= 700){
    n = 5;
  }
   else if (button_read >= 506 && button_read <= 516){
    n = 6;
  }
   else if (button_read >= 5 && button_read <= 10){
    n = 7;
  }
  else {
    pressed = false;
    return;
  }
    while(analogRead(A1)){}
  pressed = true;
  return n;
}
byte read_buttons2(int button_read){
  byte n;
  if (button_read == 1023){
    n = 8;
  }
  else if (button_read >= 990 && button_read <= 1010){
    n = 9;
  }
  else if (button_read >= 960 && button_read <= 980){
    n = 0;
  }
  else{
  pressed = false;
  return;
  }
  pressed = true;
  while(analogRead(A0)){}
  return n;
}
void pass_check(int in){
  for(int i=5; i >= 0; i--){
    Inputs[i+1]= Inputs[i];  
  }
  Inputs[0] = in;
 switch (level) {
  case 1:
    if (pass_1[0] == Inputs[5]&&pass_1[1] == Inputs[4]&&pass_1[2] == Inputs[3]&&pass_1[3] == Inputs[2]&&pass_1[4] == Inputs[1]&&pass_1[5] == Inputs[0]){
      Serial.println("1");
        myservo.write(0);
      level = level + 1;
       for(int i=0; i < 6; i++){
        Inputs[i]=0;
        }
    }
    break;
  case 2:
    if (pass_2[0] == Inputs[5]&&pass_2[1] == Inputs[4]&&pass_2[2] == Inputs[3]&&pass_2[3] == Inputs[2]&&pass_2[4] == Inputs[1]&&pass_2[5] == Inputs[0]){
      Serial.println("2");
      level = level + 1;
      for(int i=0; i < 6; i++){
        Inputs[i]=0;
        }
    }
    break;
  case 3:
    if (pass_3[0] == Inputs[5]&&pass_3[1] == Inputs[4]&&pass_3[2] == Inputs[3]&&pass_3[3] == Inputs[2]&&pass_3[4] == Inputs[1]&&pass_3[5] == Inputs[0]){
      Serial.println("3");
      level = level + 1;
      for(int i=0; i < 6; i++){
        Inputs[i]=0;
        }
    }
    break;
  case 4:
   if (pass_4[0] == Inputs[5]&&pass_4[1] == Inputs[4]&&pass_4[2] == Inputs[3]&&pass_4[3] == Inputs[2]&&pass_4[4] == Inputs[1]&&pass_4[5] == Inputs[0]){
      Serial.println("4");
      for(int i=0; i < 6; i++){
        Inputs[i]=0;
        }
    }
    break;
  }
}
