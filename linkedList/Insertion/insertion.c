//wap to create a link list of n number , use menu to accept type of insertion of data and display it

#include<stdio.h>
#include<stdlib.h>

typedef struct nodelist{
    int data;
    struct nodelist *next;
}node;

node *start = NULL;
int n;

///////////////////////
// ACCEPT FUNCTION HERE
/////////////////////// 
node *accept(node *temp)
{
    node *newnode;
    int i;

    //accept data
    for(i=0;i<n;++i)
    {
        newnode = (node*)malloc(sizeof(node));
        newnode->next =NULL;

        printf("Enter data  %d : " , i+1);
        scanf("%d" , &newnode->data);

        if(NULL == start)
        {
            start = temp  =newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
}

////////////////////////
// DISPLAY FUNCTION HERE 
////////////////////////

node *display(node *temp){
    for(temp=start ; temp != NULL; temp=temp->next)
       {
           printf("%3d" , temp->data);
       } 
    
}
///////////////////////////////
// INSERTION DATA FUNCTION HERE
///////////////////////////////
node *insert(node *temp , int pos)
{
    int i;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->next =NULL;
    printf("\nEnte new data : ");
    scanf("%d" , &newnode->data);

    
    if(pos == 1){   
        newnode->next = start;
        start = newnode;
    }
    else if(pos == n-1){
        for(temp=start;temp->next != NULL;temp = temp->next);        
        temp->next = newnode;
    }
    else{
        //traverse at the position 
        for(i=1 ,temp=start ;i<pos-1; ++i , temp = temp->next);   
        newnode->next = temp->next;
        temp->next = newnode;        
    }

    n++;
}

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    node *temp = (node*)malloc(sizeof(node));
    temp->next =NULL;
    int pos , op  , ch;

    do{
        printf("\n----LINK LIST-------\n");
        printf("\n------MENU-----\n");
        printf("\n[1]Enter data ");
        printf("\n[2]Display Data");
        printf("\n[3]Insert Data");
        printf("\n[4]Exit");
    
        printf("\nEnter your choice : ");
        scanf("%d" , &op);
            switch (op)
            {
                case 1: /*accept data*/
                        printf("\nHow many values you need to insert : ");
                        scanf("%d" , &n);
                        accept(temp);
                        break;
                case 2: //display data
                        if(NULL == start){
                            printf("NO data found to display!!!");
                            break;
                        }
                        printf("\nEntered data is : ");
                        display(temp);
                        break;
                case 3://insert data;
                        if(NULL == start){
                            printf("\nNO list found to insert data !!!!");
                            break;
                        }
                            
                            printf("\n      Insertion Menu    \n");
                            printf("\n[1]Beginning");
                            printf("\n[2]End");
                            printf("\n[3]Middle");

                            printf("\nEnter your choice : ");
                            scanf("%d",&ch);
                            switch (ch)
                            {
                            case 1: /* insertion in beggining */
                                insert(temp , 1);
                                break;
                            case 2: //Insertion End
                                insert(temp , n-1);
                                break;
                            case 3:
                                printf("\nEnter the position where you wanna insert data : ");
                                scanf("%d" , &pos);
                                if(pos>n)
                                {
                                    printf("\nError !!!!: Given position exceeds given links!!!");
                                    break;
                                }
                                insert(temp , pos);
                                break;
                            default:
                                    printf("\nEnter a valid option only !!!\n");
                                break;
                            }

                        break;
                default:
                    printf("\nEntered option is invalid !!!");
                    break;
            }
        }while(op!=4);
    
    printf("\n----THANK YOU USE AGIAN-------\n");    
    return 0;
}
