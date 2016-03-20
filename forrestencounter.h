//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        forrestencounter.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Forrest encounter class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef FORRESTENCOUNTER_H_BATESE
#define FORRESTENCOUNTER_H_BATESE

#include "location.h"

class Forrestencounter : public Location
{
 protected:

 public:
  Forrestencounter ();
  Forrestencounter (std::string name);
  ~Forrestencounter ();
  void resolve ();
};

#endif
