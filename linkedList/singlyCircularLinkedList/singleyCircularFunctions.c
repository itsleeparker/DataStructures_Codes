#include"singleyCircularStructure.h"
node *rare;
node *createList(node *start , int n)
{
    node *temp;
    node *newnode;
    int i;

    for(i=0;i<n;++i)
    {
        newnode = (node*)malloc(sizeof(node));
        
        printf("\nEnter data for node %d : " , i+1);
        scanf("%d" , &newnode->data);

        if(NULL == start){
            start = temp = newnode;
            newnode->next = start;
        }
        else{
            temp->next = newnode;
            newnode->next = start;
            temp = newnode;
        }
    }
    rare = temp;
    return start;
}

void display(node *start)
{
    node *temp;
    temp = start;
    do{ 
        printf("%3d" , temp->data);
        temp = temp->next;
    }while(temp != start);
}

node *deleteNodePos(node *start , int pos , int *n)
{
    node *temp , *traverseTemp;
    int flag=0 , i;

    if(pos == 1)
    {
        if(start->next == NULL)
        {
            printf("\nOnly One Node Found !!!");
            temp = start;
            start =  NULL;
        }

        else{
            temp = start;
            start = start->next;
            rare->next = start;        
        }
        flag =1;
    }

    else if(pos == *n)
    {
        for(traverseTemp = start ; traverseTemp->next != rare ; traverseTemp = traverseTemp->next);
        temp = rare;
        traverseTemp->next = start;
        rare = traverseTemp;
        flag = 1;
    }
    else{
        for(traverseTemp = start  , i =0 ; i<pos-2 ;traverseTemp = traverseTemp->next , ++i);
        temp = traverseTemp->next;
        traverseTemp->next = temp->next;
        flag = 1;
    }

    if(flag)
    {
        printf("\nNode Deleted Successfully !!!");
        free(temp);
        *n--;
    }
    else{
        printf("\nSomething Went wrong!!!");
    }
    return start;
}

node *deleteByVal(node *start , int val , int *n)
{
    int flag = 0;
    node *temp , *traverseTemp =start;

    //check if value is at the beggining of the node
    if(start->data == val)
    {   
        
        if(start->next == NULL)
        {
            printf("\nOnly One node found !!! Deleting the node \n");
            temp = start;
        }
        else{
            temp  = start;
            start = start->next;
            rare->next = start;
        }
        flag = 1;
    }
    else{
        do{
            temp = traverseTemp->next;
            
            if(temp->data == val)
            {
                traverseTemp->next = temp->next;
                if(temp == rare)
                {
                    rare = traverseTemp;
                    rare->next = start;
                }
                flag = 1;
                break;
            }
            
            traverseTemp = traverseTemp->next;
        }while(traverseTemp!=start);
    }

    if(flag)
    {
        printf("\nNode Delted successfully!!!");
        free(temp);
        *n--;
    }
    else{
        printf("\nNo Node found with value %d!!\n" , val);
    }
    return start;
}

int search(node *start , int val)
{
    node *temp;
    int i = 0;
    do{
        i++;
        if(temp->data == val)
        {
            return i;
        }
        temp = temp->next;
    }while(temp != start);
    return -1;
}

int length(node *start)
{
    int count;
    node *temp;
    do{
        count++;
        temp = temp->next;
    }while(temp!=start);

    return count;
}