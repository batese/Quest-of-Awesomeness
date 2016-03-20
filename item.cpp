//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/14/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			item.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Item class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "item.h"
#include "hero.h"

// CONSTRUCTOR //
// Description: Assigns values to a blank Item object.
Item::Item ()
{
  this->name = "";
  this->description = "";
  this->value = 0;
  this->owned = NULL;
}

// CONSTRUCTOR //
// Description: Assigns values to a new object of Item class. Requires name, description, value
//              and a pointer to the hero it is owned by.
Item::Item (std::string name, std::string description, int value, Hero* owned)
{
  this->name = name;
  this->description = description;
  this->value = value;
  this->owned = owned;
}

// DESTRUCTOR //
// Description: Destroys an object of Item class
Item::~Item ()
{
  this->owned = NULL;
}

// USE FUNCTION //
// Description: Use function for items of the base class (which cannot be used). Returns false.
//              The use funstion in derived classes will return true for items which are used up
//              when they are used.
bool Item::use ()
{
  std::cout << "You use the " << this->name << "... but nothing happens." << std::endl;
  usleep(500000 * this->owned->getGameSpeed());
  return false;
}
