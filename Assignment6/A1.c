//wap to implement quene in c and its function 
#include<stdio.h>
#define SIZE 10

typedef struct Quene
{
    int data[SIZE];
    int front , rare;
}node;


//FUNCTION FOR INTIATING STACK 
void Init(node *q){
    q->front = q->rare = -1;
}

int IsFull(node *q){
    return (q->rare == SIZE-1);
}

int IsEmpty(node *q){
    return (q->front == q->rare);
}

//INSERION AND DELETION FUNCTION FOR QUENE 
void Enquene(node *q , int data){

    q->rare++;
    q->data[q->rare] = data;
}

int Denequene(node *q ){

    q->front++;
    return q->data[q->front];
}

//DISPLAY FUNCTION HERE 
void Display(node *q){

    int i;
    for(i=q->front +1 ; i<=q->rare ; ++i){
        printf("%3d" , q->data[i]);
    }
}

int main(int argc, char const *argv[])
{
    int ch , data;
    node q;
    Init(&q);
    char op;
    printf("\n--STATIC QUENE----\n");
    //display menu and start the program
    do{
        printf("\n--MENU---\n");
        printf("\n[1]Insert\n");
        printf("\n[2]Delete\n");
        printf("\n[3]Display\n");
        printf("\n[4]Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d" ,&ch);

        switch (ch)
        {
            case 1:
                ///Insert
                if(IsFull(&q)){
                    printf("\nThe quene is full!!");
                    break;
                }
                printf("\nEnter a number to be insrted : ");
                scanf("%d" , &data);
                Enquene(&q , data);
                break;
            case 2:
                //delete
                if(IsEmpty(&q)){
                    printf("\nThe Quene is empty !!");
                    break;
                }
                data  = Denequene(&q);
                printf("\n%d Was removed from the quene\n" , data);
                break;
            case 3:
                //dispplay
                if(IsEmpty(&q)){
                    printf("\nThe Qunee is empty nothing to display");
                    break;
                }
                Display(&q);
                break;
            case 4:
                    //exit
                break;
        default:
                printf("\nEnter a valid choice");
            break;
        }
    }while(ch  != 4);
    printf("\n----THANKYOU USE AGIAN----\n");
    return 0;
}
