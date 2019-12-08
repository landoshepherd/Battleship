//
//  Game_Components.hpp
//  Battleship
//
//  Created by Lando Shepherd on 11/13/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#ifndef Game_Components_hpp
#define Game_Components_hpp

#include <iomanip>
#include <iostream>
#include <memory>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "landingscreen.hpp"
#include "utilities/BS_Utilities.hpp"

#include "Player.hpp"

namespace engine
{
	class Dashboard
	{
		public:
			Dashboard();
			~Dashboard();
			void DisplayVessels();
			void BuildGameBoard();
			void PrintGameBoard();
			void DisplayDashboard();
			void initialize();

		private:
			char** m_gameBoard = nullptr;
			const int m_boardRow;
			const int m_boardCol;
	};

	class Engine{
	public:
		Engine();

		/*!
			Destructor - Clean up any dynamic memory
		 */
		~Engine();
		void initialize();
		bool SpaceAvailable(std::vector<Vessel*> vessels, int x, int y);
		void DeployComputerVessels();
		void SetupComputerPlayer();

		int SetXCoorHumanVessel(Vessel* vessel);
		int SetYCoorHumanVessel(Vessel* vessel);
		void DeployHumanVessels();




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

	private:
		//These are data members used to build the main structure of the game.
		std::unique_ptr<landingScreen::GameSign> gameSign;
		std::unique_ptr<Dashboard> dashboard;
		std::unique_ptr<Player> m_human;
		std::unique_ptr<Player> m_computer;
		std::string m_humanReport;
		std::string m_computerReport;
		std::string m_generalReport;
	};


}
#endif /* Battleship_hpp */
