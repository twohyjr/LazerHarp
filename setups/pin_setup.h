//#####################################################

//------ Instatiate Methods Here -----
void setupLCD();
void setupLazerPins();
void setupUltraSonicSensors();
void setupSoundOutput();
void setupMenu();

//------ Setup Lazers --------
int lazer1 = 2;
int lazer2 = 3;
int lazer3 = 4;

//------ Setup Photocells ------
int photocell1 = A0;
int photocell2 = A1;
int photocell3 = A2;

//------ SetupLCD ----------
int d7 = 9;
int d6 = 8;
int d5 = 7;
int d4 = 6;
int rs = 13;
int enable = 10;
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

//------- Setup SoundOutput -------
int speakerOut = 53;

// ------ Setup UltraSonicSensors ----
int trigPin = 12; // blue
int echoPin = 11; // green

//------- Setup Menu Stuff ----------
int selectButton = 5;
int menuDial = A4;

//#####################################################

void initializePinSetup(){
     Serial.begin(9600);
     setupLCD();
     setupLazerPins();
     setupUltraSonicSensors();
     setupSoundOutput();
     setupMenu();
}

void setupLCD(){
     lcd.begin(16,2);
}

void setupLazerPins(){
     pinMode(lazer1,OUTPUT);
     pinMode(lazer2,OUTPUT);
     pinMode(lazer3,OUTPUT);
}

void setupUltraSonicSensors(){
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);
}

void setupSoundOutput(){
     pinMode(speakerOut,OUTPUT);
}

void setupMenu(){
     pinMode(selectButton, OUTPUT);
}
