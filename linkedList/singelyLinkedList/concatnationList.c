//wap to conctatanate 2 different lists 
#include<stdio.h>
#include<stdlib.h>
#include "linkedListStruct.h"
#include "linkedListFunction.c"

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    int  ch , flag=0 , n;
    node *start1  =NULL, *start2 = NULL;

    printf("\n----CONCTANATE TWO LINKS------\n");
   do{
            printf("\n-----MENU-----");
            printf("\n[1]Create List1");
            printf("\n[2]Display List 1");
            printf("\n[3]Display List2 ");
            printf("\n[4]Concatanate List");
            printf("\n[5]Sort Both of the list");
            printf("\n[6]Exit ");

            printf("\nEnter your choice  : ");
            scanf("%d" , &ch);
            switch (ch)
            {
            case 1: 
                    createNode:
                    if(flag == 0){
                        printf("\nEnter the value of N for the first Linked List : ");
                        scanf("%d" , &n);

                        start1 = createList(start1 ,  n);
                        flag = 1;
                    }
                    else if(flag ==1)
                    {
                        printf("\nEnter the value of N for second linked list  : ");
                        scanf("%d" , &n);
                        start2 = createList(start2 ,  n);
                    }
                    else{
                        printf("\nList Already Created !!! creating new one !!");
                        flag = 0;
                        goto createNode;
                    }
                break;
            case 2: //check if any link is present or not
                    if(NULL == start1){
                        printf("\nNO List found to be displayed !!!");
                        break;
                    }
                    display(start1);
                break;
            case 3: if(NULL == start2)
                    {
                        printf("\nNo list found to display!!!");
                        break;
                    }
                    display(start2);
                break;
            case 4: //conctanate lists
                    //check if both lists has data 
                    if(start1 != NULL && start2 != NULL){
                        concatnate(start1 , start2);
                    }
                    else{
                        printf("\nNot Enough lists to conctatnate!!!\n");
                    }
                    break;
            case 5: 
                    if(start1 != NULL  && start2 !=NULL){
                        sortList(start1);
                        sortList(start2);
                        printf("List Sorted Successfully!!!!");
                    }
                    else{
                        printf("\nMake Sure that both links have data to use this !!!!\n");
                    }
                    break;

            case 6: //exit program
                    break;
            default:
                    printf("\nEntered Option is not a valid one !!!\n");
                break;
            }
   }while(ch != 6);

   printf("\n-----THANK YOU VISIT AGAIN-------\n");
    return 0;
}
