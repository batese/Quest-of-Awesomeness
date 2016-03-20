//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/14/2015				//
// Last Date Modified:		03/14/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			elixir.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the elixir class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "elixir.h"

using std::cin;
using std::cout;
using std::endl;

// DEFAULT CONSTRUCTOR //
// Description: Assigns values to a blank new object of elixir class.
Elixir::Elixir ()
  : Item ()
{
  this->attack = 0;
  this->defence = 0;
  this->armour = 0;
  this->hitPoints = 0;
}

// CONSTRUCTOR //
// Description: Assigns values to a new object of elixir class.
Elixir::Elixir (std::string name, std::string description, int value, Hero* owned, int attack, int defence, int armour, int hitPoints)
  : Item (name, description, value, owned)
{
  this->attack = attack;
  this->defence = defence;
  this->armour = armour;
  this->hitPoints = hitPoints;
}

// DESTRUCTOR //
// Description: Destroys an item of elixir class.
Elixir::~Elixir ()
{

}

// USE FUNCTION //
// Description: The heroes stats are increased and a message is displayed. Returns true since the item is used up
bool Elixir::use ()
{
  int pause = this->owned->getGameSpeed() * 500000;
  
  cout << "You drink the " << this->name << "." << endl;
  usleep(pause);
  if (this->attack)
    {
      cout << "Attack +" << this->attack << "!" << endl;
      usleep(pause);
      this->owned->addAttack(this->attack);
    }
  if (this->defence)
    {
      cout << "Defence +" << this->defence << "!" << endl;
      usleep(pause);
      this->owned->addDefence(this->defence);
    }
  if (this->armour)
    {
      cout << "Armour +" << this->armour << "!" << endl;
      usleep(pause);
      this->owned->addArmour(this->armour);
    }
  if (this->hitPoints)
    {
      cout << "Max Hit Points +" << this->hitPoints << "!" << endl;
      usleep(pause);
      this->owned->setMaxHitPoints(this->owned->getMaxHitPoints() + hitPoints);
    }
  return true;
}
