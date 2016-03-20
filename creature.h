//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/17/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			creature.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		 Creature class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef CREATURE_H_BATESE
#define CREATURE_H_BATESE

class Creature
{
 protected:
  std::string name;
  int attackMax;
  int attackMin;
  int defenceMax;
  int defenceMin;
  int armour;
  int maxHitPoints;
  int hitPoints;

 public:
  Creature ();
  Creature (std::string name, int attackMax, int attackMin, int defenceMax, int defenceMin, int armour, int maxHitPoints);
  ~Creature ();
  void setName (std::string name) {this->name = name;}
  std::string getName () {return this->name;}
  void setAttackMax (int attackMax) {this->attackMax = attackMax;}
  int getAttackMax () {return this->attackMax;}
  void setAttackMin (int attackMin) {this->attackMin = attackMin;}
  int getAttackMin () {return this->attackMin;}
  void setDefenceMax (int defenceMax) {this->defenceMax = defenceMax;}
  int getDefenceMax () {return this->defenceMax;}
  void setDefenceMin (int defenceMin) {this->defenceMin = defenceMin;}
  int getDefenceMin () {return this->defenceMin;}
  void setArmour (int armour) {this->armour = armour;}
  int getArmour () {return this->armour;}
  void setMaxHitPoints (int maxHitPoints) {this->maxHitPoints = maxHitPoints;}
  int getMaxHitPoints () {return this->maxHitPoints;}
  void setHitPoints (int hitPoints) {this->hitPoints = hitPoints;}
  int getHitPoints () {return this->hitPoints;}
  std::string getNameHp ();
  void addHitPoints (int hitPoints) {this->hitPoints += hitPoints;}
  void addArmour (int armour) {this->armour += armour;}
  void addAttack (int attack);
  void addDefence (int defence);
  virtual int attack () {return (rand() % (attackMax - attackMin)) + attackMin;}
  virtual int defend () {return (rand() % (defenceMax - defenceMin)) + defenceMin;}
};

#endif
