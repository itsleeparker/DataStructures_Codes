//wap to insert a node in the given doublyCircular Linked List
#include<stdio.h>
#include<stdlib.h>
#include"doublyStructure.h"
#include"doublyCircularFunctions.c"

int n;

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    node *start = NULL;
    int ch , op , pos;

    printf("\n----INSERT A NODE----\n");

    do{
        printf("\n---MENU---\n");
        printf("\n[1]Create List");
        printf("\n[2]Display List");
        printf("\n[3]Display Reverse List");
        printf("\n[4]Insert a Node");
        printf("\n[5]Exit");

        printf("\nEnter your option  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:
                //Create List
            printf("\nEnter value of n : ");
            scanf("%d" , &n);
            start = createList(start , n);
            break;
        case 2:
                //Display List
            if(NULL == start)
            {
                printf("\nNO List found to display !!!");
                break;
            }

            printf("\nEntered Elements are  : ");
            display(start);

            break;
        
        case 3:
                //Display reverse 
            if(NULL == start)
            {
                printf("\nNO List found to display !!!");
                break;
            }

            printf("\nThe Reverse list is  : ");
            displayRev(start);

            break;

        case 4:
            //insert node function 
            if(NULL == start)
            {
                printf("\nNO List found to display !!!");
                break;
            }


            printf("\n---INSERT -----\n");
            printf("\n[1]Insert node at the Beggining ");
            printf("\n[2]Insert node at the Middle");
            printf("\n[3]Insert node at the End");

            printf("\nEnter your choice : ");
            scanf("%d" , &op);

            switch (op)
            {
            case 1:
                start = Insert(start , 1 , &n);
                break;
            case 2:
                printf("\nEnter position to insert node at  : ");
                scanf("%d" , &pos);
                if(pos>n)
                {
                    printf("\nGiven Positon does not exist !!!");
                    break;
                }
               start =  Insert(start , pos , &n);
                break;

            case 3:
                start = Insert(start  , n , &n);
                break;

            default:
                printf("\nEnter a valid option only !!!!");
                break;
            }
            break;
        case 5:
                    //exit 
            break;
    
        default:
            printf("\nEntered option is not valid !!!");
            break;
        }
    }while(ch != 5); 

    printf("\n----THANK YOU VISIT AGAIN-------\n");
    return 0;
}
