#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag; //added this 

        int score; //added this
        
        int boardSizeX;
        int boardSizeY;

        int **gameBoard; 

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // added this
        
        bool getExitFlagStatus(); //ok
        void setExitTrue(); //ok 

        bool getLoseFlagStatus(); //ok
        void setLoseFlag(); //ok

        char getInput(); //ok
        void setInput(char this_input); //ok
        void clearInput(); //ok

        int getBoardSizeX(); //ok
        int getBoardSizeY(); //ok

        int getScore(); //ok
        void incrementScore(); // ok
      

};

#endif