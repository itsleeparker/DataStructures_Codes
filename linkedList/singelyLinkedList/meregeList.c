//wap to accept two lists and merge them together 
#include<stdio.h>
#include<stdlib.h>
#include "linkedListStruct.h"
#include "linkedListFunction.c"

node *start1 = NULL, *start2 = NULL , *start3 =NULL;

// MAIN FUNCITON HERE 
int main(int argc, char const *argv[])
{
    int n , ch , flag=0 , sorted =1;

    printf("\n-----MERGE LIST-----\n");
    
    do{
        printf("\n----MENU-----\n");
        printf("\n[1]Create List ");
        printf("\n[2]Display List 1");
        printf("\n[3]Display List 2");
        printf("\n[4]Display List 3");
        printf("\n[5]Sort the List");
        printf("\n[6]Merge Lists ");
        printf("\n[7]Exit\n");

        printf("\nEnter an option  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:
            create:
            if(flag == 0){
                printf("\nEnter value of N for list 1 ");
                scanf("%d" ,&n);
                start1 = createList(start1 , n);
                flag = 1;
            }
            else if(flag == 1){
                printf("\nEnter Value of N for list 2 ");
                scanf("%d" , &n);
                start2 = createList(start2 , n);
            }
            else{
                printf("\nList already Created continung with list 1");
                flag = 0;
                goto create;
            }
            break;
        
        case 2:
            if(NULL != start1){
                display(start1);
            }
            else{
                printf("\nNO list found to display !!!!");
                break;
            }
            break;
        case 3: 
            if(NULL != start2){
                display(start2);
            }
            else{
                printf("\nNO list found to display !!!!");
            }
                break;
        case 4:
                
            if(NULL != start3){
                display(start3);
            }
            else{
                printf("\nNO list found to display !!!!");
            }   
                break;
        case 5:
                if(NULL != start2 && NULL != start2){
                    sortList(start1);
                    sortList(start2);
                    sorted = 0;
                }
                break;
        case 6: 
                //check if both of the list or not
                if(sorted == 1){
                    printf("\nLists are not sorted please sort the list first !!!");
                    break;
                }
                else{
                    start3 = merge(start1 , start2 , start3);
                    printf("\nMergeing performed successfuly !!!!");
                }
                break;

        case 7: //exit programme;
                break;
        default:
            printf("\nEnter a valid option !!!!");
            break;
        }
    }while(ch != 7);

    printf("\n-----THANK YOU USE AGIAN ------\n");
    return 0;
}