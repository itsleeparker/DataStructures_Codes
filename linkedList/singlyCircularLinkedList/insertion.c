//wap to insert a node in a singly circular linked list
#include<stdio.h>
#include<stdlib.h>

typedef  struct LinkedList
{
    int data;
    struct LinkedList *next;
}node;

int n;
node *rare;

// CREATE FUNCTION HERE 
node *createList(node *start , int n)
{
    node *newnode  , *temp;
    int i;
    for(i=0 ; i<n ; ++i)
    {
        newnode =(node*)malloc(sizeof(node));

        printf("\nEnter data for node %d : " , i+1);
        scanf("%d" , &newnode->data);

        if(NULL == start)
        {
            start = rare =temp = newnode;
            rare->next = start;
        } 
        else{
            temp->next = newnode;
            rare = newnode;
            rare->next = start;
            temp  = newnode;
        }
    }
    return start;
}

// DISPLAY FUNCTION HERE 

void display(node *start)
{  
    node *temp;
    temp = start;
    
    do{
        printf("%3d" , temp->data);
        temp= temp->next;
    }while(temp != start);
}

// INSERT FUNCTION HERE 
node *Insert(node *start , int pos)
{
    int i;
    node *temp , *traverseTemp;
    node *newnode;
    newnode = (node*)malloc(sizeof(node));      ///allocate memory for new node

    printf("\nEnter data for new node  : ");
    scanf("%d" , &newnode->data);
    //insert the node
    if(pos == 1)
    {
        newnode->next = start;
        rare->next = newnode;
        start = newnode;
    }
    else if(pos == n)
    {
        rare->next = newnode;
        newnode->next = start;
        rare = newnode;
    }
    else{
        for(i=0  , traverseTemp = start ;i<pos-2 ; traverseTemp=traverseTemp->next ,++i);
                
        temp = traverseTemp->next;
        traverseTemp->next = newnode;
        newnode->next = temp;
    }
    return start;
}
// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    node *start = NULL;
    int ch , op , pos;

    printf("\n----Insertion In Singley Circular Linked List-----\n");

    do{
        printf("\n---MENU----\n");
        printf("\n[1]Create List");
        printf("\n[2]Display List");
        printf("\n[3]Insert Node");
        printf("\n[4]Exit ");

        printf("\nEnter your choice  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1: //create list
            printf("\nEnter value for n : ");
            scanf("%d" , &n);

            start = createList(start , n);
            break;
        case 2: //display List
             if(NULL == start)
             {
                 printf("\nNO List Found to Diplay !!!");
                 break;
             }
             display(start);
            break;
        case 3:     //insert node
             if(NULL == start)
             {
                 printf("\nNO List Found to Diplay !!!");
                 break;
             }
             printf("\n--INSERT NODE---\n");
             printf("\n[1]Insert Node at the beggining ");
             printf("\n[2]Insert Node at the  Middle");
             printf("\n[3]Insert Node at the End");

             printf("\nEnter your choice  : " );
             scanf("%d" , &op);
             switch (op)
             {
             case 1:
                start = Insert(start , 1);
                break;
             case 2:
                printf("\nEnter position to Insert Node at : ");
                scanf("%d" , &pos);
                start = Insert(start ,pos);
                break;
            case 3:         //insert node at the end
                start = Insert(start , n);
                break;
             default:
                 break;
             }
            break;
        case 4:     //exit 
            /* code */
            break;
        default:
            break;
        }
    }while(ch != 4);
    return 0;
}
