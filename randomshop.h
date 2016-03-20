//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        randomshop.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Random shop class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef RANDOMSHOP_H_BATESE
#define RANDOMSHOP_H_BATESE

#include <iostream>
#include <string>
#include "location.h"

class Randomshop : public Location
{
 protected:
  
 public:
  Randomshop ();
  Randomshop (std::string name);
  ~Randomshop ();
  void resolve ();
};

#endif
