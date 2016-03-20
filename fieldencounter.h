//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        fieldencounter.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Field encounter class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef FIELDENCOUNTER_H_BATESE
#define FIELDENCOUNTER_H_BATESE

#include "location.h"

class Fieldencounter : public Location
{
 protected:

 public:
  Fieldencounter ();
  Fieldencounter (std::string name);
  ~Fieldencounter ();
  void resolve ();
};

#endif
