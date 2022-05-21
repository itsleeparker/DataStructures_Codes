//wap to merge two given linked list
#include<stdio.h>
#include<stdlib.h>
#include"doubleLinkedListStructure.h"
#include"doubleLinkedListFunction.c"

int n;

// MEREGE FUNCTION HERE 
node *Merge(node *start1 , node *start2 , node *start3)
{
    node *temp1 = start1;
    node *temp2 = start2;
    node*temp , *newnode;

    while(temp1 != NULL && temp2 !=  NULL)
    {
        //allocate new memeory
        newnode = (node*)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->prev =NULL;

        if(temp1->data < temp2->data)
        {
            newnode->data = temp1->data;
            temp1 = temp1->next;
        }
        else{
            newnode->data =temp2->data;
            temp2 = temp2->next;
        }

        if(start3 == NULL)
        {
            start3 = temp = newnode;

        }
        else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    if(temp1 != NULL)
    {
        temp->next = temp1;
    }
    
    else if(temp2 != NULL)
    {
        temp->next = temp2;
    }
    return start3;
}

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    int ch  , flag=0;
    node *start1= NULL , *start2 = NULL  , *start3 = NULL;

    printf("\n-----MEREGE LIST-----\n");
    do{    
        printf("\n----MENU----\n");
        printf("\n[1]Create List [Use twice for creating two lists]");
        printf("\n[2]Display List 1");
        printf("\n[3]Display List 2");
        printf("\n[4]Display List 3");
        printf("\n[5]Merge List");
        printf("\n[6] Exit");

        printf("\nEnter your choice  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:
            if(!flag){
                printf("\nEnter value of n for 1 List : ");
                scanf("%d" ,&n);
                start1 = createList(start1 , n);
                flag = 1;
            }
            else{
                printf("\nEnter Value of n for 2 List : ");
                scanf("%d" , &n);
                start2 = createList(start2 , n);
            }
            break;
        case 2: //display first list
                if(start1 == NULL){
                    printf("\nNo list Found ,create list first !!!");
                    break;
                }
                display(start1);
            break;
        case 3: //display second list
                if(start2 == NULL){
                    printf("\nNo list Found ,create list first !!!");
                    break;
                }
                display(start2);
            break;

        case 4: //display second list
                if(start3 == NULL){
                    printf("\nNo list Found ,create list first !!!");
                    break;
                }
                display(start3);
            break;

        case 5: //concatante function 
                if(start1 == NULL || start2 == NULL){
                    printf("\nNo list Found ,create list first !!!");
                    break;
                }
                start3 = Merge(start1 , start2  , start3);

                printf("\nList 1 Concanated to Link 2 Successfully!!!\n");
            break;
        case 6: //exit programe
            break;

        default:
            printf("\nEnter option from the given menu itself ");
            break;
        }
    }while(ch != 6);

    printf("\n-----THANK YOU USE AGAIN------\n");
    return 0;
}
