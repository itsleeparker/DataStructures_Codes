#include<stdio.h>
#include<stdlib.h>

typedef struct Quene
{
    int data;
    struct Quene *next;
    
}node;

node *rare , *front;

void Init(node *q){
    rare = front = NULL;
}

//IS EMPTY FUNCTION 
int Isempty(node *q){
    return front == rare;
}

//INSERTION AND DELETION FUNCTION 
void Enquene(node *q , int data){

    node  *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    //place the node accordingly
    if(rare == NULL){
        front = rare = newnode;
    }
    else{
        rare->next = newnode;
        rare  = newnode;
    }
}

int Dequene(node *q){
    node *temp;
    int  data;
    temp = front;
    data = temp->data;
    front = temp->next;
    free(temp);
    return data;
}

void Display(node *q){
    node *temp;
    temp = front;
    do{
        printf("%3d" , temp->data);
        temp = temp->next;
    }while(temp!=NULL);
}

int main(int argc, char const *argv[])
{
    int ch , data;
    node *q;
    Init(q);
    //dstart the progeam here 
    printf("\n----DYNAMIC QUENE---\n");
    do{
        printf("\n[1]Insert");
        printf("\n[2]Delete");
        printf("\n[3]Display");
        printf("\n[4]Exit");

        //take users choice 
        printf("\nEnter your choice  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
            case 1:
                    //insert
                    printf("\nEnter data for node  : ");
                    scanf("%d" , &data);                    
                break;
            case 2:
                 //Delete
                if(Isempty(q)){
                    printf("\nThe quene is empty");
                    break;
                }
                data = Dequene(q);
                printf("\n%d was removed from the quene ", data);
                break;
            case 3:
                    //display
                if(Isempty(q)){
                    printf("\nThe quene is empty");
                    break;
                }   
                    Display(q);
                break;
            case 4:
                    //Exit
                break;
        default:
            printf("\nEnter a valid choice \n");
            break;
        }
    }while(ch!=4);
    printf("\n----THANKNYOU USE AGAIN----\n"); 
    return 0;
}
