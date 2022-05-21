//wap to implement static quene and  write its functions 
#include<stdio.h>
#include<stdlib.h>
#define SIZE 11

typedef struct staticCircular{
    int data[SIZE];
    int front;
    int rare;
}c_quene;

// INIT FUNCTION HERE 
void Init(c_quene *q)
{
    q->rare = q->front = SIZE-1;        //pyt both of the elements at the end of quene 
}

int isFull(c_quene *q)
{
    return ((q->rare+1)%SIZE == q->front);
}

int isEmpty(c_quene *q)
{
    return (q->front == q->rare);
}

void enquene(c_quene *q , int val)
{
    q->rare = (q->rare + 1)%SIZE;
    q->data[q->rare] = val;
}

int dequene(c_quene *q)
{
    q->data[q->front] = 0;
    q->front = (q->front  + 1)%SIZE;
    return q->data[q->front];
}

void display(c_quene *q)
{
    int temp = q->front;
    do{
        temp = (temp+1)%SIZE;
        printf(" %2d " ,q->data[temp]);
    }while(temp != q->rare);
}

int main(int argc, char const *argv[])
{
    int ch , val;
    c_quene q;
    //intilaize the quene 
    Init(&q);

    printf("\n---CIRCULAR QUENE----\n");    
    do{
        printf("\n--MENU---\n");
        printf("\n[1]Add Data");
        printf("\n[2]Remove Data");
        printf("\n[3]Display Data");
        printf("\n[4]Exit");

        printf("\nEnter your choice : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:
            //Enquene 
            if(!isFull(&q))
            {
                printf("\nEnter data for node  : ");
                scanf("%d" , &val);
                enquene(&q , val);
            }
            break;
        case 2:
            //Dequene
            if(!isEmpty(&q))
            {
                val = dequene(&q);
                printf("\n%d Removed from the quene " , val);
            }
            else{
                printf("\nQuene is empty !!!");
            }
            break;

        case 3:
            //display quene
            if(!isEmpty(&q))
            {
                display(&q);
            }
            else{
                printf("\nQuene is empty !!!");
            } 
            break;
        
        case 4:
            //exit
            
            break;
        default:
            printf("\nEnter a valid choice  !!!");
            break;
        }
    }while(ch!=4);

    printf("\n---THANK YOU USE AGIAN----\n");
    return 0;
}
