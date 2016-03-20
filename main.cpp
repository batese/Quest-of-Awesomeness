//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/17/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			main.cpp				//
//									//
//	Overview:							//
//		This program is a text based quest game. The player	//
//		must travel between the locations in the game		//
//		collecting items and visiting characters. The game	//
//		alse includes combat.					//
//  									//
//	Input:								//
//		The user chooses from option presnted in a range of	//
//	      	menues. Input is made through the keyboard.		//
//									//
//    	Output:								//
//		Current events and information from the game is		//
//		outputted to the screen for the player to see.		//
//////////////////////////////////////////////////////////////////////////

/////////////
// HEADERS //
/////////////
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "creature.h"
#include "hero.h"
#include "location.h"
#include "quest1.h"
#include "quest2.h"
#include "quest3.h"
#include "quest4.h"
#include "quest5.h"
#include "randomshop.h"
#include "healingfountain.h"
#include "forrestencounter.h"
#include "fieldencounter.h"
#include "swampencounter.h"
#include "mountainencounter.h"
#include "item.h"
#include "elixir.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/////////////////////////
// FUNCTION PROTOTYPES //
/////////////////////////
void makeWorld (std::vector<Location*>& locations);
void showMap ();
void showHead ();
void gameOver ();
void showInstructions ();

///////////////////
// MAIN FUNCTION //
///////////////////
int main(int argc, char **argv)
{
  int mainChoice;
  int gameSpeed = 3;
  bool godMode = false;;

  ///////////////////////
  // MAIN PROGRAM LOOP //
  ///////////////////////

  do
    {
      showHead ();
      cout << "Main Menu:" << endl;
      cout << "1. Play Game" << endl;
      cout << "2. Play Game (skip intro)" << endl;
      cout << "3. Instructions" << endl;
      cout << "4. Settings" << endl;
      cout << "5. Exit Game" << endl;
      mainChoice = 0;
      while (mainChoice < 1 || mainChoice > 5)
	{
	  cout << "Choice: ";
	  cin >> mainChoice;
	  cin.clear();
	  cin.ignore(1000, '\n');
	}
      
      //////////////////////////
      // RUN CODE FOR PROGRAM //
      //////////////////////////

      if (mainChoice == 1 || mainChoice == 2)
	{
	  int menuChoice = 0;
	  int day = 1;
	  unsigned inventoryChoice;
	  bool changeLocation;
	  std::vector<Location*> worldMap; // Create and fill map;
	  std::vector<Location*>* mapPtr;
	  mapPtr = &worldMap;
	  makeWorld(worldMap);
	  string name;
	  string className;
	  srand(time(NULL));
	  int pause = gameSpeed * 500000; // 3000000 good

	  ///////////////////////
	  // GAME INDRODUCTION //
	  ///////////////////////

	  if (mainChoice == 1)
	    {
	      for (int x = 0; x < 100; x++)
		{
		  if (x == 10)
		    {
		      cout << "The" << endl;
		    }
		  else if (x == 30)
		    {
		      cout << "Quest" << endl;
		    }
		  else if (x == 50)
		    {
		      cout << "Will" << endl;
		    }
		  else if (x == 70)
		    {
		      cout << "Begin" << endl;
		    }
		  else if (x == 90)
		    {
		      cout << "Shortly" << endl;
		    }
		  else
		    {
		      cout << "..." << endl;
		    }
		  usleep(50000);
		}
	      for (int x = 0; x < 10; x++)
		{
		  cout << "..." << endl;
		  usleep(300000);
		}
	      for (int x = 0; x < 5; x++)
		{
		  cout << "..." << endl;
		  usleep(800000);
		}
	      
	      usleep(pause);
	      cout << "..." << endl;
	      usleep(pause);
	      cout << "......" << endl;
	      usleep(pause);
	      cout << "........." << endl;
	      usleep(pause);
	      cout << "You awake in a dark forest to the thunderous sound of terror all around you." << endl;
	      usleep(pause);
	      cout << "You have no time to think. You just run." << endl;
	      usleep(pause);
	      cout << "You don't know what the noise is, or what you can feel behind you..." << endl;
	      usleep(pause);
	      cout << "But you know if it catches you then it will be your end." << endl;
	      usleep(pause);
	      cout << "Press [ENTER] to continue..." << endl;
	      cin.get();
	      
	      cout << "Suddenly you burst through a gap in the trees into a small clearing." << endl;
	      usleep(pause);
	      cout << "You collapse to the floor, exhausted, and turn just in time to see a small man." << endl;
	      usleep(pause);
	      cout << "He leaps infront of the opening in the trees and begins to chant." << endl;
	      usleep(pause);
	      cout << "You cling onto your conciousness just long enough to see the gap in the trees begin to close." << endl;
	      usleep(pause);
	      cout << "Press [ENTER] to continue..." << endl;
	      cin.get();
	      
	      cout << "Your eyes slowly open. You are greeted by a strange man." << endl;
	      usleep(pause);
	      cout << "Man: \"That was a close call. What is your name traveller?\"" << endl;
	      cout << "Name (e.g. Terry): ";
	      getline(cin, name);
	      cout << "Man: \"Nice to meet you " << name << ". How did you get in that part of the forrest anyway?\"" << endl;
	      usleep(pause);
	      cout << name << ": \"I don't know. I don't remember much...\"" << endl;
	      usleep(pause);
	      cout << name << ": \"What the hell was chasing me in there?\"" << endl;
	      usleep(pause);
	      cout << "Man: \"I can't be sure. Whatever it was it's bad. Real bad.\"" << endl;
	      usleep(pause);
	      cout << "Press [ENTER] to continue..." << endl;
	      cin.get();
	      
	      cout << "Man: \"Something evil is afoot here. I fear it may be too late to stop it already.\"" << endl;
	      usleep(pause);
	      cout << "Man: \"If you came from inside the forrest though, you may just be the key to stopping it.\"" << endl;
	      usleep(pause);
	      cout << "Man: \"You look like a strong warrior. What kind of warrior are you?\"" << endl;
	      cout << "Class (e.g. Ranger): ";
	      getline(cin, className);
	      cout << name << ": \"So what can I do to help?\"" << endl;
	      usleep(pause);
	      cout << "Man: \"You need to go to the castle. Help will find you there.\"" << endl;
	      usleep(pause);
	      cout << "Man: \"Head East from here into the forrest. Then it's North from there to the Castle.\"" << endl;
	      usleep(pause);
	      cout << "Man: \"Here, take this old sword and shield. I think you will need them.\"" << endl;
	      usleep(pause);
	      cout << "Press [ENTER] to continue..." << endl;
	      cin.get();
	    }
	  else // (mainChoice == 2)
	    {
	      cout << "Please enter a name (e.g. Terry): ";
	      getline(cin, name);
	      cout << "Please enter a class name (e.g. Ranger): ";
	      getline(cin, className);
	    }
	  Hero* myhero = new Hero (name, className, mapPtr, worldMap[5], gameSpeed); // Create hero object 
	  Sword* sword = new Sword ("Old Sword", "An old sowrd. It doesn't look very sharp. Attack +5", 0, myhero, 5);
	  myhero->setSword(sword);
	  Shield* shield = new Shield ("Old Shield", "An old shield. It doesn't look very strong. Defence +5.", 0, myhero, 5);
	  myhero->setShield(shield); // Add base sword and shield to hero

	  if (godMode) // Give godmode elixir and gold if godmode is on
	    {
	      Elixir* elixir = new Elixir ("God Mode Elixir", "Powerful stuff", 0, myhero, 1000, 1000, 100, 1000);
	      myhero->addItem(elixir);
	      myhero->addGold(10000);
	    }
	  
	  if (mainChoice == 1)
	    {
	      cout << "Man: \"I can give you one last bit of help for your journey. Choose one of these powers:\"" << endl;
	      usleep(pause/10);
	    }
	  else
	    {
	      cout << "Choose one of the following perks:" << endl;
	      usleep(pause/10);
	    }
	  cout << "1. Fury of the Beast (+3 Attack)" << endl;
	  usleep(pause/10);
	  cout << "2. Reflexes of the Cat (+3 Defence)" << endl;
	  usleep(pause/10);
	  cout << "3. Hide of the Rhino (+2 Armour)" << endl;
	  usleep(pause/10);
	  while (menuChoice < 1 || menuChoice > 3)
	    {
	      cout << "Perk choice: ";
	      cin >> menuChoice;
	      cin.clear();
	      cin.ignore(1000, '\n');
	    }
	  if (mainChoice == 1)
	    {
	      cout << "The man begins to chant. You feel a strange power course through your body." << endl;
	      usleep(pause);
	    }
	  
	  if (menuChoice == 1)
	    {
	      myhero->addAttack(3);
	      cout << "Attack +3!" << endl;
	    }
	  else if (menuChoice == 2)
	    {
	      myhero->addDefence(3);
	      cout << "Defence +3!" << endl;
	    }
	  else
	    {
	      myhero->addArmour(2);
	      cout << "Armour +2!" << endl;
	    }
	  
	  usleep(pause/2);
	  cout << "Man: \"Well " << myhero->getFullName() << ", you'd better get on your way.\"" << endl;
	  usleep(pause);
	  cout << "Press [ENTER] to continue..." << endl;
	  cin.get();
	  
	  for (unsigned x = 0; x < worldMap.size(); x++) // Connect hero and locations
	    {
	      worldMap[x]->setHero(myhero);
	    }
	  
	  /////////////////////////////////
	  // MAIN GAME AND MOVEMENT LOOP //
	  /////////////////////////////////

	  do
	    {
	      cout << endl;
	      pause = myhero->getGameSpeed() * 500000;
	      cout << "Day " << day << ": " << myhero->getCurrentLocation()->getName() << endl;
	      usleep(pause);
	      myhero->getCurrentLocation()->resolve(); // Call function for current location
	      if (myhero->getHitPoints() < 1)
		{
		  cout << "You are dead." << endl; // End game if hero dies in the current location
		  usleep(pause);
		  gameOver ();
		  myhero->setQuestOver(true);
		}
	      if (!myhero->getQuestOver())
		{
		  changeLocation = false;

		  //////////////////////////////////////
		  // MOVEMENT/INTERACTION CHOICE LOOP //
		  //////////////////////////////////////

		  do
		    {
		      menuChoice = 0;
		      cout << "What would you like to do now? (Current Location: " << myhero->getCurrentLocation()->getName() << ")" << endl;
		      usleep(pause/10);
		      if (myhero->getCurrentLocation()->getNorth()) // Show movement options
			{
			  cout << "1. Go North (" << myhero->getCurrentLocation()->getNorth()->getName() << ")" << endl;
			}
		      else
			{
			  cout << "1. Go North (Nothing)" << endl;
			}
		      usleep(pause/10);
		      if (myhero->getCurrentLocation()->getEast())
			{
			  cout << "2. Go East (" << myhero->getCurrentLocation()->getEast()->getName() << ")" << endl;
			}
		      else
			{
			  cout << "2. Go East (Nothing)" << endl;
			}
		      usleep(pause/10);
		      if (myhero->getCurrentLocation()->getSouth())
			{
			  cout << "3. Go South (" << myhero->getCurrentLocation()->getSouth()->getName() << ")" << endl;
			}
		      else
			{
			  cout << "3. Go South (Nothing)" << endl;
			}
		      usleep(pause/10);
		      if (myhero->getCurrentLocation()->getWest())
			{
			  cout << "4. Go West (" << myhero->getCurrentLocation()->getWest()->getName() << ")" << endl;
			}
		      else
			{
			  cout << "4. Go West (Nothing)" << endl;
			}
		      usleep(pause/10);
		      cout << "5. Check Map" << endl;
		      usleep(pause/10);
		      cout << "6. Inspect " << myhero->getFullName() << "/Use Items" << endl;
		      usleep(pause/10);
		      cout << "7. Game Settings" << endl;
		      usleep(pause/10);
		      cout << "8. Help" << endl;
		      usleep(pause/10);
		      cout << "9. Exit To Main Menu" << endl;
		      
		      while (menuChoice < 1 || menuChoice > 9)
			{
			  usleep(pause/10);
			  cout << "Choice: ";
			  cin >> menuChoice;
			  cin.clear();
			  cin.ignore(1000, '\n');
			}
		      
		      if (menuChoice == 1) // GOING NORTH
			{
			  if (myhero->getCurrentLocation()->getNorth())
			    {
			      if (myhero->getCurrentLocation()->getName() == "Central Causeway")
				{
				  if (!myhero->getGotLadder())
				    {
				      cout << "This rockface is too steep to climb. Better keep looking for some help." << endl;
				      usleep(pause/2);
				      cout << "Press [ENTER] to continue..." << endl;
				      cin.get();
				    }
				  else
				    {
				      cout << "You climb the ladder to reach the Upper Mountain Pass." << endl;
				      usleep(pause/2);
				      cout << "Press [ENTER] to continue..." << endl;
				      cin.get();
				      myhero->setCurrentLocation(myhero->getCurrentLocation()->getNorth());
				      changeLocation = true;
				      for (unsigned x = 0; x < myhero->getCarry().size(); x++)
					{
					  if (myhero->getCarry()[x]->getName() == "Ladder")
					    {
					      delete myhero->getCarry()[x];
					      myhero->getCarry().erase(myhero->getCarry().begin() + x);
					    }
					}	  
				    }
				}
			      else
				{
				  myhero->setCurrentLocation(myhero->getCurrentLocation()->getNorth());
				  changeLocation = true;
				}
			    }
			  else
			    {
			      cout << "You can't go that way." << endl;
			      usleep(pause/2);
			      cout << "Press [ENTER] to continue..." << endl;
			      cin.get();
			    }
			}
		      else if (menuChoice == 2) // GOING EAST
			{
			  if (myhero->getCurrentLocation()->getEast())
			    {
			      if ((myhero->getCurrentLocation()->getName() == "Retupmoc field North-East" && !myhero->getCastleVisited())
				  || (myhero->getCurrentLocation()->getName() == "Retupmoc field East" && !myhero->getCastleVisited())
				  || (myhero->getCurrentLocation()->getName() == "Retupmoc field South-East" && !myhero->getCastleVisited()))
				{
				  cout << "You must go and visit the castle before continuing your quest." << endl;
				  usleep(pause/2);
				  cout << "Press [ENTER] to continue..." << endl;
				  cin.get();
				}
			      else
				{
				  myhero->setCurrentLocation(myhero->getCurrentLocation()->getEast());
				  changeLocation = true;
				}
			    }
			  else
			    {
			      cout << "You can't go that way." << endl;
			      usleep(pause/2);
			      cout << "Press [ENTER] to continue..." << endl;
			      cin.get();
			    }
			}
		      else if (menuChoice == 3) // GOING SOUTH
			{
			  if (myhero->getCurrentLocation()->getSouth())
			    {
			      myhero->setCurrentLocation(myhero->getCurrentLocation()->getSouth());
			      changeLocation = true;
			    }
			  else
			    {
			      cout << "You can't go that way." << endl;
			      usleep(pause/2);
			      cout << "Press [ENTER] to continue..." << endl;
			      cin.get();
			    }
			}
		      else if (menuChoice == 4) // GOING WEST
			{
			  if (myhero->getCurrentLocation()->getWest())
			    {
			      if ((myhero->getCurrentLocation()->getName() == "Retupmoc field West" && !myhero->getCastleVisited())
				  || (myhero->getCurrentLocation()->getName() == "Retupmoc field South-West" && !myhero->getCastleVisited()))
				{
				  cout << "You must go and visit the castle before continuing your quest." << endl;
				  usleep(pause/2);
				  cout << "Press [ENTER] to continue..." << endl;
				  cin.get();
				}
			      else if ((myhero->getCurrentLocation()->getName() == "Retupmoc field West" && !myhero->getCastleRevisited())
				       || (myhero->getCurrentLocation()->getName() == "Retupmoc field South-West" && !myhero->getCastleRevisited()))
				{
				  cout << "Go and find the amulet and take it to the Princess before you venture into the swamp." << endl;
				  usleep(pause/2);
				  cout << "Press [ENTER] to continue..." << endl;
				  cin.get();
				}
			      else
				{
				  myhero->setCurrentLocation(myhero->getCurrentLocation()->getWest());
				  changeLocation = true;
				}
			    }
			  else
			    {
			      cout << "You can't go that way." << endl;
			      usleep(pause/2);
			      cout << "Press [ENTER] to continue..." << endl;
			      cin.get();
			    }
			}
		      else if (menuChoice == 5) // VIEW MAP
			{
			  showMap();
			  cout << "Press [ENTER] to continue..." << endl;
			  cin.get();
			}
		      else if (menuChoice == 6) // INSPECT HERO
			{
			  inventoryChoice = -1;
			  cout << "Name: " << myhero->getFullName() << "   Current Gold: " << myhero->getGold() << endl;
			  usleep(pause/10);
			  cout << "Current Objective: " << myhero->getCurrentObjective() << endl;
			  usleep(pause/10);
			  cout << "Sword: " << myhero->getSword()->getName() << " (+" << myhero->getSword()->getAttack() << ")" << "   Shield: "
			       << myhero->getShield()->getName() << " (+" << myhero->getShield()->getDefence() << ")" << endl;
			  usleep(pause/10);
			  cout << "Attack: " << myhero->getAttackMin() << "-" << myhero->getAttackMax() << "   Defence: " << myhero->getDefenceMin()
			       << "-" << myhero->getDefenceMax() << "   Armour: " << myhero->getArmour() << "   Hit Points: "
			       << myhero->getHitPoints() << "/" << myhero->getMaxHitPoints() << endl;
			  usleep(pause/10);
			  if (myhero->getCarry().size() == 0)
			    {
			      cout << "Your inventory is curretly empty." << endl;
			    }
			  else
			    {
			      cout << "Current Inventory: (Inventory capacity: " << myhero->getCarrySize() << ")" << endl; // SHOW INVENTORY AND ALLOW ITEMS TO BE USED
			      for (unsigned x = 0; x < myhero->getCarry().size(); x++)
				{
				  usleep(pause/10);
				  cout << x + 1 << ". " << myhero->getCarry()[x]->getName() << " (" << myhero->getCarry()[x]->getDescription() << ")" << endl;
				}
			      usleep(pause/10);
			      cout << "Enter an item's number to use it or enter 0 to go back." << endl;
			      while (inventoryChoice < 0 || inventoryChoice > myhero->getCarry().size())
				{
				  usleep(pause/10);
				  cout << "Choice: ";
				  cin >> inventoryChoice;
				  cin.clear();
				  cin.ignore(1000, '\n');
				}
			      if (inventoryChoice && myhero->getCarry()[inventoryChoice - 1]->use())
				{
				  delete myhero->getCarry()[inventoryChoice - 1];
				  myhero->getCarry().erase(myhero->getCarry().begin() + (inventoryChoice - 1));
				}
			    }
			  cout << "Press [ENTER] to continue..." << endl;
			  cin.get();
			}
		      else if (menuChoice == 7) // GAME SETTINGS (game speed)
			{
			  cout << "The game speed effects how quickly new lines of text are printed on the screen." << endl;
			  usleep(pause/2);
			  cout << "Current Game Speed: " << myhero->getGameSpeed() << endl;
			  usleep(pause/2);
			  do
			    {
			      cout << "Enter a new game speed from 1 - 5: ";
			      cin >> gameSpeed;
			      cin.clear();
			      cin.ignore(1000, '\n');
			      usleep(pause/10);
			    } while (gameSpeed < 1 || gameSpeed > 5);
			  cout << "Game speed updated. Changes will take effect after you travel to a new location." << endl;
			  usleep(pause);
			  myhero->setGameSpeed(gameSpeed);
			  cout << "Press [ENTER] to continue..." << endl;
			  cin.get();
			}
		      else if (menuChoice == 8)  // HELP
			{
			  showInstructions();
			}
		      else // (menuChoice == 9)
			{
			  changeLocation = true; // Exit game
			  myhero->setQuestOver(true);
			}
		    }while(!changeLocation);
		}
	      day++;
	      
	      if (day == 100)
		{
		  cout << "The sky begins to turn dark. Thunder rumbles and lightning flashes." << endl;
		  usleep(pause);
		  cout << "You are too late..." << endl;
		  usleep(pause);
		  gameOver ();
		  myhero->setQuestOver(true);
		}
	  	      
	    }while(!myhero->getQuestOver()); // END OF MAIN GAME LOOP
	  
	  delete myhero;
	  
	  while(!worldMap.empty()) // Clean up map memory
	    {
	      delete worldMap[worldMap.size() - 1];
	      worldMap[worldMap.size() - 1] = NULL;
	      worldMap.erase(worldMap.end()-1);
	    }
	}
      else if (mainChoice == 3) // Main menu instruction option
	{
	  showInstructions();
	}
      else if (mainChoice == 4) // Main menu settings option
	{
	  int settingsChoice = 0;
	  cout << "Settings Menu:" << endl;
	  cout << "1. Change game speed" << endl;
	  cout << "2. Toggle god mode";
	  if (godMode)
	    {
	      cout << " (God mode is ON)" << endl;
	    }
	  else
	    {
	      cout << " (God mode if OFF)" << endl;
	    }
	  cout << "3. Back to main menu" << endl;
	  while (settingsChoice < 1 || settingsChoice > 3)
	    {
	      cout << "Choice: ";
	      cin >> settingsChoice;
	      cin.clear();
	      cin.ignore(1000, '\n');
	    }
	  if (settingsChoice == 1) // Game speed
	    {
	      cout << "The game speed effects how quickly new lines of text are printed on the screen." << endl;
	      cout << "You probably shouldn't change this if this is your first time playing the game." << endl;
	      cout << "Current Game Speed: " << gameSpeed << endl;
	      do
		{
		  cout << "Enter the new game speed (from 1 - 5): ";
		  cin >> gameSpeed;
		  cin.clear();
		  cin.ignore(1000, '\n');
		} while (gameSpeed < 1 || gameSpeed > 5);
	      cout << "Game speed updated." << endl;
	      cout << "Press [ENTER] to continue..." << endl;
	      cin.get();
	    }
	  else if (settingsChoice == 2) // God mode
	    {
	      if (godMode)
		{
		  godMode = false;
		}
	      else
		{
		  godMode = true;
		}
	    }
	}
    } while (mainChoice != 5); // End of main program loop

  return 0;
}

// MAKE WORLD FUNCTION //
// Description: This function accepts a reference to a vector of pointers to locations. The location
//              pointers and locations for the game are created and added to the vector. This function
//              is used to generate the game world.
void makeWorld (std::vector<Location*>& locations)
{
  Quest1* quest1 = new Quest1;
  Quest2* quest2 = new Quest2;
  Quest3* quest3 = new Quest3;
  Quest4* quest4 = new Quest4;
  Quest5* quest5 = new Quest5;
  Healingfountain* forrestheal1 = new Healingfountain ("Quiet Clearing Healing Fountain");
  Healingfountain* forrestheal2 = new Healingfountain ("Forrest Pass Healing Fountain");
  Healingfountain* swampheal = new Healingfountain ("Smelly Swamp Healing Fountain");
  Healingfountain* mountainheal = new Healingfountain ("Mountain Pass Healing Fountain");
  Randomshop* forrestshop = new Randomshop ("Forrest Trinkets");
  Randomshop* swampshop = new Randomshop ("Swamp Supplies");
  Randomshop* mountainshop = new Randomshop ("Mountain Stores");
  Forrestencounter* forrest1 = new Forrestencounter ("Tangled Brambles");
  Forrestencounter* forrest2 = new Forrestencounter ("Tall Trees");
  Forrestencounter* forrest3 = new Forrestencounter ("Bright Clearing");
  Forrestencounter* forrest4 = new Forrestencounter ("Tranquil Pond");
  Fieldencounter* field1 = new Fieldencounter ("Retupmoc field North-West");
  Fieldencounter* field2 = new Fieldencounter ("Retupmoc field North");
  Fieldencounter* field3 = new Fieldencounter ("Retupmoc field North-East");
  Fieldencounter* field4 = new Fieldencounter ("Retupmoc field East");
  Fieldencounter* field5 = new Fieldencounter ("Retupmoc field South-East");
  Fieldencounter* field6 = new Fieldencounter ("Retupmoc field South");
  Fieldencounter* field7 = new Fieldencounter ("Retupmoc field South-West");
  Fieldencounter* field8 = new Fieldencounter ("Retupmoc field West");
  Swampencounter* swamp1 = new Swampencounter ("Swamp Entrance");
  Swampencounter* swamp2 = new Swampencounter ("Brimming Bog");
  Swampencounter* swamp3 = new Swampencounter ("Misty Marshes");
  Swampencounter* swamp4 = new Swampencounter ("Southern Marshes");
  Swampencounter* swamp5 = new Swampencounter ("Northern Marshes");
  Swampencounter* swamp6 = new Swampencounter ("Eastern Marshes");
  Swampencounter* swamp7 = new Swampencounter ("Abandoned Shack");
  Mountainencounter* mountain1 = new Mountainencounter ("Central Causeway");
  Mountainencounter* mountain2 = new Mountainencounter ("Lower Mountain pass");
  Mountainencounter* mountain3 = new Mountainencounter ("Upper Mountain pass");
  Mountainencounter* mountain4 = new Mountainencounter ("Mountain Trail");
  Mountainencounter* mountain5 = new Mountainencounter ("Rocky River");

  quest1->setEast(forrestheal1);
  quest2->setNorth(field2);
  quest2->setEast(field4);
  quest2->setSouth(field6);
  quest2->setWest(field8);
  quest3->setNorth(mountain2);
  quest3->setWest(mountainshop);
  quest4->setSouth(mountain3);
  quest5->setNorth(swamp2);
  quest5->setEast(swamp4);

  forrestheal1->setWest(quest1);
  forrestheal1->setEast(forrest1);
  forrestheal2->setNorth(field6);
  forrestheal2->setEast(forrest4);
  forrestheal2->setSouth(forrest2);
  swampheal->setEast(field8);
  swampheal->setSouth(swamp6);
  swampheal->setWest(swamp1);
  mountainheal->setNorth(mountain4);
  mountainheal->setEast(mountain1);
  mountainheal->setSouth(mountain5);
  mountainheal->setWest(field4);

  forrestshop->setWest(forrest1);
  forrestshop->setNorth(forrest3);
  swampshop->setEast(swamp1);
  swampshop->setSouth(swamp2);
  mountainshop->setNorth(mountain1);
  mountainshop->setEast(quest3);
  mountainshop->setWest(mountain5);

  forrest1->setWest(forrestheal1);
  forrest1->setEast(forrestshop);
  forrest1->setNorth(forrest2);
  forrest2->setNorth(forrestheal2);
  forrest2->setEast(forrest3);
  forrest2->setSouth(forrest1);
  forrest3->setNorth(forrest4);
  forrest3->setWest(forrest2);
  forrest3->setSouth(forrestshop);
  forrest4->setNorth(field5);
  forrest4->setSouth(forrest3);
  forrest4->setWest(forrestheal2);

  field1->setEast(field2);
  field1->setSouth(field8);
  field2->setEast(field3);
  field2->setSouth(quest2);
  field2->setWest(field1);
  field3->setEast(mountain4);
  field3->setSouth(field4);
  field3->setWest(field2);
  field4->setNorth(field3);
  field4->setEast(mountainheal);
  field4->setSouth(field5);
  field4->setWest(quest2);
  field5->setNorth(field4);
  field5->setEast(mountain5);
  field5->setSouth(forrest4);
  field5->setWest(field6);
  field6->setNorth(quest2);
  field6->setEast(field5);
  field6->setSouth(forrestheal2);
  field6->setWest(field7);
  field7->setNorth(field8);
  field7->setEast(field6);
  field7->setWest(swamp6);
  field8->setNorth(field1);
  field8->setEast(quest2);
  field8->setSouth(field7);
  field8->setWest(swampheal);

  mountain1->setNorth(mountain3);
  mountain1->setEast(mountain2);
  mountain1->setSouth(mountainshop);
  mountain1->setWest(mountainheal);
  mountain2->setSouth(quest3);
  mountain2->setWest(mountain1);
  mountain3->setNorth(quest4);
  mountain3->setSouth(mountain1);
  mountain4->setSouth(mountainheal);
  mountain4->setWest(field3);
  mountain5->setNorth(mountainheal);
  mountain5->setEast(mountainshop);
  mountain5->setWest(field5);

  swamp1->setNorth(swamp5);
  swamp1->setEast(swampheal);
  swamp1->setSouth(swamp3);
  swamp1->setWest(swampshop);
  swamp2->setNorth(swampshop);
  swamp2->setEast(swamp3);
  swamp2->setSouth(quest5);
  swamp3->setNorth(swamp1);
  swamp3->setEast(swamp6);
  swamp3->setSouth(swamp4);
  swamp3->setWest(swamp2);
  swamp4->setNorth(swamp3);
  swamp4->setWest(quest5);
  swamp5->setNorth(swamp7);
  swamp5->setSouth(swamp1);
  swamp6->setNorth(swampheal);
  swamp6->setEast(field7);
  swamp6->setWest(swamp3);
  swamp7->setSouth(swamp5);

  locations.push_back(quest1);
  locations.push_back(quest2);
  locations.push_back(quest3);
  locations.push_back(quest4);
  locations.push_back(quest5);
  locations.push_back(forrestheal1);
  locations.push_back(forrestheal2);
  locations.push_back(mountainheal);
  locations.push_back(swampheal);
  locations.push_back(forrestshop);
  locations.push_back(swampshop);
  locations.push_back(mountainshop);
  locations.push_back(forrest1);
  locations.push_back(forrest2);
  locations.push_back(forrest3);
  locations.push_back(forrest4);
  locations.push_back(field1);
  locations.push_back(field2);
  locations.push_back(field3);
  locations.push_back(field4);
  locations.push_back(field5);
  locations.push_back(field6);
  locations.push_back(field7);
  locations.push_back(field8);
  locations.push_back(mountain1);
  locations.push_back(mountain2);
  locations.push_back(mountain3);
  locations.push_back(mountain4);
  locations.push_back(mountain5);
  locations.push_back(swamp1);
  locations.push_back(swamp2);
  locations.push_back(swamp3);
  locations.push_back(swamp4);
  locations.push_back(swamp5);
  locations.push_back(swamp6);
  locations.push_back(swamp7);
}

// SHOW MAP FUNCTION //
// Description: This function prints a graphic for the game world map to the screen. It is used to display the 
//              map during the game.
void showMap ()
{
  cout << "==============================================================================================================================" << endl;
  cout << "|                                                                                                                            |" << endl;
  cout << "|     N                                W   W   O   RR R  L     DDD     M   M   A   PPPP                                      |" << endl;
  cout << "|     ^                                W   W  O O  R   R L     D  D    MM MM  A A  P   P                                     |" << endl;
  cout << "|     |           ++++++++++++         W W W O   O RRRR  L     D   D   M M M  AAA  PPPP         ++++++++++++                 |" << endl;
  cout << "|   W   E         +          +         WW WW  O O  R  R  L     D  D    M   M A   A P            +          +                 |" << endl;
  cout << "|     S           +Abandoned +         W   W   O   R   R LLLLL DDD     M   M A   A P            + Mountain +                 |" << endl;
  cout << "|                 +  Shack   +                                                                  +   Top    +                 |" << endl;
  cout << "|                 +          +                                                                  +          +                 |" << endl;
  cout << "|                 ++++++++++++                                                                  ++++++++++++                 |" << endl;
  cout << "|                 ++++++++++++              ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++|++++++++++++                 |" << endl;
  cout << "|                 +          +              + Retupmoc + + Retupmoc + + Retupmoc + +          +|+  Upper   +                 |" << endl;
  cout << "|                 + Northern +              +  Field   + +  Field   + +  Field   + + Mountain +|+ Mountain +                 |" << endl;
  cout << "|                 + Marshes  +              +  North-  + +  North   + +  North-  + +  Trail   +|+   Pass   +                 |" << endl;
  cout << "|                 +          +              +   West   + +          + +   East   + +          +|+          +                 |" << endl;
  cout << "|                 ++++++++++++              ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++|++++++++++++                 |" << endl;
  cout << "|    ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++    |" << endl;
  cout << "|    +          + +          + +  Smelly  + + Retupmoc + +          + + Retupmoc + + Mountain + +          + +  Lower   +    |" << endl;
  cout << "|    +  Swamp   + +  Swamp   + +  Swamp   + +  Field   + + Retupmoc + +  Field   + +   Pass   + + Central  + + Mountain +    |" << endl;
  cout << "|    + Supplies + + Entrance + + Healing  + +   West   + +  Castle  + +   East   + + Healing  + + Causeway + +   Pass   +    |" << endl;
  cout << "|    +          + +          + + Fountain + +          + +          + +          + + Fountain + +          + +          +    |" << endl;
  cout << "|    ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++    |" << endl;
  cout << "|    ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++    |" << endl;
  cout << "|    +          + +          + +          + + Retupmoc + + Retupmoc + + Retupmoc + +          + +          + +          +    |" << endl;
  cout << "|    + Brimming + +  Misty   + + Eastern  + +  Field   + +  Field   + +  Field   + +  Rocky   + + Mountain + +  Small   +    |" << endl;
  cout << "|    +   Bog    + + Marshes  + + Marshes  + +  South-  + +  South   + +  South-  + +  River   + +  Stores  + +   Cave   +    |" << endl;
  cout << "|    +          + +          + +          + +   West   + +          + +   East   + +          + +          + +          +    |" << endl;
  cout << "|    ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++    |" << endl;
  cout << "|    ++++++++++++ ++++++++++++                           ++++++++++++ ++++++++++++                                           |" << endl;
  cout << "|    +          + +          +                           + Forrest  + +          +                                           |" << endl;
  cout << "|    +  Misty   + + Southern +                           +   Pass   + + Tranquil +                                           |" << endl;
  cout << "|    +  Swamp   + + Marshes  +                           + Healing  + +   Pond   +                                           |" << endl;
  cout << "|    +          + +          +                           + Fountain + +          +                                           |" << endl;
  cout << "|    ++++++++++++ ++++++++++++                           ++++++++++++ ++++++++++++                                           |" << endl;
  cout << "|                                                        ++++++++++++ ++++++++++++                                           |" << endl;
  cout << "|                                                        +          + +          +                                           |" << endl;
  cout << "|                                                        +   Tall   + +  Bright  +                                           |" << endl;
  cout << "|                                                        +  Trees   + + Clearing +                                           |" << endl;
  cout << "|                                                        +          + +          +                                           |" << endl;
  cout << "|                                                        ++++++++++++ ++++++++++++                                           |" << endl;
  cout << "|                              ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++                                           |" << endl;
  cout << "|                              +          + +  Quiet   + +          + +          +                                           |" << endl;
  cout << "|                              +   Dark   + + Clearing + + Tangled  + + Forrest  +                                           |" << endl;
  cout << "|                              + Forrest  + + Healing  + + Brambles + + Trinkets +                                           |" << endl;
  cout << "|                              +          + + Fountain + +          + +          +                                           |" << endl;
  cout << "|                              ++++++++++++ ++++++++++++ ++++++++++++ ++++++++++++                                           |" << endl;
  cout << "|                                                                                                                            |" << endl;
  cout << "|                                                                                                                            |" << endl;
  cout << "==============================================================================================================================" << endl;
}

// SHOW HEAD FUNCTION //
// Description: Displays the header ghraphic for the main program.
void showHead ()
{
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
  cout << endl;
  cout << "                                                                         )" << endl;
  cout << "                                                                           (" << endl;
  cout << "                                                                        '    } " << endl;
  cout << "                                                                      (    '    " << endl;
  cout << "                                                                     '      ( " << endl;
  cout << "                                                                      )  |    ) " << endl;
  cout << "                                                                    '   /|\\    `" << endl;
  cout << "                                                                   )   / | \\  ` )   " << endl;
  cout << "                                                                  {    | | |  {   " << endl;
  cout << "    _______           _______  _______ _________                 }     | | |  ." << endl;
  cout << "   (  ___  )|\\     /|(  ____ \\(  ____ \\\\__   __/                  '    | | |    )" << endl;
  cout << "   | (   ) || )   ( || (    \\/| (    \\/   ) (                    (    /| | |\\    ." << endl;
  cout << "   | |   | || |   | || (__    | (_____    | |                     .  / | | | \\  (" << endl;
  cout << "   | |   | || |   | ||  __)   (_____  )   | |                   }    \\ \\ | / /  .    " << endl;
  cout << "   | | /\\| || |   | || (            ) |   | |                    (    \\ `-' /    }" << endl;
  cout << "   | (_\\ \\ || (___) || (____/\\/\\____) |   | |                    .    / ,-. \\    ' " << endl;
  cout << "   (____\\/_)(_______)(_______/\\_______)   )_(                     }  / / | \\ \\  }" << endl;
  cout << "                                                                 '   \\ | | | /   }" << endl;
  cout << "                                                                  (   \\| | |/  (" << endl;
  cout << "                                                                    )  | | |  )" << endl;
  cout << "    _______  _______                                                .  | | |  '" << endl;
  cout << "   (  ___  )(  ____ \\                                                  J | L" << endl;
  cout << "   | (   ) || (    \\/                                            /|    J_|_L    |\\ " << endl;
  cout << "   | |   | || (__                                                \\ \\___/ o \\___/ / " << endl;
  cout << "   | |   | ||  __)                                                \\_____ _ _____/ " << endl;
  cout << "   | |   | || (                                                         |-| " << endl;
  cout << "   | (___) || )                                                         |-| " << endl;
  cout << "   (_______)|/                                                          |-| " << endl;
  cout << "                                                                       ,'-'. " << endl;
  cout << "                                                                       '---' " << endl;
  cout << endl;
  cout << "    _______           _______  _______  _______  _______  _______  _        _______  _______  _______  " << endl;
  cout << "   (  ___  )|\\     /|(  ____ \\(  ____ \\(  ___  )(       )(  ____ \\( (    /|(  ____ \\(  ____ \\(  ____ \\ " << endl;
  cout << "   | (   ) || )   ( || (    \\/| (    \\/| (   ) || () () || (    \\/|  \\  ( || (    \\/| (    \\/| (    \\/ " << endl;
  cout << "   | (___) || | _ | || (__    | (_____ | |   | || || || || (__    |   \\ | || (__    | (_____ | (_____  " << endl;
  cout << "   |  ___  || |( )| ||  __)   (_____  )| |   | || |(_)| ||  __)   | (\\ \\) ||  __)   (_____  )(_____  ) " << endl;
  cout << "   | (   ) || || || || (            ) || |   | || |   | || (      | | \\   || (            ) |      ) | " << endl;
  cout << "   | )   ( || () () || (____/\\/\\____) || (___) || )   ( || (____/\\| )  \\  || (____/\\/\\____) |/\\____) | " << endl;
  cout << "   |/     \\|(_______)(_______/\\_______)(_______)|/     \\|(_______/|/    )_)(_______/\\_______)\\_______) " << endl;
  cout << endl;
}

// GAME OVER FUNCTION //
// Description: Displays the graphic for game over.
void gameOver ()
{
  cout << "    _______  _______  _______  _______    _______           _______  _______  " << endl;
  cout << "   (  ____ \\(  ___  )(       )(  ____ \\  (  ___  )|\\     /|(  ____ \\(  ____ ) " << endl;
  cout << "   | (    \\/| (   ) || () () || (    \\/  | (   ) || )   ( || (    \\/| (    )| " << endl;
  cout << "   | |      | (___) || || || || (__      | |   | || |   | || (__    | (____)| " << endl;
  cout << "   | | ____ |  ___  || |(_)| ||  __)     | |   | |( (   ) )|  __)   |     __) " << endl;
  cout << "   | | \\_  )| (   ) || |   | || (        | |   | | \\ \\_/ / | (      | (\\ (    " << endl;
  cout << "   | (___) || )   ( || )   ( || (____/\\  | (___) |  \\   /  | (____/\\| ) \\ \\__ " << endl;
  cout << "   (_______)|/     \\||/     \\|(_______/  (_______)   \\_/   (_______/|/   \\__/ " << endl;
  cout << endl;
}

// SHOW INSTRUCTIONS FUNCTION //
// Description: This function displays instructions and helpful tips for playing the game.
void showInstructions()
{
  cout << "Instructions:" << endl;
  cout << "OVERVIEW - You must move through the locations; fighting creatures, meeting people, collecting" << endl;
  cout << "           items, and solving riddles. The aim of the game is to collect all the items you" << endl;
  cout << "           require to go and face the final showdown. If you die in a fight or run out of days" << endl;
  cout << "           then you lose and the quest is over." << endl;
  cout << "           Press [ENTER] to continue..." << endl;
  cin.get();
  cout << "NAVIGATION - You can go either North, East, South, or West from each location. If nothing" << endl;
  cout << "             exists in the direction you are trying to travel you will not be permitted to" << endl;
  cout << "             travel in that direction. If get lost or forget where you are supposed to be" << endl;
  cout << "             going, check the map and check your current objective (which can be found by" << endl;
  cout << "             inspecting your character." << endl;
  cout << "             Press [ENTER] to continue..." << endl;
  cin.get();
  cout << "FIGHTS - When you (inevitably) find yourself in a fight you will be presented with the option" << endl;
  cout << "         to 'Continue fight' and 'Resolve fight'. Continuing the fight will cause each cobmatant" << endl;
  cout << "         to take a single turn in attacking each other. Resolving the fight will cause the" << endl;
  cout << "         combatants to continue to take turns to attack each other unitl one is dead. Be warned," << endl;
  cout << "         if you choose to resolve the fight you will not be able to use items until after the" << endl;
  cout << "         fight is over." << endl;
  cout << "         Press [ENTER] to continue..." << endl;
  cin.get();
  cout << "ITEMS - Your character has an inventory which will hold any items that you collect along the way." << endl;
  cout << "        You can access your inventory and use your items inventory by inspecting your character."  << endl;
  cout << "        Visit one of the shops to purchase more itemsif you have some spare gold!" << endl;
  cout << "        Press [ENTER] to continue..." << endl;
  cin.get();
  cout << "TIPS - Take time to explore and 'look around', you never know what you may find!" << endl;
  cout << "     - Many interesting people can be found at the healing fountains. Listen to that they have" << endl;
  cout << "       to say." << endl;
  cout << "     - Major game events can often end in combat. Anticipate this can carry an extra healing" << endl;
  cout << "       potion or 2." << endl;
  cout << "     - Save the 'resolve fight' option for fights you are sure you are going to win." << endl;
  cout << "     - If you want an easy game turn on god mode in the main settings menu (before you start" << endl;
  cout << "       your game). This will start you with a very very powerful elixir and lots of gold." << endl;
  cout << "       Press [ENTER] to continue..." << endl;
  cin.get();
}
