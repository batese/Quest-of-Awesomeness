//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/16/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			Randomshop.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Randomshop class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <vector>
#include "randomshop.h"
#include "item.h"
#include "healingpotion.h"
#include "elixir.h"
#include "sword.h"
#include "shield.h"

using std::cin;
using std::cout;
using std::endl;

// DEFAULT CONSTRUCTOR //
// Description: Creates a randomshop object
Randomshop::Randomshop ()
  : Location ()
{

}

// CONSTRUCTOR //
// Description: Creates a randomshop object using the name arguemtn as a paramenter
Randomshop::Randomshop (std::string name)
  : Location (name, "Shop")
{

}

// DESTRUCTOR //
// Description: Destroys a randomshop object
Randomshop::~Randomshop ()
{

}

// RESOLVE FUNCTION //
// Description: Resolves events at a random shop
void Randomshop::resolve ()
{
  int pause = this->hero->getGameSpeed() * 500000;
  int randomiser = rand() % 16; // Item value randomiser
  std::string name, description;
  int menuChoice, clearChoice, randomElement, value, heal, attack, defence, armour, hitPoints;
  unsigned itemChoice, inventoryChoice;
  std::vector<Item*> items; // Shops inventor

  // Generate items for sale //

  name = "Small Healing Potion";
  description = "A small healing potion. Restores 15 hit points.";
  value = 5 + randomiser;
  heal = 15;
  Healingpotion* potion1 = new Healingpotion (name, description, value, this->hero, heal);
  items.push_back(potion1);
  
  // RANDOMLY GENERATE LIST OF ITEMS FOR SALE //

  randomElement = rand() % 2;
  if (randomElement)
    {
      name = "Medium Healing Potion";
      description = "A medium healing potion. Restores 25 hit points.";
      value = 10 + randomiser;
      heal = 25;
      Healingpotion* potion2 = new Healingpotion (name, description, value, this->hero, heal);
      items.push_back(potion2);
    }

  randomElement = rand() % 3;
  if (!randomElement)
    {
      name = "Large Healing Potion";
      description = "A large healing potion. Restores 50 hit points.";
      value = 20 + randomiser;
      heal = 50;
      Healingpotion* potion3 = new Healingpotion (name, description, value, this->hero, heal);
      items.push_back(potion3);
    }

  randomElement = rand() % 2;
  if (!randomElement)
    {
      name = "Elixir of Attack";
      description = "A powerful elixr. Increases attack by 4.";
      value = 20 + randomiser;
      attack = 4;
      defence = 0;
      armour = 0;
      hitPoints = 0;
      Elixir* elixir1 = new Elixir (name, description, value, this->hero, attack, defence, armour, hitPoints);
      items.push_back(elixir1);
    }

  randomElement = rand() % 2;
  if (!randomElement)
    {
      name = "Elixir of Defence";
      description = "A powerful elixr. Increases defence by 3.";
      value = 20 + randomiser;
      attack = 0;
      defence = 3;
      armour = 0;
      hitPoints = 0;
      Elixir* elixir2 = new Elixir (name, description, value, this->hero, attack, defence, armour, hitPoints);
      items.push_back(elixir2);
    }

  randomElement = rand() % 3;
  if (!randomElement)
    {
      name = "Elixir of Armour";
      description = "A powerful elixr. Increases armour by 2.";
      value = 20 + randomiser;
      attack = 0;
      defence = 0;
      armour = 2;
      hitPoints = 0;
      Elixir* elixir3 = new Elixir (name, description, value, this->hero, attack, defence, armour, hitPoints);
      items.push_back(elixir3);
    }
  
  randomElement = rand() % 3;
  if (!randomElement)
    {
      name = "Elixir of Life";
      description = "A powerful elixr. Increases maximum hit points by 10.";
      value = 30 + randomiser;
      attack = 0;
      defence = 0;
      armour = 0;
      hitPoints = 10;
      Elixir* elixir4 = new Elixir (name, description, value, this->hero, attack, defence, armour, hitPoints);
      items.push_back(elixir4);
    }

  randomElement = rand() % 5;
  if (!randomElement)
    {
      name = "Elixir of the Dragon";
      description = "A very powerful elixr. Increases attack by 5, defence by 5, armour by 2, and maximum hit points by 10.";
      value = 50 + randomiser;
      attack = 5;
      defence = 5;
      armour = 2;
      hitPoints = 10;
      Elixir* elixir5 = new Elixir (name, description, value, this->hero, attack, defence, armour, hitPoints);
      items.push_back(elixir5);
    }

  randomElement = rand() % 3;
  if (!randomElement)
    {
      name = "Steel Sword";
      description = "A shiney sword. It looks very sharp! Attack +8.";
      value = 35 + randomiser;
      attack = 8;
      Sword* sword1 = new Sword (name, description, value, this->hero, attack);
      items.push_back(sword1);
    }

  randomElement = rand() % 5;
  if (!randomElement)
    {
      name = "Razor Sword";
      description = "A very shiney sword. It's jagged edge looks pretty lethal. Attack +13.";
      value = 55 + randomiser;
      attack = 13;
      Sword* sword2 = new Sword (name, description, value, this->hero, attack);
      items.push_back(sword2);
    }

  randomElement = rand() % 3;
  if (!randomElement)
    {
      name = "Steel Shield";
      description = "A shiney shield. It looks pretty stong. Defence +8.";
      value = 35 + randomiser;
      defence = 8;
      Shield* shield1 = new Shield (name, description, value, this->hero, defence);
      items.push_back(shield1);
    }

  randomElement = rand() % 5;
  if (!randomElement)
    {
      name = "Shield of the Barbarian";
      description = "A huge shield. It looks like it can take a lot of damage. Defence +12.";
      value = 50 + randomiser;
      defence = 12;
      Shield* shield1 = new Shield (name, description, value, this->hero, defence);
      items.push_back(shield1);
    }

  // Interaction at shop //

  cout << "You continue along the trail and arrive at " << this->name << "." << endl;
  usleep(pause);
  cout << "Shop Keeper: \"Greetings weary traveller!\"" << endl;
  usleep(pause);

  do
    {
      menuChoice = 0;
      cout << "Shop Keeper: \"How can I help you today?\"" << endl;
      usleep(pause/4);
      cout << "1. View items for sale" << endl;
      usleep(pause/4);
      cout << "2. Leave" << endl;

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
	  do
	    {
	      if (items.size() == 0)
		{
		  cout << "Shop Keeper: \"I'm afraid we are all out of stock!\"" << endl;
		  usleep(pause);
		  itemChoice = 0;
		}
	      else
		{
		  itemChoice = -1;
		  cout << "Items for sale: (You currently have " << hero->getGold() << " gold)" << endl;
		  for (unsigned x = 0; x < items.size(); x++)
		    {
		      usleep(pause/10);
		      cout << x + 1 << ". " << items[x]->getName() << " - " << items[x]->getValue() << " gold  (" << items[x]->getDescription() << ")" << endl;
		    }
		  usleep(pause/10);
		  cout << "0. Go Back" << endl;
		  while (itemChoice < 0 || itemChoice > items.size())
		    {
		      usleep(pause/10);
		      cout << "Choice: ";
		      cin >> itemChoice;
		      cin.clear();
		      cin.ignore(1000, '\n');
		    }
		  
		  if (itemChoice != 0)
		    {
		      if (items[itemChoice - 1]->getValue() > hero->getGold())
			{
			  cout << "You cannot afford that item!" << endl;
			  usleep(pause);
			}
		      else
			{
			  if (hero->addItem(items[itemChoice - 1]))
			    {
			      cout << items[itemChoice - 1]->getName() << " added to your inventory." << endl;
			      usleep(pause);
			      hero->addGold(-1 * items[itemChoice - 1]->getValue());
			      items.erase(items.begin() + (itemChoice - 1));
			    }
			  else // ALlow hero to clear space if inventory is full
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
			    }
			}
		    } 
		} 
	    } while (itemChoice != 0);
	}
    } while (menuChoice !=2);

  cout << "Shop Keeper: \"So long!\"" << endl;
  usleep(pause);
  cout << "Press [ENTER] to continue..." << endl;
  cin.get();

  for (unsigned x = 0; x < items.size(); x++) // clean items memory
    {
      delete items[x];
      items[x] = NULL;
    }
}
