//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/14/2015				//
// Last Date Modified:		03/14/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        elixir.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		elixir class.					//
//////////////////////////////////////////////////////////////////////////
#ifndef ELIXIR_H_BATESE
#define ELIXIR_H_BATESE

#include "item.h"
#include "hero.h"

class Elixir : public Item
{
 protected:
  int attack;
  int defence;
  int armour;
  int hitPoints;
 public:
  Elixir ();
  Elixir (std::string name, std::string description, int value, Hero* owned, int attack, int defence, int armour, int hitPoints);
  ~Elixir ();
  void setAttack (int attack) {this->attack = attack;}
  int getAttack () {return this->attack;}
  void setDefence (int defence) {this->defence = defence;}
  int getDefence () {return this->defence;}
  void setArmour (int armour) {this->armour = armour;}
  int getArmour () {return this->armour;}
  void setHipPoints (int hitPoints) {this->hitPoints = hitPoints;}
  int getHitPoints () {return this->hitPoints;}
  bool use ();
};

#endif
