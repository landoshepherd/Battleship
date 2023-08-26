//
//  bs_validator.cpp
//  Battleship
//
//  Created by Lando Shepherd on 11/13/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#include "bs_utilities.hpp"

const std::string ERROR_MESSAGE = "Error: Invalid entry. Try again.";

bool BSValidator::validateMainMenu(std::string input){
    auto numOfChar = input.size();
    std::vector<char> mainMenuChoices = {'A', 'B', 'Q'};
    
    //Check if number of characters in string. Should be 1 for one character.
    if(numOfChar == 1) {
        for(auto i = 0; i < mainMenuChoices.size(); i++){
            if(toupper(input[0]) == mainMenuChoices[i]){
                return true;
            }
        }
        std::cout << ERROR_MESSAGE << std::endl;
        return false;
    }
    else{
        std::cout << ERROR_MESSAGE << std::endl;
        return false;
    }
}


bool BSValidator::validateHowToMenuSelection(std::string input){
    auto numOfChar = input.size();
    if(numOfChar == 1 && toupper(input[0]) == 'R'){
        return true;
    }
    std::cout << ERROR_MESSAGE << std::endl;
    return false;
}

bool BSValidator::validateVesselSelection(std::string selection){
    std::vector<char> vesselTypes = {'A', 'B', 'C', 'D', 'E'};
    if (selection.size() == 1) {
        for(auto i = 0; i < vesselTypes.size(); i++){
            if(toupper(selection[0]) == vesselTypes[i]){return true;}
        }
        std::cout << ERROR_MESSAGE << std::endl;
        return false;
    }
    else{
        std::cout << ERROR_MESSAGE << std::endl;
        return false;
    }
}


bool BSValidator::validateXCoordinate(std::string xCoor){
    try {
        auto validXCoor = std::stoi(xCoor);
        if(validXCoor >= 1 && validXCoor <= 10){
            return true;
        }
        else{
            std::cout << ERROR_MESSAGE << std::endl;
            return false;
        }
    }
    catch (std::invalid_argument& error) {
        std::cout << ERROR_MESSAGE << std::endl;
        return false;
    }
    catch(std::out_of_range){
        std::cout << ERROR_MESSAGE << std::endl;
        return false;
    }
}


bool BSValidator::validateYCoordinate(std::string yCoor){
    try {
        auto validYCoor = std::stoi(yCoor);
        if(validYCoor >= 1 && validYCoor <= 6){
            return true;
        }
        else{
            std::cout << ERROR_MESSAGE << std::endl;
            return false;
        }
    }
    catch (std::invalid_argument& error) {
        std::cout << ERROR_MESSAGE << std::endl;
        return false;
    }
    catch(std::out_of_range){
        std::cout << ERROR_MESSAGE << std::endl;
        return false;
    }
}


bool BSValidator::validateDashboardSelection(std::string selection){
    std::vector<char> dashboardChoices = {'L', 'S', 'Q'};
    if (selection.size() == 1) {
        for(auto i = 0; i < dashboardChoices.size(); i++){
            if(toupper(selection[0]) == dashboardChoices[i]){return true;}
        }
        std::cout << ERROR_MESSAGE << std::endl;
        return false;
    }
    else{
        std::cout << ERROR_MESSAGE << std::endl;
        return false;
    }
}

void BSUtilities::LoadingAnimation(){
    for (int i = 0; i < 50; i++) {
        usleep(10000);
        std::cout << "\b\\" << std::flush;
        usleep(10000);
        std::cout << "\b|" << std::flush;
        usleep(10000);
        std::cout << "\b/" << std::flush;
        usleep(10000);
        std::cout << "\b-" << std::flush;
    }
    std::cout << "\b" << std::flush;
}


void BSUtilities::ClearScreen(){
    std::cout << "\033[2J\033[1;1H";
}
