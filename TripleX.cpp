#include <iostream>
#include "ctime"

void PrintIntro(int NumberOfDifficulties)
{
    std::cout << "\n\n  ** You are a secret agent breaking into a server room";
    std::cout << "\n    ** You will need to get through " << NumberOfDifficulties << " levels to gain access.";

    std::cout << R"(

                  ,---------------------------,
                  |  /---------------------\  |
                  | |                       | |
                  | |     Hack me please    | |
                  | |      Services         | |
                  | |       Company         | |
                  | |                       | |
                  |  \_____________________/  |
                  |___________________________|
                ,---\_____     []     _______/------,
              /         /______________\           /|
            /___________________________________ /  | ___
            |                                   |   |    )
            |  _ _ _                 [-------]  |   |   (
            |  o o o                 [-------]  |  /    _)_
            |__________________________________ |/     /  /
        /-------------------------------------/|      ( )/
      /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /
    /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    )";
}

void printLives(int AmountOfLives)
{
    std::cout << "\n ** Lives: ";
    switch (AmountOfLives)
    {
    case 5:
        std::cout << R"(

  ,-.-.  ,-.-.  ,-.-.  ,-.-.  ,-.-.
  `. ,'  `. ,'  `. ,'  `. ,'  `. ,'
    `      `      `      `      `

        )";
        break;
    case 4:
        std::cout << R"(

  ,-.-.  ,-.-.  ,-.-.  ,-.-.
  `. ,'  `. ,'  `. ,'  `. ,'
    `      `      `      `

        )";
        break;
    case 3:
        std::cout << R"(

  ,-.-.  ,-.-.  ,-.-.
  `. ,'  `. ,'  `. ,'
    `      `      `

        )";
        break;
    case 2:
        std::cout << R"(

  ,-.-.  ,-.-.
  `. ,'  `. ,'
    `      `

        )";
        break;
    default:
        std::cout << R"(

  ,-.-.
  `. ,'
    `

        )";
        break;
    }

    std::cout << std::endl;
}

void PrintLevelIntro(int Difficulty, int AmountOfLives)
{
    std::wcout << "\n\n ** Level " << Difficulty;

    printLives(AmountOfLives);
}

void PrintAccessDenied()
{
    std::cout << R"(

    ## #################################################################### ##
    ##     ___                               ____             _          __ ##
    ##    /   | _____________  __________   / __ \___  ____  (_)__  ____/ / ##
    ##   / /| |/ ___/ ___/ _ \/ ___/ ___/  / / / / _ \/ __ \/ / _ \/ __  /  ##
    ##  / ___ / /__/ /__/  __(__  |__  )  / /_/ /  __/ / / / /  __/ /_/ /   ##
    ## /_/  |_\___/\___/\___/____/____/  /_____/\___/_/ /_/_/\___/\__,_/    ##
    ## ____________________________________________________________________ ##
    ## ******************************************************************** ##
    ## #################################################################### ##

    )";
}

void PrintAccessGranted()
{
    std::cout << R"(

    ## ############################################################################ ##
    ##     ___                               ______                 __           __ ##
    ##    /   | _____________  __________   / ____/________ _____  / /____  ____/ / ##
    ##   / /| |/ ___/ ___/ _ \/ ___/ ___/  / / __/ ___/ __ `/ __ \/ __/ _ \/ __  /  ##
    ##  / ___ / /__/ /__/  __(__  |__  )  / /_/ / /  / /_/ / / / / /_/  __/ /_/ /   ##
    ## /_/  |_\___/\___/\___/____/____/   \____/_/   \__,_/_/ /_/\__/\___/\__,_/    ##
    ## ____________________________________________________________________________ ##
    ## **************************************************************************** ##
    ## ############################################################################ ##

    )";
}

bool PlayGame(int Difficulty, int AmountOfLives)
{
    PrintLevelIntro(Difficulty, AmountOfLives);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\n > There are 3 numbers in the code";
    std::cout << "\n > The codes add-up to: " << CodeSum;
    std::cout << "\n > The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    return CodeSum == GuessSum && GuessProduct == CodeProduct;
}

int main()
{
    srand(time(NULL));

    const int MaximumLevelDifficulty = 5;
    int LevelDifficulty = 1;
    int AmountOfLives = 5;

    PrintIntro(MaximumLevelDifficulty);

    bool bLevelComplete;
    while (LevelDifficulty <= MaximumLevelDifficulty)
    {
        bLevelComplete = PlayGame(LevelDifficulty, AmountOfLives);
        std::cin.clear();  // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            PrintAccessGranted();

            std::cout << "\n ** Good Job! You have passed the level " << LevelDifficulty << std::endl;
            LevelDifficulty++;
        }
        else
        {
            AmountOfLives--;
            PrintAccessDenied();

            if (AmountOfLives <= 0)
            {
                std::cout << "\n\n ** You have exceeded the amount of lives. They reached you and killed you!\n\n";
                return 0;
            }
        }
    }

    PrintAccessGranted();

    std::cout << "\n\n ** Great work! Now get out of there!\n\n";

    return 0;
}
