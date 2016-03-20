//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/16/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			Forrestencounter.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Forrest encounter class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <string>
#include "forrestencounter.h"
#include "fight.h"
#include "healingpotion.h"
#include "elixir.h"
#include "sword.h"

using std::cin;
using std::cout;
using std::endl;

// DEFAULT CONSTRUCTOR //
// Description: Creates a forrest encounter object
Forrestencounter::Forrestencounter ()
  : Location ()
{

}

// CONSTRUCTOR //
// Description: Creates a forrest encounter object and assigns the argument string 'name' to its name
Forrestencounter::Forrestencounter (std::string name)
  : Location (name, "Forrest Encounter")
{

}

// DESTRUCTOR //
// Description: Destroys a forrest encounter object
Forrestencounter::~Forrestencounter ()
{

}

// RESOLVE FUNCTION //
// Description: Resolves events in a forrest encounter locaion. This could be a fight, finding items, or nothing
//              depending on the random elements
void Forrestencounter::resolve ()
{
  int pause = hero->getGameSpeed() * 500000;
  int menuChoice = 0;
  bool fight = true; // If a fight will happen

  cout << "You wander through the forrest." << endl;
  usleep(pause);
  if (this->name == "Tangled Brambles")
    {
      cout << "The brambles are thick. You cut them with your sword to get through." << endl;
    }
  else if (this->name == "Tall Trees")
    {
      cout << "The trees are so tall in this part of the forrest." << endl;
    }
  else if (this->name == "Bright Clearing")
    {
      cout << "The forrest gives way into a bright clearing." << endl;
    }
  else
    {
      cout << "Even in this part of the forrest you can still feel the dark energy." << endl;
    }
  usleep(pause);

  if (rand() % 2) // A fight does not initially happen
    {
      cout << "Everything seems quiet..." << endl;
      usleep(pause);
      fight = false;
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
	      fight = true; // If you look around and you find a fight
	    }
	  else
	    {
	      if (rand() % 2)
		{
		  cout << "You look around in the forrest. But you don't find anything." << endl;
		  usleep(pause);
		}
	      else
		{
		  int option = rand() % 3;
		  int clearChoice;
		  unsigned inventoryChoice;
		  bool done = false;
		  Item* thisItem;

		  if (option == 0) // Make 3 random items that can be found if you look around
		    {
		      thisItem = new Healingpotion ("Small Healing Potion", "A small healing potion. Restores 15 hit points.", 0, this->hero, 15);
		    }
		  else if (option == 1)
		    {
		      thisItem = new Elixir ("Elixir of Attack", "A powerful elixir. Permanently increases attack by 2.", 0, this->hero, 2, 0, 0, 0);
		    }
		  else // (option == 2)
		    {
		      thisItem = new Sword ("Blade of the Forrest", "A strange looking sword. The hilt is made from vines. Attack +8.", 0, this->hero, 8);
		    }
		  
		  cout << "You search in the forrest, and find a " << thisItem->getName() << "!" << endl;
		  usleep(pause);

		  do // Loop to add item to inventory
		    {
		      if(!this->hero->addItem(thisItem)) // Give player the option to clear space if they find an item and it cannot be added
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
			      for (unsigned x = 0; x < this->hero->getCarry().size(); x++) // Print inventory
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
			      done = true; // Done if player doesnt want to make space for item
			    }
			}
		      else
			{
			  done = true; // Done if item is added
			}
		      
		    } while (!done);
		}
	    }
	}
    }
  if (fight)
    {
      unsigned inventoryChoice = -1;
      int option = rand() % 3; // Opponent option number
      int randomiser = rand() % 5; // Opponent stats randomisation
      int attkMax, attkMin, defMax, defMin, armour, hp;
      int gold; // Gold to be won
      Creature* opponent;
      std::string name, battleName;
      if (option == 0) // Make 3 opponent options
	{
	  name = "Forrest Sprite";
	  attkMax = 16 + randomiser;
	  attkMin = 0 + randomiser;
	  defMax = 16 + randomiser;
	  defMin = 0 + randomiser;
	  armour = 0 + randomiser;
	  hp = 40 + randomiser;
	}
      else if (option == 2)
	{
	  name = "Wood Elf"; 
	  attkMax = 22 + randomiser;
	  attkMin = 0 + randomiser;
	  defMax = 14 + randomiser;
	  defMin = 0 + randomiser;
	  armour = 1 + randomiser;
	  hp = 45 + randomiser;
	}
      else // (option == 3)
	{
	  name = "Goblin";
	  attkMax = 18 + randomiser;
	  attkMin = 2 + randomiser;
	  defMax = 16 + randomiser;
	  defMin = 2 + randomiser;
	  armour = 2 + randomiser;
	  hp = 50 + randomiser;
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
		  cout << "You stumble and fall through the thick brush as you make your escape." << endl;
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
	  gold = rand() % 30;
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
