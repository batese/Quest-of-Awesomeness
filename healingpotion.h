//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/14/2015				//
// Last Date Modified:		03/14/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        item.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		healing potion class.					//
//////////////////////////////////////////////////////////////////////////
#ifndef HEALINGPOTION_H_BATESE
#define HEALINGPOTION_H_BATESE

#include "item.h"
#include "hero.h"

class Healingpotion : public Item
{
 protected:
  int heal;
 public:
  Healingpotion ();
  Healingpotion (std::string name, std::string description, int value, Hero* owned, int heal);
  ~Healingpotion ();
  void setHeal (int heal) {this->heal = heal;}
  int getHeal () {return this->heal;}
  bool use ();
};

#endif
