//wap to accept and display n number of data using linked list , accept another n+1 data and insert this data on the given position

#include<stdio.h>
#include<stdlib.h>

// STRUCTURE HERE
typedef struct insertionMiddle{
    int data;
    struct insertionMiddle *next;
}list;

list *start = NULL;         //ASSIGN the beggining of the node  = NULL 
 
// ACCEPT FUNCTION HERE !!!!

void accept(list *temp , int n){

    list *newnode;
    int i;
    for(i=0 ; i<n ;++i){
        newnode = (list*)malloc(sizeof(list));
        newnode->next = NULL;

        // accept data
        scanf("%d" , &newnode->data);

        if(start == NULL)
        {
            start = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
}

// display function here 
void display(list *temp){
    for(temp = start ; temp!=NULL ; temp = temp->next)
    {
        printf("%3d" , temp->data);
    }
}

void InsertMiddle(list *temp , int pos){
    int i=0;
    list *newnode;
    newnode = (list *)malloc(sizeof(list));
    
    temp = start;
    while(i<pos && temp !=NULL){
        temp = temp->next;
        ++i;
    }

    //accept the data
    printf("\nEnter new data : ");
    scanf("%d" , &newnode->data);
    newnode->next =temp->next;
    temp->next = newnode;
}

//MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    list *temp;
    int n , pos;

    //assign memory to temp
    temp = (list *)malloc(sizeof(list));

    printf("\n-------INSERT DATA IN MIDDLE-------\n");
    printf("\nEnter  value of n : ");
    scanf("%d" , &n);

    //accept data 
    printf("\nEnter %d elements  : " , n);
    accept(temp ,n);
    display(temp);

    printf("\nEnter the place you want to put new eleemnt : ");
    scanf("%d" ,&pos);
    if(pos>n){
        printf("Given Position exceeds the origninal link!!!");
        return 1;
    }

    InsertMiddle(temp , pos);

    //display the data
    display(temp);
    printf("\n--------THANK YOU USE AGAIN --------\n");
    return 0;
}
