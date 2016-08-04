void initialize();
void addNewNote();
void doTwohySaysIntro();
void doTouchToStart();
void doCountDown();
void runGame();
void displayRound();
int getNote(int number);
int selectNote(int number);
bool doLazerSelect(int lazerNumber);
void doLazerTone(int lazer);

int allLazerNumbers[1000];

int roundNumber = 1;

int whichLazer = 0;

bool gameOver = false;

void initializeTwohySaysState(){
     clearDisplay();
     allLazersOn();
     displayTop("  TWOHY SAYS!!");
     char str[15];
     sprintf(str, "High: %d ", getHighScore());
     initialize();
     displayBottom(str);
     doTwohySaysIntro();
     allLazersOff();
     doTouchToStart();
     doCountDown();
     runGame();
}

void initialize(){
     randomSeed(analogRead(0));
     addNewNote();
}

void addNewNote(){
     whichLazer = random(1, 4);
     allLazerNumbers[roundNumber - 1] = whichLazer;
}


void doTouchToStart(){
     bool started = false;
     displayBottom(" Touch To Start");
     allLazersOn();
     delay(100);
     while(!started){
          if(isPhotocell1ActiveQuick() || isPhotocell2ActiveQuick() || isPhotocell3ActiveQuick()){
               started = true;
          }
     }
}

bool doLazerSelect(int lazerNumber){
     displayBottom(lazerNumber);
     allLazersOn();
     delay(2000);
     return true;
}

void doCountDown(){
     allLazersOff();
     displayBottom(" 3");
     playTone(G,8);
     lazerOn(1);
     delay(1000);
     displayBottom(" 3   2");
     playTone(G,8);
     lazerOn(2);
     delay(1000);
     displayBottom(" 3   2   1");
     playTone(G,8);
     lazerOn(3);
     delay(1000);
     displayBottom(" 3   2   1   GO");
     playTone(A,36);
     allLazersOff();
}

void runGame(){

     while(!gameOver){
          char str[15];
          sprintf(str, "Round: %d / %d", roundNumber, getHighScore());
          displayBottom(str);
          delay(500);
          allLazersOff();
          for(int i = 0; i < roundNumber; i++){
               int whichLazer = allLazerNumbers[i];
               lazerOn(whichLazer);
               doLazerTone(whichLazer);
               allLazersOff();
               delay(300);
          }
          allLazersOn();
          delay(100);

          for(int j = 0; j < roundNumber; j++){
               bool started = false;
               int whichLazer = allLazerNumbers[j];
               while(!started){
                    if(isPhotocell1Active() || isPhotocell2Active() || isPhotocell3Active()){
                         doLazerTone(whichLazer);
                         started = true;
                    }
                    delay(200);
               }
          }
          allLazersOff();
          roundNumber++;
          addNewNote();
          delay(100);
     }

}

void doLazerTone(int lazer){
     lazerOn(lazer);
     int note = selectNote(lazer);
     playTone(note,32);
}

int selectNote(int number){
  int note = 0;
  switch(number) {

   case 1 :
      note = A;
      break; /* optional */

   case 2  :
      note = C;
      break; /* optional */

   case 3 :
      note = E;
      break; /* optional */
  }
  return note;
}


void displayRound(){
     char str[15];
     sprintf(str, "Round: %d ", roundNumber);
     displayBottom(str);
}

int getNote(int number){
  int note = 0;
  switch(number) {
   case 1 :
      note = A;
      break; /* optional */
   case 2  :
      note = C;
      break; /* optional */
   case 3 :
      note = E;
      break; /* optional */
  }
  return note;
}

//################### MUSIC ########################

void doTwohySaysIntro(){
     int melody[] = {  A,  A,  A,  A,  A,   E,  C,  C,  A,  A, G, F };
     int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 32 };
     int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.
     for (int i=0; i<MAX_COUNT; i++) {
          allLazersOff();
            int lazer = rand() % 3 + 1;
            lazerOn(lazer);
            tone_ = melody[i];
            beat = beats[i];

          //   duration = beat * tempo; // Set up timing

            playTone(tone_,beat);
            // A pause between notes...
            delayMicroseconds(pause);
     }
}

void playTwohySaysHighScore(){
     int melody[] = {Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, C, G, Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, F, D, F, D, G, F, D, C, Bb, G, Bb, C, C1, C, Bb, F, D, Bb, G, F, D, C, Bb, D, C, Bb, G};
     int beats[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};

     int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.
     for (int i=0; i<MAX_COUNT; i++) {
       tone_ = melody[i];
       beat = beats[i]*2;

       duration = beat * tempo; // Set up timing

       playTone(tone_,duration);
       // A pause between notes...
       delayMicroseconds(pause);
     }
}


//################################################################
