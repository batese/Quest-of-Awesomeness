//////////////////////////////////////////////////////////////////////////
// Author:			Elliot Bates				//
// Date Created:		03/08/2015				//
// Last Date Modified:		03/08/2015				//
// Reference To:		CS 162 Final Project			//
// File Name:			Quest5.cpp				//
//									//
//	Overview:							//
//		This file contains the member function definitions for	//
//		the Quest5 class.					//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "quest5.h"
#include "fight.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

// CONSTRUCTOR //
// Description: Creates an object of quest5 class
Quest5::Quest5 ()
  : Location ("Misty Swamp", "Quest")
{

}

// DESTRUCTOR //
// Description: Destroys a quest 5 object
Quest5::~Quest5 ()
{

}

// RESOLVE FUNCTION //
// Description: Resolves events at the quest5 location (see demon)
void Quest5::resolve ()
{
  int pause = hero->getGameSpeed() * 500000;

  cout << "The mist slowly clears to reveal a small island in the middle of a bog." << endl;
  usleep(pause);

  if (!hero->getGotSpell()) // If not already visited
    {
      cout << "A grey cloud swirls out of the mist, revealing an old woman standing on the island." << endl;
      usleep(pause);
      cout << "Old Woman: \"Hello child. What brings you into the depths of the swamp?" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"I need your help demon.\"" << endl;
      usleep(pause);
      cout << "Old Woman: \"Demon!? I am no demon. I'm just a little old woman!\"" << endl;
      usleep(pause);
      cout << "She cackles loudly. It echoes through the swamp.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"A great evil has been sealed inside the forrest, and I must break the seal to get inside to defeat it.\"" << endl;
      usleep(pause);
      cout << "Old Woman: \"I have sensed this evil. If you do not stop it it will consume all these lands.\"" << endl;
      usleep(pause);
      cout << "Old Woman: \"Can whomever sealed the forrest not unseal it for you?\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"No. He's dead.\"" << endl;
      usleep(pause);
      cout << "Old Woman: \"How unfortunate. I think I have a spell that can help you. But just giving it to you would be too easy.\"" << endl;
      usleep(pause);
      cout << "Old Woman: \"If you can guess my password I will give you the spell.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"And if I can't guess the password?\"" << endl;
      usleep(pause);
      cout << "Old Woman: \"We will have to see won't we.\"" << endl;
      usleep(pause);
      cout << "She throws her head back and cackles loudly again." << endl;
      usleep(pause);
      cout << "Old Woman: \"I will allow you to guess up to 4 incorrect letters. If you fail to guess the password the consenquences will be dyer.\"" << endl;
      usleep(pause);
      cout << hero->getName() << ": \"Seems fair. Can you at least give me a clue though?\"" << endl;
      usleep(pause);
      cout << "Old Woman: \"The answer is right at your feet.\"" << endl;
      usleep(pause);
      cout << "You look down, but only your reflection stares back at you from the murky water at your feet." << endl;
      usleep(pause);

      // HANGMAN STYLE GUESSING GAME

      int remGuess = 4, guessNum = 1; // The remaining number of incorrect guesses
      int sum; // Used to sum the zeroes string to see if word is complete
      char guess, // This will hold the current guess
	ch; // This will be sued to take individual characters out of the secret word string
      bool guessed,
	alphaError,
	goodGuess, // True if current guess is in secret word
	gameOver, // True if guesser runs out of guesses
	guessAll; // True if all letters in secret word have been guessed
      string secretWord, // Stores the secret word
	zeroes, // Array of 0s same size as secret word
	blanks, // Array of _s and spaces to stroe correct guesses and gaps
	guessString, // This stores the current guess as a string
	choiceString, // This stores the users menu choice as a string
	guesses, // This array stores previous guesses
	missLetters; // Array of letters missed from secret word
	
      secretWord = hero->getFullName();
      for (unsigned x = 0; x < secretWord.length(); x++)
	{
	  if (isalpha(secretWord.at(x)))
	    {
	      secretWord.at(x) = toupper(secretWord.at(x));
	    }
	}
      zeroes.assign(secretWord.length(), '0'); // Create zeroes array
      blanks.assign(secretWord.length() * 2 - 1, '_'); // Create blanks array
      for (unsigned x = 1; x < 2 * secretWord.length() - 1; x += 2)
	{
	  blanks.at(x) = ' ';
	}
      guesses.assign(26 * 2 - 1, ' '); // Create guesses array
      for (unsigned x = 1; x < 2 * 26 - 1; x += 2)
	{
	  guesses.at(x) = ' ';
	}
      for (unsigned x = 0; x < secretWord.length(); x++)
	{
	  if (secretWord.at(x) == ' ')
	    {
	      zeroes.at(x) = '1';
	      blanks.at(2 * x) = ' ';
	    }
	}
	
      gameOver = false; // Reset game parameters
      guessAll = false;
    
      do
	{ 
	  cout << "Old Woman: \"The password is " << blanks << "\"" << endl; // Display blanks and guessed lettere
	  usleep(pause/2);
	  cout << "Old Woman: \"You have " << remGuess << " incorrect guesses remaining.\"" << endl; // Remaining guesses
	  usleep(pause/2);
	  if (guessNum > 1) // After first round
	    {
	      cout << "You have guessed letters " << guesses << endl; // Show guessed letters
	      usleep(pause/2);
	    }
	  
	  cout << "Old Woman: \"What letter would you like to guess?\"" << endl;
	  cout << "Guess: ";
	  getline(cin, guessString); // Get guess from user
	  
	  do
	    {
	      do
		{
		  while (guessString.length() > 1 || guessString.length() < 1) // While guess is not 1 character
		    {
		      cout << "You must guess 1 letter at a time: ";
		      getline(cin, guessString); // get new guess
		    }
		  
		  guess = guessString.at(0); // Convert string to character
		  
		  alphaError = false; // Set default value before if statement
		  if (!isalpha(guess)) // If guess is not a letter
		    {
		      cout << "Please guess a letter from A-Z: ";
		      getline(cin, guessString); // Get new guess
		      alphaError = true; // Set error
		    }
		} while (alphaError); // Repeat until guess is 1 letter
	      
	      guess = toupper(guess); // Convert guess to upper case
	      
	      guessed = false; // Set default value before for loop
	      for (int x = 0; x < 26 * 2 - 1; x += 2)
		{
		  if (guess == guesses.at(x)) // If letter has already been guessed
		    {
		      guessed = true; // Set error
		    }
		}
	      if (guessed) // If letter has already been guessed
		{
		  cout << "You have already guessed that letter!" << endl;
		  cout << "Please guess a new letter: "; // Display message
		  getline(cin, guessString); // Get new guess
		}
	    } while (guessed); // Repeat until a letter that has not already been guessed is entered
	  
	  guesses.at((guessNum - 1) * 2) = guess; // Add guess to guesses array
	  
	  goodGuess = false; // Reset before for loop
	  for(unsigned x = 0; x < secretWord.length(); x++)
	    {
	      ch = secretWord.at(x);
	      if (ch == guess) // If guess is in secret word
		{
		  blanks.at(2 * x) = guess; // Insert correct guess into blanks array
		  zeroes.at(x) = '1'; // Insert 1 into 0s array
		  goodGuess = true;
		}
	    }
	  if (goodGuess) // If guess was in secret word display message
	    {
	      cout << "Old Woman: \"Good guess! " << guess << " is in the password.\"" << endl;
	    }
	  else // If guess was not in secret word display message
	    {
	      cout << "Old Woman: \"Unlucky, " << guess << " is not in the password.\"" << endl;
	      remGuess--; // And remove 1 from remaining guesses
	    }
	  if (remGuess == 0) // If no guesses are remaining
	    {
	      gameOver = true; // Game is lost
	    }
	  
	  sum = 0; // Reset before for loop
	  for (unsigned x = 0; x < zeroes.length(); x++) // Check if all letters have been guessed
	    {
	      sum = sum + int(zeroes.at(x));
	    }
	  if (unsigned(sum) == zeroes.length() * 49) // If all letters have been guessed
	    {
	      guessAll = true; // Game is won
	    }
	  guessNum++;
	}while (!guessAll && !gameOver); // Repeat loop until game is won or lost
      
      if (guessAll) // If game is won
	{
	  cout << "Old Woman: \"You guessed the password! Congratulations warrior, I will give you the spell you need.\"" << endl;
	  usleep(pause);
	  cout << "She cackles loudly again as the mist begins to swirl around her.\"" << endl;
	  usleep(pause);
	  cout << "Suddenly the mist disperses with a bang." << endl;
	  usleep(pause);
	  cout << "The old woman is nowhere to be seen. In her place there is just a small scroll on the island." << endl;
	  usleep(pause);
	  cout << "You got the spell!" << endl;
	  usleep(pause);
	  cout << "Press [ENTER] to continue..." << endl;
	  cin.get();
	}
      else if (gameOver) // game is lost
	{
	  int menuChoice;
	  unsigned inventoryChoice;

	  cout << "Old Woman: \"Oh deary me. It seems you couldn't guess the password.\"" << endl;
	  usleep(pause);
	  cout << "She cackles loudly again as the mist begins to swirl around her.\"" << endl;
	  usleep(pause);
	  cout << "Suddenly the mist disperses with a bang... Revealing a giant serpent!" << endl;
	  usleep(pause);
	  cout << "Serpent: \"And now you must fight me.\"" << endl;
	  usleep(pause);

	  std::string name = "The Demon Serpent"; // Stats for demon if fight happens
	  int attkMax = 45;
	  int attkMin = 0;
	  int defMax = 30;
	  int defMin = 0;
	  int armour = 3;
	  int hp = 100;
	  
	  Creature* opponent = new Creature (name, attkMax, attkMin, defMax, defMin, armour, hp);
	  Fight* thisFight = new Fight (hero, opponent, hero->getGameSpeed());

	  // BEGINNING OF FIGHT LOOP

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
	      if (this->hero->getHitPoints() < 1) // If hero dies
		{
		  delete thisFight;
		  delete opponent;
		  return;
		}
	    } while (opponent->getHitPoints() > 0); // End of fight loop
	  
	  delete thisFight;
	  delete opponent;
	  
	  cout << "The serpent lets out an almighty screech and begins to coil into a ball." << endl;
	  usleep(pause);
	  cout << "As it coils tighter the screech gets higher and more desperate." << endl;
	  usleep(pause);
	  cout << "Suddenly it dissappears with a bang, leaving only a small scroll in the middle of the island." << endl;
	  usleep(pause);
	  cout << "You got the spell!" << endl;
	  usleep(pause);
	  cout << "Press [ENTER] to continue..." << endl;
	  cin.get();
	}
      Item* spell = new Item ("Demon's Spell", "An old and dog-eared scroll with some writing on it. You can't read what it says.", 0, this->hero);
      this->hero->setCarrySize(this->hero->getCarrySize() + 1); // Create spell and add to inventory
      this->hero->addItem(spell);
      hero->setCurrentObjective("Go back to the castle and speak with Princess Goodface");
      hero->setGotSpell(true);      
    }

  else // If hero returns later
    {
      cout << "The swamp is quiet now. It still smells though..." << endl;
      usleep(pause);
      cout << "Press [ENTER] to continue..." << endl;
      cin.get();
    }      
}

