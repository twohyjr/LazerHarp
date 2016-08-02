int photocellReading1;
int photocellReading2;
int photocellReading3;

int threshold = 300;

bool isPhotocell1Active(){
     photocellReading1 = analogRead(photocell1);
     return photocellReading1 < threshold;
}

bool isPhotocell2Active(){
     photocellReading2 = analogRead(photocell2);
     return photocellReading2 < threshold;
}

bool isPhotocell3Active(){
     photocellReading3 = analogRead(photocell3);
     return photocellReading3 < threshold;
}
