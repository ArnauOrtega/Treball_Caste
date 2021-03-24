byte Inputs[6];
byte input;
byte level = 1;
byte pass_1 [6];
byte pass_2 [6];
byte pass_3 [6];
byte pass_4 [6];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  input = read_buttons(analogRead(A0));
  if (input == 0){
    input = read_buttons2(analogRead(A1));
  }
  pass_check(input);
  delay(50);
}
byte read_buttons(int button_read){
  byte n;
  //Serial.println(button_read);
  if (button_read == 1023){
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
    n = 0;
  }
  return n;
  while(analogRead(A0)!= 0){
    }
}
byte read_buttons2(int button_read){
  byte n;
  if (button_read == 1023){
    n = 8;
  }
  else if (button_read >= 1010 && button_read <= 1020){
    n = 9;
  }
  else if (button_read >= 60 && button_read <= 70){
    n = 10;
  }
  while(analogRead(A1)!= 0){
    }
  return n;
}
void pass_check(int in){
  for(int i=0; i < 6; i++){
    Inputs[i+1]= Inputs[i];  
  }
  Inputs[0] = in;
  switch (level) {
  case 1:
    if (pass_1 == Inputs){
      Serial.println("1");
      level = level + 1;
    }
    break;
  case 2:
    if (pass_2 == Inputs){
      Serial.println("2");
      level = level + 1;
    }
    break;
  case 3:
    if (pass_3 == Inputs){
      Serial.println("3");
      level = level + 1;
    }
    break;
  case 4:
    if (pass_3 == Inputs){
      Serial.println("4");
    }
    break;
  }
}
