//wap to delete a node from a doubly linked list
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct NodeList
{
    struct NodeList *prev;
    int data;
    struct NodeList *next;  
}node;

//GLOBAL VARIABLES HERE 
int n;

// CREATE LIST FUNCTION HERE 
node *createList(node *start ){

    node *newnode   , *temp;
    int i;

    printf("\nEnter %d elements  : " , n);
    for(i=0;i<n;++i){
        newnode = (node*)malloc(sizeof(node));
        newnode->prev= NULL;
        newnode->next= NULL;

        printf("\nEnter data for %d Node : " , i+1);
        scanf("%d" , &newnode->data);

        if(NULL == start){
            start = temp = newnode;
        }
        else{
            temp->next =newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    return start;
}

// DISPLAY FUNCTION HERE 
void display(node *start)
{
    
    node *temp;

    for(temp = start ; temp != NULL ; temp =  temp->next)
    {
        printf("%3d" , temp->data);
    }
}

//DISPLAY REVERSE FUNCTION HERE
void revDisplay(node *start){
   node *temp;
   for(temp = start ; temp->next != NULL ; temp = temp->next);

   //reverse the list
   for(;temp!=NULL; temp =  temp->prev){
       printf("%3d" , temp->data);
   } 
}

// DELETE NDOE FUNCTION HERE 
node *deleteNode(node *start , int pos)
{
    node *temp;
    int flag =0 , i;

    if(pos  == 1){
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
        flag = 1;
    }
    else if(pos == n-1)
    {
        for(temp = start ; temp->next != NULL ; temp = temp->next);
        temp->prev->next = temp->next;
        free(temp);
    }
    else{
        for(i=0 , temp = start ; i<pos -1 ; temp = temp->next  , ++i);

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

    //check if any node is deleted or not
    if(flag != 0)
    {
        printf("\nNode Deleted Successfully !!!");
        n--;
    }
    return start;
}
// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    node *start = NULL;
    int ch , op , pos;

    printf("\n----DELETE NODE------\n");
    do{
        printf("\n----MENU----\n");
        printf("\n[1]Create List\n");
        printf("\n[2]Display List\n");
        printf("\n[3]DeletNode\n");
        printf("\n[4]Display reverse\n");
        printf("\n[5]Exit");

        printf("\nEnter your choice  :  ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case  1:    //CREATE LIST FUNCTION HERE 
                printf("\nEnter value of n : ");
                scanf("%d" , &n);
                start = createList(start);
                break;
        case 2: //Display List
                if(NULL == start){
                    printf("\nNo List found to display !!!");
                    break;
                }
                printf("\nEntered List is  : \n");
                display(start);
                break;

        case 3: //Delete Node 
                if(NULL == start){
                    printf("\nNo list found to delete node from \n");
                    break;
                }
                else if(n == 1){
                    printf("\n--Only One Node Found !!! Deleting Node--\n");
                    start = NULL;
                    break;
                }
                printf("\n[1]Delete Node from the first position");
                printf("\n[2]Delete Node from Middle");
                printf("\n[3]Delete Node from End");

                printf("\nEnter your choice  :");
                scanf("%d" , &op);
                
                switch (op)
                {
                case 1: //DELETE FIRST NODE
                    start = deleteNode(start , 1);
                    break;
                
                case 2: //DELETE NODE FROM MIDDLE
                        printf("\nEnter position to delete the node from :  ");
                        scanf("%d" , &pos);
                        if(pos > n){
                            printf("\nGiven Position not found in list !!!");
                            break;
                        }
                        start = deleteNode(start , pos);
                        break;
                
                case 3: //DELETE NODE FROM THE END
                        start = deleteNode(start , n-1);
                        break;
                default:
                        printf("\nEnter Option from the given Menu only !!!\n");
                    break;
                }

                break;
        case 4: //reverse Display
                if(NULL == start){
                    printf("\nNo List found to reverse Display !!!");
                    break;
                }
                printf("\nReverse List is  : ");
                revDisplay(start);
                break;
        case 5: //exit
                break;
        default:
                printf("\nPlease enter option from the given menu only !!!");
            break;
        }

    }while(ch != 5);

    printf("\n----THANK YOU USE AGAIN------\n");
    return 0;
}
