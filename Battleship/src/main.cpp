//
//  main.cpp
//  Battleship
//
//  Created by Lando Shepherd on 12/6/19.
//  Copyright © 2019 Lando Shepherd. All rights reserved.
//

#include <iostream>
#include <memory>
#include <string>

#include "engine.hpp"

int main() {
    //Player* human = new Player;
    //Player* computer = new Player;
    std::unique_ptr<engine::Engine> gameEngine(new engine::Engine);

    while(true)
	{
        char action;
		//Setup engine internals.
		gameEngine->initialize();

		gameEngine->mainMenu(action);

        switch (action)
		{
            case 'A':{
				//Start the game!
				gameEngine->startGame(action);
                break;
            }
            case 'B':{
                gameEngine->activateHowToMenu();
                break;
            }
            case 'Q':{
                std::cout << "Thanks for playing!" << std::endl;
                break;
            }
        }
        if(toupper(action) == 'Q'){
            break;
        }
    }
    return 0;
}
