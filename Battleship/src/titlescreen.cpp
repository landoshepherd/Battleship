//
//  titlescreen.cpp
//  Battleship
//
//  Created by Lando Shepherd on 12/7/19.
//  Copyright © 2019 Lando Shepherd. All rights reserved.
//

#include "titlescreen.hpp"

#include "utilities/BS_Utilities.hpp"



TitleScreen::TitleScreen():
			m_signRow(11),
			m_signCol(68),
			m_sign(new char*[m_signRow])
{}

TitleScreen::~TitleScreen()
{
	//Used to delete dynamic allocated memory
}

void TitleScreen::initialize()
{
	for(int i = 0; i < m_signRow; i++){
        m_sign[i] = new char [m_signCol];
    }

    for(int i = 0; i < m_signRow; i++){
        for(int j = 0; j < m_signCol; j++){
            m_sign[i][j] = ' ';
        }
    }
}

void TitleScreen::displayBanner()
{
	for (int i = 0; i < m_signRow; i++) {
		for(int j = 0; j < m_signCol; j++){
			std::cout << m_sign[i][j];
		}
		std::cout << std::endl;
	}
	for(int i = 0; i < 68; i++){
		std::cout << "#";
	}
	std::cout << std::endl;
}

char TitleScreen::mainMenu()
{
	std::string user_input;
	printMainMenu();

	while(true){
		std::getline(std::cin, user_input);
		if(BSValidator::validateMainMenu(user_input)){
			break;
		}
	}
	return toupper(user_input[0]);
}

void TitleScreen::printMainMenu()
{

	std::cout << "[A] Play Battleship\n";
	std::cout << "[B] How to play\n";
	std::cout << "[Q] Quit\n";
}
void TitleScreen::displayLandingScreen()
{
	buildBanner();
	displayBanner();
	printMainMenu();
}

void TitleScreen::buildBanner(){
    for(int i = 0; i < m_signRow; i++){
        for(int j = 0; j < m_signCol; j++){
            if(i == 0)
            {
                row0(i, j);
            }

            if(i == 1){
                row1(i, j);
            }

            if(i == 2){
                row2(i, j);
            }

            if(i == 3){
                row3(i, j);
            }

            if(i == 4){
                row4(i, j);
            }

            if(i == 5){
                row5(i, j);
            }

            if(i == 6){
                row6(i, j);
            }

            if(i == 7){
                row7(i, j);
            }

            if(i == 8){
                row8(i, j);
            }

            if(i == 9){
                row9(i, j);
            }

            if(i == 10){
                row10(i, j);
            }
        }
    }
}


void TitleScreen::row0(int i, int j){
    if(j >= 0 && j <= 4){
        m_sign[i][j] = '*';
    }

    if(j >= 9 && j <= 10){
        m_sign[i][j] = '*';
    }

    if(j >= 14 && j <= 19){
        m_sign[i][j] = '*';
    }

    if(j >= 21 && j <= 26){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 29){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 40){
        m_sign[i][j] = '*';
    }

    if(j >= 42 && j <= 47){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 50){
        m_sign[i][j] = '*';
    }

    if(j >= 53 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 56 && j <= 61){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 67){
        m_sign[i][j] = '*';
    }
}

void TitleScreen::row1(int i, int j){
    if(j >= 0 && j <= 5){
        m_sign[i][j] = '*';
    }

    if(j >= 8 && j <= 11){
        m_sign[i][j] = '*';
    }

    if(j >= 14 && j <= 19){
        m_sign[i][j] = '*';
    }

    if(j >= 21 && j <= 26){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 29){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 40){
        m_sign[i][j] = '*';
    }

    if(j >= 42 && j <= 47){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 50){
        m_sign[i][j] = '*';
    }

    if(j >= 53 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 56 && j <= 61){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 68){
        m_sign[i][j] = '*';
    }
}

void TitleScreen::row2(int i, int j){
    if(j >= 0 && j <= 1){
        m_sign[i][j] = '*';
    }

    if(j >= 4 && j <= 5){
        m_sign[i][j] = '*';
    }

    if(j >= 7 && j <= 8){
        m_sign[i][j] = '*';
    }

    if(j >= 11 && j <= 12){
        m_sign[i][j] = '*';
    }

    if(j >= 16 && j <= 17){
        m_sign[i][j] = '*';
    }

    if(j >= 23 && j <= 24){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 29){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 36){
        m_sign[i][j] = '*';
    }

    if(j >= 42 && j <= 43){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 50){
        m_sign[i][j] = '*';
    }

    if(j >= 53 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 58 && j <= 59){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 64){
        m_sign[i][j] = '*';
    }

    if(j >= 67 && j <= 68){
        m_sign[i][j] = '*';
    }
}

void TitleScreen::row3(int i, int j){
    if(j >= 0 && j <= 1){
        m_sign[i][j] = '*';
    }

    if(j >= 4 && j <= 5){
        m_sign[i][j] = '*';
    }

    if(j >= 7 && j <= 8){
        m_sign[i][j] = '*';
    }

    if(j >= 11 && j <= 12){
        m_sign[i][j] = '*';
    }

    if(j >= 16 && j <= 17){
        m_sign[i][j] = '*';
    }

    if(j >= 23 && j <= 24){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 29){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 36){
        m_sign[i][j] = '*';
    }

    if(j >= 42 && j <= 43){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 50){
        m_sign[i][j] = '*';
    }

    if(j >= 53 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 58 && j <= 59){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 64){
        m_sign[i][j] = '*';
    }

    if(j >= 67 && j <= 68){
        m_sign[i][j] = '*';
    }
}

void TitleScreen::row4(int i, int j){
    if(j >= 0 && j <= 5){
        m_sign[i][j] = '*';
    }

    if(j >= 7 && j <= 8){
        m_sign[i][j] = '*';
    }

    if(j >= 11 && j <= 12){
        m_sign[i][j] = '*';
    }

    if(j >= 16 && j <= 17){
        m_sign[i][j] = '*';
    }

    if(j >= 23 && j <= 24){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 29){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 40){
        m_sign[i][j] = '*';
    }

    if(j >= 42 && j <= 47){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 58 && j <= 59){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 68){
        m_sign[i][j] = '*';
    }
}

void TitleScreen::row5(int i, int j){
    if(j >= 0 && j <= 4){
        m_sign[i][j] = '*';
    }

    if(j >= 7 && j <= 12){
        m_sign[i][j] = '*';
    }

    if(j >= 16 && j <= 17){
        m_sign[i][j] = '*';
    }

    if(j >= 23 && j <= 24){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 29){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 40){
        m_sign[i][j] = '*';
    }

    if(j >= 42 && j <= 47){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 58 && j <= 59){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 67){
        m_sign[i][j] = '*';
    }
}

void TitleScreen::row6(int i, int j){
    if(j >= 0 && j <= 5){
        m_sign[i][j] = '*';
    }

    if(j >= 7 && j <= 12){
        m_sign[i][j] = '*';
    }

    if(j >= 16 && j <= 17){
        m_sign[i][j] = '*';
    }

    if(j >= 23 && j <= 24){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 29){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 36){
        m_sign[i][j] = '*';
    }

    if(j >= 46 && j <= 47){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 50){
        m_sign[i][j] = '*';
    }

    if(j >= 53 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 58 && j <= 59){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 64){
        m_sign[i][j] = '*';
    }
}

void TitleScreen::row7(int i, int j){
    if(j >= 0 && j <= 1){
        m_sign[i][j] = '*';
    }

    if(j >= 4 && j <= 5){
        m_sign[i][j] = '*';
    }

    if(j >= 7 && j <= 8){
        m_sign[i][j] = '*';
    }

    if(j >= 11 && j <= 12){
        m_sign[i][j] = '*';
    }

    if(j >= 16 && j <= 17){
        m_sign[i][j] = '*';
    }

    if(j >= 23 && j <= 24){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 29){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 36){
        m_sign[i][j] = '*';
    }

    if(j >= 46 && j <= 47){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 50){
        m_sign[i][j] = '*';
    }

    if(j >= 53 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 58 && j <= 59){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 64){
        m_sign[i][j] = '*';
    }
}

void TitleScreen::row8(int i, int j){
    if(j >= 0 && j <= 1){
        m_sign[i][j] = '*';
    }

    if(j >= 4 && j <= 5){
        m_sign[i][j] = '*';
    }

    if(j >= 7 && j <= 8){
        m_sign[i][j] = '*';
    }

    if(j >= 11 && j <= 12){
        m_sign[i][j] = '*';
    }

    if(j >= 16 && j <= 17){
        m_sign[i][j] = '*';
    }

    if(j >= 23 && j <= 24){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 29){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 36){
        m_sign[i][j] = '*';
    }

    if(j >= 46 && j <= 47){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 50){
        m_sign[i][j] = '*';
    }

    if(j >= 53 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 58 && j <= 59){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 64){
        m_sign[i][j] = '*';
    }
}

void TitleScreen::row9(int i, int j){
    if(j >= 0 && j <= 5){
        m_sign[i][j] = '*';
    }

    if(j >= 7 && j <= 8){
        m_sign[i][j] = '*';
    }

    if(j >= 11 && j <= 12){
        m_sign[i][j] = '*';
    }

    if(j >= 16 && j <= 17){
        m_sign[i][j] = '*';
    }

    if(j >= 23 && j <= 24){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 33){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 40){
        m_sign[i][j] = '*';
    }

    if(j >= 42 && j <= 47){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 50){
        m_sign[i][j] = '*';
    }

    if(j >= 53 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 56 && j <= 61){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 64){
        m_sign[i][j] = '*';
    }
}

void TitleScreen::row10(int i, int j){
    if(j >= 0 && j <= 4){
        m_sign[i][j] = '*';
    }

    if(j >= 7 && j <= 8){
        m_sign[i][j] = '*';
    }

    if(j >= 11 && j <= 12){
        m_sign[i][j] = '*';
    }

    if(j >= 16 && j <= 17){
        m_sign[i][j] = '*';
    }

    if(j >= 23 && j <= 24){
        m_sign[i][j] = '*';
    }

    if(j >= 28 && j <= 33){
        m_sign[i][j] = '*';
    }

    if(j >= 35 && j <= 40){
        m_sign[i][j] = '*';
    }

    if(j >= 42 && j <= 47){
        m_sign[i][j] = '*';
    }

    if(j >= 49 && j <= 50){
        m_sign[i][j] = '*';
    }

    if(j >= 53 && j <= 54){
        m_sign[i][j] = '*';
    }

    if(j >= 56 && j <= 61){
        m_sign[i][j] = '*';
    }

    if(j >= 63 && j <= 64){
        m_sign[i][j] = '*';
    }
}


