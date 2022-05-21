//wap to insert a new node in doubley linked list
#include<stdio.h>
#include<stdlib.h>
#include "doubleLinkedListStructure.h"
#include "doubleLinkedListFunction.c"

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    node *start=NULL;
    int ch  , pos , n;
    printf("\n----INSERTION DOUBLEY LINKED LIST-----\n");

    do{
        printf("\n----MENU-----\n");
        printf("\n[1]Create List");
        printf("\n[2]Display List");
        printf("\n[3]Insert Node");
        printf("\n[4]Exit");

        printf("\nEnter your choice  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1: //Create List
                printf("\nEnter how many nodes you need ");
                scanf("%d" , &n);
                start = createList(start  , n);
                break;
        case 2: //Dsiplay List
                if(NULL == start){
                    printf("\nNo list Found to Dipsplay !!!");
                    break;
                }
                display(start);
                break;
        case 3: //Insert Node
                if(NULL == start){
                    printf("\nNo list Found to insert node at !!!");
                    break;
                }
                printf("\nEnter Position for new node  :");
                scanf("%d" , &pos);
                if(pos>n)
                {
                    printf("\nGiven position exceeds lenght of linked list !!!");
                    break;
                }
                start = Insertnode(start , pos , &n);
                break;
        case 4: //Exit Code
                break;
        default:
                printf("\nEnter a valid option only !!!\n");
            break;
        }
    }while(ch != 4);
    return 0;
}
