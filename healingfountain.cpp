//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/16/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			Healingfountain.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Healingfountain class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "healingfountain.h"

using std::cin;
using std::cout;
using std::endl;

// CONSTRUCTOR //
// Description: Creates a healingfountain object
Healingfountain::Healingfountain ()
  : Location ()
{

}

// CONSTRUCTOR //
// Description: Creates a healing fountain object using the 'name' argument as a parameter
Healingfountain::Healingfountain (std::string name)
  : Location (name, "Healing Fountain")
{

}

// DESTRUCTOR //
// Description: Destroys a healingfountain object
Healingfountain::~Healingfountain ()
{

}

// RESOLVE FUNCTION //
// Description: Resolves events at a healing fountain
void Healingfountain::resolve ()
{
  int pause = hero->getGameSpeed() * 500000;
  int menuChoice = 0;
  int option; // Random option for messages

  cout << "You arrive at the " << this->name << endl;
  usleep(pause);
  cout << "The water in the fountain looks warm and soothing." << endl;
  usleep(pause);
  cout << "What do you want to do? (Hit Points: " << this->hero->getHitPoints() << "/" << this->hero->getMaxHitPoints() << ")" << endl;
  usleep(pause/4);
  cout << "1. Relax in the healing fountain" << endl;
  usleep(pause/4);
  cout << "2. Keep going" << endl;
  while (menuChoice < 1 || menuChoice > 2)
    {
      usleep(pause/4);
      cout << "Choice: ";
      cin >> menuChoice;
      cin.clear();
      cin.ignore(1000, '\n');
    }

  if (menuChoice == 1)
    {
      cout << "You relax in the fountain. You can feel the healing energy flowing through you." << endl;
      usleep(pause);
      if (rand() % 2) // Chance for nothing to happen
	{
	  cout << "All your troubles just soak away." << endl;
	  usleep(pause);
	}
      else // Chance for a random message
	{
	  option = rand() % 7;
	  if (option == 0) // Hint about moutnain spirit battle
	    {
	      cout << "A strange man comes over and sits next to you." << endl;
	      usleep(pause);
	      cout << "Man: \"There are legends of elemental beasts in these lands.\"" << endl;
	      usleep(pause);
	      cout << "Man: \"Legend has it that each element is weak against it's opposite.\"" << endl;
	      usleep(pause);
	      cout << "Man: \"Like rock is weak against water. Y'know?\"" << endl;
	      usleep(pause);
	    }
	  else if (option == 1)
	    {
	      cout << "A strange man comes over and sits next to you." << endl;
	      usleep(pause);
	      cout << "Man: \"Don't go into the swamp lands. They are full of leeches.\"" << endl;
	      usleep(pause);
	      cout << "Man: \"I hate leeches.\"" << endl;
	      usleep(pause);
	    }
	  else if (option == 2)
	    {
	      cout << "A strange man comes over and sits next to you." << endl;
	      usleep(pause);
	      cout << "Man: \"Did you hear the one about the man who lost his left arm and left leg in a fight?\"" << endl;
	      usleep(pause);
	      cout << "Man: \"He's all right now.\"" << endl;
	      usleep(pause);
	    }
	  else if (option == 3)
	    {
	      cout << "A strange man comes over and sits next to you." << endl;
	      usleep(pause);
	      cout << "Man: \"Did you hear the one about the man who put on a clean pair of socks every day of the week?\"" << endl;
	      usleep(pause);
	      cout << "Man: \"By Friday he could hardly het his boots on.\"" << endl;
	      usleep(pause);
	    }
	  else if (option == 4)
	    {
	      cout << "A strange man comes over and sits next to you." << endl;
	      usleep(pause);
	      cout << "Man: \"Did you hear the one about the the two cyclops who were always arguing with each other?\"" << endl;
	      usleep(pause);
	      cout << "Man: \"They could never see eye to eye.\"" << endl;
	      usleep(pause);
	    }
	  else if (option == 5)
	    {
	      cout << "A strange man comes over and sits next to you." << endl;
	      usleep(pause);
	      cout << "Man: \"Did you hear the one about the man who gave up his job as a fish monger?\"" << endl;
	      usleep(pause);
	      cout << "Man: \"He said it was making him selfish.\"" << endl;
	      usleep(pause);
	    }
	  else // (option == 6)
	    {
	      cout << "A strange man comes over and sits next to you." << endl;
	      usleep(pause);
	      cout << "Man: \"Did you hear the one about the man who opened a flea circus?\"" << endl;
	      usleep(pause);
	      cout << "Man: \"He started it from scratch.\"" << endl;
	      usleep(pause);
	    }
	}
      hero->setHitPoints(hero->getMaxHitPoints()); // Heal hero
    }
  else // (menuChoice == 2)
    {
      cout << "You leave the healing fountain and continue on your journey." << endl;
      usleep(pause);
    }
  cout << "Press [ENTER] to continue..." << endl;
  cin.get();
}
