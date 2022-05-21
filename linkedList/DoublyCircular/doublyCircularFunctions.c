//create function here
node *createList(node *start  , int n)
{
    node *temp;
    node *newnode;
    int i;

    for(i=0 ;i<n ;++i)
    {
        newnode  =(node*)malloc(sizeof(node));
    
        printf("\nEnter data to be entered  for %d Node  : " , i+1);
        scanf("%d" , &newnode->data);

        if(NULL == start)
        {
            temp = start = newnode;
            start->prev = start;
        }
        else{
            temp->next = newnode;
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

// REVERSE FUNCTION HERE 
void displayRev(node *start)
{
    node *temp;
    temp = start->prev;
    do{
        printf("%3d" , temp->data);
        temp = temp->prev;
    }while(temp != start->prev);
}

// INSERTION FUNCTION HERE 
node *Insert(node *start  , int pos , int *n)
{
    node *newnode;
    node *temp , *traverseTemp;
    int flag = 0 , i;

    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter data for new node  : ");
    scanf("%d" , &newnode->data);

    if(pos == 1)
    {
        newnode->next = start;
        newnode->prev = start->prev;
        start->prev->next = newnode;
        start->prev = newnode;
        start = newnode;
        flag = 1;
    }
    else if(pos == *n)
    {
        temp = start->prev;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = start;
        start->prev = newnode;
    }
    else{
        for(i=0 ,traverseTemp = start; i<pos-2 ;++i , traverseTemp = traverseTemp->next);
        temp = traverseTemp->next;
        traverseTemp->next = newnode;
        temp->prev = newnode;
        newnode->next = temp;
        newnode->prev = traverseTemp;   
    }

    if(flag)
    {
        printf("\nNode Inserted Successfully !!!");
        *n++;
    }

    return start;
}

//DELETE NODE BY POSITION FUNCTION HERE 
node *delteNode(node *start , int pos , int *n)
{
    node *temp ,*traverseTemp;
    int flag = 0 , i;

    if(pos == 1)
    {
        if(NULL == start->next)
        {
            printf("\nOnly One Node found !!!");
            temp = start;
            start == NULL;
            flag =1;
        }
        else{
            temp = start;
            start = start->next;
            temp->prev->next = start;
            start->prev = temp->prev;
            flag = 1;
        }
    }
    else if(pos == *n)
    {
        temp = start->prev;
        temp->prev->next = start;
        start->prev = temp->prev;
        flag = 1;
    }
    else{
        for(i=0 ,  traverseTemp = start ;i<pos-2 ;traverseTemp = traverseTemp->next ,++i);
        temp = traverseTemp->next;
        temp->prev = traverseTemp;
        traverseTemp->next = temp->next;
        flag = 1;
    }

    //check if node was deleted
    if(flag)
    {
        printf("\nNode Delted Successfully !!!");
        *n--;
        free(temp);
    }
    else{
        printf("\nSomething went wrong");
    }
    return start;
}


// DELETE A NODE BY VALUE FUNCTION HERE 
node *deleteByValue(node *start , int val , int *n)
{
    node *temp , *traverseTemp;
    int flag = 0 , i;
    if(start->data == val)
    {
        if(start->next == NULL)
        {
            temp = start;
            start = NULL;
            flag = 1;
        }
        else{
            temp = start;
            start = start->next;
            start->prev = temp->prev;
            temp->prev->next = start;
            flag = 1;
        }
    }
    else{
        traverseTemp = start;
        do{
            if(traverseTemp->data == val)
            {
                temp = traverseTemp->prev;
                temp->next = traverseTemp->next;
                traverseTemp->next->prev =temp;
                temp = traverseTemp;
                flag = 1; 
            }
            traverseTemp = traverseTemp->next;
        }while(traverseTemp!=start);
    }

    //IF NODE IS DELTED
    if(flag)
    {
        printf("\nNode Deleted Successfully!!!");
        *n--;
        free(temp);
    }
    else{
        printf("\nGiven Node is not present inside the list!!!");
    }
    return start;
}

//append node at the end function here 
node *append(node *start)
{
    node *temp ,*newnode;
    temp = start;
    
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the value to be appended  : ");
    scanf("%d" , &newnode->data);

    do{
        temp = temp->next;
    }while(temp->next != start);
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = start;
    start->prev = newnode;
    
    return start;
}