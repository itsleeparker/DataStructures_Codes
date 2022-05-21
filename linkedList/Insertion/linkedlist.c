//wap to acceot value of n from the user and form N number of link list using structures

#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist
{
    int num;
    struct linkedlist *next;    
}list;

list *start =NULL ,*temp , *next;           //intialize the head as null

int main(int argc, char const *argv[])
{
    int n , i;
    //accept the number of n;
    printf("\nEnter value of n : ");
    scanf("%d" , &n);

    //accept value till the link list has ended 
    for(i=0;i<n;++i)
    {
        next = (list *)malloc(sizeof(list));
        next->next =NULL;
        //take data from user
        printf("\nEnter the data : ");
        scanf("%d" , &next->num);

        //check if the current node has a blank head or not
        if(NULL == start)
        {
            start=temp=next;
        }
        else{
            temp->next = next;
            temp = next;
        }
    }

    //display all the data in nodes
    printf("\nEntered data is  : ");
    for(temp = start ; temp != NULL ; temp = temp->next)
    {
        printf("%3d" ,temp->num);
    }

    printf("\n-----THANK YOU USE AGAIN ------------\n");
    return 0;
}
