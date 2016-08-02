void startSelection(int currentSelection);

char *menuOptions[] = {"Lazer Harp ->", "<- Twohy Says!"};

int numberOfOptions = sizeof(menuOptions);
bool isSelected = false;

int showMenu(){
     clearDisplay();
     allLazersOff();
     displayTop("Select A Mode!");
     int currentSelection = 0;
     char* textToDisplay = "";
     while(!isSelected){
          int currentInput = analogRead(menuDial);

          if(currentInput <= 1024/numberOfOptions){
               displayBottom(menuOptions[0]);
               currentSelection = 0;
          }else{
               displayBottom(menuOptions[1]);
               currentSelection = 1;
          }

          if(digitalRead(selectButton) == HIGH){
               isSelected = true;
          }
     }
     isSelected = false;
     launchLoadingDisplay();
     startSelection(currentSelection);
     return currentSelection;
}

void startSelection(int currentSelection){
     if(currentSelection == 0){
          initializeLazerHarpState();
     }else if(currentSelection == 1){
          initializeTwohySaysState();
     }
     isSelected = false;
}

bool isMenuButtonSelected(){
     return false;
}
