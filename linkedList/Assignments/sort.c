//wap to sort the linked list in ascending order
#include<stdio.h>
#include<stdlib.h>
#include"doubleLinkedListStructure.h"
#include"doubleLinkedListFunction.c"

int n;

void sort(node *start)
{
    node *transverseTemp , *temp;
    int num;

    for(transverseTemp = start ; transverseTemp->next != NULL ; transverseTemp = transverseTemp->next)
    {
        temp = transverseTemp;
        while (temp!=NULL)
        {
            if(transverseTemp->data > temp->data)
            {
                num = temp->data;
                temp->data = transverseTemp->data;
                transverseTemp->data = num;
            }
            temp = temp->next;
        }
        
    }
    printf("\nList sorted successfully\n");
}

node *sortData(node *start)
{
    node *temp;
    node *traverseTemp;
    node *cur;
    int flag = 0;

    //use bubble sort
    for(cur = start ;cur->next != NULL ;cur=cur->next)
    {
         traverseTemp = start;
         while(traverseTemp->next != NULL)
         {
             
             if(start->data > start->next->data)
             {
                 temp = start->next;
                 temp->prev = NULL;
                 temp->next->prev = start;
                 start->next = temp->next;
                 temp->next = start;
                 start->prev = temp;
                 start = temp;
                 break;
             }

             if(traverseTemp->data > traverseTemp->next->data)
             {
                 flag =1;
                 //left side of node
                 temp = traverseTemp->next;
                 traverseTemp->prev->next = temp;
                 temp->prev = traverseTemp->prev;
                 traverseTemp->prev = temp;
                 
                 //right side of node
                 traverseTemp->next = temp->next;
                 temp->next->prev = traverseTemp;
                 temp->next = traverseTemp;
             }
             traverseTemp = traverseTemp->next;
             if(flag == 1)
             {
                 break;
             }
         }        
    }
    return start;
}
// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    int ch;
    node *start =NULL;
    printf("\n---SORT THE LIST----\n");
    do{
        printf("\n----MENU-----\n");
        printf("\n[1]Create List");
        printf("\n[2]Display List");
        printf("\n[3]Sort The data by pos(under Consrtruction)");
        printf("\n[4]Sort Data Normally");
        printf("\n[5]Display Reverse List");
        printf("\n[6]Exit ");

        printf("\nEnter your choice  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
            case 1:// CREATE LIST
                printf("\nEnter Value of n : ");
                scanf("%d" , &n);
                start = createList(start , n);
                break;

            case 2: //DISPLAY LIST
                    if(NULL==start)
                    {
                        printf("\nNo List Found  , Create List first\n");
                    }
                    display(start);
                break;

            case 3: //SORT THE LIST
                                    if(NULL==start)
                    {
                        printf("\nNo List Found  , Create List first\n");
                    }
                    printf("\nThis function is under construction dont use");
                    start = sortData(start);
                break;

            case 4://sort data 
                    if(NULL==start)
                    {
                        printf("\nNo List Found  , Create List first\n");
                    }
                    sort(start);
                break;
            case 5: //display reverse
                    displayReverse(start);
                break;
            case 6: //exit
                break;
            default:
                printf("\nEnter a valid option !!!");
                break;
        }
    }while(ch != 6);
    return 0;
}