//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        swampencounter.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Swamp encounter class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef SWAMPENCOUNTER_H_BATESE
#define SWAMPENCOUNTER_H_BATESE

#include "location.h"

class Swampencounter : public Location
{
 protected:

 public:
  Swampencounter ();
  Swampencounter (std::string name);
  ~Swampencounter ();
  void resolve ();
};

#endif
