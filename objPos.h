#ifndef OBJPOS_H
#define OBJPOS_H

class objPos
{
    public:
        int x;
        int y;
        char symbol;

        objPos(); //class defination
        objPos(objPos &o); // copy constructor
        objPos(int xPos, int yPos, char sym);//constructors


        //setters
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  
        void getObjPos(objPos &returnPos); // pass by reference 
        char getSymbol();

        bool isPosEqual(const objPos* refPos);//pass by pointer
        
        //getters
        char getSymbolIfPosEqual(const objPos* refPos); // pass by pointer
};

#endif