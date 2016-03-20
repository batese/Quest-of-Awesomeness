//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		02/05/2015				//
// Last Date Modified:		03/15/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			fight.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Fight class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include "creature.h"
#include "fight.h"

//////////////////////////////////////////////////////////////////////////
//		        DEFAULT CONSTRUCTOR				//
//									//
//	Entry:								//
//		None.							//
//									//
//	Exit:								//
//		Makes a blank object of Fight class.			//
//									//
//	Purpose:							//
//		This function is used make a Fight with no information.	//
//////////////////////////////////////////////////////////////////////////
Fight::Fight()
{
  this->fighter1 = NULL;
  this->fighter2 = NULL;
  this->speed = 0;
}

//////////////////////////////////////////////////////////////////////////
//			CONSTRUCTOR					//
//									//
//	Entry:								//
//		Pointers to two fighters and a boolean value for	//
//		whether dice rolls are to be displayed.			//
//									//
//	Exit:								//
//		Creates a Fight with inputted information.		//
//									//
//	Purpose:							//
//		The function creates a Fight object from the		//
//		inputted arguments.					//
//////////////////////////////////////////////////////////////////////////
Fight::Fight(Creature* fighter1, Creature* fighter2, int speed)
{
  this->fighter1 = fighter1;
  this->fighter2 = fighter2;
  this->speed = speed;
}

//////////////////////////////////////////////////////////////////////////
//		        DESTRUCTOR					//
//									//
//	Entry:								//
//		None.							//
//									//
//	Exit:								//
//		Sets pointers to NULL.					//
//									//
//	Purpose:							//
//		This function is a destructor for the Fight class.	//
//////////////////////////////////////////////////////////////////////////
Fight::~Fight()
{
  this->fighter1 = NULL;
  this->fighter2 = NULL;
}

//////////////////////////////////////////////////////////////////////////
//			SWAP FIGHTERS FUNCTION				//
//									//
//	Entry:								//
//		None.							//
//									//
//	Exit:								//
//		None.							//
//									//
//	Purpose:							//
//		Swaps the pointers between the fighters.		//
//////////////////////////////////////////////////////////////////////////
void Fight::swapFighters()
{
  Creature* temp = fighter1;
  fighter1 = fighter2;
  fighter2 = temp;
}

// ONE ROUND FUNCTION //
// Description: Completes one round of combat. The itital attacker is randomly decided. Then each fighter attacks once
//              (provided one of them doesn't die on the first attack).
void Fight::oneRound ()
{
 int attack, defend, delay = this->speed * 300000;

  std::string termsArray [] = {"attacks", "charges", "strikes at", "lunges at", "swipes at", "swings at", "blindsides"};
  int terms = 7;

  if(rand() %2) // Randomly decide who attacks first
    {
      swapFighters();
    }

  for (int x = 0; x < 2; x++)
    {
      if (fighter1->getHitPoints() > 0 && fighter2->getHitPoints() > 0)
	{
	  attack = fighter1->attack(); // Get attack value
	  defend = fighter2->defend(); // Get defend value
	  
	  std::cout << fighter1->getNameHp() << " " << termsArray[rand() % terms] << " " << fighter2->getNameHp() << std::endl; // Print who attacks who
	  
	  usleep(delay); // Add delay
	  
	  if(attack > defend) // If damage is done
	    {
	      std::cout << fighter2->getName() << " recieves " << attack - defend << " damage.";
	      fighter2->addHitPoints(-(attack - defend)); // Apply damage to fighter's strength points
	      std::cout << std::endl;
	    }
	  else // If no damage is done
	    {
	      if(defend - fighter2->getArmour() < attack) // If attack is absorbed by armour
		{
		  std::cout << "The attack doesn't penetrate " << fighter2->getName() << "'s armour.";
		}
	      else // If base defend stops attack
		{
		  std::cout << "But no damage is recieved.";
		}
	      std::cout << std::endl;
	    }
	  usleep(delay); // Add delay
	  swapFighters();
	}
    }
}
