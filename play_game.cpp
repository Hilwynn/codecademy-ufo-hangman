#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "functions.hpp"

void play_game()
{

  srand(time(NULL));

  std::string codeword;
  std::string answer;
  std::vector<std::string> possible_codewords = {
      "midsummer",
      "unnecessary",
      "practicality",
      "kaleidoscope",
      "cinematography",
      "enigmatic",
      "phosphorous",
      "negotiation",
      "phalanx",
      "neanderthal",
      "osteoporosis",
      "concatenation",
      "avarice",
      "benevolence",
      "machiavellian",

  };

  codeword = possible_codewords[(rand() % possible_codewords.size())];

  for (int i = 0; i < codeword.length(); i++)
  {
    answer += "_";
  }

  greet();

  int misses = 0;
  std::vector<char> incorrect;
  bool guess = false;
  char letter;

  while (answer != codeword && misses < 7)
  {

    display_misses(misses);

    display_status(incorrect, answer);

    std::cout << "\n\nPlease enter your guess: ";

    std::cin >> letter;

    for (int i = 0; i < codeword.length(); i++)
    {

      if (tolower(letter) == codeword[i])
      {

        answer[i] = tolower(letter);
        guess = true;
      }
    }

    if (guess)
    {

      std::cout << "\nCorrect!\n";
    }
    else
    {

      std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(toupper(letter));
      misses++;
    }

    guess = false;
  }

  end_game(answer, codeword);
}
