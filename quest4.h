//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        quest4.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Quest4 class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef QUEST4_H_BATESE
#define QUEST4_H_BATESE

#include "location.h"

class Quest4 : public Location
{
 protected:

 public:
  Quest4 ();
  ~Quest4 ();
  void resolve ();
};

#endif
