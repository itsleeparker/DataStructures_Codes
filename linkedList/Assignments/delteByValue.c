//wap to create  , display and insert node in a doubly linked list
#include<stdio.h>
#include<stdlib.h>
#include "doubleLinkedListStructure.h"
#include "doubleLinkedListFunction.c"
int n = 0;

// DELETE NODE FUNTION HERE 
node *deleteNode(node *start , int val){
    int flag = 0;
    node *temp , *traverseTemp;
    //check if the ndoe is at the beggining
    if(start->data == val){
        if(start->next != NULL)
        {
            flag = 1;
            temp = start;
            start = temp->next;
            start->prev = NULL;
        }
        else{
            printf("\nOnly One node Foudn!!!");
            temp = start;
            start=NULL;
        }
    }

    else{
        for(traverseTemp = start ; traverseTemp->next != NULL ; traverseTemp = traverseTemp->next)
        {
            if(traverseTemp->data == val)
            {
                flag =1;
                temp = traverseTemp->prev;
                temp->next = traverseTemp->next;
                traverseTemp->next->prev = temp;
                temp = traverseTemp;
                break;
            }
        }
    
    }
    if(flag == 1)
    {
        printf("\nNode deleted Successfully !!!");
        free(temp);
        n--;
    }
    else{
        printf("\nGiven Element not found !!!");
    }
    return start;
}

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    node *start =  NULL;
    int ch ,  val;
    printf("\n-----INSERTION DOUBLY LINKED LIST-------\n");
    do{
        printf("\n----MENU----\n");
        printf("\n[1]Create List");
        printf("\n[2]Display List");
        printf("\n[3]Delete By Value Node");
        printf("\n[4]Display reverse ");
        printf("\n[5]Exit ");

        printf("\nEnter your choice  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1: //Create List
                printf("\nEnter value for n : ");
                scanf("%d" , &n);
                start = createList(start ,n);
            break;
        case 2: //display List
                if(NULL == start){
                    printf("\nNo list found to be dipslayed !!!");
                    break;
                }
                printf("\nEnetred Data is  : \n");
                display(start);
            break;
        case 3: //DeleteByValue Node
                if(NULL == start)
                {
                    printf("\nNo nodes found to delete !!!");
                    break;
                }
                printf("\nEnter Value to be deleted  : ");
                scanf("%d" , &val);

                start = deleteNode(start , val);
            break;
        case 4:
                if(NULL == start)
                {
                    printf("\nNo List found to display reverse of  :  ");
                    break;
                }
                displayReverse(start);
            break;
        case 5: //exit code
                break;
        default:
            printf("\nEnter option from the given menu only!!!!\n");
            break;
        }
    }while(ch != 5);
    return 0;
}
