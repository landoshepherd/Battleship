//
//  Player.cpp
//  Battleship
//
//  Created by Lando Shepherd on 11/16/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#include "player.hpp"

Player::Player(){
    num_of_vessels = 5;
    stealth_count = 0;
    current_stealth_vessel = nullptr;
    player_in_stealth_mode = false;
    
    carrier = new Carrier();
    vessels.push_back(carrier);
    
    battleship = new Battleship;
    vessels.push_back(battleship);
    
    cruiser = new Cruiser();
    vessels.push_back(cruiser);
    
    submarine = new Submarine();
    vessels.push_back(submarine);
    
    destroyer = new Destroyer();
    vessels.push_back(destroyer);
};

std::string Player::GetPlayerName(){
    return name;
}

std::vector<Vessel*> Player::GetVessels(){
    return vessels;
}

void Player::UpdateNumOfVessels(int numOfVessels){
    this->num_of_vessels = numOfVessels;
}

int Player::GetNumOfVessels(){
    return num_of_vessels;
}

void Player::UpdateStealthCount(){
    stealth_count++;
}

int Player::GetStealthCount(){
    return stealth_count;
}

void Player::UpdateCurrentStealthVessel(Vessel* vessel){
    current_stealth_vessel = vessel;
}

Vessel* Player::GetCurrentStealthVessel(){
    return current_stealth_vessel;
}

void Player::UpdateStealthMode(bool mode){
    player_in_stealth_mode = mode;
}

bool Player::GetStealthMode(){
    return player_in_stealth_mode;
}

Player::~Player(){
    for (int i = 0; i < vessels.size(); i++) {
        if(vessels[i] != NULL)
        {
            delete vessels[i];
        }
    }
};
