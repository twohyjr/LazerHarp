//#####################################################
//------ Instatiate Methods Here -----
int getRandomLazer();

//#####################################################


void initializeRandomNumbers(){
     randomSeed(analogRead(0));
}

int getRandomLazer(){
     return random(1, 4);
}
