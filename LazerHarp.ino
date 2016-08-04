#include <stdio.h>
#include <stdlib.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include "utils/score_keeper.h"
#include "setups/pin_setup.h"
#include "setups/randoms_setup.h"
#include "setups/sound_setup.h"
#include "controllers/lazer_controller.h"
#include "controllers/lcd_controller.h"
#include "controllers/photocell_controller.h"
#include "controllers/sound_controller.h"
#include "controllers/ultra_sonic_controller.h"
#include "states/loading_state.h"
#include "states/lazer_harp.h"
#include "states/twohy_says.h"
#include "states/wack_a_lazer.h"
#include "states/main_menu_state.h"
#include "states/play_again_state.h"

bool displayMenu = true;
int currentState = 0;

void setup() {
     initializePinSetup();
     initializeRandomNumbers();
     initializeLazerController();
     initializeScoreKeeper();
}

// Initialize core variables

void loop() {
     if(displayMenu){
          currentState = showMenu();
          displayMenu = false;
     }

     //The game code goes on here
    if(currentState != 0){
        bool playAgain = displayPlayAgain();
    
        if(playAgain){
          clearDisplay();
          startSelection(currentState);
        }else{
          displayMenu = true;
        }
    }else{
      displayMenu = true;
    }
}

