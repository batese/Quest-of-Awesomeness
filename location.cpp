//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			Location.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Location class.					//
//////////////////////////////////////////////////////////////////////////

#include "location.h"

// DEFAULT CONSTRUCTOR //
// Description: Assigns values to a new location object
Location::Location ()
{
  this->name = "";
  this->type = "";
  this->north = NULL;
  this->east = NULL;
  this->south = NULL;
  this->west = NULL;
}

// CONSTRUCTOR //
// Description: Assigns values to a new location object. String arguments for name and type
//              are assignmed to the corresponding member variables
Location::Location (std::string name, std::string type)
{
  this->name = name;
  this->type = type;
  this->north = NULL;
  this->east = NULL;
  this->south = NULL;
  this->west = NULL;
}

// DESTRUCTOR //
// Description: Destroys an object of location class
Location::~Location ()
{
  this->north = NULL;
  this->east = NULL;
  this->south = NULL;
  this->west = NULL;
}
