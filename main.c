#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main()
{
    uint8_t text[5]= {'a','b','c','d','e'};
    uint8_t text_2[7]= {'q','w','e','r','t','y','u'};
    uint8_t data,top_data;
    ST_stack_t newStack;
    createEmptyStack(&newStack);        //create an empty stack
    for(int x=0; x<5; x++)
        printf("push state=%d\n",push(&newStack,text[x]));         //push 5 characters to the stack
    printStack(&newStack);              //print all stack data
    pop(&newStack,&data);               //pop one character
    getStackTop(&newStack,&top_data);
    printf("stack top:%c\n",top_data);  //print the stack top
    printStack(&newStack);              //print all stack data
    for(int x=0; x<7; x++)
    {
        if(isFull(&newStack) != -1 )     //check stack is full
            printf("push state=%d\n",push(&newStack,text_2[x]));      //Push another 7 different characters to the stack
        else
        {
            printf("====the stack is full=====\n");
            break;
        }
    }
    getStackTop(&newStack,&top_data);
    printf("stack top:%c\n",top_data);  //print the stack top
    printStack(&newStack);              //print all stack data
    for(int x=0; x<4; x++)
        pop(&newStack,&data);           // Pop 4 characters from the stack
    getStackTop(&newStack,&top_data);
    printf("stack top:%c\n",top_data);  //print the stack top
    printStack(&newStack);              //print all stack data
    for(int x=0; x<7; x++)
    {
        if(isEmpty(&newStack) != -2)    //check stack is empty
            printf("pop state=%d\n",pop(&newStack,&data));// Pop 7 characters from the stack
        else
        {
            printf("====the stack is empty=====\n");
            break;
        }
    }
    getStackTop(&newStack,&top_data);
    printf("stack top:%c\n",top_data);  //print the stack top

    if(isEmpty(&newStack) == -2)
        printf("====the stack is empty=====\n");            //print all stack data
    else
        printStack(&newStack);

}
