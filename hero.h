//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/17/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        hero.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Hero class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef HERO_H_BATESE
#define HERO_H_BATESE

#include <vector>
#include "creature.h"
#include "sword.h"
#include "shield.h"

class Item;
class Location;

class Hero : public Creature
{
 protected:
  std::string className;
  std::string fullName;
  std::vector<Item*> carry;
  int carrySize;
  Location* currentLocation;
  std::vector<Location*>* worldMap;
  int gold;
  int gameSpeed;
  std::string currentObjective;
  Sword* sword;
  Shield* shield;
  bool questOver;
  bool castleVisited;
  bool gotLadder;
  bool gotAmulet;
  bool castleRevisited;
  bool gotSpell;
  bool gotPower;
  
 public:
  Hero ();
  Hero (std::string name, std::string className, std::vector<Location*>* worldMap, Location* currentLocation, int gameSpeed);
  ~Hero ();
  void setClassName (std::string className) {this->className = className;}
  std::string getClassName () {return this->className;}
  void setFullName (std::string fullName) {this->fullName = fullName;}
  std::string getFullName () {return this->fullName;}
  void setCarry (std::vector<Item*>& carry) {this->carry = carry;}
  std::vector<Item*>& getCarry () {return this->carry;}
  void setCarrySize (int carrySize) {this->carrySize = carrySize;}
  int getCarrySize () {return this->carrySize;}
  void setCurrentLocation (Location* currentLocation) {this->currentLocation = currentLocation;}
  Location* getCurrentLocation () {return this->currentLocation;}
  void setWorldMap (std::vector<Location*>* worldMap) {this->worldMap = worldMap;}
  std::vector<Location*>* getWorldMap () {return this->worldMap;}
  void setGold (int gold) {this->gold = gold;}
  int getGold () {return this->gold;}
  void addGold (int gold) {this->gold += gold;}
  void setGameSpeed (int gameSpeed) {this->gameSpeed = gameSpeed;}
  int getGameSpeed () {return this->gameSpeed;}
  void setCurrentObjective (std::string currentObjective) {this->currentObjective = currentObjective;}
  std::string getCurrentObjective () {return this->currentObjective;}
  void setSword (Sword* sword) {this->sword = sword;}
  Sword* getSword () {return this->sword;}
  void setShield (Shield* shield) {this->shield = shield;}
  Shield* getShield () {return this->shield;}
  void setQuestOver (bool questOver) {this->questOver = questOver;}
  bool getQuestOver () {return this->questOver;}
  void setCastleVisited (bool castleVisited) {this->castleVisited = castleVisited;}
  bool getCastleVisited () {return this->castleVisited;}
  void setGotLadder (bool gotLadder) {this->gotLadder = gotLadder;}
  bool getGotLadder () {return this->gotLadder;}
  void setGotAmulet (bool gotAmulet) {this->gotAmulet = gotAmulet;}
  bool getGotAmulet () {return this->gotAmulet;}
  void setCastleRevisited (bool castleRevisited) {this->castleRevisited = castleRevisited;}
  bool getCastleRevisited () {return this->castleRevisited;}
  void setGotSpell (bool gotSpell) {this->gotSpell = gotSpell;}
  bool getGotSpell () {return this->gotSpell;}
  void setGotPower (bool gotPower) {this->gotPower = gotPower;}
  bool getGotPower () {return this->gotPower;}
  std::string getFullNameHp ();
  bool addItem (Item* add);
  int attack () {return (rand() % (attackMax - attackMin)) + attackMin + this->sword->getAttack();}
  int defend () {return (rand() % (defenceMax - defenceMin)) + defenceMin + this->shield->getDefence();}
};

#endif
