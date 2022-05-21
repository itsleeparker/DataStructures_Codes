//wap to create n number of linked list , accept a new node and insert it at the end of the list
#include<stdio.h>
#include<stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedList *next;
}list;

list *start  = NULL;


//INSERTION FUNCTION HERE
void insertEnd(list *temp){

    list *newnode;
    newnode = (list *)malloc(sizeof(list));
    newnode->next = NULL;
    scanf("%d" , &newnode->data);

    //transverse to the end of list
    if(temp == NULL)
    {
        temp->next=newnode;
    }
    else{
        temp =start;
        while (temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next  = newnode;
    }    
}


//DISPLAY FUNCTION HERE!!!!
list *display(list *temp){
    //display all the elements
    for(temp  =start ;temp!=NULL ;temp = temp->next){
        printf("%3d" , temp->data);
    }
}


//ACCEPT FUNCTION HERE !!!!

list *accept(list *temp , int n){
    int i;
    list *newnode;
    //accept all the data 
    for(i=0;i<n;++i)
    {
        newnode = (list *)malloc(sizeof(list));     //allocate space to new node
        newnode->next =NULL;

        //accept data
        scanf("%d" , &newnode->data);

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

//MAIN FUNTION HERE
int main(int argc, char const *argv[])
{

    list *temp;
    int n;

    //ASSIGN SOME SPACE TO TEMP
    temp = (list*)malloc(sizeof(list));

    printf("\n-----LINKED LIST INSERTION AT THE END---------\n");
    printf("\nEnter number of data you need  : ");
    scanf("%d" , &n);

    printf("\nEnter %d numbers : " , n);
    accept(temp ,n);

    //display given data before insertion
    printf("\nEnter data is  : \n");
    display(temp);

    printf("\nEnter insertion data  : ");
    insertEnd(temp);
    display(temp);
    printf("\n-------THANK YOU USE AGIAN --------------------\n");
    return 0;
}

