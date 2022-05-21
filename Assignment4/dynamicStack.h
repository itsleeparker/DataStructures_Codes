//wap to implement functions and opration for Dynamic stack
#include<stdlib.h>
typedef struct dynamicStack
{
    struct dynamicStack *top;
    int data;
}D_stack;

void D_Init(D_stack *s)
{
    s->top == NULL;
}

int D_IsEmpty(D_stack *s)
{
    return (s->top == NULL);
}


void D_Push(D_stack *s , int val)
{
    D_stack *newnode;
    newnode = (D_stack*)malloc(sizeof(D_stack));
    newnode->data = val;
    newnode->top = s->top;
    s->top = newnode;
}

int D_Pop(D_stack *s)
{
    D_stack *temp;
    int val;
    temp = s->top;
    s->top  = temp->top;
    val = temp->data;
    free(temp);
    return val;
}

int D_Peek(D_stack *s)
{
    return s->top->data;
}

void D_Display(D_stack *s)
{
    D_stack *temp;
    temp = s;
    while(temp->top != NULL)
    {
        temp = temp->top;
        printf("%3d" , temp->data);
    }    
}