int prevState = 0;
bool isSelectButtonFullyPressed(){

     int isPressed = digitalRead(selectButton);

     if(isPressed == 0 && prevState == 1){

          return true;

     }else if(isPressed == 1 && prevState == 0){

          prevState = 1;
          return false;

     }else{
          prevState = isPressed;
          return false;
     }
}
