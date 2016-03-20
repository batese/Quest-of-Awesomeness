//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        quest5.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Quest5 class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef QUEST5_H_BATESE
#define QUEST5_H_BATESE

#include "location.h"

class Quest5 : public Location
{
 protected:

 public:
  Quest5 ();
  ~Quest5 ();
  void resolve ();
};

#endif
