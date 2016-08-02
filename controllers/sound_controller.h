
void playTone(int note,long dur) {
  long elapsed_time = 0;
  if (note > 0) { // if this isn't a Rest beat, while the tone has
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < dur) {

      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(note / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(note / 2);

      // Keep track of how long we pulsed
      elapsed_time += (note);
    }
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < 100; j++) { // See NOTE on rest_count
      delayMicroseconds(dur);
    }
  }
}

void playTwohySaysIntro(){
     int melody[] = {  A,  A,  A,  A,  A,   E,  C,  C,  A,  A, G, F };
     int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 32 };
     int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.
     for (int i=0; i<MAX_COUNT; i++) {
       tone_ = melody[i];
       beat = beats[i];

       duration = beat * tempo; // Set up timing

       playTone(tone_,duration);
       // A pause between notes...
       delayMicroseconds(pause);
     }
}

void playTwohySaysHighScore(){
     int melody[] = {Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, C, G, Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, G, Bb, G, F, D, F, D, G, F, D, C, Bb, G, Bb, C, C1, C, Bb, F, D, Bb, G, F, D, C, Bb, D, C, Bb, G};
     int beats[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};

     int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.
     for (int i=0; i<MAX_COUNT; i++) {
       tone_ = melody[i];
       beat = beats[i]*2;

       duration = beat * tempo; // Set up timing

       playTone(tone_,duration);
       // A pause between notes...
       delayMicroseconds(pause);
     }
}
