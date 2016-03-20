//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        mountainencounter.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Mountain encounter class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef MOUNTAINENCOUNTER_H_BATESE
#define MOUNTAINENCOUNTER_H_BATESE

#include "location.h"

class Mountainencounter : public Location
{
 protected:

 public:
  Mountainencounter ();
  Mountainencounter (std::string name);
  ~Mountainencounter ();
  void resolve ();
};

#endif
