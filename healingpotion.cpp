//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/14/2015				//
// Last Date Modified:		03/14/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			healingpotion.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the healing potion class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "healingpotion.h"

// DEFAULT CONSTRUCTOR //
// Description: Assigns values to a blank new object of Healingpotion class.
Healingpotion::Healingpotion ()
  : Item ()
{
  this->heal = 0;
}

// CONSTRUCTOR //
// Description: Assigns values to a healing potion object using given arguments.
Healingpotion::Healingpotion (std::string name, std::string description, int value, Hero* owned, int heal)
  : Item (name, description, value, owned)
{
  this->heal = heal;
}

Healingpotion::~Healingpotion ()
{

}

// USE FUNCTION //
// Description: Heals the hero it is owned by and displays a message. Returns true since the item is used up
bool Healingpotion::use ()
{
  int pause = 500000 * this->owned->getGameSpeed();

  std::cout << "You drink the health potion." << std::endl;
  usleep(pause);
  std::cout << "Hit Points +" << this->heal << "!" << std::endl;
  usleep(pause);

  this->owned->addHitPoints(heal);

  if (this->owned->getHitPoints() > this->owned->getMaxHitPoints())
    {
      this->owned->setHitPoints(this->owned->getMaxHitPoints());
    }
  return true;
}
