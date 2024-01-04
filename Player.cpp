#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(
    mainGameMechsRef->getBoardSizeX()/2, 
    mainGameMechsRef->getBoardSizeY()/2, 
    '@'); 

    playerPosList = new objPosArrayList[ARRAY_MAX_CAP];
    playerPosList->insertHead(tempPos);
          

}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList; 
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput(); 
    // PPA3 input processing logic for changing direction
    switch(input)
    {                      
        case 'w':
            if (myDir == LEFT || myDir == RIGHT || myDir == STOP){
                myDir = UP;
            }
            break;
        
        case 's':
            if (myDir == LEFT || myDir == RIGHT || myDir == STOP){
                myDir = DOWN;
            }
            break;
                     
        case 'a':
            if (myDir == UP || myDir == DOWN || myDir == STOP){
                myDir = LEFT;
            }
            break;
        
        case 'd':
            if (myDir == UP || myDir == DOWN || myDir == STOP){
                myDir = RIGHT;
            }
            break;
        
        default:
            break;
    }
    // Sets input to 0 after making the direction change to avoid potential repeated inputs
    mainGameMechsRef->setInput(0);
}

void Player::movePlayer(objPos &foodPos)
{
    // PPA3 Finite State Machine logic
    // Creates a temp objPos to store updated head position
    objPos currHead;

    playerPosList->getHeadElement(currHead);   

    // Switch case to update the new head position
    switch(myDir){
        case UP:
            currHead.y--;
            break;
        case DOWN:
            currHead.y++;
            break;
        case LEFT:
            currHead.x--;
            break;
        case RIGHT:
            currHead.x++;
            break;
        default:
            break;
    }
    // Wrap around logic
    if (currHead.y == 0){
            currHead.y = mainGameMechsRef->getBoardSizeY() - 2;
    }
    if (currHead.y == mainGameMechsRef->getBoardSizeY() - 1){
        currHead.y = 1;
    }
    if (currHead.x == 0){
        currHead.x = mainGameMechsRef->getBoardSizeX() - 2;
    }
    if (currHead.x == mainGameMechsRef->getBoardSizeX() - 1){
        currHead.x = 1;
    }
    // Adds the new head position to the playerPosList
    playerPosList->insertHead(currHead);

    // Checks to see if the head has not collided with the food before removing the tail
    if(currHead.x != foodPos.x  || currHead.y != foodPos.y){
        playerPosList->removeTail();
    } 
    // create a temp body position to check for collision
    objPos tempBody;
    // i starts at 1 so that it checks each position other than the head
    for(int i = 1; i < playerPosList->getSize(); i++){
        playerPosList->getElement(tempBody, i);
        if(currHead.x == tempBody.x && currHead.y == tempBody.y){
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
        }
    }
}

