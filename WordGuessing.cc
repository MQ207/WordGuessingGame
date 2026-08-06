/*
  Word Guesser! By: Minh-Quan Pham
    Uses random to pull a random word from a word bank from 
    which the user can type in chars to reveal letters

  To-Do
    Fix bug where user types in a letter that has already 
      been guessed and is in the word which adds to 
      wordFoundCount and may prematurely end the game

    Add Banner or welcome graphic
    
    Expand word bank

*/

#include <iostream>
#include <vector>
#include <random>


void game_loop(std::string word) {
  std::string currGuess = "_____\n";
  char userIn;
  int wordFoundCount = 0;

  std::cout << currGuess;

  while (true) {
    std::cin >> userIn;

    for (unsigned i = 0; i < word.size(); i++) {
      if (word[i] == userIn) {
        currGuess[i] = userIn;
        wordFoundCount++;
      }
    }

    std::cout << currGuess << std::endl << std::endl;
    if (userIn == '0' || wordFoundCount == 5) break;
  }

  std::cout << "Goodjob!";

}

int main() {
  std::vector<std::string> wordBank = {
        "apple", "alive", "bowel", "birth", "close", "color", 
        "dirty", "dweeb", "earth", "exist", "flirt", "funny", 
        "greet", "glass", "hails", "heart", "image", "input", 
        "joker", "jacks", "knock", "knots", "laugh", "learn", 
        "money", "month", "niche", "never", "other", "otter", 
        "plyth", "polar", "quilt", "qwell", "reaps", "relay",
        "steam", "slime", "trust", "titty", "under", "upper",};

  // 1. Obtain a random seed from the hardware
  std::random_device rd;

  // 2. Initialize the Standard Mersenne Twister engine with the seed
  std::mt19937 gen(rd());

  // 3. Define the distribution range [min, max] inclusive
  std::uniform_int_distribution<int> distrib(0, wordBank.size() - 1);

  std::string randomWord = wordBank[distrib(gen)];

  game_loop(randomWord);

}