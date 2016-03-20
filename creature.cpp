//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/15/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			creature.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Creature class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "creature.h"

//////////////////////////////////////////////////////////////////////////
//		        DEFAULT CONSTRUCTOR				//
//									//
//	Entry:								//
//		None.							//
//									//
//	Exit:								//
//		Makes a blank object of Creature class.			//
//									//
//	Purpose:							//
//		This function is used make a Creature with no		//
//		 information.						//
//////////////////////////////////////////////////////////////////////////
Creature::Creature ()
{
  this->name = "";
  this->attackMax = 0;
  this->attackMin = 0;
  this->defenceMax = 0;
  this->defenceMin = 0;
  this->armour = 0;
  this->maxHitPoints = 0;
  this->hitPoints = 0;
}

//////////////////////////////////////////////////////////////////////////
//		         CONSTRUCTOR					//
//									//
//	Entry:								//
//		None.							//
//									//
//	Exit:								//
//		Makes an object of Creature class.			//
//									//
//	Purpose:							//
//		This function is used make a Creature with given	//
//		 information.						//
//////////////////////////////////////////////////////////////////////////
Creature::Creature (std::string name, int attackMax, int attackMin, int defenceMax, int defenceMin, int armour, int maxHitPoints)
{
  this->name = name;
  this->attackMax = attackMax;
  this->attackMin = attackMin;
  this->defenceMax = defenceMax;
  this->defenceMin = defenceMin;
  this->armour = armour;
  this->maxHitPoints = maxHitPoints;
  this->hitPoints = maxHitPoints;
}

//////////////////////////////////////////////////////////////////////////
//		        DESTRUCTOR					//
//									//
//	Entry:								//
//		None.							//
//									//
//	Exit:								//
//		Sets pointers to NULL.					//
//									//
//	Purpose:							//
//		This function is a destructor for the Creature class.	//
//////////////////////////////////////////////////////////////////////////
Creature::~Creature()
{

}

// GET NAME HP FUNCTION //
// Description: This funtions returns the creatures name plus its hitpoints as a fraction
//              of its total hit points. It is returned as one combined string.
std::string Creature::getNameHp()
{
  std::stringstream ss; 
  ss << this->name << " (" << this->hitPoints << "/" << this->maxHitPoints << ")";
  std::string full = ss.str();
  
  return full;
}

// ADD ATTACK FUNCTION //
// Description: This function is used to increase the creatures attack stats. Either the
//              desired increase is added to both the min and max attack stats, or twice
//              the increase is added just to the max.
void Creature::addAttack (int attack)
{
  if (rand() % 2)
    {
      this->attackMax += attack;
      this->attackMin += attack;
    }
  else
    {
      this->attackMax += (2 * attack);
    }
}

// ADD DEFENCE FUNCTION //
// Description: This function is used to increase the creatures defence stats. Either the
//              desired increase is added to both the min and max defence stats, or twice
//              the increase is added just to the max.
void Creature::addDefence (int defence)
{
  if (rand() % 2)
    {
      this->defenceMax += defence;
      this->defenceMin += defence;
    }
  else
    {
      this->defenceMax += (2 * defence);
    }
}
