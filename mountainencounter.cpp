//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/16/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			Mountainencounter.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Mountain encounter class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "mountainencounter.h"
#include "fight.h"
#include "healingpotion.h"
#include "elixir.h"
#include "shield.h"

using std::cin;
using std::cout;
using std::endl;

// DEFAULT CONSTRUCTOR //
// Description: Creates a mountainencounter object
Mountainencounter::Mountainencounter ()
  : Location ()
{

}

// CONSTRUCTOR //
// Description:  Creates a mountainencounter object using the name argument
Mountainencounter::Mountainencounter (std::string name)
  : Location (name, "Mountain Encounter")
{

}

// DESTRUCTOR //
// Description: Destroys a mountainencounter object
Mountainencounter::~Mountainencounter ()
{

}

// RESOLVE FUNCTION //
// Description: Resolves events in a mountainencounter location.
void Mountainencounter::resolve ()
{
  int pause = hero->getGameSpeed() * 500000;
  int menuChoice = 0;
  bool fight = true;

  cout << "You trek your way across the mountain side." << endl;
  usleep(pause);
  if (this->name == "Central Causeway")
    {
      cout << "You kick a stone along as you walk. The sound echoes off the high walls on either side." << endl;
    }
  else if (this->name == "Lower Mountain Pass")
    {
      cout << "You notice an eagles nest high above you on a tree sticking out of the mountain." << endl;
    }
  else if (this->name == "Bright Clearing")
    {
      cout << "This part of the mountain is very high. You can even see the castle off in the distance." << endl;
    }
  else
    {
      cout << "It would be a long way down if you fell from here!" << endl;
    }
  usleep(pause);

  if (rand() % 2)
    {
      cout << "Everything seems quiet..." << endl;
      usleep(pause);
      fight = false; // No initial fight
      cout << "What would you like to do?" << endl;
      usleep(pause/10);
      cout << "1. Look around" << endl;
      usleep(pause/10);
      cout << "2. Keep going" << endl;
      usleep(pause/10);
      while (menuChoice < 1 || menuChoice > 2)
	{
	  cout << "Choice: ";
	  cin >> menuChoice;
	  cin.clear();
	  cin.ignore(1000, '\n');
	}
      if (menuChoice == 1)
	{
	  if (rand() % 2)
	    {
	      fight = true; // If hero looks and finds a fight
	    }
	  else
	    {
	      if (rand() % 2)
		{
		  cout << "You look around on the mountain. But you don't find anything." << endl;
		  usleep(pause);
		}
	      else
		{
		  int option = rand() % 3; // random item option
		  int clearChoice;
		  unsigned inventoryChoice;
		  bool done = false;
		  Item* thisItem;

		  if (option == 0)
		    {
		      thisItem = new Healingpotion ("Medium Healing Potion", "A medium healing potion. Restores 25 hit points.", 0, this->hero, 25);
		    }
		  else if (option == 1)
		    {
		      thisItem = new Elixir ("Elixir of Life", "A powerful elixir. Permanently increases maximum hit points by 5.", 0, this->hero, 0, 0, 0, 5);
		    }
		  else // (option == 2)
		    {
		      thisItem = new Shield ("Shield of the Mountain", "A strange looking shield. It seems to be made from solid rock! Defence +12.", 0, this->hero, 15);
		    }
		  
		  cout << "You search the Mountain side, and find a " << thisItem->getName() << "!" << endl;
		  usleep(pause);

		  do
		    {
		      if(!this->hero->addItem(thisItem))
			{
			  cout << "Your inventory is currently full." << endl;
			  usleep(pause);
			  cout << "Would you like to clear some space?" << endl;
			  usleep(pause/10);
			  cout << "1. Yes" << endl;
			  usleep(pause/10);
			  cout << "2. No" << endl;
			  clearChoice = 0;
			  while (clearChoice < 1 || clearChoice > 2)
			    {
			      cout << "Choice: ";
			      cin >> clearChoice;
			      cin.clear();
			      cin.ignore(1000, '\n');
			    }
			  if (clearChoice == 1)
			    {
			      cout << "Current Inventory:" << endl;
			      for (unsigned x = 0; x < this->hero->getCarry().size(); x++)
				{
				  usleep(pause/10);
				  cout << x + 1 << ". " << this->hero->getCarry()[x]->getName() << " (" << this->hero->getCarry()[x]->getDescription() << ")" << endl;
				}
			      usleep(pause/10);
			      inventoryChoice = -1;
			      cout << "Enter an item's number to use it or enter 0 to go back." << endl;
			      while (inventoryChoice < 0 || inventoryChoice > this->hero->getCarry().size())
				{
				  usleep(pause/10);
				  cout << "Choice: ";
				  cin >> inventoryChoice;
				  cin.clear();
				  cin.ignore(1000, '\n');
				}
			      if (inventoryChoice && this->hero->getCarry()[inventoryChoice - 1]->use())
				{
				  delete this->hero->getCarry()[inventoryChoice - 1];
				  this->hero->getCarry().erase(this->hero->getCarry().begin() + (inventoryChoice - 1));
				}
			    }
			  else
			    {
			      done = true; // Done if item not wanted
			    }
			}
		      else
			{
			  done = true; // Done if item added
			}
		      
		    } while (!done);
		}
	    }
	}
    }
  if (fight)
    {
      unsigned inventoryChoice = -1;
      int option = rand() % 3;
      int randomiser = rand() % 6;
      int attkMax, attkMin, defMax, defMin, armour, hp;
      int gold;
      Creature* opponent;
      std::string name, battleName;
      if (option == 0)
	{
	  name = "Rabid Rock Badger";
	  attkMax = 50 + randomiser;
	  attkMin = 0 + randomiser;
	  defMax = 10 + randomiser;
	  defMin = 0 + randomiser;
	  armour = 0 + randomiser;
	  hp = 30 + randomiser;
	}
      else if (option == 2)
	{
	  name = "Mountain Ogre"; 
	  attkMax = 30 + randomiser;
	  attkMin = 0 + randomiser;
	  defMax = 25 + randomiser;
	  defMin = 0 + randomiser;
	  armour = 3 + randomiser;
	  hp = 70 + randomiser;
	}
      else // (option == 3)
	{
	  name = "Bandit";
	  attkMax = 25 + randomiser;
	  attkMin = 0 + randomiser;
	  defMax = 25 + randomiser;
	  defMin = 0 + randomiser;
	  armour = 1 + randomiser;
	  hp = 55 + randomiser;
	}
      cout << "Suddenly a " << name << " attacks!" << endl;
      usleep(pause);
      battleName = "The " + name;
      opponent = new Creature (battleName, attkMax, attkMin, defMax, defMin, armour, hp);
      Fight* thisFight = new Fight (hero, opponent, hero->getGameSpeed());

      // Beginning of fight loop

      do
	{
	  cout << "Name: " << name << "   Attack: " << attkMin << "-" << attkMax << "   Defence: " << defMin << "-" << defMax
	       << "   Armour: " << armour << "   Hit Points: " << opponent->getHitPoints() << "/" << opponent->getMaxHitPoints() << endl;
	  usleep(pause/4);
	  cout << hero->getFullName() << ":   Attack: " << hero->getAttackMin() << "-" << hero->getAttackMax() << " (+" << hero->getSword()->getAttack()
	       << ")   Defence: " << hero->getDefenceMin() << "-" << hero->getDefenceMax() << " (+" << hero->getShield()->getDefence() << ")   Armour: "
	       << hero->getArmour() << "   Hit points: " << hero->getHitPoints() << "/" << hero->getMaxHitPoints() << endl;
	  usleep(pause/4);
	  
	  
	  cout << "What are you going to do?" << endl;
	  usleep(pause/10);
	  cout << "1. Continue fight" << endl;
	  usleep(pause/10);
	  cout << "2. Resolve fight" << endl;
	  usleep(pause/10);
	  cout << "3. Use item" << endl;
	  usleep(pause/10);
	  cout << "4. Run" << endl;
	  menuChoice = 0;
	  while (menuChoice < 1 || menuChoice > 4)
	    {
	      usleep(pause/10);
	      cout << "Choice: ";
	      cin >> menuChoice;
	      cin.clear();
	      cin.ignore(1000, '\n');
	    }
	  
	  if (menuChoice == 1)
	    {
	      thisFight->oneRound();
	    }
	  else if (menuChoice == 2)
	    {
	      while (this->hero->getHitPoints() > 0 && opponent->getHitPoints() > 0)
		{
		  thisFight->oneRound();
		}
	    }
	  else if (menuChoice == 3)
	    {
	      if (this->hero->getCarry().size() == 0)
		{
		  cout << "Your inventory is curretly empty." << endl;
		}
	      else
		{
		  cout << "Current Inventory:" << endl;
		  for (unsigned x = 0; x < this->hero->getCarry().size(); x++)
		    {
		      usleep(pause/10);
		      cout << x + 1 << ". " << this->hero->getCarry()[x]->getName() << " (" << this->hero->getCarry()[x]->getDescription() << ")" << endl;
		    }
		  usleep(pause/10);
		  inventoryChoice = -1;
		  cout << "Enter an item's number to use it or enter 0 to go back." << endl;
		  while (inventoryChoice < 0 || inventoryChoice > this->hero->getCarry().size())
		    {
		      usleep(pause/10);
		      cout << "Choice: ";
		      cin >> inventoryChoice;
		      cin.clear();
		      cin.ignore(1000, '\n');
		    }
		  if (inventoryChoice && this->hero->getCarry()[inventoryChoice - 1]->use())
		    {
		      delete this->hero->getCarry()[inventoryChoice - 1];
		      this->hero->getCarry().erase(this->hero->getCarry().begin() + (inventoryChoice - 1));
		    }
		}
	    }
	  else // (menuChoice == 4)
	    {
	      if (rand() % 2)
		{
		  cout << "You escape safely from the battle." << endl;
		  usleep(pause);
		}
	      else
		{
		  cout << "You stumble and cut your self on a jagged rock as you make your escape." << endl;
		  usleep(pause);
		  cout << "-2 Hit Points!" << endl;
		  usleep(pause);
		  hero->addHitPoints(-2);
		}
	    }
	  if (this->hero->getHitPoints() < 1)
	    {
	      delete thisFight;
	      delete opponent;
	      return;
	    }
	} while (opponent->getHitPoints() > 0 && menuChoice != 4); // End of fight loop

      if (menuChoice != 4)
	{
	  gold = rand() % 45;
	  cout << "You defeated " << opponent->getName() << "!" << endl;
	  usleep(pause);
	  cout << "You found " << gold << " gold." << endl;
	  usleep(pause);
	  hero->addGold(gold);
	}

      delete thisFight;
      delete opponent;
    }

  cout << "Press [ENTER] to continue..." << endl;
  cin.get();
}
