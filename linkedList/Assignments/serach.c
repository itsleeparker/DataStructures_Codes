//wap to create  , display and search an element in double linked list 
#include<stdio.h>
#include<stdlib.h>
#include"doubleLinkedListStructure.h"
#include"doubleLinkedListFunction.c"

int n;


// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    node *start = NULL;
    int ch , val;

    printf("\n----Serch a value in list--------\n");
    do{
        printf("\n-------Menu-----\n");
        printf("\n[1]Create List");
        printf("\n[2]Display List");
        printf("\n[3]Search value ");
        printf("\n[4]Display Reverse List");
        printf("\n[5]Exit ");

        printf("\nEnter your option  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1: //CREATE LIST 
            printf("\nEnter the value of  n : ");
            scanf("%d" , &n);
            start = createList(start , n);
            break;
        case 2:
            if(NULL == start)
            {
                printf("\nNo List found Make list first !!!");
            } 
            display(start);
            break;
        case 3: 
            if(NULL == start)
            {
                printf("\nNo List found Make list first !!!");
            } 
            printf("\nEnter value to be searched  : ");
            scanf("%d" , &val);
            Search(start , val);
            break;
        case 4: //display reverse list
            if(NULL == start)
            {
                printf("\nNo List found Make list first !!!");
            } 
            displayReverse(start);
            break;
        case 5: //exit code
            break;
        default:
            printf("\nEntered option is not valid !!!");
            break;
        }
    }while(ch != 5);
    return 0;
}
