#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

void createTree(cellPointer *p_Cell){
    *p_Cell = NULL;
}

cellPointer* searchItem(int p_Key, cellPointer *p_Pointer){
    if (*p_Pointer == NULL){
        printf("Key not found.\n");
        return NULL;
    }else if ((*p_Pointer) -> m_Key == p_Key){
        return p_Pointer;
    }else{
        if ((*p_Pointer) -> m_Key < p_Key){
            searchItem(p_Key, &((*p_Pointer) -> m_Right));
        }else{
            searchItem(p_Key, &((*p_Pointer) -> m_Left));
        }
    }
}

void insertItem(int p_Key, cellPointer *p_Pointer){
    if (*p_Pointer != NULL){
        if ((*p_Pointer) -> m_Key < p_Key){
            insertItem(p_Key, &((*p_Pointer) -> m_Right));
            return;
        }else{
            insertItem(p_Key, &((*p_Pointer) ->m_Left));
            return;
        }
    }else{
        printf("Inserted item %d\n", p_Key);
        *p_Pointer = (cellPointer)malloc(sizeof(Cell));
        (*p_Pointer) -> m_Key = p_Key;
        (*p_Pointer) -> m_Left = NULL;
        (*p_Pointer) -> m_Right = NULL;;
    }
}

void findAntecessor(cellPointer p_Root, cellPointer *p_Tree){
    if ((*p_Tree) -> m_Right != NULL){
        findAntecessor(p_Root, &((*p_Tree) -> m_Right));
        return;
    }
    p_Root -> m_Key = (*p_Tree) -> m_Key;
    p_Root = (*p_Tree);
    (*p_Tree) = (*p_Tree) -> m_Left;
    free(p_Root);
}

void findSucessor(cellPointer p_Root, cellPointer *p_Tree){
    if ((*p_Tree) -> m_Left != NULL){
        findSucessor(p_Root, &((*p_Tree) -> m_Left));
        return;
    }
    p_Root -> m_Key = (*p_Tree) -> m_Key;
    p_Root = (*p_Tree);
    (*p_Tree) = (*p_Tree) -> m_Right;
    free(p_Root);
}

void removeItem(int p_Key, cellPointer *p_Tree){
    cellPointer* v_SubTree = searchItem(p_Key, p_Tree);
    if ((*v_SubTree) -> m_Left == NULL && (*v_SubTree) -> m_Right == NULL){
        (*v_SubTree) = NULL;
    }else if ((*v_SubTree) -> m_Left != NULL && (*v_SubTree) -> m_Right != NULL){
        findAntecessor((*p_Tree), &((*v_SubTree) -> m_Left));
    }else{
        if ((*v_SubTree) -> m_Left != NULL){
            cellPointer v_Aux = (*v_SubTree) -> m_Left;
            (*v_SubTree) -> m_Left = v_Aux -> m_Left;

        }else{
            cellPointer v_Aux = (*v_SubTree) -> m_Right;
            (*v_SubTree) -> m_Right = v_Aux -> m_Right;
        }
        (*v_SubTree) = NULL;
    }
}

void printTree(cellPointer *p_Tree){
    if (*p_Tree == NULL)
        return;
    else{
        printTree(&((*p_Tree) -> m_Left));
        printf("%i ", (*p_Tree) -> m_Key);
        printTree(&((*p_Tree) -> m_Right));
    }
}
