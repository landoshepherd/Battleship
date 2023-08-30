//
//  main.cpp
//  Battleship
//
//  Created by Lando Shepherd on 12/6/19.
//  Copyright © 2019 Lando Shepherd. All rights reserved.
//

#include <iostream>
#include <string>

#include "src/engine.hpp"

void GameSetup(std::shared_ptr<Engine> game, std::shared_ptr<Player> human, std::shared_ptr<Player> computer){
    std::cout << "Setting up board...";
    BSUtilities::LoadingAnimation();
    std::cout << std::endl;
    game->BuildGameBoard();
    game->DeployComputerVessels();
    game->DeployHumanVessels();
}

void MainMenu(std::shared_ptr<Engine> game, char& action){
    std::string user_input;
    //BSUtilities::ClearScreen();
    game->PrintMainMenu();

    while(true){
        std::getline(std::cin, user_input);
        if(BSValidator::validateMainMenu(user_input)){
            break;
        }
    }
    action = toupper(user_input[0]);
}

int main() {
    std::shared_ptr<Player> human(new Player);
    std::shared_ptr<Player> computer(new Player);
    std::shared_ptr<Engine> battleship(new Engine(human, computer));

    char action;

    while(true) {
        MainMenu(battleship, action);
        switch (action) {
            case 'A':{

                GameSetup(battleship, human, computer);

                while (true) {
                    battleship->HumanTurnSequence(action);
                    if (toupper(action) == 'Q') {
                        std::cout << "Thanks for playing!" << std::endl;
                        break;
                    }

                    if (battleship->CheckForGameWinner() == 'H') {
                        battleship->UpdateGeneralReport("You win!");
                        break;
                    }
                    else{
                        battleship->ComputerAttack();
                        if (battleship->CheckForGameWinner() == 'C') {
                            battleship->UpdateGeneralReport("You've been defeated.");
                            break;
                        }
                    }
                }
                break;
            }
            case 'B':{
                battleship->ActivateHowToMenu();
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
