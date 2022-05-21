//wap to accept and display a linked list  , and insert a newnode at the beginning of list

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

//STRUCTURE DECLARATION
typedef struct linkedlist{
    int data;
    struct linkedlist *next;
}list;

list *start = NULL;

//MAIN FUNTION HERE 
int main(int argc, char const *argv[])
{
    list *accept(list * ,int );
    void display(list *);
    void insertData(list *);

    list *temp;
    temp = (list *)malloc(sizeof(list));
    int n;

    printf("\n-----INSERTION LINKED LIST---------\n");
    printf("\nEnter number of items  : ");
    scanf("%d" , &n);
    accept(temp , n);
    printf("\nEntered Data is : ");
    display(temp);
    insertData(temp);
    printf("\nNew Data list is  : ");
    display(temp);
    printf("\n-------THANK YOU USE AGIAN---------\n");
    return 0;
}


list *accept(list *temp , int n)
{
    int i;
    list *newnode;
    for(i=0;i<n;++i)
    {
        newnode = (list*)malloc(sizeof(list));
        newnode->next = NULL;

        //ACCEPT DATA FROM USER
        printf("\nEnter data %d : " , i+1);
        scanf("%d" , &newnode->data);

        //check if the current node is the first node
        if(NULL == start)
        {
            start = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void display(list *temp){
    for(temp=start;temp!=NULL;temp = temp->next){
        printf("%3d" , temp->data);
    }
}

void insertData(list *curr){
    list *newnode;
    newnode = (list*)malloc(sizeof(list));
    newnode->next=start;
    start = newnode;
    //accept data
    printf("\nEnter new data :  ");
    scanf("%d" , &newnode->data);
}