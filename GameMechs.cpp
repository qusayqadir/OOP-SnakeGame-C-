#include "GameMechs.h"
#include "MacUILib.h"


//creates the constructor for the game mechs
// and creates crucial member variables
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;  
    score = 0; 
    boardSizeX = 30; 
    boardSizeY = 15;
    //dynamic memory alloaction to create 2d array 
    gameBoard = new int*[boardSizeX]; 
    for(int i=0; i < boardSizeX; i++)
        gameBoard[i] = new int[boardSizeY]; 


}

//initialixes the GameMechs object, setting values to memeber variables
GameMechs::GameMechs(int boardX, int boardY) //2-D Array
{
    input = 0;
    exitFlag = false;
    loseFlag = false;  
    score = 0; 
    boardSizeX = boardX; 
    boardSizeY = boardY; 
    // does this need to save guards? 
    //if the input is deemed incorrect then set it to these defauly values 
    if( boardSizeX <= 0)
        boardSizeX = 30;
    if(boardSizeY <= 0)
        boardSizeY = 15; 
    gameBoard = new int*[boardSizeX]; 
    for(int i=0; i < boardSizeX; i++)
        gameBoard[i] = new int[boardSizeY]; 

}

// do you need a destructor? --> nothing on the heap? 
//does GameMech require to create a board for the game? 

//deconstructor created to remove all the variables from the heap at the end of the program
GameMechs::~GameMechs()
{
    for(int i=0; i < boardSizeX; i++)
        delete[] gameBoard[i]; 
    delete[] gameBoard; 
}


//memmeber function that returns the value of the exitFlag when called
bool GameMechs::getExitFlagStatus()
{
    return exitFlag; 
}

//member function that returns the value of the losetFlag when called
bool GameMechs::getLoseFlagStatus()
{
    return loseFlag; 
}


//member function that checks if there is an input or not and if there is then
//store in input that was intialized as a memeber variable within the consutrctor 
char GameMechs::getInput()
{
    if(MacUILib_hasChar() == 1) 
    {
        input = MacUILib_getChar(); 
    }
    return input; 
}

//return boardSizeXm the number of rows
int GameMechs::getBoardSizeX()
{
    return boardSizeX; 
}

//returns number of columns
int GameMechs::getBoardSizeY()
{
    return boardSizeY; 
}
//returns game score 
int GameMechs::getScore()
{
    return score; 
}
//when called, this memeber function would change the value of the exitflag 
void GameMechs::setExitTrue()
{
    exitFlag = true; 
}
//change the value of the loserflag
void GameMechs::setLoseFlag()
{
    loseFlag = true; 
}

//changes the current value of input to the input that was passed into this funciton as a parameter
void GameMechs::setInput(char this_input)
{
    input = this_input; 
}

//clear the input to 0 
void GameMechs::clearInput()
{
    input = 0; 

}

//will change the value of the score by 1 
void GameMechs::incrementScore()
{
    score++; 
}
