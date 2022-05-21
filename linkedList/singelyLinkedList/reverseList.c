//wap to reverse a linkeed List
#include<stdio.h>
#include<stdlib.h>
#include "linkedListStruct.h"
#include "linkedListFunction.c"

int main(int argc, char const *argv[])
{
    int  n  , ch;
    node *start = NULL;

    printf("\n----REVERESE AN LINKED LIST----\n"); 

    do{
        printf("\n----MENU-----\n");
        printf("\n[1]Create List ");
        printf("\n[2]Display List");
        printf("\n[3]Reverse an array");
        printf("\n[4]Exit ");

        printf("\nEnter your choice ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1 : //create a list 
                printf("\nEnter the value of n for list  : ");
                scanf("%d" , &n);

                start = createList(start , n);
            break;
        case 2: //Display List
                if(NULL == start){
                    printf("\nNo list Found to display !!! Create list first \n");
                    break;
                }
                display(start);
                break;
        case 3: //reverse a list
                if(NULL == start){
                    printf("\nNO list found to revererse the list !!!");
                    break;
                }
                start =  reverseList(start);
            break;
        case 4:
                break;
        default:
            printf("\nEnter a valid choice only pls !!!!");
            break;
        }
    }while (ch != 4);

    printf("\n-----THANK YOU USE AGAIN-------\n");       
    return 0;
}
