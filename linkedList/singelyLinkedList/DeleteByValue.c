//wap to create a linked list , and display it. write a function that accepts a value  and delete it from//the link list

#include<stdio.h>
#include<stdlib.h>

typedef struct DeleteByValue
{
    int data;
    struct DeleteByValue *next;
    
}node;

node *start = NULL;
int n;

////////////////////////////
// CREATE LIST FUNCTION HERE 
////////////////////////////

void createList(node *temp)
{

    int i;
    node *newnode;

    for(i=0;i<n;++i)
    {
        newnode = (node*)malloc(sizeof(node));
        newnode->next = NULL;

        //accept data 
        printf("\nEnter data %d : " , i+1);
        scanf("%d" , &newnode->data);

        //check if the current node is first node
        if( NULL == start)
        {
            start = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp  = newnode;
        }
    }
    
}

////////////////////////
// DIPSLAY FUNCTION HERE
////////////////////////

void display(node *temp){
    
    for(temp = start ; temp!=NULL; temp= temp->next)        //go through each node
    {
        printf("%3d" , temp->data);
    }
}

///////////////////////////////
//DELETE FUNCTION FUNCTION HERE
///////////////////////////////

void deleteData(node *temp , int val){
    int i = 0 , flag;
    node *temp ,*tarverseTemp;

    //check if the value is at the first node
    if(start->data == val){
        if(start->next!=NULL)       //checkf if the link has more nodes
        {
            temp = start;
            start = temp->next;
        }
        else{
         printf("\nOnly One Node found in List!");
         temp=start;
         start= NULL;   
        }
        flag =1;
    }
    //check if data is in middle or end
    else{
        for(tarverseTemp = start ; tarverseTemp->next != NULL ; tarverseTemp=tarverseTemp->next){

            if(tarverseTemp->next->data == val)
            {
                flag = 1;
                temp = tarverseTemp->next;
                tarverseTemp->next = temp->next;
                break;
            }
        }
    }


  //check if any data is deleted
  if(flag == 1)
  {
      free(temp);
      n--;
      printf("\nValue :%d Delted from list successfully !!!!" , val);
  }  
  else{
      printf("\nGiven Valyue %d was not found in the given Lisr" , val)
  }
}
///////////////////////
// MAIN FUNCTION HERE 
//////////////////////
int main(int argc, char const *argv[])
{
    int val  , ch ;
    node *temp;

    printf("\n-----DELETION USING VALUE------\n");
    do{
        printf("\n-------MENU-------\n");
        printf("\n[1]Create List");
        printf("\n[2]Dipslay List");
        printf("\n[3]Delete Value  ");
        printf("\n[4]Exit");

        printf("\nEnter your choice: ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1: //Create list
                printf("\nEnter value of n : ");
                scanf("%d" , &n);
                createList(temp);        //function call here
            break;
        case 2: //display list
                if(NULL == start){
                    printf("\nNo List to display !!!!");
                    break;
                }
                printf("\nEntered data is  : \n");
                display(temp);
                break;
        case 3: //Delete value
                if(NULL == start){
                    printf("\nNo link found to delete data !!!\n");
                    break;
                }
                printf("\nEnter the value you want to delete  : ");
                scanf("%d" , &val);
                deleteData(temp , val);
                break;
        case 4: //exit program;
                break;
        default:
            printf("\nEnter a valid option only !!!");
            break;
        }
    }while(ch != 4);
    printf("\n-----THANK YOU USE AGIAN-------\n");    
    return 0;
}
