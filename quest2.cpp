//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			Quest2.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Quest2 class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "quest2.h"

using std::cin;
using std::cout;
using std::endl;

// CONSTRUCTOR //
// Description: Creates a quest2 object
Quest2::Quest2 ()
  : Location ("Retupmoc Castle", "Quest")
{

}

// DESTRUCTOR //
// Description: Destroys a quest2 object
Quest2::~Quest2 ()
{

}

// RESOLVE FUNCTION //
// Description: Resolves the events that happen at the quest2 location. These are the interactions with the
//              princess at the castle.
void Quest2::resolve ()
{
  int pause = hero->getGameSpeed() * 500000;

  usleep(pause);
  cout << "You enter Retupmoc Castle." << endl;
  usleep(pause);

  if (!hero->getCastleVisited()) // First visit to the castle
    {
      cout << "You barely make it a few paces inside the gate when a hooded figure grabs you." << endl;
      usleep(pause);
      cout << "He pulls you into a dark empty building and bolts the door." << endl;
      usleep(pause);
      cout << "Stranger: \"You're " << hero->getFullName() << " right?\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"Yeah that's me, I just came from the forrest. I don't...\"" << endl;
      usleep(pause/2);
      cout << "Stranger: \"Not here! Follow me, it's not safe to talk here. The king has spies everywhere." << endl;
      usleep(pause);
      cout << "You follow the stranger down into the tunnels beneath the castle." << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();

      cout << "..." << endl;
      usleep(pause);
      cout << "Stranger: \"OK, we should be safe here\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"Right, I've had enough. What the hell is going on?\"" << endl;
      usleep(pause);
      cout << "The figure slowly removes their hood..." << endl;
      usleep(pause);
      cout << "It's a girl!" << endl;
      usleep(pause);
      cout << "Stranger: \"My name is Princess Goodface. My father is Lord Evilface, the ruler of these lands.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"Am I supposed to be impressed or something?\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"No. I'm sorry for the way you have been dragged into this, but you are the only one who can save us.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"Save you from what?\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Lord Evilface has meddled with forces he doesn't understand.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"In his quest for power he has summoned a great and poweful evil to these lands.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"For now this evil has been contained to the depths of the forrest, but it will soon spread.\"" << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();

      cout << hero->getName() << ": \"And you expect me to stop this great evil? I don't think I can...\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"You must have faith in yourself brave warrior. I sense a great power inside you.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"And I'm just supposed to go back and fight it?\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"No, it is a powerful evil. It would destroy you if you faced it now.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"That's not very reassuring...\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"I'm sorry. You will defeat this evil. But you will need some help first.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"There is an amulet. It is said this amulet holds the power of all mankinds goodness inside it.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"With this amulet you will be able to triumph in your battle.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"And I don't suppose you have the amulet?\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"I'm afraid not. It has been lost for many centuries.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Head East into the mountains. Look for Gorag the mountain keeper. He will help you with your search.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Come back and find me when you have the amulet.\""<< endl;
      usleep(pause);
      cout << hero->getName() << ": \"Well thanks... I guess...\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Hurry brave warrior. If this evil is not defeated by mid-summers eve (day 100) it will already be too late.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"I will hurry.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Good luck " << hero->getFullName() << ", all our fates rest on your shoulders.\"" << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
      
      hero->setCurrentObjective("Head East into the mountains and look for Gorag. You need to find the amulet.");
      hero->setCastleVisited(true);
    }
  
  else if (!hero->getGotAmulet()) // Returning before you get the amulet
    {
      cout << "You head down into the tunnels beneath the castle." << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Go East into the mountains. Gorag will help you find the amulet.\"" << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
    }
  
  else if (!hero->getCastleRevisited()) // Returning with the amulet
    {
      cout << "You head down into the tunnels beneath the castle." << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Did you find the amulet?\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"It wasn't easy, but I've got it.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"I'm afraid we have a new problem now though.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Oh no. What has happened now?\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"That man that rescued me in the forrest, the one who sent me here in the first place...\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"He died on the mountain. He said we won't be able to open the seal he put on the forrest without him.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"So what are we suposed to do then?\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"I don't know. He said you would know of another way to break the spell.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Hmm...\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"There is a demon who lives in the Western swamplands. She will know how to break the spell.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Be very cautious though. She is devious and cunning and cares not for our plight.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"If you are to get her help you will need your whits about you.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"She will help us or she will die.\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"That's the spirit! Come back once you have been to see the demon. Good luck.\"" << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();

      hero->setCurrentObjective("Head West into the swamp. Look for the demon. Hopefully she can help you with you spell problems.");
      hero->setCastleRevisited(true);
    }

  else if (!hero->getGotSpell()) // Returning before you get the spell
    {
      cout << "You head down into the tunnels beneath the castle." << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Go West into the swamp. Look for the demon. Hopefully she can help you.\"" << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
    }
  
  else if (!hero->getGotPower()) // Returning with the spell
    {
      cout << "Princess Goodface is waiting for you just inside the castle gates." << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Did you do it? Did you find the demon? Did you get the spell?\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"I did I did and I did.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"Is that everything we need? Can I go back to the forrest now?\"" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Almost. There is one last thing you need.\"" << endl;
      usleep(pause);
      cout << "She places her hand on your chest." << endl;
      usleep(pause);
      cout << "Princess Goodface: \"I will give you what power I have to help you with your fight.\"" << endl;
      usleep(pause);
      cout << "A bright light bursts fourth from her hand." << endl;
      usleep(pause);
      cout << "You feel a warmth rush through your body. It feels good. It feels powerful." << endl;
      usleep(pause);
      cout << "Attack +10! Defence +10! Max Hit Points +20!" << endl;
      usleep(pause);
      cout << "Princess Goodface: \"Now go warrior. It is time to rid us of this evil once and for all.\"" << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();

      hero->addAttack(10);
      hero->addDefence(10);
      hero->setMaxHitPoints(hero->getMaxHitPoints() + 20);
      
      hero->setCurrentObjective("Go back to the dark forrest and face your destiny!");
      hero->setGotPower(true);
    }

  else // Returning at the end of the game
    {
      cout << "The castle seems quiet. It's probably time to head back to the forrest." << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
    }
}
