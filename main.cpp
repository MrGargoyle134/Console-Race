#include <iostream>
#include <string>
#include <windows.h>

//Race Game

void ResetPosition() {
  SetConsoleCursorPosition
    (GetStdHandle(STD_OUTPUT_HANDLE), COORD {
      0,
      0
    });
}

std::string Map[24] =
{
    "+======================================================================+",
    "|**********************************************************************|",
    "|***................................................................***|",
    "|**..................................................................**|",
    "|*....................................................................*|",
    "|*....................................................................*|",
    "|*.....................................................................|",
    "|*.......+-----------------------------------------------------+.......|",
    "|*......|#######################################################|......|",
    "|*......|###############                         ###############|......|",
    "|*......|##           |                           |           ##|......|",//10
    "|*......|##           |                           |           ##|......|",
    "|*......|##           |                           |           ##|......|",
    "|*......|##           |                           |           ##|......|",
    "|*......|##           |                           |           ##|......|",//14
    "|*......|###############                        ################|......|",
    "|*......|#######################################################|......|",
    "|*.......+-------------+--------------+------------------------+.......|",
    "|*.....................+..............|................................|",
    "|*....................................|................................|",
    "|**...................................|...............................*|",
    "|***...................+..............|..............................**|",
    "|**********************+**************|********************************|",
    "+======================+==============+================================+",
};


int Player1X = 51,  Player1Y = 19;
int Player2X = 51,  Player2Y = 20;

bool CanRight1;
bool CanLeft1;
bool CanUp1;
bool CanDown1;

bool CanRight2;
bool CanLeft2;
bool CanUp2;
bool CanDown2;

int first;

bool RIGHT1, LEFT1, UP1, DOWN1;
bool RIGHT2, LEFT2, UP2, DOWN2;


int place1, place2;

int main()
{

    SetConsoleTitle("Console Race");
    for(int b = 0; b < 4; b++)
    {

        if(b == 0)
        {
  Map[10] =     "|*......|##           |         33333             |           ##|......|";
  Map[11] =     "|*......|##           |            33             |           ##|......|";
  Map[12] =     "|*......|##           |         33333             |           ##|......|";
  Map[13] =     "|*......|##           |            33             |           ##|......|";
  Map[14] =     "|*......|##           |         33333             |           ##|......|";
        }
        if(b == 1)
        {
  Map[10] =     "|*......|##           |          222              |           ##|......|";
  Map[11] =     "|*......|##           |         2  22             |           ##|......|";
  Map[12] =     "|*......|##           |           22              |           ##|......|";
  Map[13] =     "|*......|##           |          22               |           ##|......|";
  Map[14] =     "|*......|##           |          2222             |           ##|......|";
        }
        if(b == 2)
        {
  Map[10] =     "|*......|##           |          111              |           ##|......|";
  Map[11] =     "|*......|##           |         1111              |           ##|......|";
  Map[12] =     "|*......|##           |         1 11              |           ##|......|";
  Map[13] =     "|*......|##           |           11              |           ##|......|";
  Map[14] =     "|*......|##           |         11111             |           ##|......|";
        }
        if(b == 3)
        {
  Map[10] =     "|*......|##           |      GGGG    OOO   !!     |           ##|......|";
  Map[11] =     "|*......|##           |     G       O   O  !!     |           ##|......|";
  Map[12] =     "|*......|##           |     G   GG  O   O  !!     |           ##|......|";
  Map[13] =     "|*......|##           |     G    G  O   O         |           ##|......|";
  Map[14] =     "|*......|##           |      GGGG    OOO   !!     |           ##|......|";
        }

        for(int i = 0; i < 24; i++)
        {
            for(int a = 0; a < 72; a++)
            {
                switch(Map[i][a])
                {
                    case '.': Map[i][a] = 176; break;
                    case '*': Map[i][a] = 177; break;
                    case '#': Map[i][a] = 219; break;
                }
                std::cout << Map[i][a];
            }
            std::cout << std::endl;
        }
        Sleep(1000);
        ResetPosition();
            }
    for(;;)
    {

        Map[Player1Y][Player1X] = '1';
        Map[Player2Y][Player2X] = '2';

        for(int i = 0; i < 24; i++)
        {
            for(int a = 0; a < 72; a++)
            {
                switch(Map[i][a])
                {
                    case '.': Map[i][a] = 176; break;
                    case '*': Map[i][a] = 177; break;
                    case '#': Map[i][a] = 219; break;
                }
                std::cout << Map[i][a];
            }
            std::cout << std::endl;
        }

        std::cout << "First: Player " << first << std::endl;

//Some bools
CanRight1 = Map[Player1Y][Player1X+1] != '*' && Map[Player1Y][Player1X+1] != '+' && Map[Player1Y][Player1X+1] != '-' && Map[Player1Y][Player1X+1] != '|';
CanLeft1 = Map[Player1Y][Player1X-1] != '*' && Map[Player1Y][Player1X-1] != '+' && Map[Player1Y][Player1X-1] != '-' && Map[Player1Y][Player1X-1] != '|';
CanUp1 = Map[Player1Y-1][Player1X] != '*' && Map[Player1Y-1][Player1X] != '+' && Map[Player1Y-1][Player1X] != '-' && Map[Player1Y-1][Player1X] != '|';
CanDown1 = Map[Player1Y+1][Player1X] != '*' && Map[Player1Y+1][Player1X] != '+' && Map[Player1Y+1][Player1X] != '-' && Map[Player1Y+1][Player1X] != '|';

CanRight2 = Map[Player2Y][Player2X+1] != '*' && Map[Player2Y][Player2X+1] != '+' && Map[Player2Y][Player2X+1] != '-' && Map[Player2Y][Player2X+1] != '|';
CanLeft2 = Map[Player2Y][Player2X-1] != '*' && Map[Player2Y][Player2X-1] != '+' && Map[Player2Y][Player2X-1] != '-' && Map[Player2Y][Player2X-1] != '|';
CanUp2 = Map[Player2Y-1][Player2X] != '*' && Map[Player2Y-1][Player2X] != '+' && Map[Player2Y-1][Player2X] != '-' && Map[Player2Y-1][Player2X] != '|';
CanDown2= Map[Player2Y+1][Player2X] != '*' && Map[Player2Y+1][Player2X] != '+' && Map[Player2Y+1][Player2X] != '-' && Map[Player2Y+1][Player2X] != '|';

RIGHT1 = Player1X > 36;
LEFT1 = Player1X < 36;
UP1 = Player1Y < 12;
DOWN1 = Player1Y > 12;

RIGHT2 = Player2X > 36;
LEFT2 = Player2X < 36;
UP2 = Player2Y < 12;
DOWN2 = Player2Y > 12;

        ///Moves

        //Player 1:
        if(GetAsyncKeyState(VK_RIGHT))
        {
            if(CanRight1)
            {
            Map[Player1Y][Player1X] = 176;
            Player1X++;
            Map[Player1Y][Player1X] = '1';
            }
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            if(CanLeft1)
            {

            Map[Player1Y][Player1X] = 176;
            Player1X--;
            Map[Player1Y][Player1X] = '1';

            }
        }
        if(GetAsyncKeyState(VK_UP))
        {
            if(CanUp1)
                {

            Map[Player1Y][Player1X] = 176;
            Player1Y--;
            Map[Player1Y][Player1X] = '1';

                }
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            if(CanDown1)
            {

            Map[Player1Y][Player1X] = 176;
            Player1Y++;
            Map[Player1Y][Player1X] = '1';

            }
        }


        //Player 2:
        if(GetAsyncKeyState('D'))
        {
            if(CanRight2)
            {
            Map[Player2Y][Player2X] = 176;
            Player2X++;
            Map[Player2Y][Player2X] = '2';
            }
        }
        if(GetAsyncKeyState('Q'))
        {
            if(CanLeft2)
            {

            Map[Player2Y][Player2X] = 176;
            Player2X--;
            Map[Player2Y][Player2X] = '2';

            }
        }
        if(GetAsyncKeyState('Z'))
        {
            if(CanUp2)
                {

            Map[Player2Y][Player2X] = 176;
            Player2Y--;
            Map[Player2Y][Player2X] = '2';

                }
        }
        if(GetAsyncKeyState('S'))
        {
            if(CanDown2)
            {

            Map[Player2Y][Player2X] = 176;
            Player2Y++;
            Map[Player2Y][Player2X] = '2';

            }
        }

//First:

        if(DOWN1 && RIGHT1){place1 = 1;}        else if(RIGHT1){place1 = 2;}
        else if(UP1)  {place1 = 3;}        else if(LEFT1) {place1 = 4;}
        else if(LEFT1 && DOWN1) {place1 = 5;}

        if(DOWN2 && RIGHT1){place2 = 1;}        else if(RIGHT2){place2 = 2;}
        else if(UP2)  {place2 = 3;}        else if(LEFT1) {place2 = 4;}
        else if(LEFT2 && DOWN2){place2 = 5;}


        if(DOWN1&&RIGHT1 && DOWN2&&RIGHT2){if(Player1X > Player2X){first = 1;}else{first = 2;}}
        else if(UP1 && UP2){if(Player1X < Player2X){first = 1;}else{first = 2;}}
        else if(RIGHT1 && RIGHT2){if(Player1Y < Player2Y){first = 1;}else{first = 2;}}
        else if(LEFT1 && LEFT2){if(Player1Y > Player2Y){first = 1;}else{first = 2;}}
        else if(DOWN1&&RIGHT1 && DOWN2&&RIGHT2){if(Player1X > Player2X){first = 1;}else{first = 2;}}

        else if(place1 > place2){first = 1;}else{first = 2;}

        //WIN:
        if(place1 == 4 && Player1X >= 23)
        {
            system("cls");
            std::cout << "Player 1 WIN! \n" << std::endl;
            system("PAUSE");
            return 0;
        }
        else if(place2 == 4 && Player2X >= 23)
        {
            system("cls");
            std::cout << "Player 2 WIN! \n" << std::endl;
            system("PAUSE");
            return 0;
        }

        ResetPosition();
    }
    return 0;
}
