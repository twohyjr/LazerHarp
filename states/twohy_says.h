void initialize();
void addNewNote();
void doTwohySaysIntro();
void playTwohySaysHighScore(int roundNumber);
void doTouchToStart();
void doCountDown();
void runGame();
void displayRound();
int getNote(int number);
int selectNote(int number);
bool doLazerSelect(int lazerNumber);
void doLazerTone(int lazer);
void doGameOver();
bool checkHighScore();
void loadNameSave();
char selectLetter(int input);

int allLazerNumbers[1000];

int roundNumber = 1;

int whichLazer = 0;

bool gameOver = false;

void initializeTwohySaysState(){
     clearDisplay();
     allLazersOn();
     displayTop("  TWOHY SAYS!!");
     char str[16];

     char name[4];
     char score[1];
     int x = getHighScore();
     eeprom_read_string(1, name, 4);
     sprintf(str, "High: %d by %s",x, name);
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
     gameOver = false;
     while(!gameOver){
          char str[15];
          sprintf(str, "Round: %d / %d", roundNumber, getHighScore());
          displayBottom(str);
          delay(500);
          allLazersOff();
          //Play the notes that are stored
          for(int i = 0; i < roundNumber; i++){
               int whichLazer = allLazerNumbers[i];
               lazerOn(whichLazer);
               doLazerTone(whichLazer);
               allLazersOff();
               delay(300);
          }
          allLazersOn();
          delay(100);

          //The users turn to try
          for(int j = 0; j < roundNumber; j++){
               bool started = false;
               int whichLazer = allLazerNumbers[j];
               while(!started){
                    bool is1Active = isPhotocell1Active();
                    bool is2Active = isPhotocell2Active();
                    bool is3Active = isPhotocell3Active();

                    int selectedLazer = 0;
                    bool correct = false;
                    if(is1Active || is2Active || is3Active){
                         if(is1Active && whichLazer == 1){
                              selectedLazer = 1;
                              correct = true;
                         }else if(is2Active && whichLazer == 2){
                              selectedLazer = 2;
                              correct = true;
                         }else if(is3Active && whichLazer == 3){
                              selectedLazer = 3;
                              correct = true;
                         }else if(is1Active && whichLazer != 1){
                              selectedLazer = 1;
                              correct = false;
                         }else if(is2Active && whichLazer != 2){
                              selectedLazer = 2;
                              correct = false;
                         }else if(is3Active && whichLazer != 3){
                              selectedLazer = 3;
                              correct = false;
                         }

                         doLazerTone(selectedLazer);
                         started = true;
                         if(!correct){
                              bool isHigh = checkHighScore();
                              if(isHigh){
                                   playTwohySaysHighScore(roundNumber);
                                   loadNameSave();
                              }else{
                                   displayBottom("   GAME OVER");
                                   playTone(G,100);
                                   delay(2000);
                                   char str[15];
                                   sprintf(str, " Your Score: %d ", roundNumber);
                                   displayBottom(str);
                                   delay(2000);
                              }

                              gameOver = true;
                              roundNumber = 0;

                              break;
                         }
                    }
                    delay(200);
               }
               if(gameOver == true){
                    break;
               }
          }
          allLazersOff();
          roundNumber++;
          addNewNote();
          delay(100);
     }

}

bool checkHighScore(){
     if(roundNumber > getHighScore()){

          storeHighScore(roundNumber);

          return true;
     }else{
          return false;
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

void playTwohySaysHighScore(int roundNumber){
     displayBottom(" New High Score");
     int melody[] = {Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, C, G, Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, F, D, F, D, G, F, D, C, Bb, G, Bb, C, C1, C, Bb, F, D, Bb, G, F, D, C, Bb, D, C, Bb, G};
     int beats[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
     int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.
     for (int i=0; i<MAX_COUNT; i++) {
          allLazersOff();
            int lazer = rand() % 3 + 1;
            lazerOn(lazer);
            tone_ = melody[i];
            beat = beats[i];
            if(i >= MAX_COUNT/2){
                 char str[15];
                 sprintf(str, "   New High: %d ", roundNumber);
                 displayBottom(str);
            }
          //   duration = beat * tempo; // Set up timing

            playTone(tone_,beat);
            // A pause between notes...
            delayMicroseconds(pause);
     }
}


void loadNameSave(){
     int nameIndex = 0;

     char* name = "AAA";
     allLazersOff();
     lazerOn(2);

     bool nameIsCreated = false;
     while(!nameIsCreated){
          int input = analogRead(menuDial);
          char letter = selectLetter(input);
          name[nameIndex] = letter;
          displayTop("Enter Your Name!");
          displayBottom(name);

          if(isSelectButtonFullyPressed()){
               name[nameIndex] = letter;
               nameIndex++;
               prevState = 0;
          }

          if(nameIndex == 3){
               nameIsCreated = true;

               eeprom_write_string(1, name);
          }
     }


}

char selectLetter(int input){
     char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9'};
     int totalChars = sizeof(letters);

     int split = (int)floor(1023/totalChars);
     int whichChar = (int)floor(input/split);
     int i = (int)floor(whichChar) - 1;
     if(i < 0){
          i = 0;
     }
     char letter = letters[i];
     char myStg[10];
     sprintf(myStg, "%c", letter);

     return myStg[0];
}


//################################################################
