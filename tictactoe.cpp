#include <iostream>
#include <string> 

using namespace std;

void displayBoard(string board[3][3]);
void validateEntry(int player, int& place, char symbol);
bool isWinner(string board[3][3], char& symbol);
bool checkRow(string board[3][3], char& symbol);
bool checkCol(string board[3][3], char& symbol);
bool checkDiag(string board[3][3], char& symbol);
void placer(string board[3][3], int place, string letter);
bool usedSpace(int used[9], int place);


int main() {
  string board[3][3];
  int used [9] = { };
  
  int turn = 0;
  int where = 1;
  int player = 1;
  int place; 
  string letter = " ";
  char symbol = ' ';

  for (int x = 0; x < 3; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      string space = to_string(where);
      board[x][y] = space;
      where++;
    }
  }
  displayBoard(board);

  while (turn != 9 )
  {
    if (turn%2==0)
    {
      player = 1;
      symbol = 'O';
      cout << "\nPlayer 1 turn! Where would you like to place O?\n";
      cin >> place;
      letter = "O";
      validateEntry(player,place,symbol);
      while (usedSpace(used, place) == true)
      {
        cout << "Spot is taken!"; 
        cout << "\nPlayer 1 turn! Where would you like to place O?\n";
        cin >> place;
        usedSpace(used, place);
        validateEntry(player,place,symbol);
      } 
      used[turn] = place;
      placer(board,place,letter);
      displayBoard(board);
      if (isWinner(board, symbol)==true)
      {
        turn = 8;
      }
      turn++;
    }
    else if (turn%2 == 1)
    {
      player = 2;
      symbol = 'X';
      cout << "\nPlayer 2 turn! Where would you like to place X?\n";
      cin >> place;
      letter = "X";
      validateEntry(player,place,symbol);
      while (usedSpace(used,place) == true)
      {
        cout << "Spot is taken!";
        cout << "\nPlayer 2 turn! Where would you like to place X?\n";
        cin >> place;
        usedSpace(used, place);
        validateEntry(player,place,symbol);
      }
      used[turn] = place;
      placer(board,place,letter);
      displayBoard(board);
      if (isWinner(board, symbol)==true)
      {
        turn = 8;
      }
      turn++;
    }
  }
  cout << endl << symbol << " won!";
  if (isWinner(board, symbol) == false && turn == 9)
  {
    cout << "Draw!";
  }
}

void displayBoard(string board[3][3])
{
  for (int x = 0; x < 3; x++)
  {
    for (int y = 0; y < 3; y++)
      {
        cout << board[x][y];
        if (y!=2)
        {
          cout << " | ";
        }
      }
    if (x!=2)
    {
      cout << "\n---------\n";
    }
  }
}

void validateEntry(int player, int& place, char symbol)
{
  while (place <= 0 || place > 9)
  {
    cout << "Please input number between 1-9";
    cout << "\nPlayer " << player << " turn! Where would you like to place " << symbol << "?\n";
    cin >> place;
  }
}

bool isWinner(string board[3][3], char& symbol)
{
  if (checkRow(board, symbol) || checkCol(board, symbol) || checkDiag(board, symbol))
  {
    return true;
  }
  return false;
}
  
bool checkRow(string board[3][3], char& symbol)
{
  for (int x = 0; x < 3; x++)
  {
    if (board[x][0] == "X" && board[x][1] == "X" && board[x][2] == "X")
    {
      symbol = 'X';
      return true;
    }
    else if (board[x][0] == "O" && board[x][1] == "O" && board[x][2] == "O")
    {
      symbol = 'O';
      return true;
    }
  }
  return false;
}
      
bool checkCol(string board[3][3], char& symbol)
{
  for (int x = 0; x < 3; x++)
  {
    if (board[0][x] == "X" && board[1][x] == "X" && board[2][x] == "X")
    {
      symbol = 'X';
      return true;
    }
    else if (board[0][x] == "O" && board[1][x] == "O" && board[2][x] == "O")
    {
      symbol = 'O';
      return true;
    }
  }
  return false;
}
      
bool checkDiag(string board[3][3], char& symbol)
{
  if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X")
  {
    symbol = 'X';
    return true;
  }
  else if (board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X")
  {
    symbol = 'X';
    return true;
  }
  else if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O")
  {
    symbol = 'O';
    return true;
  }
  else if (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O")
  {
    symbol = 'O';
    return true;
  }
  return false;
}
  
void placer(string board[3][3], int place, string letter)
{
  if (place == 1)
  {
    board[0][0] = letter;
  }
  else if (place == 2)
  {
    board[0][1] = letter;
  }
  else if (place == 3)
  {
    board[0][2] = letter;
  }
  else if (place == 4)
  {
    board[1][0] = letter;
  }
  else if (place == 5)
  {
    board[1][1] = letter;
  }
  else if (place == 6)
  {
    board[1][2] = letter;
  }
  else if (place == 7)
  {
    board[2][0] = letter;
  }
  else if (place == 8)
  {
    board[2][1] = letter;
  }
  else if (place == 9)
  {
    board[2][2] = letter;
  }
}
    
bool usedSpace(int used[9], int place)
{ 
  for (int i = 0; i < 9; i++)
  {
    if (used[i] == place)
    {
      return true;
    }
  }
  return false;
}
