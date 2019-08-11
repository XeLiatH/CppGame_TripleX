#include <iostream>
#include "ctime"

void PrintIntro(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << "secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntro(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\n+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

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

    bool bLevelComplete;
    while (LevelDifficulty <= MaximumLevelDifficulty)
    {
        bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "\n\n*** Great work! Now get out of there! ***\n\n";

    return 0;
}
