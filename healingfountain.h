//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        healingfountain.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Healing fountain class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef HEALINGFOUNTAIN_H_BATESE
#define HEALINGFOUNTAIN_H_BATESE

#include <iostream>
#include <string>
#include "location.h"

class Healingfountain : public Location
{
 protected:
  
 public:
  Healingfountain ();
  Healingfountain (std::string name);
  ~Healingfountain ();
  void resolve ();
};

#endif
