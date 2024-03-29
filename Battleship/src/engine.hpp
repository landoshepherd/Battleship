//
//  Game_Components.hpp
//  Battleship
//
//  Created by Lando Shepherd on 11/13/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#ifndef Engine_hpp
#define Engine_hpp

#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <vector>

#include "bs_utilities.hpp"
#include "player.hpp"

class Engine{
private:
    struct BigSign{
        std::string signString = "*****    **   ****** ****** **     ****** ****** **  ** ****** *****\n"
        "******  ****  ****** ****** **     ****** ****** **  ** ****** ******\n"
        "**  ** **  **   **     **   **     **     **     **  **   **   **  **\n"
        "**  ** **  **   **     **   **     **     **     **  **   **   **  **\n"
        "****** **  **   **     **   **     ****** ****** ******   **   ******\n"
        "*****  ******   **     **   **     ****** ****** ******   **   ******\n"
        "****** ******   **     **   **     **         ** **  **   **   **\n"
        "**  ** **  **   **     **   **     **         ** **  **   **   **\n"
        "**  ** **  **   **     **   **     **         ** **  **   **   **\n"
        "****** **  **   **     **   ****** ****** ****** **  ** ****** **\n"
        "*****  **  **   **     **   ****** ****** ****** **  ** ****** **\n"
        "####################################################################";
    };
    
public:
    Engine(Player* player1, Player* player2);
    
    void DisplayMarquee_();
    void PrintMainMenu();
    char MainMenu();
    
    void DisplayVessels();
    void BuildGameBoard();
    void PrintGameBoard();
    
    bool SpaceAvailable(std::vector<Vessel*> vessels, int x, int y);
    void DeployComputerVessels();
    void SetupComputerPlayer();
    
    int SetXCoorHumanVessel(Vessel* vessel);
    int SetYCoorHumanVessel(Vessel* vessel);
    void DeployHumanVessels();
    
    void DisplayDashboard();
    
    
    /*!
		Functions for Human Attack Sequence
	*/
    void HumanTurnSequence(char* action);
    char SelectDashboardOption();
    void HumanAttack();
    void SetAttackCoordinates(std::string& xCoor, std::string& yCoor);
    void InitiateHumanAttack(std::string xCoordinate, std::string yCoordinate, Vessel* attackVessel);
    bool AttackVesselFound(int x, int y); //Generic Function
    void ActivateHumanStealthMode();
    char SetHumanAttackVessel();
    Vessel* SelectStealthVessel();
    void SetHumanVesselToStealthMode(Vessel* vessel);
    
    
    /******************************************************
     Functions for Computer Attack Sequence
     ******************************************************/
    Vessel* SetAttackVesselForComputer();
    void InitiateComputerAttack(Vessel* attackingVessel, int x, int y);

    bool IsVesselDestroyed(Vessel* vessel); //Generic Function
    void ComputerAttack();
    char CheckForGameWinner();
    Player* GetHumanPlayer();
    Player* GetComputerPlayer();
    
    void UpdateGeneralReport(std::string generalReport);
    void UpdateHumanReport(std::string humanReport);
    void UpdateComputerReport(std::string computerReport);
    std::string GetReport();
    void DisplayInstructions();
    char ActivateHowToMenu();
    void ClearReports();
    
    
    void ResetStealthVessel();
    Vessel* GetSelectedVessel(char vessel);
    ~Engine();
    
private:
    //These are data members used to build the main structure of the game.
    char** game_board = nullptr;
    const int GBROW = 8, GBCOL = 26;
    Player* human = nullptr;
    Player* computer = nullptr;
    std::string human_report;
    std::string computer_report;
    std::string general_report;
};

#endif /* Battleship_hpp */
