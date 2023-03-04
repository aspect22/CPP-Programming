#include <iostream>
using namespace std;

int range;
int guess;
int lives;
int number;
char HearRules;
bool win = false;
int main();
int GameLoop();
void PlayAgain();

// Just a function to print the rules of the game
int rules()
{
    cout << "Welcome to Guess The Number!" << endl;
    cout << "The Rules of the game are: " << endl;
    cout << "1. You will be asked to enter a range of numbers you want to guess from." << endl;
    cout << "2. You have 3 Lives." << endl;
    cout << "3. You will be asked to guess a number within the range you entered." << endl;
    cout << "4. If you guess the number correctly, you win!" << endl;
    cout << "5. If you guess the number incorrectly, you lose a life." << endl;
    cout << "6. If you lose all 3 lives, you lose the game." << endl;
    cout << "Good Luck!" << endl;
}

// Function to check if the player has won or lost
bool checkWin(int guess, int number, int &lives, int range)
{

    // Horrible Code yes ik
    if (guess == number)
    {
        system("CLS");
        cout << "You Win!" << endl;
        return true;
    }
    else if (guess > range)
    {
        system("CLS");
        cout << "Your guess is out of range!" << endl;
        return false;
    }
    else if (guess > number)
    {
        system("CLS");
        cout << "Your guess is too high!" << endl;
        lives--;
        return false;
    }
    else if (guess < number)
    {
        system("CLS");
        cout << "Your guess is too low!" << endl;
        lives--;
        return false;
    }
}

// Function to loop the game
int GameLoop()
{
    cout << "Please enter your guess:" << endl;
    cin >> guess;
    cout << "remaining lives: " << lives << endl;

    win = checkWin(guess, number, lives, range);
    if (win == true)
    {
        PlayAgain();
    }
    else
    {
        if (lives == 0)
        {
            cout << "You Lose!" << endl;
            cout << "The number was: " << number << endl;
            PlayAgain();
        }
        GameLoop();
    }
}

// Function to ask the player if they want to play again
void PlayAgain()
{
    char playAgain;
    cout << "Would you like to play again? (Y/N)" << endl;
    cin >> playAgain;
    playAgain = tolower(playAgain);
    if (playAgain == 'y')
    {
        system("CLS");
        main();
    }
    else if (playAgain == 'n')
    {
        cout << "Thanks for playing!" << endl;
        exit(0);
    }
    else
    {
        system("CLS");
        cout << "Invalid Input!" << endl;
        PlayAgain();
    }
}

// Main function
int main()
{
    lives = 3;
    cout << "Welcome to Guess The Number!" << endl;
    cout << "Would you like to hear the rules? (Y/N)" << endl;
    cin >> HearRules;
    HearRules = tolower(HearRules);
    if (HearRules == 'y')
    {
        rules();
    }
    else if (HearRules == 'n')
    {
        cout << "Good Luck!" << endl;
    }
    else
    {
        system("CLS");
        cout << "Invalid Input!" << endl;
        main();
    }

    cout << "Please enter the range of numbers you want to guess from (0 is min): " << endl;
    cin >> range;
    number = rand() % range + 1;
    GameLoop();
}