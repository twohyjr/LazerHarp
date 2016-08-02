bool isSelectButtonPressed();

boolean cState = LOW;//stroage for current button state
boolean lastState = LOW;//storage for last button state

void initializeLazerHarpState(){
     displayTop("LAZER HARP");
     displayBottom("Quit --->");
     while(!isSelectButtonPressed()){
          allLazersOn();
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
