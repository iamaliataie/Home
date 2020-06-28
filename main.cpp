#include <iostream>
#include <ctime>
#include <set>

using namespace std;
void gameBoard(string arr [][5])
{
                for(int i = 0; i < 5 ; i++)
            {
                for(int j = 0; j < 5 ; j++)
                    cout << arr[i][j];

                cout << endl;
            }
}
void Position(string TicTacToe [][5] , int gamePos , string user)
{
    string symbol = "";
    if(user == "Player")
        symbol = " X";
    else if(user == "CPU")
        symbol = " O";
    switch(gamePos)
        {
        case 1:
            TicTacToe[0][0] = symbol;
            break;
        case 2:
            TicTacToe[0][2] = symbol;
            break;
        case 3:
            TicTacToe[0][4] = symbol;
            break;
        case 4:
            TicTacToe[2][0] = symbol;
            break;
        case 5:
            TicTacToe[2][2] = symbol;
            break;
        case 6:
            TicTacToe[2][4] = symbol;
            break;
        case 7:
            TicTacToe[4][0] = symbol;
            break;
        case 8:
            TicTacToe[4][2] = symbol;
            break;
        case 9:
            TicTacToe[4][4] = symbol;
            break;
        }
}
int winningCondition(string TicTacToe [][5])
{
            if(TicTacToe[0][0] == " X" && TicTacToe[0][2] == " X" && TicTacToe[0][4] == " X")
            {
                cout << "Player wins!" << endl;
                return 1;
            }
            else if(TicTacToe[2][0] == " X" && TicTacToe[2][2] == " X" && TicTacToe[2][4] == " X")
            {
                cout << "Player wins!" << endl;
                return 1;
            }
            else if(TicTacToe[4][0] == " X" && TicTacToe[4][2] == " X" && TicTacToe[4][4] == " X")
            {
                cout << "Player wins!" << endl;
                return 1;
            }
            else if(TicTacToe[0][0] == " X" && TicTacToe[2][0] == " X" && TicTacToe[4][0] == " X")
            {
                cout << "Player wins!" << endl;
                return 1;
            }
            else if(TicTacToe[0][2] == " X" && TicTacToe[2][2] == " X" && TicTacToe[4][2] == " X")
            {
                cout << "Player wins!" << endl;
                return 1;
            }
            else if(TicTacToe[0][4] == " X" && TicTacToe[2][4] == " X" && TicTacToe[4][4] == " X")
            {
                cout << "Player wins!" << endl;
                return 1;
            }
            else if(TicTacToe[0][0] == " X" && TicTacToe[2][2] == " X" && TicTacToe[4][4] == " X")
            {
                cout << "Player wins!" << endl;
                return 1;
            }
            else if(TicTacToe[0][4] == " X" && TicTacToe[2][2] == " X" && TicTacToe[4][0] == " X")
            {
                cout << "Player wins!" << endl;
                return 1;
            }
            else if(TicTacToe[0][0] == " O" && TicTacToe[0][2] == " O" && TicTacToe[0][4] == " O")
            {
                cout << "CPU wins!" << endl;
                return 2;
            }
            else if(TicTacToe[2][0] == " O" && TicTacToe[2][2] == " O" && TicTacToe[2][4] == " O")
            {
                cout << "CPU wins!" << endl;
                return 2;
            }
            else if(TicTacToe[4][0] == " O" && TicTacToe[4][2] == " O" && TicTacToe[4][4] == " O")
            {
                cout << "CPU wins!" << endl;
                return 2;
            }
            else if(TicTacToe[0][0] == " O" && TicTacToe[2][0] == " O" && TicTacToe[4][0] == " O")
            {
                cout << "CPU wins!" << endl;
                return 2;
            }
            else if(TicTacToe[0][2] == " O" && TicTacToe[2][2] == " O" && TicTacToe[4][2] == " O")
            {
                cout << "CPU wins!" << endl;
                return 2;
            }
            else if(TicTacToe[0][4] == " O" && TicTacToe[2][4] == " O" && TicTacToe[4][4] == " O")
            {
                cout << "CPU wins!" << endl;
                return 2;
            }
            else if(TicTacToe[0][0] == " O" && TicTacToe[2][2] == " O" && TicTacToe[4][4] == " O")
            {
                cout << "CPU wins!" << endl;
                return 2;
            }
            else if(TicTacToe[0][4] == " O" && TicTacToe[2][2] == " O" && TicTacToe[4][0] == " O")
            {
                cout << "CPU wins!" << endl;
                return 2;
            }

}
int main()
{
    srand(time(0));
    int userPos;
    int cpuPos;
    set<int> position;
  
    string TicTacToe [5][5] = {{"  "," |","  "," |","  "},
                                {"---","+","---","+","---"},
                                {"  "," |","  "," |","  "},
                                {"---","+","---","+","---"},
                                {"  "," |","  "," |","  "}};

        gameBoard(TicTacToe);

        while(true)
        {

        while(true)
        {
            cout << "Input number"<< endl;
            cin >> userPos;
            auto check = position.find(userPos);
            if(check != position.end())
            {
                cout << userPos << " used before\nTry Again!" << endl;
                True = true;
            }
            else
            {
                position.insert(userPos);
                break;
            }
        }
        Position(TicTacToe , userPos , "Player");

        if(position.size() < 9)
        {

        while(true)
        {
            cpuPos = rand() % 9 + 1;
            auto check = position.find(cpuPos);
            if(check != position.end())
            {
                True = true;
            }
            else
            {
                position.insert(cpuPos);
                break;
            }
        }
        Position(TicTacToe , cpuPos , "CPU");
        }
        gameBoard(TicTacToe);
        int result = winningCondition(TicTacToe);
        if(result == 1 || result == 2)
            return false;

        if(position.size()==9)
        {
            cout << "CAT" << endl;
            return false;

        }
        } // end of while


    return 0;
}
