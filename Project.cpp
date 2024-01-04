#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGame; 
Player* myPlayer; 
Food* myFood; 
char input; 

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGame->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGame = new GameMechs(26,13); 
    myPlayer = new Player(myGame); 
    myFood = new Food(myGame);

    // Creates temp body to pass into generate food function
    objPosArrayList *tempBody = myPlayer->getPlayerPos();

    myFood->generateFood(tempBody);

}

void GetInput(void)
{
    input = myGame->getInput(); 

}

void RunLogic(void)
{
    // creates and assigns food position to a value
    objPos tempFoodPos; 
    myFood->getFoodPos(tempFoodPos);

    // Passes food position into move player
    myPlayer->updatePlayerDir(); 
    myPlayer->movePlayer(tempFoodPos); 

    // Creates temp body to assign temp pos to player head
    objPos tempPos; 
    objPosArrayList* tempBody = myPlayer->getPlayerPos(); 

    tempBody->getHeadElement(tempPos);

    if(input == '\t'){
        myGame->setExitTrue();
    }
    myGame->clearInput();

    // checks for collision with food pos and player head using temp pos
    if (tempPos.x == tempFoodPos.x && tempPos.y == tempFoodPos.y)
    {   
        myFood->generateFood(tempBody);     
        myGame->incrementScore(); 
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    // Creates temporary player body for drawscreen
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;
    bool draw;

    // Create temp food position for drawscreen
    objPos tempFoodPos;
    myFood->getFoodPos(tempFoodPos);
    int i, j; 
    for ( i =0; i < myGame->getBoardSizeY(); i++) 
    {
        for(j=0; j < myGame->getBoardSizeX(); j++)
        {

            draw = false;
            for(int k = 0; k < playerBody->getSize(); k++){
                playerBody->getElement(tempBody, k);
                if(tempBody.x == j && tempBody.y == i){
                    MacUILib_printf("%c", tempBody.symbol);
                    draw = true;
                    break;
                }
            }

            if(draw) continue;

            if( i == 0 || j == 0 || i == myGame->getBoardSizeY()-1 || j == myGame->getBoardSizeX() -1) 
            {
                
                MacUILib_printf("%c", '#'); 
            }

        
            else if ( i == tempFoodPos.y && j == tempFoodPos.x)
            {
                MacUILib_printf("%c", tempFoodPos.symbol); 
            }
            else{
        
                MacUILib_printf("%c", ' '); 
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Your Current Score is: %d", myGame->getScore()); 

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen(); 


    // Prints loss message
    if(myGame->getExitFlagStatus()){
        MacUILib_printf("You lost, Your score was: %d", myGame->getScore());
    }   
  
    MacUILib_uninit();
    delete myGame; 
    delete myPlayer;
    delete myFood; 
}
