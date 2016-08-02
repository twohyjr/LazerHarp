void launchLoadingDisplay(){
     allLazersOff();
     clearDisplay();
     displayTop("Loading.");
     lazerOn(1);
     delay(300);
     allLazersOff();
     lazerOn(2);
     displayTop("Loading..");
     delay(300);
     displayTop("Loading...");
     allLazersOff();
     lazerOn(3);
     delay(300);
}
