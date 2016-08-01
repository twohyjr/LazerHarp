
//#####################################################
//------ Instatiate Methods Here -----
void displayTop(char text[]);
void clearDisplay();
//#####################################################

void displayTop(char text[]){
     int numSpaces = 16 - sizeof(text);
     if(numSpaces < 0){
          numSpaces = 0;
     }
     lcd.setCursor(0,0);
     lcd.print(text);
     for(int i = 0; i < numSpaces; i++){
          lcd.print(" ");
     }
}

void displayBottom(char text[]){
     int numSpaces = 16 - sizeof(text);
     if(numSpaces < 0){
          numSpaces = 0;
     }
     lcd.setCursor(0,1);
     lcd.print(text);
     for(int i = 0; i < numSpaces; i++){
          lcd.print(" ");
     }
}

void clearDisplay(){
     lcd.clear();
}
