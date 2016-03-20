//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        quest2.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Quest2 class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef QUEST2_H_BATESE
#define QUEST2_H_BATESE

#include "location.h"

class Quest2 : public Location
{
 protected:

 public:
  Quest2 ();
  ~Quest2 ();
  void resolve ();
};

#endif
