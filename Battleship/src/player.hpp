//
//  Player.hpp
//  Battleship
//
//  Created by Lando Shepherd on 11/16/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <vector>

#include "vessel.hpp"

class Player
{
private:
    std::string name;
    std::vector<std::shared_ptr<Vessel> > vessels;
    int num_of_vessels;
    int stealth_count;
    std::shared_ptr<Carrier> carrier;
    std::shared_ptr<Battleship> battleship;
    std::shared_ptr<Cruiser> cruiser;
    std::shared_ptr<Submarine> submarine;
    std::shared_ptr<Destroyer> destroyer;
    std::shared_ptr<Vessel> current_stealth_vessel;
    bool player_in_stealth_mode;
    
public:
    Player();
    Player(std::string Name);
    std::string GetPlayerName();
    std::vector<std::shared_ptr<Vessel> > GetVessels();
    void UpdateNumOfVessels(int num_of_vessels);
    int GetNumOfVessels();
    void UpdateStealthCount();
    int GetStealthCount();
    void UpdateCurrentStealthVessel(std::shared_ptr<Vessel> vessel);
    std::shared_ptr<Vessel> GetCurrentStealthVessel();
    void UpdateStealthMode(bool status);
    bool GetStealthMode();
    ~Player();
};

#endif /* Player_hpp */
