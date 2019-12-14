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
	class Dashboard;
	class Engine
	{

		public:
			Engine();
			/*!
				Destructor - Clean up any dynamic memory
			*/
			~Engine();
			void initialize();
			bool spaceAvailable(std::vector<Vessel*> vessels, int x, int y);
			void deployComputerVessels();
			void setupComputerPlayer(); //Missing function definition.
			int setXCoorHumanVessel(Vessel* vessel);
			int setYCoorHumanVessel(Vessel* vessel);
			void deployHumanVessels();
			void mainMenu(char& playerAction);
			void startGame(char& playerAction);

			/*!
				Functions for Human Attack Sequence
			*/
			void humanTurnSequence(char& action);
			char selectDashboardOption();
			void humanAttack();
			void setAttackCoordinates(std::string& xCoor, std::string& yCoor);
			void initiateHumanAttack(std::string xCoordinate, std::string yCoordinate, Vessel* attackVessel);
			bool attackVesselFound(int x, int y); //Generic Function
			void activateHumanStealthMode();
			char setHumanAttackVessel();
			Vessel* selectStealthVessel();
			void setHumanVesselToStealthMode(Vessel* vessel);


			/******************************************************
			Functions for Computer Attack Sequence
			******************************************************/
			Vessel* setAttackVesselForComputer();
			void initiateComputerAttack(Vessel* attackingVessel, int x, int y);

			bool vesselDestroyed(Vessel* vessel); //Generic Function
			void computerAttack();
			char checkForGameWinner();
			std::shared_ptr<Player> getHumanPlayer();
			std::shared_ptr<Player> getComputerPlayer();
			void updateGeneralReport(std::string generalReport);
			void updateHumanReport(std::string humanReport);
			void updateComputerReport(std::string computerReport);
			std::string getReport();
			void displayInstructions();
			char activateHowToMenu();
			void clearReports();
			void resetStealthVessel();
			Vessel* getSelectedVessel(char vessel);

		protected:
			//These are data members used to build the main structure of the game.
			std::unique_ptr<TitleScreen> titleScreen;
			std::unique_ptr<Dashboard> m_dashboard;
			std::shared_ptr<Player> m_human;
			std::shared_ptr<Player> m_computer;
			const int m_boardRow;
			const int m_boardCol;
			char** m_gameBoard = nullptr;
			std::string m_humanReport;
			std::string m_computerReport;
			std::string m_generalReport;
	};

	class Dashboard : public Engine
	{
		public:
			Dashboard() = default;
			~Dashboard() = default;
			void initialize();
			void displayHumanVessels();
			void buildGameBoard();
			void printGameBoard();
			void displayDashboard();

		private:
	};
}
#endif /* Battleship_hpp */
