//wap to implement Stack and its functions 
#include<stdio.h>
#include<stdlib.h>

// node STRUCTURE HERE 
typedef struct nodeStruct
{
    int data;
    struct nodeStruct *next;
}node;

// Stack INIT FUNCTION HERE 
node  *Init(node *top)
{
    top = NULL;
    return top;
}

// PUSH FUNCTION HERE 
node *push(node *top , int val)
{
    node *newnode;          //allocate memory for new node in stack
    newnode = (node*) malloc(sizeof(node));
    
    newnode->data = val;    
    newnode->next = top;        //stack the new node above the previous node

    top = newnode;
}

node *pop(node *top)
{
    node *temp;
    temp = top;
    top = temp->next;

    printf("\nThe node with data %d removed !!" ,temp->data);
    free(temp);

    return top;
}

void peek(node *top)
{
    printf("\nThe element at the top is %d \n" , top->data);
}

int isEmpty(node *top)
{
    return (top == NULL);   
}

void display(node *top)
{
    node *temp;
    temp = top;
    while(temp != NULL)
    {
        printf("%3d" , temp->data);
        temp = temp->next;
    }
}

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    node *top;
    int ch , val;

    //intiate node
    top = Init(top);

    printf("\n---STACK----\n");
    do{
        printf("\n----MENU----\n");
        printf("\n[1]Push");
        printf("\n[2]Pop");
        printf("\n[3]Peek");
        printf("\n[4]Display");
        printf("\n[5]Exit");

        //take users choice  
        printf("\nEnter your choice : ");
        scanf("%d" ,&ch);
        
        switch (ch)
        {
        case 1:
            //insert a new element from the top
            printf("\nEnter element to be pushed ");        //take value to be pushed from user
            scanf("%d" , &val);
            top = push(top , val);
            printf("\nEntered element pushed on the top !\n");
            break;
        
        case 2:
            //remove element from the top
            if(isEmpty(top))
            {
                printf("\nThe Stack is empty");
            }

            else{
                top = pop(top);
            }
            break;
        
        case 3:
            //display element on the top
            if(isEmpty(top))
            {
                printf("\nStack Is empty");
            }
            else{
                peek(top);
            }
            break;  
        case 4:
            //display whole stack
            if(isEmpty(top))
            {
                printf("\nStack is empty");
                break;
            }
            printf("\nThe enetered Element are  : ");
            display(top);
            break;
        case 5:
            break;
                //exit function option            
        
        default:
            printf("\nEnter a valid option !!!");
            break;
        }
    }while(ch != 5);

    printf("\n---THANK YOU USE AGIAN----\n");
    return 0;
}