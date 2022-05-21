//wap to implement quene in C program write functions of quene such as enque dequene  , isfull \\
is empty etc
#include<stdio.h>
#define SIZE 10

typedef struct staticQuene{
    int data[SIZE];
    int front , rare;
}quene;

// INTI FUNCTION HERE 
void Init(quene *q)
{
    q->front=q->rare = -1;
}

int isEmpty(quene *q)
{
    return (q->rare == q->front);
}

int isFull(quene *q)
{
    return (q->rare == SIZE-1);
}

void enquene(quene *q , int val)
{
    q->rare++;
    q->data[q->rare] = val;
}

int dequene(quene *q )
{
    q->front++;
    return q->data[q->front];
}

void display(quene *q)
{
    int i;
    for(i = q->front +1 ;i<=q->rare ; ++i)
    {
        printf(" %2d " , q->data[i]);
    }
}

// MAIN FUNCTION HERE
int main(int argc, char const *argv[])
{
    quene q;
    int ch ,val;
    Init(&q);       //intiate quene before start 

    printf("\n---STATIC QUENE---\n");   

    do{
        printf("\n---MENU--\n");
        //display menu and carry out the task accordingly
        printf("\n[1]Insert in quene \n");
        printf("\n[2]Pop From quene \n");
        printf("\n[3]Display Quene \n");
        printf("\n[4]Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:
            //enquene
            if(isFull(&q))
            {
                printf("\nThe stack is full !! remove something");
                break;
            }
            printf("\nEnter element to be inserted  : ");
            scanf("%d" , &val);
            enquene(&q , val);

            break;
        case 2:
            if(isEmpty(&q))
            {
                printf("\nThe quene is empty !!! Insert something first !!");
                break;
            }
            val = dequene(&q);
            printf("\nThe %d element removed from quene  ! " , val);
            break;    
        case 3 :
            //display function 
            if(isEmpty(&q))
            {
                printf("\nThe quene is empty !!! Insert something first !!");
                break;
            }
            printf("\nThe data inside stack is  : ");
            display(&q);
            break;
        case 4:
            //exit
            break;
        default:
            printf("\nEnter a valid choice !!!");
            break;
        }
    }while(ch!=4);
    printf("\n-----------Thank You Use Agian-------\n");
    return 0;
}
