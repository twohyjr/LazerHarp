bool displayOptions();


bool selected = false;

bool displayPlayAgain(){
     int secondsLeft = 10;
     int time_now = 0;
     allLazersOff();
     bool playAgain = false;
     while(!selected){
          if(time_now >= 50){
               time_now = 0;
               secondsLeft--;
          }else{
               time_now++;
          }
          playAgain = displayOptions();
          if(secondsLeft == 0){
               selected = true;
          }

          char str[15];
          sprintf(str, "Play Again?   %d", secondsLeft);

          displayTop(str);

     }
     selected = false;
     launchLoadingDisplay();
     return playAgain;
}

bool displayOptions(){
     displayBottom("YES           NO");
     lazerOn(1);
     lazerOn(3);

     if(isPhotocell1Active()){
          selected = true;
          return true;
     }else if(isPhotocell3Active()){
          selected = true;
          return false;
     }

     return false;
}
