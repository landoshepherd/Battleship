//
//  bs_validator.hpp
//  Battleship
//
//  Created by Lando Shepherd on 11/13/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#ifndef BS_Utilities_hpp
#define BS_Utilities_hpp

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

class BSValidator{
private:
public:
    static bool validateMainMenu(std::string& input);
    static bool validateHowToMenuSelection(std::string& input);
    static bool validateVesselSelection(std::string& selection);
    static bool isValidInteger(std::string& input);
    static bool validateXCoordinate(std::string& xCoor);
    static bool validateYCoordinate(std::string& yCoor);
    static bool validateDashboardSelection(std::string& selection);
};

class BSUtilities{
private:
public:
    static void LoadingAnimation();
    static void ClearScreen(); //Will be modified to be cross platform.
};
#endif /* bs_validator_hpp */
