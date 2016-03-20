//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/16/2015				//
// Last Date Modified:		03/16/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        shield.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		shield class.					//
//////////////////////////////////////////////////////////////////////////
#ifndef SHIELD_H_BATESE
#define SHIELD_H_BATESE

#include "item.h"

class Hero;

class Shield : public Item
{
 protected:
  int defence;
 public:
  Shield ();
  Shield (std::string name, std::string description, int value, Hero* owned, int defence);
  ~Shield ();
  void setDefence (int defence) {this->defence = defence;}
  int getDefence () {return this->defence;}
  bool use ();
};

#endif
