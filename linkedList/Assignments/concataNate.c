//wap to concatanate two linked lists
#include<stdio.h>
#include<stdlib.h>
#include"doubleLinkedListStructure.h"
#include"doubleLinkedListFunction.c"

int n;


// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    node *start1 = NULL , *start2 = NULL;
    int ch , flag = 0;

    printf("\n----concatanate lists----\n");
    do{
        printf("\n----MENU----\n");
        printf("\n[1]Create List [Use twice for creating two lists]");
        printf("\n[2]Display List 1");
        printf("\n[3]Display List 2");
        printf("\n[4]Conctanate List");
        printf("\n[5] Exit");

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
                if(start1 == NULL){
                    printf("\nNo list Found ,create list first !!!");
                    break;
                }
                display(start2);
            break;
        case 4: //concatante function 
                if(start1 == NULL || start2 == NULL){
                    printf("\nNo list Found ,create list first !!!");
                    break;
                }
                concat(start1 , start2);
                printf("\nList 1 Concanated to Link 2 Successfully!!!\n");
            break;
        case 5: //exit programe
        default:
            break;
        }
    }while(ch != 5);
    return 0;
}
