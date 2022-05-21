//wrute functions and operations for implemnting dynamic stack
#include<stdlib.h>

typedef struct dynamicCharstack
{
    char data;
    struct dynamicCharstack *top;
}D_stack;

void D_Init(D_stack *s)
{
    s->top = NULL;
}

int D_IsEmpty(D_stack *s)
{
    return(s->top == NULL);
}

void D_Push(D_stack *s , char val)
{
    D_stack *newnode;

    //allocate memeory 
    newnode = (D_stack *)malloc(sizeof(D_stack));
    newnode->data = val;
    newnode->top = s->top;
    
    s->top = newnode;
}

char D_Pop(D_stack *s)
{
    char val;
    D_stack *temp;
    
    temp = s->top;      //remove the top block
    s->top = temp->top;
    
    val = temp->data;   //send tbe data to the user
    free(temp);
    return val;
}