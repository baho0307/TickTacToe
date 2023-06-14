#include <iostream>

//The Player Plays First:
int player = 0;

//If this variable is true ,game continues
bool isGameOn = true;

//XOX Inputs Will Come here:
std::string playground[9] = {"1","2","3","4","5","6","7","8","9"};

//Simple Show Playground Function:
void ShowGround()
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
            std::cout << "|" <<std::endl;
        std::cout << "|" << playground[i];
    }
    std::cout <<"|" << std::endl;
}

//Is Game Ended Function
int GameControl()
{
    int xoFinder = 0;
    for (int i = 0; i < 9; i += 3)
    {
        if(playground[i] == playground[i+1] && playground[i] == playground[i + 2])
            return playground[i] == "x" ? 1 : 2;
    }
    for (int i = 0; i < 3; i ++)
    {
        if (playground[i] == playground[i + 3] && playground[i] == playground[i + 6])
            return playground[i] == "x" ? 1 : 2;
    }
    if ((playground[0] == playground[4] && playground[0] == playground[8]) || (playground[2] == playground[4] && playground[2] == playground[6])) 
        return (playground[0]  == "x") || (playground[2] == "x") ? 1 : 2;
    for (int i = 0; i < 9; i++)
    {
        
        if (playground[i] == "x"|| playground[i] == "o")
            xoFinder += 1;
    }
    if (xoFinder == 9)
        return 0;
    else
        return 3;
}

int main()
{
    //Player Input
    int indexInput;

    while (isGameOn) 
    {
        ShowGround();
        do {
            std::cout << "Player "<< player + 1 << "'s turn (please write the number which you want) ";
            std::cin >> indexInput;
        } while (playground[indexInput-1] == "x" || playground[indexInput-1] == "o");
        if (!player)
            playground[indexInput-1] = "x";
        else
            playground[indexInput-1] = "o";
        player++;
        player %= 2;
        if (!GameControl())
        {
            ShowGround();
            std::cout << "Draw!";
            break;
        }
        else if (GameControl() == 3);
        else
        {
            ShowGround();
            std::cout << "Player " << GameControl() << " Won!";
            break;
        }
    }
}
