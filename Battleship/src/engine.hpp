//
//  Game_Components.hpp
//  Battleship
//
//  Created by Lando Shepherd on 11/13/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#ifndef Game_Components_hpp
#define Game_Components_hpp

#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <vector>

#include "utilities/BS_Utilities.hpp"

#include "Player.hpp"

class Engine{
public:
    Engine();

	/*!
		Destructor - Clean up any dynamic memory
	 */
	~Engine();
    
    void SetupMarquee();
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

    bool VesselDestroyed(Vessel* vessel); //Generic Function
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
    
    //Battleship landing page sign.
    void row0(int row, int col);
    void row1(int row, int col);
    void row2(int row, int col);
    void row3(int row, int col);
    void row4(int row, int col);
    void row5(int row, int col);
    void row6(int row, int col);
    void row7(int row, int col);
    void row8(int row, int col);
    void row9(int row, int col);
    void row10(int row, int col);
    
private:
    //These are data members used to build the main structure of the game.
	const int m_signRow;
	const int m_signCol;
	const int m_boardRow;
	const int m_boardCol;
    char** m_sign = nullptr;
    char** m_gameBoard = nullptr;
    Player* m_human = nullptr;
    Player* m_computer = nullptr;
    std::string m_humanReport;
    std::string m_computerReport;
    std::string m_generalReport;
    
    
    

};

#endif /* Battleship_hpp */
