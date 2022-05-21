//wap to implement quene dynamically and write its functions as per need 
#include<stdio.h>
#include<stdlib.h>

typedef struct dynamicQuene{
    int data;
    struct dynamicQuene *next;
}Quene;

Quene *front  ,*rare;

// INIT FUNCTION HERE 
void Init()
{
    front = rare = NULL;
}

int isEmpty()
{
    return(front == rare);
}

void enquene()
{
    Quene *newnode;
    //allocate memeory for newnode 
    newnode = (Quene*)malloc(sizeof(Quene));

    //accept data for new node
    printf("\nEnter data for quene  : ");
    scanf("%d" , &newnode->data);

    if(rare == NULL)
    {
        front = rare = newnode;
    }
    else{
        rare->next = newnode;
        rare = newnode;
    }
}

int denquene()
{
    Quene *temp;
    int val;
    val = front->data;
    temp  = front;
    front = front->next;

    //free the memory occupied by old node
    free(temp);
    return val;

}

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    //init quene before anything
    Init();

    int ch , val;
    printf("\n---DYNAMIC QUENE-----\n");
    do{
        printf("\n---MENU---\n");
        printf("\n[1]Insert in quene ");
        printf("\n[2]Remove the top element");
        printf("\n[3]Display Quene");
        printf("\n[4]Exit");

        printf("\nEnter your choice : ");
        scanf("%d" , &ch);

        switch(ch)
        {
            case 1:
                //enquene
                enquene();
                break;
            case 2:
                if(isEmpty())
                {
                    printf("\nQuene is currrenly empty !!!");
                    break;
                }
                //denquene
                val = denquene();
                printf("\nElement %d removed from quene  !!" ,val);
                break;
            case 3:
                //dsiplay 
                break;
            case 4:
                    //exit 
                break;
            default:
                printf("\nEnter a valid choice !!");
                break;
        }
    }while(ch!=4);

    printf("\n---THANKYOU USE AGAIN----\n");
    return 0;
}
