#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; 
    sizeList = 0; 
    arrayCapacity =  ARRAY_MAX_CAP; 
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; 
}

int objPosArrayList::getSize()
{
    return sizeList; 
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList < ARRAY_MAX_CAP){
        for(int i = sizeList; i>0; i--){
            aList[i].setObjPos(aList[i-1]);
        }
        aList[0].setObjPos(thisPos);
        sizeList++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList < ARRAY_MAX_CAP){
        aList[sizeList].setObjPos(thisPos);
        sizeList++;
    }
}

void objPosArrayList::removeHead()
{
    if(sizeList>0){
        for(int i = 0; i < sizeList-1; i++){
            aList[i].setObjPos(aList[i+1]);
        }
        sizeList--;
    }
}

void objPosArrayList::removeTail()
{
    if(sizeList > 0){
        sizeList--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    aList[0].getObjPos(returnPos);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    aList[sizeList - 1].getObjPos(returnPos);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    aList[index].getObjPos(returnPos);
}
