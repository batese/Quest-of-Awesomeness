/////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		02/05/2015				//
// Last Date Modified:		03/15/2015				//
// Reference To:		CS 162 Final Rpoject			//
// File Name:			fight.h					//
//									//
//	Overview:							//
//		This file contains the class declaration for the Fight	//
//		class.							//
//////////////////////////////////////////////////////////////////////////

#ifndef FIGHT_H_BATESE
#define FIGHT_H_BATESE

#include <iostream>
#include "creature.h"

class Fight
{
 protected:
  Creature* fighter1;
  Creature* fighter2;
  int speed;
 public:
  Fight();
  Fight(Creature* fighter1, Creature* fighter2, int speed);
  ~Fight();
  void setFighter1(Creature* fighter1) {this->fighter1 = fighter1;}
  Creature* getFighter1() {return this->fighter1;}
  void setFighter2(Creature* fighter2) {this->fighter2 = fighter2;}
  Creature* getFighter2() {return this->fighter2;}
  void setSpeed (int speed) {this->speed = speed;}
  int getSpeed () {return this->speed;}
  void swapFighters();
  void oneRound ();
};

#endif
