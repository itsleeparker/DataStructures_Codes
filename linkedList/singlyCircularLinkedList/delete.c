//wap to create and display singly circular linked list , write a function to delete a node by position and value
#include<stdio.h>
#include<stdlib.h>
#include"singleyCircularStructure.h"
#include"singleyCircularFunctions.c"

int n;
node *rare;

// MAIN FUNCITON HERE 
int main(int argc, char const *argv[])
{
    int ch , op , pos , val;
    node *start = NULL;

    printf("\n---DELETE A NODE---\n");
    do{
        printf("\n----MENU----\n");
        printf("\n[1]Create List");
        printf("\n[2]Display List");
        printf("\n[3]Delete Node by Position");
        printf("\n[4]Delete Node by Value");
        printf("\n[5]Exit");

        printf("\nEnter your choice : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1: //create list
            printf("\nEnter value of n : ");
            scanf("%d" , &n);
            start = createList(start , n);
            break;
        
        case 2:     //display
            if(NULL == start)
            {
                printf("\nNO List found Create Node first");
                break;
            }
            printf("\nEntered Linked List is  : ");
            display(start);
            break;
        
        case 3:       //delete a node by position
            if(NULL == start)
            {
                printf("\nNO List found Create Node first");
                break;
            }
                printf("\n--Delete Node By Position---\n");
                printf("\n[1]Delete the node at the Beggining ");
                printf("\n[2]Delete the node at the Middle");
                printf("\n[3]Delete the node at the End");

                printf("\nEnter your option : ");
                scanf("%d" , &op);

                switch (op)
                {
                case 1:
                    start = deleteNodePos(start , 1 , &n);
                    break;

                case 2:     //delete the node in the middle
                        printf("\nEnter the position you want to delete the node  : ");
                        scanf("%d" , &pos);
                        if(pos > n)
                        {
                            printf("\nGiven Position does not exist on Linked List !!!");
                            break;
                        }
                        start = deleteNodePos(start , pos , &n);
                    break;

                case 3:         //delete the node at the end
                    start = deleteNodePos(start , n , &n);
                    break;

                default:
                    printf("\nEnter a valid option only !!!");
                    break;

             }
            break;
        
            case 4:     //Delete a node by value
                if(NULL == start)
                {
                    printf("\nNO List found Create Node first");
                    break;
                }
            printf("\nEnter value to be deleted  : ");
            scanf("%d" , &val);

            start = deleteByVal(start , val , &n);
            
            break;
        
        case 5:
                //exit 
            break;
        
        default:
            printf("\nEnter a valid option only !!!");
            break;
        }
    }while(ch != 5);

    printf("\n----THANK YOU USE AGIAN-------\n");
    return 0;
}
