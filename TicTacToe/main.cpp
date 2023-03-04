#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// Variables
char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};
int gamemode = 1;
string selectedMode;
int menuInput;
int gameMove;
int selectedAi = 0;

// Player Variables
char player1 = 'X';
char player2 = 'O';
char activePlayer;

// Function declarations
void Rules();
void Menu();
void SelectGameMode();
void GameLoop();
void Player1Turn();
void Player2Turn();
void AITurn();
void DrawBoard();
bool CheckTaken(int, int);
void CheckInput();
bool CheckWin(char);

// Main Function
int main()
{
    // Welcome message
    cout << "Welcome to TicTacToe!" << endl;

    // Rule checkup
    cout << "Would you like to check out the rules? (y/n)" << endl;
    char rules;
    cin >> rules;

    // Check if user wants to see the rules
    rules = tolower(rules);
    if (rules == 'y')
    {
        Rules();
    }
    else
    {
        cout << "Ok, let's get started!" << endl;
    }

    // Call the Menu
    Menu();
    return 0;
}

void Rules()
{
    // Print out the Rules of the Game
    cout << "--------------------" << endl;
    cout << "The rules are simple: get three in a row to win!" << endl;
    cout << "You can each take turns placing your X or O on the board." << endl;
    cout << "The first player to get three in a row wins!" << endl;
    cout << "--------------------" << endl;
}

void Menu()
{
    // Menu Fucntion
    system("cls");

    // Gamemode Check
    switch (gamemode)
    {
    case 1:
        selectedMode = "Player vs Player";
        break;
    case 2:
        selectedMode = "Player vs Computer";
        break;
    default:
        selectedMode = "Player vs Player";
        break;
    }

    // Menu Options
    cout << "--------------------" << endl;
    cout << "Selected Mode: " << selectedMode << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Select Game Mode" << endl;
    cout << "3. Exit" << endl;
    cout << "--------------------" << endl;

    // check if menu input is a number
    cin >> menuInput;

    // Check what option was selected
    switch (menuInput)
    {
    case 1:
        cout << "Starting game..." << endl;
        GameLoop();
        break;
    case 2:
        SelectGameMode();
        break;
    case 3:
        cout << "Exiting..." << endl;
        exit(0);
        break;
    default:
        cout << "Invalid input." << endl;
        Menu();
        break;
    }
}

void SelectGameMode()
{
    // Game Mode Selection
    cout << "--------------------" << endl;
    cout << "1. Player vs Player" << endl;
    cout << "2. Player vs Computer [NOT WORKIN]" << endl;
    cout << "What mode would you like to select?" << endl;
    cout << "--------------------" << endl;
    cin >> gamemode;

    // Check if gamemode is valid
    if (gamemode != 1 && gamemode != 2)
    {
        cout << "Invalid gamemode." << endl;
        gamemode = 0;
        SelectGameMode();
        return;
    }

    // Go Back to the Menu
    Menu();
}

void GameLoop()
{
    // This is our game loop
    // We cycle through this until someone wins
    system("cls");
    Player1Turn();
    system("cls");
    if (gamemode == 1)
    {
        Player2Turn();
    }
    else
    {
        AITurn();
    }
    GameLoop();
}

void Player1Turn()
{
    // This is Player 1's turn
    activePlayer = player1;
    cout << "--------------------" << endl;
    DrawBoard();
    cout << "Player 1: " << player1 << endl;
    cout << "What is your move?" << endl;
    cout << "--------------------" << endl;
    cin >> gameMove;
    CheckInput();

    if (CheckWin(activePlayer))
    {
        system("cls");
        DrawBoard();
        cout << "Player " << activePlayer << " wins!" << endl;
        exit(0);
    }
}

void Player2Turn()
{
    // This is Player 2's turn
    activePlayer = player2;
    cout << "--------------------" << endl;
    DrawBoard();
    cout << "Player 2: " << player2 << endl;
    cout << "What is your move? " << endl;
    cout << "--------------------" << endl;
    cin >> gameMove;
    CheckInput();

    if (CheckWin(activePlayer))
    {
        system("cls");
        DrawBoard();
        cout << "Player " << activePlayer << " wins!" << endl;
        exit(0);
    }
}

void AITurn()
{
    // gay ai
    activePlayer = player2;
    selectedAi = 0;
    srand(time(nullptr));
    switch (selectedAi)
    {
    case 0:
        cout << "--------------------" << endl;
        DrawBoard();
        cout << "AI: " << player2 << endl;
        cout << "What is your move? " << endl;
        cout << "--------------------" << endl;
        Sleep(2000);
        gameMove = rand() % 9 + 1;
        CheckInput();
        if (CheckWin(activePlayer))
        {
            system("cls");
            DrawBoard();
            cout << "AI " << activePlayer << " wins!" << endl;
            exit(0);
        }
        break;
    case 2:
        break;
    }
}

void DrawBoard()
{
    // This is our function to draw the Board. Very Readable and simple
    // Totally not stolen from the internet
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool CheckTaken(int row, int col)
{
    // This is our check to see if a field is taken
    // We use this to make sure we don't overwrite a field
    if (board[row][col] == 'X' || board[row][col] == 'O')
        return true;
    else
        return false;
}

void CheckInput()
{
    // This is our function to check the input
    // We use this to make sure the input is valid
    // We also use this to place the X or O on the board
    // Also totally not stolen from the internet
    int row, col;
    switch (gameMove)
    {
    case 1:
        row = 0;
        col = 0;
        break;
    case 2:
        row = 0;
        col = 1;
        break;
    case 3:
        row = 0;
        col = 2;
        break;
    case 4:
        row = 1;
        col = 0;
        break;
    case 5:
        row = 1;
        col = 1;
        break;
    case 6:
        row = 1;
        col = 2;
        break;
    case 7:
        row = 2;
        col = 0;
        break;
    case 8:
        row = 2;
        col = 1;
        break;
    case 9:
        row = 2;
        col = 2;
        break;
    default:
        cout << "Invalid input, please try again." << endl;
        if (activePlayer == player1)
            Player1Turn();
        else
            Player2Turn();
        return;
    }
    if (CheckTaken(row, col))
    {
        cout << "This field is already taken, please try again." << endl;
        if (activePlayer == player1)
            Player1Turn();
        else if (activePlayer == player2)
            Player2Turn();
        else
            AITurn();
        return;
    }
    board[row][col] = activePlayer;
}

bool CheckWin(char player)
{
    // check for horizontal win
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    // check for vertical win
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }

    // check for diagonal win (top left to bottom right)
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    // check for diagonal win (bottom left to top right)
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
    {
        return true;
    }

    // no win
    return false;
}
