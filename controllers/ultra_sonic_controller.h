int dur, distance;

int getDistance(){
     digitalWrite(trigPin, HIGH);      // start of trigger sequence
     delayMicroseconds(1000);          // delay 1ms
     digitalWrite(trigPin, LOW);       // complete trigger sequence
     dur = pulseIn(echoPin, HIGH);  // see: http://arduino.cc/en/Reference/pulseIn
     distance = (dur/2) / 29.1;  // calculate distance from time
     if (distance >= 200 || distance <= 0){  // remove out-of-bounds readings
         displayBottom("Out Of Range");
       }
     return distance;
}
