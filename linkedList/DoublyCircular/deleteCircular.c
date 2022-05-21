//wap to create and delete a node by postin and value in doubly circular linked list
#include<stdio.h>
#include<stdlib.h>
#include"doublyStructure.h"
#include"doublyCircularFunctions.c"

int n;

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    int ch ,op,val,pos;
    node *start = NULL;

    printf("\n----Delete a Node-----\n");
    do{
        printf("\n[1]Create List");
        printf("\n[2]Display List");
        printf("\n[3]Display Revserse List");
        printf("\n[4]Delete Node");
        printf("\n[5]Append node");
        printf("\n[6]Exit");

        printf("\nEnter your choice : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:
                //create
                printf("\nEnter value of n : ");
                scanf("%d" , &n);
                start = createList(start , n);
            break;

        case 2:
                //display
                if(NULL == start)
                {
                    printf("\nNo List found to display!!!");
                    break;
                }
                printf("\nList is  : ");
                display(start);
            break;

        case 3:
                //display reverse
                if(NULL == start)
                {
                    printf("\nNo List found to display!!!");
                    break;
                }
                printf("\nReverse list is : ");               
                displayRev(start);

            break;
        case 4:
                //delete by posoiton
                if(NULL == start)
                {
                    printf("\nNo List found to display!!!");
                    break;
                }                
                printf("\n---Delete----\n");
                printf("\n[1]Delete a node at the beggining");
                printf("\n[2]Delete a node at the middle");
                printf("\n[3]Delete a node at the end");
                printf("\n[4]Delete a node by Value");

                printf("\nEnter your choice  : ");
                scanf("%d" , &op);

                switch (op)
                {
                case 1:
                        //Delete a node at the beggining
                        start = delteNode(start , 1 , &n);
                    break;
                case 2:
                        //Delete a node at the middle
                        printf("\nEnter positon to delete node from  : ");
                        scanf("%d" , &pos);
                        if(pos > n || pos < 0)
                        {
                            printf("\nGiven Position does not exitst !!!");
                            break;
                        }
                        start = delteNode(start , pos , &n);
                    break;
                case 3:
                        //Delete a node at the end 
                        start = delteNode(start  , n , &n);
                    break;
                case 4:
                        //Delete a node by value
                        printf("\nEnter the value to be deleted  : ");
                        scanf("%d" , &val);
                        start = deleteByValue(start , val , &n);
                    break;

                default:
                    printf("\nEnter a valid option only !!!");
                    break;
                }
            break;
            case 5:
                 if(NULL == start)
                 {
                     printf("\nNo List found !!!");
                     break;
                 }    
                 start = append(start);
                 break;
        case 6:
                //exit
            break;    
        default:
            printf("\nEntere a valid option!!! \n");
            break;
        }
    }while(ch != 6);

    printf("\n----THANK YOU USE AGAIN-----\n");
    return 0;
}
