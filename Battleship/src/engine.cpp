//
//  Game_Components.cpp
//  Battleship
//
//  Created by Lando Shepherd on 11/13/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#include "engine.hpp"

Engine::Engine(Player* player1, Player* player2){
    srand(unsigned(time(0)));
    human = player1;
    computer = player2;
    
    game_board = new char*[GBROW];
    for(int i = 0; i < GBROW; i++){
        game_board[i] = new char [GBCOL];
    }
    
    for(int i = 0; i < GBROW; i++){
        for(int j = 0; j < GBCOL; j++){
            game_board[i][j] = ' ';
        }
    }
    
    human_report = "Nothing to report.";
}

//Displays "Battleship" sign.
void Engine::DisplayMarquee_(){
    system("clear");
    BigSign bigSign;
    std::cout << bigSign.signString << std::endl;
}


void Engine::PrintMainMenu(){
    DisplayMarquee_();
    std::cout << "[A] Play Battleship\n";
    std::cout << "[B] How to play\n";
    std::cout << "[Q] Quit\n";
#if DEBUG_MODE
    std::cout << "\n\n";
    std::cout << "DEBUG MODE" << std::endl;
#endif
}


/******************************************************
 Responsibility: Main menu controls. Prints the main
 menu and prompts the user to select to start the game,
 view game instructions or to quit the game.
 
 Return: Char value of the user's choice.
 ******************************************************/
char Engine::MainMenu(){
    std::string user_input;
    PrintMainMenu();
    
    while(true){
        std::getline(std::cin, user_input);
        if(BSValidator::validateMainMenu(user_input)){
            break;
        }
    }
    return toupper(user_input[0]);
}



/******************************************************
 Responsibility: Populates the 2-dimensional array that
 is the game board where the vessels of both players
 will be displayed.
 
 Return: Nothing
 ******************************************************/
void Engine::BuildGameBoard(){
    for (int i = 0; i < GBROW; i++) {
        for(int j = 0; j < GBCOL; j++){
            if(i == 0){
                if(j >= 0 && j < 12){
                    game_board[i][j] = '#';
                }
                if(j >= 14 && j < 26){
                    game_board[i][j] = '#';
                }
            }
            if(i == 7)
            {
                if(j >= 0 && j < 12){
                    game_board[i][j] = '#';
                }
                if(j >= 14 && j < 25){
                    game_board[i][j] = '#';
                }
            }
            if(j == 0){
                if(i >= 0 && i < 8){
                    game_board[i][j] = '#';
                }
            }
            if(j == 11){
                if(i >= 0 && i < 8){
                    game_board[i][j] = '#';
                }
            }
            if(j == 14){
                if(i >= 0 && i < 8){
                    game_board[i][j] = '#';
                }
            }
            if(j == 25){
                if(i >= 0 && i < 8){
                    game_board[i][j] = '#';
                }
            }
        }
    }
}

void Engine::PrintGameBoard(){
    std::cout << std::endl;
    for (auto i = 0; i < GBROW; i++) {
        for(int j = 0; j < GBCOL; j++){
            std::cout << game_board[i][j];
        }
        std::cout << std::endl;
    }
}

/******************************************************
 Responsibility: Displays the attack points, current
 defense points and stealth indicator.
 
 Return: Nothing
 ******************************************************/
void Engine::DisplayVessels(){
    std::vector<Vessel*> vessels = human->GetVessels();
    char letter = 65;
    for (int i = 0; i < vessels.size(); i++){
        std::cout << "[" << letter << "] " << vessels[i]->GetVesselName() << "\t"
        << vessels[i]->GetAttackPoints() << "\t"
        << vessels[i]->GetDefensePoints() << "%"
        << std::right << std::setw(8)
        << vessels[i]->GetStealthIndicator() << std::endl;
        letter++;
    }
}

/******************************************************
 Responsibility: This function clears the messaging
 system for after every turn so that new messages may
 appear.
 
 Return: Nothing
 ******************************************************/
void Engine::ClearReports(){
    human_report.clear();
    computer_report.clear();
    general_report.clear();
}


void Engine::DisplayDashboard(){
    BSUtilities::ClearScreen();
    PrintGameBoard();
    std::cout << std::right << std::setw(9) << "You\t" << "Computer" << std::endl;
    std::cout << std::endl;
    std::cout << std::left << std::setw(13) << "Vessels";
    std::cout << std::left << std::setw(9) << "Atk Pts";
    std::cout << std::left << std::setw(9) << "Shields";
    std::cout << "Stealth\n";
    std::cout << "****************************************\n";
    DisplayVessels();
    std::cout << std::endl;
    std::cout << "AI Assistant: " + human_report + "\n";
    std::cout << general_report << "\n";
    std::cout << computer_report << "\n\n";
    std::cout << "Select your next action from the choices below:" << std::endl;
    std::cout << "[L] Launch Attack\t";
    std::cout << "[S] Activate Stealth\t";
    std::cout << "[Q] Quit" << std::endl;
    
    ClearReports();
}


/******************************************************
 Responsibility: The primary job of this function is to
 check if the space that the user is deploying a vessel
 to is available.
 
 Return: True if space is available and false if not.
 ******************************************************/
bool Engine::SpaceAvailable(std::vector<Vessel*> vessels, int x, int y){
    int usedX, usedY;
    if(vessels.size() == 0){
        return true;
    }
    for (int i = 0; i < vessels.size(); i++) {
        usedX = vessels[i]->GetXCoor();
        usedY = vessels[i]->GetYCoor();
        if(usedX == x && usedY == y){
            return false;
        }
    }
    return true;
}


/******************************************************
 Responsibility: Deploys the computer vessels to the
 game board by randomly assigning coordinates to it's
 vessels.
 
 Return: Nothing
 ******************************************************/
void Engine::DeployComputerVessels(){
    int x = 0,y = 0;
    for (int i = 0; i < 5; i++) {
        while(true) {
            x = rand() % 10 + 1;
            y = rand() % 6 + 1;
            bool valid_space = SpaceAvailable(computer->GetVessels(), x, y);
            if(valid_space){
                computer->GetVessels()[i]->UpdateXCoor(x);
                computer->GetVessels()[i]->UpdateYCoor(y);
                break;
            }
        };
    }
}


/******************************************************
 Responsibility: Helper function to DeployHumanVessels.
 This function takes a pointer to a vessel.
 Then prompts the user to enter a value within the
 specified range, once validated, that value is
 assigned to the x coordinate of the specified vessel.
 
 Return: Returns x coordinate as integer.
 ******************************************************/
int Engine::SetXCoorHumanVessel(Vessel* vessel){
    std::string unvalidatedX;
    int validatedX;
    while(true) {
        std::cout << "Enter X Coordinate for " +
        vessel->GetVesselName() + " within range of 1-10: ";
        std::getline(std::cin, unvalidatedX);
        std::cout << std::endl;
        if(BSValidator::validateXCoordinate(unvalidatedX) == true){
            validatedX = std::stoi(unvalidatedX);
            break;
        }
    };
    return validatedX;
}


/******************************************************
 Responsibility: Helper function to DeployHumanVessels.
 This function takes a pointer to a vessel.
 Then prompts the user to enter a value within the
 specified range, once validated, that value is
 assigned to the y coordinate of the specified vessel.
 
 Return: Returns y coordinate as integer.
 ******************************************************/
int Engine::SetYCoorHumanVessel(Vessel* vessel){
    std::string unvalidatedY;
    int validatedY;
    while(true) {
        std::cout << "Enter Y Coordinate for " +
        vessel->GetVesselName() + " within range of 1-6: ";
        std::getline(std::cin, unvalidatedY);
        std::cout << std::endl;
        if(BSValidator::validateYCoordinate(unvalidatedY) == true){
            validatedY = std::stoi(unvalidatedY);
            break;
        }
    };
    return validatedY;
}

/******************************************************
 Responsibility: Sets the coordinates to the each of
 the player's vessels by iterating through a vector of
 vessels, prompting the player to enter coordinate
 values and assigning those coordinates to each vessel.
 
 Return: Nothing
 ******************************************************/
void Engine::DeployHumanVessels(){
    int x = 0, y = 0;
    Vessel* temp_vessel_ptr = nullptr;
    
    std::cout << "Now that the stage is set, let's deploy your vessels!" << std::endl;
#if DEBUG_MODE
    std::cout << "In debug mode" << std::endl;
    int debugPoint = 1;
    for(int i = 0; i < 5; i++){
        temp_vessel_ptr = human->GetVessels()[i];
        temp_vessel_ptr->UpdateXCoor(debugPoint);
        temp_vessel_ptr->UpdateYCoor(debugPoint);
        game_board[debugPoint][debugPoint] = temp_vessel_ptr->GetSymbol();
        debugPoint++;
    }
#else
    for (int i = 0; i < 5; i++) {
        temp_vessel_ptr = human->GetVessels()[i];
        while(true){
            x = SetXCoorHumanVessel(temp_vessel_ptr);
            y = SetYCoorHumanVessel(temp_vessel_ptr);
            
            if(SpaceAvailable(human->GetVessels(), x, y)){
                temp_vessel_ptr->UpdateXCoor(x);
                temp_vessel_ptr->UpdateYCoor(y);
                game_board[y][x] = temp_vessel_ptr->GetSymbol();
                break;
            }
            std::cout << "You've already placed a vessel here. Try another space." << std::endl;
        }
    }
#endif
}



/******************************************************
 Responsibility: Determines if a vessel is destroyed
 by taking a pointer to the vessel in question and
 checking if the defense points are less than or
 equal to 0. Destroyed if less than or equal to 0 and
 false if greater than 0.
 
 Return: True if destroyed false if not destroyed.
 ******************************************************/
bool Engine::IsVesselDestroyed(Vessel* vessel){
    if(vessel->GetDefensePoints() <= 0){
        return true;
    }
    else{
        return false;
    }
}


/******************************************************
 Responsibility: Searches opponents' vessels to find
 matching set of coordinates.
 
 Return: True if matching coordinates are found and
 false if matching coordinates are not found.
 ******************************************************/
bool Engine::AttackVesselFound(int x, int y){
    //Loop through list of vessels using XY coordinates to locate a vessel.
    for (int i = 0; i < computer->GetVessels().size(); i++) {
        if(computer->GetVessels()[i]->GetXCoor() == x && computer->GetVessels()[i]->GetYCoor() == y){
            return true;
        }
    }
    return false;
}


/******************************************************
 Responsibility:
 ******************************************************/
void Engine::InitiateHumanAttack(std::string xCoordinate, std::string yCoordinate, Vessel* attack_vessel){
    Vessel* target_vessel = nullptr;
    int y = std::stoi(yCoordinate);
    int x = std::stoi(xCoordinate);
    
    
    if (AttackVesselFound(x, y)) {
        if (target_vessel->GetStealthStatus()) {
            human_report = "Attack Unsuccessful!";
            game_board[y][x+14] = 'X';
        }
        else{
            int new_defense_points = target_vessel->GetDefensePoints()
            - attack_vessel->GetAttackPoints();
            human_report = "Direct hit!";
            if (new_defense_points <= 0) {
                target_vessel->UpdateDefensePoints(0);
                human_report = "Opponent's " + target_vessel->GetVesselName()
                + " has been destroyed!";
                game_board[y][x+14] = '*';
            }
            else{
                target_vessel->UpdateDefensePoints(new_defense_points);
                human_report = "Opponent's " + target_vessel->GetVesselName()
                + " down to " + std::to_string(target_vessel->GetDefensePoints());
            }
        }
    }
    else{
        human_report = "Attack unsuccessful!";
        game_board[y][x+14] = 'X';
    }
    target_vessel = nullptr; //Sets targetVessel to nullptr as it is no longer in use.
}

/******************************************************
 Responsibility:
 ******************************************************/
char Engine::SetHumanAttackVessel(){
    std::string raw_input;
    char vesselSelection = '\0';
    bool validVesselSelection;
    Vessel* selectedVesselPtr = nullptr;
    
    while(true) {
        std::cout << "Select a vessel in your fleet to launch an attack: ";
        std::getline(std::cin,raw_input);
        validVesselSelection = BSValidator::validateVesselSelection(raw_input);
        if (validVesselSelection == true) {
            std::cout << "Valid selection" << std::endl;
            vesselSelection = toupper(raw_input[0]);
            selectedVesselPtr = GetSelectedVessel(vesselSelection);
            if (IsVesselDestroyed(selectedVesselPtr) == true) {
                std::cout << "This vessel is destroyed. Pick another one." << std::endl;
            }
            else{
                break;
            }
        }
    };
    return vesselSelection;
}

/******************************************************
 Responsibility:
 ******************************************************/
Vessel* Engine::SelectStealthVessel(){
    std::string rawInput;
    char vesselSelection = '\0';
    bool validInput = true;
    Vessel* tempVesselPtr = nullptr;
    
    while(true) {
        std::cout << "Select a vessel to go into stealth mode: ";
        std::cin >> rawInput;
        validInput = BSValidator::validateVesselSelection(rawInput);
        
        //Checks if input is valid
        if (validInput) {
            vesselSelection = toupper(rawInput[0]);
            tempVesselPtr = GetSelectedVessel(vesselSelection);
            if (IsVesselDestroyed(tempVesselPtr)) {
                std::cout << "This vessel is destroyed. Pick another one." << std::endl;
            }
            else{
                return GetSelectedVessel(vesselSelection);
            }
        }
    }
}

/******************************************************
 Responsibility:
 ******************************************************/
void Engine::SetHumanVesselToStealthMode(Vessel* vessel){
    vessel->UpdateStealthStatus(true);
    human_report = vessel->GetVesselName() + " set to stealth mode, Captain.";
}

void Engine::ActivateHumanStealthMode(){
    Vessel* selected_vessel = nullptr;
    
    if(human->GetStealthMode() || human->GetStealthCount() >= 1){
        general_report = "You currently have a vessel in stealth mode\n"
                        "or have already activated stealth mode once this game.";
    }
    else{
        selected_vessel = SelectStealthVessel();
        SetHumanVesselToStealthMode(selected_vessel);
        std::cin.clear();
        std::cin.ignore();
    }
    
    selected_vessel = nullptr;
}


/******************************************************
 Responsibility:
 ******************************************************/
void Engine::SetAttackCoordinates(std::string& x_coor, std::string& y_coor){
    bool valid_x_coordinate = false;
    bool valid_y_coordinate = false;
    std::string raw_input;
    while(true) {
        std::cout << "Enter X attack coordinate within range of 1-10: ";
        std::getline(std::cin,raw_input);
        valid_x_coordinate = BSValidator::validateXCoordinate(raw_input);
        if(valid_x_coordinate == true){
            x_coor = raw_input;
            break;
        };
    }
    
    
    while(true) {
        std::cout << "Enter Y attack coordinate within range of 1 - 6: ";
        std::getline(std::cin,raw_input);
        valid_y_coordinate = BSValidator::validateYCoordinate(raw_input);
        if(valid_y_coordinate == true){
            y_coor = raw_input;
            break;
        }
    };
}


/******************************************************
 Responsibility: Performs all routine and subroutines
 to complete a successful attack on the opponent. 
 ******************************************************/
void Engine::HumanAttack(){
    //SetHumanAttackVessel returns a character input by the user to select which vessel will be used for the attack.
    Vessel* attack_vessel = GetSelectedVessel(SetHumanAttackVessel());
    
    std::string x_coordinate;
    std::string y_coordinate;
    SetAttackCoordinates(x_coordinate, y_coordinate);
    InitiateHumanAttack(x_coordinate, y_coordinate, attack_vessel);
    attack_vessel = nullptr;
}


/******************************************************
 Responsibility:
 ******************************************************/
Vessel* Engine::SetAttackVesselForComputer(){
    bool valid_vessel = false;
    Vessel* attack_vessel = nullptr;
    while(true) {
        int random_choice = rand() % 5;
        attack_vessel = computer->GetVessels()[random_choice];
        if (attack_vessel->GetDefensePoints() == 0) {
            valid_vessel = false;
        }
        else{
            valid_vessel = true;
        }
        
        if(valid_vessel == true){
            break;
        }
    };
    return attack_vessel;
}


/******************************************************
 Responsibility:
 ******************************************************/
void Engine::InitiateComputerAttack(Vessel* attacking_vessel, int x, int y){
    std::vector<Vessel*> human_vessels = human->GetVessels();
    
    for (int i = 0; i < 5; i++){
        if(human_vessels[i]->GetXCoor() == x && human_vessels[i]->GetXCoor() == y){
            if (human_vessels[i]->GetDefensePoints() > 0){
                int attack_points = attacking_vessel->GetAttackPoints();
                int human_def_points = human_vessels[i]->GetDefensePoints();
                int new_human_def_points = human_def_points - attack_points;
                
                if (new_human_def_points <= 0){
                    new_human_def_points = 0;
                    human_vessels[i]->UpdateSymbol(' ');
                    computer_report = "The enemy destroyed one of your vessels! Check for damages";
                }
                else{
                    computer_report = "The enemy hit one of your vessels! Check for damages!";
                }
                human_vessels[i]->UpdateDefensePoints(new_human_def_points);
            }
            else{
                computer_report = "The enemy attacked a destroyed vessel.";
                return;
            }
        }
    }
    computer_report = "The enemy missed";
}


/******************************************************
 Responsibility:
 ******************************************************/
void Engine::ComputerAttack(){
    int x_coor = rand() % 10 + 1;
    int y_coor = rand() % 14 + 1;
    Vessel* com_attack_vessel = SetAttackVesselForComputer();
    InitiateComputerAttack(com_attack_vessel, x_coor, y_coor);
    com_attack_vessel = nullptr;
}

char Engine::CheckForGameWinner(){
    char winner = 'N';
    if (computer->GetNumOfVessels() == 0) {
        winner = 'H';
    }
    else if(human->GetNumOfVessels() == 0){
        winner = 'C';
    }
    return winner;
}

Player* Engine::GetHumanPlayer(){
    return human;
}


Player* Engine::GetComputerPlayer(){
    return computer;
}


/******************************************************
 Responsibility:
 ******************************************************/
char Engine::SelectDashboardOption(){
    std::string raw_input;
    bool valid_selection;
    while(true) {
        DisplayDashboard();
        std::getline(std::cin, raw_input);
        valid_selection =
        BSValidator::validateDashboardSelection(raw_input);
        if(valid_selection == true){
            break;
        }
    };
    return raw_input[0];
}


void Engine::UpdateGeneralReport(std::string general_report){
    this->general_report = general_report;
}


void Engine::UpdateHumanReport(std::string human_report){
    this->human_report = human_report;
}


void Engine::UpdateComputerReport(std::string computer_report){
    this->computer_report = computer_report;
}

std::string Engine::GetReport(){
    return general_report;
}

void Engine::DisplayInstructions(){
    BSUtilities::ClearScreen();
    std::string message;
    message = "How to play:\n";
    message += "Welcome Captain! Glad you could join us! We are\n";
    message += "getting hammered out there and need your help!\n";
    message += "I am your AI assistant, here to help you win the battle. \n";
    message += "But first, lets go over the rules of engagement.\n\n";
    message += "You are facing a worthy adversary; the Computer.\n";
    message += "I have updated the ships software to give you the\n";
    message += "ability to set your vessels in stealth mode.\n";
    message += "This means that the computer will not detect your\n";
    message += "vessels on their radar. Use this ability wisely, as\n";
    message += "you're only allowed to place one vessel in stealth mode at a time.\n";
    message += "Also, you may only do this every three turns.\n\n";
    message += "Once the game begins, you will be prompted to\n";
    message += "deploy your ships out to sea. Once that is set up,\n";
    message += "the battle will commence.\n";
    message += "The rules are simple, select a ship you want to use\n";
    message += "to launch an attack. Guess the coordinates for a\n";
    message += "possible location of a computer vessel and attack.\n";
    message += "I will notify you if you hit a computer vessel or \n";
    message += "if you missed. You will also be notified if you\n";
    message += "have been hit as well. The first player to destory\n";
    message += "all of their opponent's ships wins the game!\n\n";
    message += "PREPARE FOR BATTLE!\n";
    std::cout << message;
    std::cout << "Press [R] to return." << std::endl;
}


/******************************************************
 Responsibility:
 ******************************************************/
char Engine::ActivateHowToMenu(){
    std::string action;
    DisplayInstructions();
    while(true){
        std::getline(std::cin, action);
        if(BSValidator::validateHowToMenuSelection(action)){
            break;
        }
        std::cin.clear();
        //std::cin.ignore(1000, '\n');
    }
    return action[0];
}


/******************************************************
 Responsibility:
 ******************************************************/
void Engine::HumanTurnSequence(char* action){
    char user_input;
    bool attack_launched = false;
    
    while(attack_launched == false) {
        //Displays dashboard and gets input from the user.
        //SelectDashboardOption verifies the input.
        user_input = toupper(SelectDashboardOption());
        
        if (user_input == 'L') {
            HumanAttack();
            attack_launched = true;
        }
        else if(user_input == 'S'){
            ActivateHumanStealthMode();
        }
        else{
            //Action must be 'Q' here.
            *action = user_input;
            break;
        }
    }
    
    //User may only use stealth once per game. Once used, reset stealth mode
    if(human->GetStealthCount() >= 1){
        human->UpdateStealthMode(false);
        ResetStealthVessel();
    }
    else{
        human->UpdateStealthCount();
    }
}


void Engine::ResetStealthVessel(){
    human->GetCurrentStealthVessel()->UpdateStealthStatus(false);
    human->UpdateCurrentStealthVessel(nullptr);
}


/******************************************************
 Responsibility:
 ******************************************************/
Vessel* Engine::GetSelectedVessel(char vessel){
    if (vessel == 'A') {
        return human->GetVessels()[0];
    }
    else if (vessel == 'B') {
        return human->GetVessels()[1];
    }
    else if (vessel == 'C') {
        return human->GetVessels()[2];
    }
    else if (vessel == 'D') {
        return human->GetVessels()[3];
    }
    else{
        return human->GetVessels()[4];
    }
}

Engine::~Engine(){
}
