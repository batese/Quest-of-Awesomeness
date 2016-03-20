//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        quest1.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Quest1 class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef QUEST1_H_BATESE
#define QUEST1_H_BATESE

#include "location.h"

class Quest1 : public Location
{
 protected:

 public:
  Quest1 ();
  ~Quest1 ();
  void resolve ();
};

#endif
