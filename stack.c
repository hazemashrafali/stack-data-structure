#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void createEmptyStack(ST_stack_t *stack)
{
    for(int x=0; x<STACK_SIZE; x++)
        stack->elements[x]=0;
    stack->top=-1;
}

int8_t push(ST_stack_t *stack, uint8_t data)
{
    if(stack->top == (STACK_SIZE-1))  //check stack is full
        return -1;
    stack->top++;
    stack->elements[stack->top]=data;
    return 0;
}

int8_t pop(ST_stack_t *stack, uint8_t *data)
{
    if(stack->top == -1)
        return -2;      //check stack is empty
    *data=stack->elements[stack->top];
    stack->top--;
    return 0;
}

int8_t printStack(ST_stack_t *stack)
{
    if(stack->top == -1)
        return -2;      //check stack is empty
    for(int x=stack->top; x>-1; x--)
        printf("%c\n",stack->elements[x]);
    if(stack->top == (STACK_SIZE-1))  //check stack is full
        return -1;
    else
        return 0;
}

int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{
    *topData=stack->elements[stack->top];
    if(stack->top == -1)
        return -2;      //check stack is empty
    else
        return 0;
}

int8_t isFull(ST_stack_t *stack)
{
    if(stack->top == (STACK_SIZE-1))  //check stack is full
        return -1;
    else
        return 0;
}

int8_t isEmpty(ST_stack_t *stack)
{
    if(stack->top == -1)
        return -2;      //check stack is empty
    else
        return 0;
}
