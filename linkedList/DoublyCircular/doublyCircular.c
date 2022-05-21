//wap to create and display a doubly circular linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct doublyCircular
{
    struct doublyCircular *prev;
    int data;
    struct doublyCircular *next;
}node;

int n;

//CREATE LIST FUNCCTION HERE 
node *createList(node *start , int  n)
{
    node *temp;
    node *newnode;
    int i;

    for(i=0; i<n ;i++)
    {
        newnode = (node*)malloc(sizeof(node));      //allocate memory for node
        
        printf("\nEnter element for node %d : " , i+1);
        scanf("%d" , &newnode->data);

        if(NULL == start)
        {
            start = temp = newnode;
        }
        else{
            temp->next =newnode;
            newnode->prev = temp;
            newnode->next = start;
            start->prev = newnode;
            temp = newnode;
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
        temp = temp->next;
    }while(temp != start);
}

// REVERSE DISPLAY FUNCTION HERE 
void displayrev(node *start)
{
    node *temp;
    temp = start->prev;

    do{
        printf("%3d" , temp->data);
        temp = temp->prev;
    }while(temp != start->prev);
}
// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    node *start = NULL;
    int ch;

    printf("\n-----Doubly Linked List----\n");
    do{
        printf("\n----MENU-----\n");
        printf("\n[1]Create List");
        printf("\n[2]Display List");
        printf("\n[3]Display List reverse");
        printf("\n[4]Exit");

        printf("\nEnter your choice  : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:     //create List
            printf("\nEnter value for n : ");
            scanf("%d" , &n);

            start = createList(start , n);

            break;
        
        case 2:     //Display List
            if(NULL == start)
            {
                printf("\nNo lIst found to display !!!");
                break;
            }     

            printf("\nEntered elements are  : ");
            display(start);

            break;
        case 3:     //Display List In reverese 
            if(NULL == start)
            {
                printf("\nNo lIst found to display !!!");
                break;
            }
            
            printf("\nThe reverse list is  : ");
            displayrev(start);
            break;
        
        case 4:     //Exit
            /* code */
            break;
        

        default:
            printf("\nEnter a valid option !!");
            break;
        }
    }while(ch != 4);

    printf("\n----THANK YOU USE AGIAN------\n");

    return 0;
}
