int photocellReading1;
int photocellReading2;
int photocellReading3;

int threshold = 300;

bool isPhotocell1Active(){
     bool photocell1IsActive = false;
     bool isActive = false;
     photocellReading1 = analogRead(photocell1);
     if(photocellReading1 < threshold){
          photocell1IsActive = true;
     }
     delay(10);
     while(photocell1IsActive){
          photocellReading1 = analogRead(photocell1);
          if(photocellReading1 > threshold){
               photocell1IsActive = true;
               return true;
          }
     }
     return false;
}

bool isPhotocell2Active(){
     bool photocell2IsActive = false;
     bool isActive = false;
     photocellReading2 = analogRead(photocell2);
     if(photocellReading2 < threshold){
          photocell2IsActive = true;
     }
     delay(10);
     while(photocell2IsActive){
          photocellReading2 = analogRead(photocell2);
          if(photocellReading2 > threshold){
               photocell2IsActive = true;
               return true;
          }
     }
     return false;
}

bool isPhotocell3Active(){
     bool photocell3IsActive = false;
     bool isActive = false;
     photocellReading3 = analogRead(photocell3);
     if(photocellReading3 < threshold){
          photocell3IsActive = true;
     }
     delay(10);
     while(photocell3IsActive){
          photocellReading3 = analogRead(photocell3);
          if(photocellReading3 > threshold){
               photocell3IsActive = true;
               return true;
          }
     }
     return false;
}

bool isPhotocell1ActiveQuick(){
     photocellReading1 = analogRead(photocell1);
     return photocellReading1 < threshold;
}

bool isPhotocell2ActiveQuick(){
     photocellReading2 = analogRead(photocell2);
     return photocellReading2 < threshold;
}

bool isPhotocell3ActiveQuick(){
     photocellReading3 = analogRead(photocell3);
     return photocellReading3 < threshold;
}
