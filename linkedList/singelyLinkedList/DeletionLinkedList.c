//write a menu driven program to create  and  display a linked list , user must be able to delete any node from the given list

#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;    
}node;

node *start = NULL;
int n;

////////////////////////////
// CREATE LIST FUNCTION HERE 
////////////////////////////

void createList(node *temp){
    node *newnode;
    int i;

    //make new linkList
    for(i=0;i<n;++i)
    {
        newnode = (node*)malloc(sizeof(node));
        newnode->next = NULL;

        printf("\nEnter data %d  : " , i+1);
        scanf("%d" , &newnode->data);

        //assign the postion 
        if(NULL == start){
            start = temp =newnode;
        }

        else{
            
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void display(node *temp){

    for(temp=start ; temp!=NULL ;temp = temp->next)
    {
        printf("%3d"  , temp->data);
    }
}

void delete(node *temp , int pos){
    int i;
    node *deletnode;
    temp = start;

    if(pos == 1){
        start  = temp->next;
        free(temp);
    }
    else if(pos == n){
        for(i=1 , temp=start ; i<pos-1; temp =temp->next , i++);        
        deletnode = temp->next;
        temp->next=NULL;
        free(deletnode);
    }
    else{
        //transverse through the list
        for(i=1  , temp=start ; i<pos-1; temp = temp->next  , i++);
        for(i=1 , deletnode=start ; i<pos ;deletnode = deletnode->next , i++);
        temp->next = deletnode->next;
        free(deletnode);    
        
    }
    
    //check if node is deleted or not
    if(deletnode != 0 ){
        printf("Error in removing the element\n");
        // exit(1);
    }
    --n;            //decrement of n in
}

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{ 
    node *temp;
    int  ch , op , pos;

    printf("\n-------LINKED LIST------\n");
   
    //DISPLAY THE MENU
    do{
        printf("\n----MENU-----\n");
        printf("\n[1]Create List");
        printf("\n[2]Display List");
        printf("\n[3]Delete a node ");
        printf("\n[4]Exit");

        printf("\nEnter a choice : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1: //CREATE LIST
                printf("\nEnter number of nodes you want to make : ");
                scanf("%d" , &n);
                createList(temp);
                break;
        case 2: //DISPLAY LIST
                if(NULL == start){
                    printf("\nNo List found to be displayed !!!!");
                    break;
                }
                display(temp);
                break;
        case 3: //DELETE A NODE
                if(NULL == start){
                    printf("\nNo List found to Delete node from !!!!");
                    break;
                }
                printf("\n----DELETION MENU----\n");
                printf("\n[1]Delete Node at the beggining ");
                printf("\n[2]Delete Node at the end ");
                printf("\n[3]Delete Node in the Middle ");

                printf("\nEnter your Choice : ");
                scanf("%d" , &op);
                switch (op)
                {
                
                case 1: //delet at the beginning 
                        delete(temp , 1);
                        break;
                case 2: //delete at the middle
                        delete(temp , n);
                        break;
                case 3://delete at the middle
                        printf("\nEnter the position of node : ");
                        scanf("%d" , &pos);
                        if(pos>n){
                            printf("\nError given position is not valid!!!");
                            break;
                        }
                        delete(temp , pos);
                        break;
                default:
                    printf("\nEnter a valid option only !!!!!");
                    break;
                }
                break;
        case 4: //exit the program;
                break;
        default:
                printf("\nInvalid option chosen try again !!!!");
            break;
        }
    }while(ch != 4);
    
    printf("\n------THANK YOU USE AGAIN -----\n");
    
    return 0;
}
