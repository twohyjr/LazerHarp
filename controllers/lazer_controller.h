//#####################################################

//------ Instatiate Methods Here -----
void createLazerArray();
void createLazersOnArray();
void lazerOn();
void lazerOff();
void allLazersOn();
void allLazersOff();

//#####################################################

int lazers[3];
bool lazersOn[3];

void initializeLazerController(){
     createLazerArray();
     createLazersOnArray();
}

void createLazerArray(){
     lazers[0] = lazer1;
     lazers[1] = lazer2;
     lazers[2] = lazer3;
}

void createLazersOnArray(){
     for(int i = 0; i < sizeof(lazersOn); i++){
          lazersOn[i] = false;
     }
}

void lazerOn(int whichLazer){
     if(lazersOn[whichLazer - 1] == false){
          digitalWrite(lazers[whichLazer - 1],HIGH);
     }
}

void lazerOff(int whichLazer){
     if(lazersOn[whichLazer - 1] == true){
          digitalWrite(lazers[whichLazer - 1],LOW);
     }
}

void allLazersOn(){
     for(int i = 0; i < sizeof(lazers); i++){
          digitalWrite(lazers[i], HIGH);
     }
}

void allLazersOff(){
     for(int i = 0; i < sizeof(lazers); i++){
          digitalWrite(lazers[i], LOW);
     }
}
