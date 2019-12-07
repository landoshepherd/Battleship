//
//  main.cpp
//  Battleship
//
//  Created by Lando Shepherd on 11/13/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#include <iostream>
#include <string>

#include "Game_Components.hpp"

void GameSetup(BSComponent* game, Player* human, Player* computer){
    std::cout << "Setting up board...";
    BSUtilities::LoadingAnimation();
    std::cout << std::endl;
    game->BuildGameBoard();
    game->DeployComputerVessels();
    game->DeployHumanVessels();
}

void MainMenu(BSComponent* game, char* action){
    std::string user_input;
    BSUtilities::ClearScreen();
    game->PrintMainMenu();
    
    while(true){
        std::getline(std::cin, user_input);
        if(BSValidator::validateMainMenu(user_input)){
            break;
        }
    }
    *action = toupper(user_input[0]);
}

int main() {
    Player* human = new Player;
    Player* computer = new Player;
    BSComponent* battleship = nullptr;
    battleship = new BSComponent(human, computer);
    char action;
    
    while(true) {
        MainMenu(battleship, &action);
        switch (action) {
            case 'A':{
                
                GameSetup(battleship, human, computer);
                
                while (true) {
                    battleship->HumanTurnSequence(&action);
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
