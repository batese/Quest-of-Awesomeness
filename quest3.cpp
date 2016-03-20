//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			Quest3.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Quest3 class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "quest3.h"

using std::cin;
using std::cout;
using std::endl;

// CONSTRUCTOR //
// Description: Creates a quest3 object
Quest3::Quest3 ()
  : Location ("Small Cave", "Quest")
{

}

// DESTRUCTOR //
// Description: Destroys a quest3 object
Quest3::~Quest3 ()
{

}

// RESOLVE FUNCTION //
// Description: Resolves events at the quest 3 location (Gorag's cave)
void Quest3::resolve ()
{
  int pause = hero->getGameSpeed() * 500000;

  cout << "You enter a small cave opening in the mountain-side." << endl;
  usleep(pause);

  if (!hero->getGotLadder()) // First visit, get the ladder
    {
      cout << "You edge slowly into the cave." << endl;
      usleep(pause);
      cout << "As your eyes adjust to the light you begin to make out a figure standing at the back of the cave." << endl;
      usleep(pause);
      cout << "Stranger: \"What are you doing on my mountain? What are you doing in my cave?\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"Princess Goodface sent me up here, I'm supposed to be looking for someone called Gorag.\"" << endl;
      usleep(pause);
      cout << "Stranger: \"Princess Goodface sent you? It must be important. My name is Gorag. What can I do for you?\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"I'm looking for an amulet. Something about the goodness of mankind. I don't really remember.\"" << endl;
      usleep(pause);
      cout << "Gorag: \"The Amulet of Goodness!? We must really be up the creek if you're looking for that.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"It seems so. Princess Goodface said you might know where to find it.\"" << endl;
      usleep(pause);
      cout << "Gorag: \"The amulet hasn't been seen for centuries. Legend has it though that it can be found somewhere near the top of this mountain.\"" << endl;
      usleep(pause);
      cout << "Gorag: \"But it's guarded by a great mountain spirit. Everyone who ventures up there does not return.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"Well I've got to try. How do I get up there?.\"" << endl;
      usleep(pause);
      cout << "Gorag: \"Take this ladder, you'll need it to climb up to the upper mountain pass.\"" << endl;
      usleep(pause);
      cout << "You got the ladder!" << endl;
      cout << hero->getName() << ": \"Where is the upper mountain pass?\"" << endl;
      usleep(pause);
      cout << "Gorag: \"Head North-West from here. The entrance to the upper pass is close to the entrance to the mountain itself.\"" << endl;
      usleep(pause);
      cout << "Gorag: \"Go to the top of the mountain and look for the amulet there.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"Thanks Gorag. Goodbye.\"" << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
      
      this->name = "Gorag's Cave";
      Item* ladder = new Item ("Ladder", "A ladder. Could be used for climbing.", 0, this->hero); // Create ladder and ass to inventory
      this->hero->setCarrySize(this->hero->getCarrySize() + 1);
      this->hero->addItem(ladder);
      hero->setCurrentObjective("Head towards the top of the mountain and look for the amulet.");
      hero->setGotLadder(true);
    }
  else if (!hero->getGotAmulet()) // If you got back without the amulet
    {
      cout << "Gorag: \"Head North-West from here. The entrance to the upper pass is close to the entrance to the mountain itself.\"" << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
    }
  else // If you go back with the amulet
    {
      cout << "Gorak: \"Get out! I'm trying to meditate.\"" << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
    }
}
