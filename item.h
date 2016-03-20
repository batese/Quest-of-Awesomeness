//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/17/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:		        item.h				//
//									//
//	Overview:							//
//		This file contains the class declaration for the	//
//		Item class.					//
//////////////////////////////////////////////////////////////////////////

#ifndef ITEM_H_BATESE
#define ITEM_H_BATESE

#include <iostream>
#include <string>

class Hero;

class Item
{
 protected:
  std::string name;
  std::string description;
  int value;
  Hero* owned;
 public:
  Item ();
  Item (std::string name, std::string description, int value, Hero* owned);
  ~Item ();
  void setName (std::string name) {this->name = name;}
  std::string getName () {return this->name;}
  void setDescription (std::string description) {this->description = description;}
  std::string getDescription () {return this->description;}
  void setValue (int value) {this->value = value;}
  int getValue () {return this->value;}
  void setOwned (Hero* owned) {this->owned = owned;}
  Hero* getOwned () {return this->owned;}
  virtual bool use ();
};

#endif
