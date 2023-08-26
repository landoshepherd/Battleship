//
//  Vessel.hpp
//  Battleship
//
//  Created by Lando Shepherd on 11/14/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#ifndef Vessel_hpp
#define Vessel_hpp

#include <iostream>

class Vessel{
protected:
    std::string vessel_name;
    char symbol;
    char stealth_indicator;
    int attack_points;
    int defense_points;
    bool stealth_status;
    int x_coor;
    int y_coor;
    
public:
    Vessel(){}
    
    std::string GetVesselName(){
        return vessel_name;
    }
    
    void UpdateSymbol(char new_symbol){
        symbol = new_symbol;
    }
    
    char GetSymbol(){
        return symbol;
    }
    
    void UpdateAttackPoints(int new_points){
        attack_points = new_points;
    }
    
    int GetAttackPoints(){
        return attack_points;
    }
    
    void UpdateDefensePoints(int new_points){
        defense_points = new_points;
    }
    
    int GetDefensePoints(){
        return defense_points;
    }
    
    void UpdateStealthStatus(bool status){
        stealth_status = status;
        if(this->stealth_status){
            stealth_indicator = 'X';
        }
        else{
            stealth_indicator = ' ';
        }
    }
    
    char GetStealthIndicator(){
        return stealth_indicator;
    }
    
    bool GetStealthStatus(){
        return stealth_status;
    }
    
    void UpdateXCoor(int x){
        x_coor = x;
    }
    
    char GetXCoor(){
        return x_coor;
    }
    
    void UpdateYCoor(int y){
        y_coor = y;
    }
    
    int GetYCoor(){
        return y_coor;
    }
    
    ~Vessel(){};

};
#endif /* Vessel_hpp */


class Carrier : public Vessel{
public:
    Carrier(){
        vessel_name = "Carrier";
        symbol = 'C';
        stealth_indicator = ' ';
        attack_points = 30;
        defense_points = 100;
        stealth_status = false;
        x_coor = 0;
        y_coor = 0;
    }
};


class Battleship : public Vessel{
public:
    Battleship(){
        vessel_name = "Battleship";
        symbol = 'B';
        stealth_indicator = ' ';
        attack_points = 25;
        defense_points = 100;
        stealth_status = false;
        x_coor = 0;
        y_coor = 0;
    }
};


class Cruiser : public Vessel{
public:
    Cruiser(){
        vessel_name = "Cruiser";
        symbol = 'R';
        stealth_indicator = ' ';
        attack_points = 20;
        defense_points = 100;
        stealth_status = false;
        x_coor = 0;
        y_coor = 0;
    }
};


class Submarine : public Vessel{
public:
    Submarine(){
        vessel_name = "Submarine";
        symbol = 'S';
        stealth_indicator = ' ';
        attack_points = 15;
        defense_points = 100;
        stealth_status = false;
        x_coor = 0;
        y_coor = 0;
    }
};


class Destroyer : public Vessel{
public:
    Destroyer(){
        vessel_name = "Destroyer";
        symbol = 'D';
        stealth_indicator = ' ';
        attack_points = 10;
        defense_points = 100;
        stealth_status = false;
        x_coor = 0;
        y_coor = 0;
    }
};
