bool isSelectButtonPressed();

boolean cState = LOW;//stroage for current button state
boolean lastState = LOW;//storage for last button state

void initializeLazerHarpState(){
     displayTop("LAZER HARP");
     displayBottom("Quit --->");
     bool canLight = true;
     while(!isSelectButtonPressed()){
          allLazersOn();
          bool isLight1 = isPhotocell1ActiveQuick();
          bool isLight2 = isPhotocell2ActiveQuick();
          bool isLight3 = isPhotocell3ActiveQuick();
          if(isLight1 || isLight2 || isLight3){
               if(!canLight){
                    canLight = true;
               }
               int distance = getDistance();
               if(canLight){
                    if(isLight1){
                         if(distance <= 4){
                              playTone(A,32);
                         }else{
                              playTone(B,32);
                         }
                    }else if(isLight2){
                         if(distance <= 4){
                              playTone(C,32);
                         }else{
                              playTone(D,32);
                         }
                    }else if(isLight3){
                         if(distance <= 4){
                              playTone(E,32);
                         }else{
                              playTone(F,32);
                         }
                    }
                    canLight = false;
               }

          }
     }
     launchLoadingDisplay();
}

bool isSelectButtonPressed(){
     cState = digitalRead(selectButton);
     if (cState == HIGH && lastState == LOW){//if button has just been pressed
          return true;
          delay(1);//crude form of button debouncing
    }
    lastState = cState;
    return false;
  }
