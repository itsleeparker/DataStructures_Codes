//wap to implement adjacency list 
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct AdjacencyList
{
    int data;
    struct AdjacencyList *next;
}node;


void AcceptVertex(node *l[SIZE] , int n){

    int i , j;
    char ch;
    node *temp , *newnode;
    for(i=0;i<n;++i)
    {
        //allocate memory for node only when vertex is present
        for(j=0;j<n;++j)
        {
            printf("\nIs there any vertex between %d and %d : " , i , j);
            scanf(" %c" ,&ch);

            if(ch == 'y' || ch == 'Y'){
                newnode = (node*)malloc(sizeof(node));
                newnode->data = j+1;
                newnode->next = NULL;

                //check if there is any node ahead and push this node 
                temp = l[i];
                if(temp == NULL){
                    l[i] = newnode;
                }
                else{

                    while(temp->next!=NULL){
                        temp = temp->next;
                    }
                    temp->next = newnode;
                }

            }
        }
    }
}

void Display(node *l[SIZE]  , int n){
    int i , j;
    node *temp;        
    printf("\nAdjacnecy List \n");
    for(i=0;i<n;++i)
    {
        //display adjacency list
        temp =l[i];
        while(temp!=NULL)
        {
            printf("%3d " , temp->data);
            temp = temp->next;
        }
        printf(" NULL ");    
        printf("\n\n");
    }

}

void DisplayDegree(node *l[SIZE] , int n){
    int i ,j , indegree = 0 , outDegree = 0;
    node *temp;
    printf("\nIndegree\t\tOutDegree\t\tBoth\n");
    for(i=0;i<n ; ++i){
        temp = l[i];
        outDegree = 0;
        indegree  =0 ;
        while(temp!=NULL){
            outDegree++;
            temp = temp->next;
        }

        //check for indegree
        for(j=0;j<n;++j){
            temp = l[j];
            while(temp!=NULL){
                if(temp->data == i+1){
                    indegree++;
                }
                temp = temp->next;
            }
        }
        printf("\n\n %d\t\t %d\t\t %d\t\t" , indegree , outDegree , indegree+outDegree);
    }
    printf("\n\n");
}

int main(int argc, char const *argv[])
{
    int n  ,i;
    node *list[SIZE];
    //intiate the list 
    for(i=0;i<SIZE;++i){
        list[i] = NULL;
    }

    //get the number of vertex from the user 
    printf("\n---ADJACENY LIST----\n");

    printf("\nEnter number of vertex  : ");
    scanf("%d" , &n);

    AcceptVertex(list , n);

    printf("\nThe Adjacecncy List is ");
    Display(list , n);

    printf("\nThe Indegree and outDegree for given vertices are  : \n");
    DisplayDegree(list , n);
    printf("\n---THAKYOU USE AGIAN----\n");
    return 0;
}