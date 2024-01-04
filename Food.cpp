#include "Food.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include <iostream> 
#include <cstdlib> // Include the necessary library for srand/rand
#include <ctime>

using namespace std; 

//constructor class to initialize object for foodPOs
Food::Food(GameMechs* thisGMRef)
{
    foodPos.setObjPos(5,5,'0'); 
    //allows the food class to interact with the gameMechs object
    mainGameMechsRef = thisGMRef;
    srand(time(NULL)); 


}

Food::~Food()
{
    //nothing to be deleteed
}

//randomly generates a position for the food

void Food::generateFood(objPosArrayList *blockoff)
{
    int randX = 0, randY = 0;
    objPos temp;
    bool flag = false;

    // change for all elements of player
    while (!flag)
    {   
        //random x position that is within the range of the gamebaord
        randX = (rand() % (mainGameMechsRef->getBoardSizeX() - 2)) + 1;
        //random y position that is within the range of the gameboard
        randY = (rand() % (mainGameMechsRef->getBoardSizeY() - 2)) + 1;
        //sets the position of the food at the random x y coordiante that was generated
        foodPos.setObjPos(randX, randY, 'o');

        flag = true;  
        
        //checks to see if any of the new random position that was generated 
        // is generated at a position that is blocked off by the position of the snake
        for (int i = 0; i < blockoff->getSize(); i++)
        {
            blockoff->getElement(temp, i);
            if (temp.x == randX && temp.y == randY)
            {
                flag = false;  
                break;
            }
        }
    }
}


void Food::getFoodPos(objPos &returnPos){

    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol); 
}


