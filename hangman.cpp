#include <iostream>
#include "play_game.hpp"

int main()
{

  bool exit_game = false;

  while (!exit_game)
  {

    play_game();

    char rematch;

    std::cout << "\n\nWould you like to play again? (y/n) ";
    std::cin >> rematch;

    while (rematch != 'y' && rematch != 'n')
    {
      std::cout << "\nPlease enter a valid option.\n";
      std::cout << "Would you like to play again? (y/n) ";
      std::cin >> rematch;
    }

    if (rematch == 'n')
    {
      exit_game = true;
    }
  }
}
