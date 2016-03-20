//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        location.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Location class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef LOCATION_H_BATESE
#define LOCATION_H_BATESE

#include <iostream>
#include <string>
#include "hero.h"

class Hero;

class Location
{
 protected:
  std::string name;
  std::string type;
  Hero* hero;
  Location* north;
  Location* east;
  Location* south;
  Location* west;
 public:
  Location ();
  Location (std::string name, std::string type);
  ~Location ();
  void setName (std::string name) {this->name = name;}
  std::string getName () {return this->name;}
  void setType (std::string type) {this->type = type;}
  std::string getType () {return this->type;}
  void setHero (Hero* hero) {this->hero = hero;}
  Hero* getHero () {return this->hero;}
  void setNorth (Location* north) {this->north = north;}
  Location* getNorth () {return this->north;}
  void setEast (Location* east) {this->east = east;}
  Location* getEast () {return this->east;}
  void setSouth (Location* south) {this->south = south;}
  Location* getSouth () {return this->south;}
  void setWest (Location* west) {this->west = west;}
  Location* getWest () {return this->west;}
  virtual void resolve () = 0;
};

#endif
