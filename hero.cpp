//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/16/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			hero.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Hero class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <sstream>
#include "hero.h"
#include "item.h"

// DEFAULT CONSTRUCTOR //
// Description: Used to set up a blank object of hero class
Hero::Hero ()
  : Creature()
{
  this->className = "";
  this->fullName = "";
  this->carrySize = 0;
  this->currentLocation = NULL;
  this->worldMap = NULL;
  this->gold = 0;
  this->gameSpeed = 0;
  this->currentObjective = "";

  this->sword = NULL;
  this->shield = NULL;

  this->questOver = false;
  this->castleVisited = false;
  this->gotLadder = false;
  this->gotAmulet = false;
  this->castleRevisited = false;
  this->gotSpell = false;
  this->gotPower = false;
  std::vector<Item*> carry;
}

// CONSTRUCTOR //
// Description: Assigns values to a new hero object. Requires arguments for the name, class name, a vector
//              of pointers representing the world map, a pointer to the current location, and the game speed.
Hero::Hero (std::string name, std::string className, std::vector<Location*>* worldMap, Location* currentLocation, int gameSpeed)
  : Creature (name, 30, 0, 20, 0, 0, 100)
{
  this->className = className;
  this->fullName = this->name + " the " + this->className;
  this->carrySize = 5;
  this->currentLocation = currentLocation;
  this->worldMap = worldMap;
  this->gold = 0;
  this->gameSpeed = gameSpeed;
  this->currentObjective = "Head North to the castle and seek help there";

  this->sword = NULL;
  this->shield = NULL;

  this->questOver = false;
  this->castleVisited = false;
  this->gotLadder = false;
  this->gotAmulet = false;
  this->castleRevisited = false;
  this-> gotSpell = false;
  this->gotPower = false;
  std::vector<Item*> carry;
}

// DESTRUCTOR //
// Description: Destroys an object of Hero class.
Hero::~Hero ()
{
  for (unsigned x = 0; x < this->carry.size(); x++)
    {
      delete this->carry[x];
    }
  delete this->sword;
  delete this->shield;
  this->currentLocation = NULL;
  this->worldMap = NULL;
}

// GET FULL NAME HP FUNCTION //
// Description: Returns the heroes full name plus its current hit points as a fraction of
//              total hitpoitns in one combined string.
std::string Hero::getFullNameHp ()
{
  std::stringstream ss; 
  ss << this->fullName << " (" << this->hitPoints << "/" << this->maxHitPoints << ")";
  std::string full = ss.str();
  
  return full;
}

// ADD ITEM FUNCTION //
// Description: Attempts to add the item pointer passed as an argument to the heroes carry
//              vector. Returns true if the items is added successfully or false if not.
bool Hero::addItem (Item* add)
{
  if (this->carry.size() == unsigned(this->carrySize))
    {
      return 0;
    }
  else
    {
      carry.push_back(add);
      return 1;
    }
}
