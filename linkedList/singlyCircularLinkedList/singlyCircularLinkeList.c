//wap to accept a value of n and create a singly circular linked list , and display this list
#include<stdio.h>
#include<stdlib.h>
#include "singleyCircularFunctions.c"
typedef struct circularLinkedList
{
    int data;
    struct circularLinkedList *next;
}node;

int n;

// CREAET FUNCTION HERE 
node * createList(node *start , int n){
    node *newnode , *temp;
    int i;

    for(i=0 ; i<n ;++i)
    {
        newnode = (node*)malloc(sizeof(node));              //allocate memory
        printf("\nEnter data for %d Node  : " , i+1);
        scanf("%d" , &newnode->data);

        if(NULL == start)
        {
            start = temp = newnode;
            newnode->next  =start;
        }
        else{
            temp->next = newnode;
            newnode->next = start;
            temp = newnode;
        }
    }
    return start;
}

// DISPLAY FUNCTION HERE 
void display(node *start)
{
    node *temp;
    temp = start;
    do{ 
        printf("%3d" , temp->data);
        temp = temp->next;
    }while(temp != start);
}

// MAIN FUNCTON HERE 
int main(int argc, char const *argv[])
{
    node *start = NULL ;
    int ch , count   , val , pos;

    printf("\n----CIRCULAR LINKED LIST----\n");
    do{
        printf("\n[1]Create List\n");
        printf("\n[2]Display List \n");
        printf("\n[3]Lenght");
        printf("\n[4]Search");
        printf("\n[5]Exit \n");
        
        printf("\nEnter your option : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:    //Create List
                printf("\nEnter value of n : ");
                scanf("%d" , &n);
                start=createList(start , n);
            break;
        
        case 2:     //display List
            if(NULL == start)
            {
                printf("\nNO list Found to display !!!");
            }
            display(start);
            break;
        
        case 3:     //display List
            if(NULL == start)
            {
                printf("\nNO list Found to display !!!");
            }
            count  = length(start);
            printf("\nThe given list %d length " , count);
            break;            

        case 4:
            if(NULL == start)
            {
                printf("\nNO list Found to display !!!");
            }
            printf("\nEnter value to be searched  : ");
            scanf("%d" , &val);
            pos = search(start , val);
            if(pos != -1)
            {
                printf("\nElement found at %d position \n ");
            }
            else{
                printf("\nElement not found!!");
            }
            break;

        case 5: //Exit code
            /* code */
            break;
        default:
            printf("\nEnter a valid option only !!!\n");
            break;
        }
    }while(ch != 5); 

    printf("\n----THANK YOU USE AGAIN ----\n");
    return 0;
}
