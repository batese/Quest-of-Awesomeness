//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			Quest4.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Quest4 class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "quest4.h"
#include "creature.h"
#include "fight.h"

using std::cin;
using std::cout;
using std::endl;

// CONSTRUCTOR //
// Description: Creates a quest4 object
Quest4::Quest4 ()
  : Location ("Mountain Top", "Quest")
{

}

// DESTRUCTOR //
// Description: Destroys a quest4 object
Quest4::~Quest4 ()
{

}

// RESOLVE FUNCTION //
// Description: Resolves events at the quest3 location (fight with the mountain spirit)
void Quest4::resolve ()
{
  int pause = hero->getGameSpeed() * 500000;
  int menuChoice = 0, menu2Choice = 0, energyChoice;
  unsigned inventoryChoice;
  std::string name;
  int attkMax, attkMin, defMax, defMin, armour, hp;

  cout << "You pull youself up onto the top of the mountain. It's an open plateau with a strange rock formation at the far side." << endl;
  usleep(pause);

  if (!hero->getGotAmulet()) // First visit
    {
      cout << "You hear a voice behind you..." << endl;
      usleep(pause);
      cout << "Voice: \"Wait for me " << hero->getName() << "!\"" << endl;
      usleep(pause);
      cout << "You turn around to see where the voice is coming from." << endl;
      usleep(pause);
      cout << "It's the man from the forrest!" << endl;
      usleep(pause);
      cout << "Man: \"I came as soon as I heard. Did you come up here to fight the mountain spirit?\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"Yeah. Princess Goodface said I had to come up here to get the amulet.\"" << endl;
      usleep(pause);
      cout << "Man: \"The amulet!? It's here!?\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"It's supposed to be. Theres supposed to be a mountain spirit up here protecting it too.\"" << endl;
      usleep(pause);
      cout << "Man: \"Oh god, a mountain spirit? Quick you'll need this.\"" << endl;
      usleep(pause);
      cout << "He hands you a box labeled 'Elemental Energies'." << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();

      cout << "As he hands you the box the mountain begins to rumble." << endl;
      usleep(pause);
      cout << "The strange rock formation on the far side of the plateau begins to morph." << endl;
      usleep(pause);
      cout << "It slowly unfolds into a giant man-like rock beast." << endl;
      usleep(pause);
      cout << "Man: \"It's the mountain spirit!!!\"" << endl;
      usleep(pause);
      cout << "He rushes over to the mountain spirit with his hands raised and begins to chant." << endl;
      usleep(pause);
      cout << "The spirit swings one of it's giant rock fists which smashes into the man." << endl;
      usleep(pause);
      cout << "He flies across the plateau and lands in a heap. He isn't moving." << endl;
      usleep(pause);
      cout << "The mountain spirit rounds on you and begins lumbering towards you." << endl;
      usleep(pause);
      cout << "You look down at the box the man gave you. It contains 4 vials of stange coloured gas." << endl;
      usleep(pause);
      cout << "One of these has got to be the key to defeating this monstrosity." << endl;
      usleep(pause);
      cout << "What are you going to do?" << endl;
      usleep(pause/4);
      cout << "1. Use redish elemental energy" << endl;
      usleep(pause/4);
      cout << "2. Use greyish elemental energy" << endl;
      usleep(pause/4);
      cout << "3. Use blueish elemental energy" << endl;
      usleep(pause/4);
      cout << "4. Use clear elemental energy" << endl;
      usleep(pause/4);

      while (menuChoice < 1 || menuChoice > 4)
	{
	  cout << "Choice: ";
	  cin >> menuChoice;
	  cin.clear();
	  cin.ignore(1000, '\n');
	}
      energyChoice = menuChoice; // Different options for mountain spirit fight
      if (menuChoice == 1)
	{
	  cout << "You throw the redish vial at the mountain spirit. It explodes in a fireball." << endl;
	  usleep(pause);
	  cout << "The fire envelops the mountain spirit. It roars and continues it's charge." << endl;
	  usleep(pause);
	  cout << "Now you have a flaming rock monster to fight. Nice work." << endl;
	  usleep(pause);
	  name = "The Flaming Mountain Spirit";
	  attkMax = 45;
	  attkMin = 5;
	  defMax = 30;
	  defMin = 0;
	  armour = 7;
	  hp = 100;
	}
      else if (menuChoice == 2)
	{
	  cout << "You throw the greyish vial at the mountain spirit. The mountain spirit begins absorbing the energy." << endl;
	  usleep(pause);
	  cout << "The mountain spirit roars and continues it's charge." << endl;
	  usleep(pause);
	  cout << "It's much bigger now. Nice work." << endl;
	  usleep(pause);
	  name = "The Giant Mountain Spirit";
	  attkMax = 35;
	  attkMin = 0;
	  defMax = 30;
	  defMin = 0;
	  armour = 12;
	  hp = 120;
	}
      else if (menuChoice == 3)
	{
	  cout << "You throw the blueish vial at the mountain spirit. It explodes and drenches the mountain spirit." << endl;
	  usleep(pause);
	  cout << "The spirit slips and staggers back. It begins to shed some of its massive body" << endl;
	  usleep(pause);
	  cout << "You've weakened it. Now is the time to strike!" << endl;
	  usleep(pause);
	  name = "The Weakened Mountain Spirit";
	  attkMax = 30;
	  attkMin = 0;
	  defMax = 25;
	  defMin = 0;
	  armour = 2;
	  hp = 60;
	}
      else //(menuChoice == 4)
	{
	  cout << "You throw the clear vial at the mountain spirit. It explodes in a rush of air." << endl;
	  usleep(pause);
	  cout << "The air wistles past the moutnain spirit but it seems unphased. It roars and charges at you." << endl;
	  usleep(pause);
	  cout << "That just seems to have mae it angry. Nice work." << endl;
	  usleep(pause);
	  name = "The Mountain Spirit";
	  attkMax = 35;
	  attkMin = 0;
	  defMax = 25;
	  defMin = 0;
	  armour = 7;
	  hp = 100;
	}
      Creature* opponent = new Creature (name, attkMax, attkMin, defMax, defMin, armour, hp); // name, attkmax, attkmin, defmax, defmin, armour, hp)
      Fight* thisFight = new Fight (hero, opponent, hero->getGameSpeed()); // Create opponent and fight

      // FIGHT LOOP

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
	  if (this->hero->getHitPoints() < 1) // If hero dies
	    {
	      delete thisFight;
	      delete opponent;
	      return;
	    }
	} while (opponent->getHitPoints() > 0); // End of fight loop

      delete thisFight;
      delete opponent;

      cout << "The mountain spirit crumbles to the ground." << endl;
      usleep(pause);
      cout << "It lets out one final groan an its body turns to dust and is carried away on the wind." << endl;
      usleep(pause);
      cout << "You notice a faint glow eminating from the middle of the ash pile and begin to dig." << endl;
      usleep(pause);
      cout << "You find a large purple gemstone, detailed in gold." << endl;
      usleep(pause);
      cout << "You got the amulet!" << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
      
      cout << "A faint voice carries on the wind." << endl;
      usleep(pause);
      cout << "Voice: \"The...\"" << endl;
      usleep(pause);
      cout << "Voice: \"The... Amulet...\"" << endl;
      usleep(pause);
      cout << "It's the man! You rush to his side. He coughs and gasps for air." << endl;
      usleep(pause);
      cout << "Man: \"You... You must get a message to Princess Goodface\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"What message?\"" << endl;
      usleep(pause);
      cout << "Man: \"I sealed the evil away in the forrest with a powerful spell. You won't be able to break it.\"" << endl;
      usleep(pause);
      cout << "Man: \"You will have to find someone who can. Princess Goodface will know what to do.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"I can do that. What about now? What do you need?\"" << endl;
      usleep(pause);
      cout << "Man: \"Bring me my box, I have a final gift for you.\"" << endl;
      usleep(pause);
      cout << "You fetch the man his box. He offers it back to you.\"" << endl;
      usleep(pause);
      cout << "Man: \"Take one. Your body will absorb the elemental energy. It will make you strong.\"" << endl;
      usleep(pause);
      cout << "1. Take redish elemental energy" << endl;
      usleep(pause/4);
      cout << "2. Take greyish elemental energy" << endl;
      usleep(pause/4);
      cout << "3. Take blueish elemental energy" << endl;
      usleep(pause/4);
      cout << "4. Take clear elemental energy" << endl;

      while (menu2Choice < 1 || menu2Choice > 4 || menu2Choice == menuChoice)
	{
	  usleep(pause/4);
	  cout << "Choice: ";
	  cin >> menu2Choice;
	  cin.clear();
	  cin.ignore(1000, '\n');
	  if (menu2Choice == menuChoice)
	    {
	      cout << "You already used that one!" << endl;
	      usleep(pause/4);
	    }
	} // Allow player to pick an energy for themselves

      if (menu2Choice == 1)
	{
	  cout << "You drink the vial of red elemental energy." << endl;
	  usleep(pause);
	  cout << "You feel the power of fire running through you!" << endl;
	  usleep(pause);
	  cout << "Attack +6! Defence +3!" << endl;
	  usleep(pause);
	  hero->addAttack(6);
	  hero->addDefence(3);
	}
      else if (menu2Choice == 2)
	{
	  cout << "You drink the vial of grey elemental energy." << endl;
	  usleep(pause);
	  cout << "You feel the power of stone running through you!" << endl;
	  usleep(pause);
	  cout << "Defence +1! Armour +4!" << endl;
	  usleep(pause);
	  hero->addArmour(4);
	  hero->addDefence(1);
	}
      else if (menu2Choice == 3)
	{
	  cout << "You drink the vial of blue elemental energy." << endl;
	  usleep(pause);
	  cout << "You feel the power of water running through you!" << endl;
	  usleep(pause);
	  cout << "Attack +3! Defence +3! Armour +1!" << endl;
	  usleep(pause);
	  hero->addAttack(3);
	  hero->addDefence(3);
	  hero->addArmour(1);
	}
      else //(menu2Choice == 4)
	{
	  cout << "You drink the vial of clear elemental energy." << endl;
	  usleep(pause);
	  cout << "You feel the power of wind running through you!" << endl;
	  usleep(pause);
	  cout << "Attack +2! Defence +5!" << endl;
	  usleep(pause);
	  hero->addAttack(2);
	  hero->addDefence(5);
	}


      cout << "Man: \"I believe in you " << hero->getName() << ". I believe you will save us all.\"" << endl;
      usleep(pause);
      cout << "Man: \"Now stand back.\"" << endl;
      usleep(pause);
      cout << "You take a few steps back." << endl;
      usleep(pause);
      cout << "The man takes the final 2 vials and smashes them into his chest." << endl;
      usleep(pause);
      cout << "He disappears in a swirling storm of fire and lightning." << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();

      Item* amulet = new Item ("Amulet of Goodness", "A purple gemstone detailed in gold. It looks powerful.", 0, this->hero); // Create amulet and add to inventory
      this->hero->setCarrySize(this->hero->getCarrySize() + 1);
      this->hero->addItem(amulet);
      hero->setCurrentObjective("Go back to the castle and speak with Princess Goodface");
      hero->setGotAmulet(true);
    }
  else // Subsequent visits
    {
      cout << "The mountain top is quiet now. This place brings back bad memories..." << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
    }
}
