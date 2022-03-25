#include <iostream>

using namespace std;
//The player who plays first:
int player = 1;

bool isGameOn = true;

//XOX Inputs Will Come here:
string playground[9] = {"1","2","3","4","5","6","7","8","9"};

//Simple Show Playground Function:
void ShowGround()
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << endl;
        }
        cout << playground[i];
    }
    cout << endl;
}

int GameControl()
{
    int xoFinder = 0;
    for (int i = 0; i < 9; i += 3)
    {
        if(playground[i] == playground[i+1] && playground[i] == playground[i + 2])
        {
            
            return playground[i] == "x" ? 1 : 2;
        }
    }

    for (int i = 0; i < 3; i ++)
    {
        if (playground[i] == playground[i + 3] && playground[i] == playground[i + 6])
        {
            return playground[i] == "x" ? 1 : 2;
        }
    }
    
    if ((playground[0] == playground[4] && playground[0] == playground[8]) || (playground[2] == playground[4] && playground[2] == playground[6])) 
    {
        return (playground[0]  == "x") || (playground[2] == "x") ? 1 : 2;
    }
    for (int i = 0; i < 9; i++)
    {
        cout << xoFinder;
        if (playground[i] == "x"|| playground[i] == "o")
        {
            xoFinder += 1;
            if(xoFinder == 8)
            {
                return 0;
            }
            else 
            {
                return 3;
            }
        }
    }
    
}

int main()
{

    int indexInput;

    while (isGameOn) 
    {
        ShowGround();

        if (player == 1)
        {
            do {
             cout << "Player 1's turn (please write the number which you want) ";
             cin >> indexInput;
            } while (playground[indexInput-1] == "x" || playground[indexInput-1] == "o");
             
             playground[indexInput-1] = "x";
             player = 2;
        }
        else if (player == 2)
        {
            do {
                cout << "Player 2's turn (please write the number which you want) ";
                cin >> indexInput;
            } while (playground[indexInput-1] == "x" || playground[indexInput-1] == "o");
            playground[indexInput-1] = "o";
            player = 1;
        }
        if (GameControl() == 1)
        {
            ShowGround();
            cout << "Player 1 Won!";
            break;
        }
        else if(GameControl() == 2)
        {
            ShowGround();
            cout << "Player 2 Won!";
            break;
        }
        else if (GameControl() == 0)
        {
            ShowGround();
            cout << "Draw!";
            break;
        }
    }
}

