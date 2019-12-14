//
//  titlescreen.hpp
//  Battleship
//
//  Created by Lando Shepherd on 12/7/19.
//  Copyright © 2019 Lando Shepherd. All rights reserved.
//

#ifndef landingscreen_hpp
#define landingscreen_hpp

#include <iostream>

class TitleScreen
{
	public:
		TitleScreen();
		~TitleScreen();
		void initialize();
		void buildBanner();
		void displayBanner();
		void printMainMenu();
		char mainMenu();
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
		const int m_signRow;
		const int m_signCol;
		char** m_sign = nullptr;
};
#endif /* landingscreen_hpp */
