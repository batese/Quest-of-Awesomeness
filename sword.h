//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/16/2015				//
// Last Date Modified:		03/16/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        sword.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		sword class.					//
//////////////////////////////////////////////////////////////////////////
#ifndef SWORD_H_BATESE
#define SWORD_H_BATESE

#include "item.h"

class Hero;

class Sword : public Item
{
 protected:
  int attack;
 public:
  Sword ();
  Sword (std::string name, std::string description, int value, Hero* owned, int attack);
  ~Sword ();
  void setAttack (int attack) {this->attack = attack;}
  int getAttack () {return this->attack;}
  bool use ();
};

#endif
