
void playTone(int note,long dur) {
          dur = dur * tempo;
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
