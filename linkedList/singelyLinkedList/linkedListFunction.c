
node *reverseList(node *start){
    node *currNode=NULL , *nextNode = NULL , *prevNode = NULL;
    currNode = nextNode = start;
    
    //transverse through the list
    while (nextNode != NULL)
    {
        nextNode = nextNode->next;          //assign the next node to the cuurent node
        currNode->next = prevNode;          //asssign current node next address to prev

        prevNode = currNode;          
        currNode = nextNode;
    }
    
    printf("\nList Reveresed Successfully\n");
    return prevNode;
}

node *merge(node *start1  , node *start2 , node *start3){
    node *newnode , *temp1  , *temp2 , *temp3;
    
    temp1 = start1;
    temp2 = start2;

    while(temp1 != NULL && temp2 != NULL){
        //allocate memeory for newnode
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;

        if(temp1->data > temp2->data){
            newnode->data = temp2->data;
            temp2 = temp2->next;
        }
        else{
            newnode->data = temp1->data;
            temp1 = temp1->next;
        }

        if(start3 == NULL){
            start3 = temp3 = newnode;
        }
        else{
            temp3->next = newnode;
            temp3 = newnode;
        }
    }

    //if one list is short then another
    if(temp1 != NULL){
        temp3->next = temp1;
    }
    else if(temp2 != NULL)
    {
        temp3->next = temp2;
    }
    return start3;
}

void sortList(node *start){
    node *temp , *traverseTemp;
    int og;
    for(temp = start ; temp!=NULL ; temp = temp->next){
        traverseTemp = temp;
        while(traverseTemp != NULL){
            if(temp->data>traverseTemp->data){
                og= temp->data;
                temp->data = traverseTemp->data;

                traverseTemp->data = og;     
            }
            traverseTemp = traverseTemp->next;
        }
    }
}


node *createList(node *start , int n){
    node *newnode , *temp;
    int  i;

    //create link list
    for(i=0;i<n;++i){
        newnode = (node*)malloc(sizeof(node));
        newnode->next =NULL;

        printf("\nEnter data for node %d : " , i+1);
        scanf("%d" ,&newnode->data);

        if(NULL == start){
            start = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }

    return start;
}

// DISPLAY FUNCTION HERE 
void display(node *start){
    node *temp;

    //transverse through whole link list and display data
    for(temp=start; temp!=NULL ;temp= temp->next){
        printf("%3d" , temp->data);
    }
}

// CONCATANATE FUNCTION HERE 
node *concatnate(node *start1 , node *start2){

    node *travereseTemp;

    //check if give list has only one node
    if(start1->next == NULL){
        start1->next = start2;
    }
    else{
        
        //transverse to the end of first list
        for(travereseTemp=start1 ; travereseTemp->next != NULL; travereseTemp= travereseTemp->next);
        travereseTemp->next =  start2;        
        printf("\nConcatnation sucessfully !!!!\n");

    }
}