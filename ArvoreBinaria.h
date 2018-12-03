#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

typedef struct Cell *cellPointer;

typedef struct Cell{
    int m_Key;
    cellPointer m_Left, m_Right;
}Cell;

void createTree(cellPointer*);
cellPointer* searchItem(int, cellPointer*);
void insertItem(int, cellPointer*);
void findAntecessor(cellPointer, cellPointer*);
void findSucessor(cellPointer, cellPointer*);
void removeItem(int, cellPointer*);
void printTree(cellPointer*);
#endif // ARVOREBINARIA_H_INCLUDED
