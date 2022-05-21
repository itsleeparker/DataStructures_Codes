//wap to accept and display doubley Linked List.
#include<stdio.h>
#include<stdlib.h>
#include "doubleLinkedListStructure.h"
#include "doubleLinkedListFunction.c"

int main(int argc, char const *argv[])
{
    int  n  ,ch , cnt;
    node *start = NULL;

    printf("\n-----DOUBLY LINKED LIST------\n");
    do{
        printf("\n-----MENU-----\n");
        printf("\n[1]Create Linked List");
        printf("\n[2]Display Linked List");
        printf("\n[3]Get the size of Double Linked List");
        printf("\n[4]Exit");

        printf("\nEnter your choice : ");
        scanf("%d" ,&ch);

        switch (ch)
        {
        case 1 : //create double linked list
                printf("\nEnter value of n : ");
                scanf("%d" , &n);
                start = createList(start , n);
               break;
        case 2: //display list
                if(NULL == start){
                    printf("\nNo list found to diplay  create list first !!!!");
                    break;
                }
                printf("\nEntered Elements are  :  \n");
                display(start);
                break;

        case 3: //count the numbers in list
                if(NULL == start){
                    printf("\nNo list found to display create List first !!!!");
                    break;
                }
                cnt = countNodesInList(start);
                printf("\nThe given List has %d Nodes \n" , cnt);
                break;
        case 4: //exit code
                break;
        default:
                printf("\nEnter a valid option only !!!");
            break;
        }
    }while(ch != 4);
    return 0;
}
