//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			Quest1.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Quest1 class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "quest1.h"
#include "creature.h"
#include "fight.h"

using std::cin;
using std::cout;
using std::endl;

// CONSTRUCTOR //
// Descrtiption: Creates a quest1 object
Quest1::Quest1 ()
  : Location ("The Dark Forrest", "Quest")
{

}

// DESTRUCTOR //
// Description: Destroys a quest1 object
Quest1::~Quest1 ()
{

}

// RESOLVE FUNCTION //
// Description: Resolves the events that heppen at the quest1 location. This is mainly just the
//              final showdown of the game.
void Quest1::resolve ()
{
  int pause = hero->getGameSpeed() * 500000;

  if (!hero->getGotAmulet())
    {
      cout << "You step into a clearing in the forrest." << endl;
      usleep(pause);
      cout << "The trees are still sealed shut, and the man is no longer here." << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
    }
  
  else if (!hero->getGotSpell())
    {
      cout << "You step into a clearing in the forrest." << endl;
      usleep(pause);
      cout << "The trees are still sealed shut." << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
    }

  else // hero got spell
    {
      int menuChoice = 0;
      unsigned inventoryChoice;

      cout << "You step into a clearing in the forrest." << endl;
      usleep(pause);
      cout << "The trees infront of you are sealed shut, but you have the Demon's Spell." << endl;
      usleep(pause);
      cout << "Are you ready to face your destiny?" << endl;
      usleep(pause/4);
      cout << "1. Hell yeah!" << endl;
      usleep(pause/4);
      cout << "2. Not yet" << endl;
      while (menuChoice < 1 || menuChoice > 2)
	{
	  usleep(pause/4);
	  cout << "Choice: ";
	  cin >> menuChoice;
	  cin.clear();
	  cin.ignore(1000, '\n');
	}
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
      
      if (menuChoice == 1) // Remove amulet and spell from inventory
	{
	  for (unsigned x = 0; x < this->hero->getCarry().size(); x++)
	    {
	      if (this->hero->getCarry()[x]->getName() == "Amulet of Goodness")
		{
		  delete this->hero->getCarry()[x];
		  this->hero->getCarry().erase(this->hero->getCarry().begin() + x);
		}
	    }	  
	  for (unsigned x = 0; x < this->hero->getCarry().size(); x++)
	    {
	      if (this->hero->getCarry()[x]->getName() == "Demon's Spell")
		{
		  delete this->hero->getCarry()[x];
		  this->hero->getCarry().erase(this->hero->getCarry().begin() + x);
		}
	    }	  
	  
	  cout << "You hear a voice calling your name from behind you." << endl;
	  usleep(pause);
	  cout << "Princess Goodface: \"" << hero->getName() << " wait!\"" << endl;
	  usleep(pause);
	  cout << hero->getName() << ": \"Princess Goodface what are you doing here? This place is dangerous.\"" << endl;
	  usleep(pause);
	  cout << "Princess Goodface: \"I wanted to wish you luck one last time before you face this great evil. Are you ready?\"" << endl;
	  usleep(pause);
	  cout << hero->getName() << ": \"Ready as I will ever be.\"" << endl;
	  usleep(pause);
	  cout << "You take out the demon's spell and examine the script written on the scroll." << endl;
	  usleep(pause);
	  cout << hero->getName() << ": \"What is this? I can't even understand what's written on this scroll.\"" << endl;
	  usleep(pause);
	  cout << "You hand the scroll to Princess Goodface." << endl;
	  usleep(pause);
	  cout << "Princess Goodface: \"This is an ancient language. My father taught me a little about it when I was little. I think I can read it.\"" << endl;
	  usleep(pause);
	  cout << "She begins to slowly sound out the spell from the scroll." << endl;
	  usleep(pause);
	  cout << "..." << endl;
	  usleep(pause);
	  cout << "The ground beneath your feet rumbles." << endl;
	  usleep(pause);
	  cout << "The thick mesh of vines and branches that formed the barrier begin to slide away." << endl;
	  usleep(pause);
	  cout << "A chilling wind rushes fourth from the dark chasm they reveal." << endl;
	  usleep(pause);
	  cout << hero->getName() << ": \"I guess it's time then.\"" << endl;
	  usleep(pause);
	  cout << "You step through into the darkness." << endl;
	  usleep(pause);
	  cout << "Press [ENTER] to continue..." << endl;
	  cin.get();

	  cout << "The trees quickly close up again behind you." << endl;
	  usleep(pause);
	  cout << "A deep voice cuts through the silence, seeming to come from every direction." << endl;
	  usleep(pause);
	  cout << "Voice: \"WHY HAVE YOU COME HERE?\"" << endl;
	  usleep(pause);
	  cout << "Thunder crashes and lightning flashes and all of a sudden a huge dark figure is looming over you." << endl;
	  usleep(pause);
	  cout << "Voice: \"You should not have come back to this place.\"" << endl;
	  usleep(pause);
	  cout << "The dark figure raises one of its mighty fist to crush you." << endl;
	  usleep(pause);
	  cout << "You pull the amulet from your bag and raise it above your head." << endl;
	  usleep(pause);
	  cout << "As the figures fist bares down on you the amulet begins to glow." << endl;
	  usleep(pause);
	  cout << "A column of light beams fourth from the amulet and pierces the figure stright through the chest." << endl;
	  usleep(pause);
	  cout << "It lets out an almighty roar and stumbles back." << endl;
	  usleep(pause);
	  cout << "Voice: \"The amulet!? It can't be! It was lost...\"" << endl;
	  usleep(pause);
	  cout << hero->getName() << ": \"And now it has been found. BE GONE WITH YOU!\"" << endl;
	  usleep(pause);
	  cout << "You point the amulet directly at the dark figure." << endl;
	  usleep(pause);
	  cout << "The towering behemoth that stands infront of you  begins to shrink." << endl;
	  usleep(pause);
	  cout << "Voice: \"Nooooooooooo....\"" << endl;
	  usleep(pause);
	  cout << "Press [ENTER] to continue..." << endl;
	  cin.get();

	  cout << "As the figure continues to shrink the amulet begins to vibrate." << endl;
	  usleep(pause);
	  cout << "Suddenly it shatters." << endl;
	  usleep(pause);
	  cout << "The now almost man-sized figure before you stands back up and begins to laugh." << endl;
	  usleep(pause);
	  cout << "Dark Figure: \"You hold all the power of mankind's goodness in your hands and you still cannot defeat me.\"" << endl;
	  usleep(pause);
	  cout << "Dark Figure: \"Even in my current form you are no match for me. Now you will die.\"" << endl;
	  usleep(pause);
	  cout << "He summons a sword of pure dark energy from the air and charges at you." << endl;
	  usleep(pause);

	  std::string name = "The Dark Figure"; // Set stats for final boss
	  int attkMax = 55;
	  int attkMin = 0;
	  int defMax = 35;
	  int defMin = 0;
	  int armour = 5;
	  int hp = 120;
	  
	  Creature* opponent = new Creature (name, attkMax, attkMin, defMax, defMin, armour, hp);
	  Fight* thisFight = new Fight (this->hero, opponent, this->hero->getGameSpeed());

	  // BEGINNING OF FIGHT LOOP

	  do
	    {
	      cout << "Name: " << name << "   Attack: " << attkMin << "-" << attkMax << "   Defence: " << defMin << "-" << defMax // Show hero and opponent info
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
	      menuChoice = 0;
	      while (menuChoice < 1 || menuChoice > 3)
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
	      else // (menuChoice == 3)
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
	      if (this->hero->getHitPoints() < 1) // Leave if hero does
		{
		  delete thisFight;
		  delete opponent;
		  return;
		}
	    } while (opponent->getHitPoints() > 0); // End of fight loop
	  
	  delete thisFight;
	  delete opponent;
	  
	  cout << "You plunge your sword into the dark figures chest." << endl;
	  usleep(pause);
	  cout << "It shrieks and drops it's sword. Winds begin to rush from all around towards the figure." << endl;
	  usleep(pause);
	  cout << "You step back and watch and a storm quickly gathers around it." << endl;
	  usleep(pause);
	  cout << "Dark Figure: \"What...How...Who are you?\"" << endl;
	  usleep(pause);
	  cout << "You muster your energy to roar back at him." << endl;
	  usleep(pause);
	  cout << hero->getName() << ": \"I am " << hero->getFullName() << "!!!\"" << endl;
	  usleep(pause);
	  cout << "You charge forward and heel kick your sword straight through the figure." << endl;
	  usleep(pause);
	  cout << "He explodes, sending you flying back and knocking you to the ground." << endl;
	  usleep(pause);
	  cout << "A ray of bright light breaks through from the sky above, followed by another, and another." << endl;
	  usleep(pause);
	  cout << "You pull yourself up from the ground and go to sit by a tree as the sky completely clears." << endl;
	  usleep(pause);
	  cout << "It's over." << endl;
	  usleep(pause);
	  cout << "Press [ENTER] to continue..." << endl;
	  cin.get();
	  
	  cout << "CONGRATULATIONS!" << endl;
	  usleep(pause);
	  cout << "You completed Elliot's Super Epic Quest Game!" << endl;
	  usleep(pause);
	  cout << "I hope you enjoyed it." << endl;
	  usleep(pause);
	  cout << "Press [ENTER] to continue..." << endl;
	  cin.get();
	  
	  this->hero->setQuestOver(true);
	}
    }
}
