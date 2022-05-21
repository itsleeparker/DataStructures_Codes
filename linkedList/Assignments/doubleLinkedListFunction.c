// INSERT NODE FUNCTION HERE 
node *Insertnode(node *start , int pos  , int *n){
    int flag = 1 , i;
    node *newnode , *temp;
    newnode = (node*)malloc(sizeof(newnode));
    newnode->next = NULL;
    newnode->prev =NULL;

    //TAKE DATA FROM USER 
    printf("\nEnter Data for newnode  : ");
    scanf("%d" , &newnode->data);

    if(pos == 1)
    {  
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
        flag = 0;
    }

    else if(pos == *n)
    {
        for(temp = start ;temp->next != NULL ; temp = temp->next);
        temp->next = newnode;
        newnode->prev = temp;
        flag = 0;
    }
    else{
        for(i=1, temp = start ;i<pos-1 ; i++,temp = temp->next);

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next=newnode;
        flag = 0;
    }

    if(flag == 0)
    {
        *n++;
    }
    return start;
}

int countNodesInList(node *start){
    int cnt;
    node *temp;
    
    //count the elements in list
    for(temp=start , cnt =0 ; temp != NULL ; temp = temp->next);

    return cnt;
}

node *createList(node *start , int n){
    node *temp , *newnode;
    int i;

        for(i=0;i<n;++i){
        newnode = (node*)malloc(sizeof(node));
        newnode->next = NULL;

        //TAKE DATA FROM USER 
        printf("Enter data %d : "  ,i+1);
        scanf("%d" ,&newnode->data);

        if(NULL == start){
            start = temp = newnode;
        }
        else{
            newnode->prev = temp;
            temp->next = newnode;
            temp = newnode;
        }
    }

    return start;
}

void display(node *start){
    node *temp;
    
    for(temp  = start ; temp != NULL ;temp=temp->next){
        
        printf("%3d" ,temp->data);
    }
}


// DISPLAY REVERSE LIST FUCNTION HERE 
void displayReverse(node *start)
{
    node *temp;
    for(temp=start ; temp->next != NULL ; temp = temp->next);
    
    for(; temp != NULL; temp = temp->prev)
    {
        printf("%3d" , temp->data);
    }
}

// SEARCH FUNCTION HERE 
void Search(node *start , int val)
{
    int flag= 0 , pos = 0;
    node *temp = start;
    
    //check if the node is at the beggining itself
    if(start->data == val)
    {
        flag = 1;
    }
    else{
        for(temp = start ;temp!=NULL ;temp= temp->next , ++pos)
        {
            //one can just put another pointer at the end of the list and start from both ways 
            if(temp->data == val)
            {
                flag = 1;
                break;
            }
        }
    }

    if(flag == 1)
    {
        printf("\nGiven Element found at position %d \n" , pos+1);
    }
    else{
        printf("\nGiven element was not to be found in list!!!");
    }

}

// CONCATNATE FUNCTION HERE 
void concat(node *start1 , node *start2)
{
    node *traverseTemp;
    for(traverseTemp = start1 ; traverseTemp->next != NULL ;traverseTemp = traverseTemp->next);
    traverseTemp->next = start2;
    start2->prev = traverseTemp;
}
