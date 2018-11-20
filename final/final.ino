/*
 Author: Lawrence
 */

// assign meaningful names to those pins that will be used
#define pinL_Sen A5           //pin A5
#define pinM_Sen A4           //pin A4
#define pinR_Sen A3           //pin A3
#define pinW_Sen A2           //pin A2

#define pinLQ3 3              //pin D3
#define pinLQ2 4              //pin D4
#define pinLQ1 5              //pin D5
#define pinLQ0 6              //pin D6

#define pinRQ3 7              //pin D7
#define pinRQ2 8              //pin D8
#define pinRQ1 9              //pin D9
#define pinRQ0 10             //pin D10

#define pinLdir 11            //pin D11
#define pinRdir 12            //pin D12

//define variables to be used in script
int L_Sen = 1;
int M_Sen = 1;
int R_Sen = 1;
int W_Sen = 1;
int i = 0;
int j = 0;
bool k = 0;

//the function for different speed
void Lstopsp() {
  digitalWrite(pinLQ3, LOW);
  digitalWrite(pinLQ2, LOW);
  digitalWrite(pinLQ1, LOW);
  digitalWrite(pinLQ0, LOW);

}
void Rstopsp() {
  digitalWrite(pinRQ3, LOW);
  digitalWrite(pinRQ2, LOW);
  digitalWrite(pinRQ1, LOW);
  digitalWrite(pinRQ0, LOW);
}

void Lfullforwardsp() {
  digitalWrite(pinLQ3, HIGH);
  digitalWrite(pinLQ2, HIGH);
  digitalWrite(pinLQ1, HIGH);
  digitalWrite(pinLQ0, HIGH);

}

void Rfullforwardsp() {
  digitalWrite(pinRQ3, HIGH);
  digitalWrite(pinRQ2, HIGH);
  digitalWrite(pinRQ1, HIGH);
  digitalWrite(pinRQ0, HIGH);
}

void Lhalfforwardsp() {
  digitalWrite(pinLQ3, HIGH);
  digitalWrite(pinLQ2, LOW);
  digitalWrite(pinLQ1, LOW);
  digitalWrite(pinLQ0, HIGH);
}

void Rhalfforwardsp() {
  digitalWrite(pinRQ3, HIGH);
  digitalWrite(pinRQ2, LOW);
  digitalWrite(pinRQ1, LOW);
  digitalWrite(pinRQ0, HIGH);
}

// the setup function runs once when you press reset or power the board
void setup() {
  // define pins as input and output.
  pinMode(pinL_Sen, INPUT);
  pinMode(pinM_Sen, INPUT);
  pinMode(pinR_Sen, INPUT);
  pinMode(pinW_Sen, INPUT);

  pinMode(pinLQ3, OUTPUT);
  pinMode(pinLQ2, OUTPUT);
  pinMode(pinLQ1, OUTPUT);
  pinMode(pinLQ0, OUTPUT);

  pinMode(pinRQ3, OUTPUT);
  pinMode(pinRQ2, OUTPUT);
  pinMode(pinRQ1, OUTPUT);
  pinMode(pinRQ0, OUTPUT);

  pinMode(pinLdir, OUTPUT);
  pinMode(pinRdir, OUTPUT);

  // initialize output pins.
  digitalWrite(pinLQ3, LOW);
  digitalWrite(pinLQ2, LOW);
  digitalWrite(pinLQ1, LOW);
  digitalWrite(pinLQ0, LOW);
  digitalWrite(pinRQ3, LOW);
  digitalWrite(pinRQ2, LOW);
  digitalWrite(pinRQ1, LOW);
  digitalWrite(pinRQ0, LOW);
  digitalWrite(pinLdir, LOW);        // HIGH: move forward
  digitalWrite(pinRdir, LOW);        // LOW:  move backward
}

void fullforward() {
  digitalWrite(pinLdir, HIGH);
  digitalWrite(pinRdir, HIGH);
  Lfullforwardsp();
  Rfullforwardsp();

}
void halfforward() {
  digitalWrite(pinLdir, HIGH);
  digitalWrite(pinRdir, HIGH);
  Lhalfforwardsp();
  Rhalfforwardsp();

}

void halfbackward() {
  digitalWrite(pinLdir, LOW);
  digitalWrite(pinRdir, LOW);
  Lfullforwardsp();
  Rfullforwardsp();

}

void left() {
  digitalWrite(pinLdir, LOW);
  digitalWrite(pinRdir, HIGH);
  Lstopsp();
  Rhalfforwardsp();
}

void right() {
  digitalWrite(pinLdir, HIGH);
  digitalWrite(pinRdir, LOW);
  Rstopsp();
  Lhalfforwardsp();
}

void hardleft() {
  digitalWrite(pinLdir, LOW);
  digitalWrite(pinRdir, HIGH);
  Lhalfforwardsp();
  Rhalfforwardsp();

}

void hardright() {
  digitalWrite(pinLdir, HIGH);
  digitalWrite(pinRdir, LOW);
  Rhalfforwardsp();
  Lhalfforwardsp();

}

void stopsp() {
  digitalWrite(pinLdir, HIGH);
  digitalWrite(pinRdir, HIGH);
  Lstopsp();
  Rstopsp();
}

void turn(){
    if ((i == 1)||(i == 2)){
      hardleft();
    }
    
    if(i == 3){
      hardright();
    }
    

}

void normal() {
  if (L_Sen && !M_Sen && R_Sen) { //forward
         fullforward();
      }
    
      if (!L_Sen && !M_Sen && R_Sen) { //hardleft
         hardleft();
    
      }
    
      if (L_Sen && !M_Sen && !R_Sen) { //hardright
         hardright();
    
      }
      if (!L_Sen && M_Sen && R_Sen) {  //left
         hardleft();
      }
      if (L_Sen && M_Sen && !R_Sen) {  //right
         hardright();
      }
    
     if (!L_Sen && ! M_Sen && !R_Sen){
        halfforward();
     }


     if (!L_Sen  && M_Sen && !R_Sen  ) {   //testing 
        i += 1 ;
        turn();
        delay(250);
         
      }
      
}
// the loop function runs over and over again forever
void loop() {

  L_Sen = digitalRead(pinL_Sen);
  M_Sen = digitalRead(pinM_Sen);
  R_Sen = digitalRead(pinR_Sen);
  W_Sen = digitalRead(pinW_Sen);
      if (j == 1) {
        normal();
      }
      if (j == 2) {
        Lstopsp();
        Rstopsp();
        delay(100);
        halfbackward();
        delay(650);
        Lstopsp();
        Rstopsp();
        j++;
      }
      
      if (j == 0) {
        Lstopsp();
        Rstopsp();
      }
    if (!W_Sen) {
      j++;
      if (j == 1) {
        halfforward();
        delay(250);
      }
      delay(250);
    }

}
