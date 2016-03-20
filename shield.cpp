//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/16/2015				//
// Last Date Modified:		03/16/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			shield.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the shield class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "shield.h"
#include "hero.h"

using std::cin;
using std::cout;
using std::endl;

// DEFAULT CONSTRUCTOR //
// Description: Assigns values toa  new blank object of Shield class
Shield::Shield ()
  : Item ()
{
  this->defence = 0;
}

// CONSTRUCTOR //
// Description: Assigns values to a new object of Shield class using given arguments.
Shield::Shield (std::string name, std::string description, int value, Hero* owned, int defence)
  : Item (name, description, value, owned)
{
  this->defence = defence;
}

// DESTRUCTOR //
// Description: destroys an object of Shield class.
Shield::~Shield ()
{

}

// USE FUNCTION //
// Description: Allows the player to either discard the shield or swap it with the currently equipped one.
//              Returns true if the shield is discarded or false if it is equipped.
bool Shield::use ()
{
  int pause = this->owned->getGameSpeed() * 500000;
  int menuChoice = 0;
  bool removed = false;
  cout << "What would you like to do with the " << this->name << "?" << endl;
  usleep(pause/10);
  cout << "1. Equip in place of " << this->owned->getShield()->getName() << endl;
  usleep(pause/10);
  cout << "2. Discard" << endl;
  usleep(pause/10);
  while (menuChoice < 1 || menuChoice > 2)
    {
      cout << "Choice: ";
      cin >> menuChoice;
      cin.clear();
      cin.ignore(1000, '\n');
    }
  if (menuChoice == 1)
    {
      Shield* temp = this->owned->getShield();
      this->owned->setShield(this);
      for (unsigned x = 0; x < this->owned->getCarry().size(); x++)
	{
	  if (this->owned->getCarry()[x]->getName() == this->name && !removed)
	    {
	      this->owned->getCarry().erase(this->owned->getCarry().begin() + x);
	      removed = true;
	    }
	}
      this->owned->addItem(temp);
      cout << "Equipped the " << this->name << ". " << temp->getName() << " added to inventory." << endl;
      return false;
    }
  else // (menuChoice == 2)
    {
      cout << "You discard the " << this->name << "." << endl;
      usleep(pause/2);
      return true;
    }
}
