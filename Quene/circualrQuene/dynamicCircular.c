//wap to implement circular quene dynamically and write its function accordingly
#include<stdio.h>
#include<stdlib.h>

typedef struct DynamicQuene{
    int data;
    struct DynamicQuene *next;      //in every case rare will be poiting at front 
}d_quene;

d_quene *rare;

void Init()
{   
    rare = NULL;
}

int isEmpty(){
    return  (rare == NULL);
}

void Enquen( int val){
    d_quene *newnode;
    newnode = (d_quene *)malloc(sizeof(d_quene));
    newnode->data = val;

    if(rare == NULL)
    {
        rare = newnode;
        newnode->next = rare;
    }
    else{
        newnode->next = rare->next;
        rare->next = newnode;
        rare = newnode;
    }
}

int Denquene(){
    int val;
    d_quene *temp;
    temp = rare->next;
    if(temp == rare)
    {
        printf("\nOnly one node remaining");
        rare = NULL;
        val = temp->data;
        free(temp);
    }    
    else{
        val = temp->data;
        rare->next = temp->next;
        free(temp);       
    }
    return val;
}

void Display(){
    d_quene  *temp;
    temp = rare;
    do{
        temp = temp->next;
        printf(" %2d " , temp->data);
    }while(temp != rare);
}

int main(int argc, char const *argv[])
{
    int ch , val;
    Init();
    printf("\n----DYNAMIC CIRCULAR QUENE-----\n");   
    do{
        printf("\n----MENU-----\n");
        printf("\n[1]Add Data");
        printf("\n[2]Remove Data");
        printf("\n[3]Display Data ");
        printf("\n[4]Exit");
        
        printf("\nEnter your choice : ");
        scanf("%d" , &ch);

        switch (ch)
        {
          case 1:
                //enquene data
                printf("\nEnter data :  ");
                scanf("%d" , &val);
                Enquen(val);
                if(isEmpty())
                {
                    printf("\nData entered successfully!!!");
                    exit(1);
                }
              break;

          case 2:
                //denque data from quene 
                if(!isEmpty())
                {
                    val = Denquene();
                    printf("\n %d Data removed from quene !!\n" , val);
                    break;
                }
                printf("\nNo data found to remove !!");
              break;

          case 3:
                if(!isEmpty())
                {
                    Display();
                    break;
                }
                printf("\nNo Data found in quene!!");
              break;
          case 4:
                //exit
              break;
        default:
            printf("\nEnter a valid choice !!!");
            break;
        }
    }while(ch != 4);
    printf("\n---THANKYOU USE AGIAN----\n");
    return 0;
}