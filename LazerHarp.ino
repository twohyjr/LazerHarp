#include <stdio.h>
#include <stdlib.h>
#include <LiquidCrystal.h>
#include "setups/pin_setup.h"
#include "setups/randoms_setup.h"
#include "controllers/lazer_controller.h"
#include "controllers/lcd_controller.h"
#include "states/lazer_harp.h"
#include "states/twohy_says.h"
#include "states/wack_a_lazer.h"
#include "controllers/menu_controller.h"

bool displayMenu = true;

void setup() {
     initializePinSetup();
     initializeRandomNumbers();
     initializeLazerController();
}

void loop() {

     if(displayMenu){
          showMenu();
          displayMenu = false;
     }
     
    displayMenu = true;
}

