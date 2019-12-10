//
//  landingscreen.hpp
//  Battleship
//
//  Created by Lando Shepherd on 12/7/19.
//  Copyright © 2019 Lando Shepherd. All rights reserved.
//

#ifndef landingscreen_hpp
#define landingscreen_hpp

#include <iostream>

namespace landingScreen
{
	class GameMenu
	{
		public:
			GameMenu() = default;
			~GameMenu() = default;
			char MainMenu();
			void printMainMenu();

		private:
	};

	class GameSign
	{
		public:
			GameSign();
			~GameSign();
			void initialize();
			void buildBanner();
			void displayBanner();
			void displayLandingScreen();
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
			std::unique_ptr<GameMenu> mainMenu;
			const int m_signRow;
			const int m_signCol;
			char** m_sign = nullptr;			
	};


}
#endif /* landingscreen_hpp */
