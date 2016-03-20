//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        quest3.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Quest3 class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef QUEST3_H_BATESE
#define QUEST3_H_BATESE

#include "location.h"

class Quest3 : public Location
{
 protected:

 public:
  Quest3 ();
  ~Quest3 ();
  void resolve ();
};

#endif
