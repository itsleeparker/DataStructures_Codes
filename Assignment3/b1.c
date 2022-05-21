//wap to accept a value and search that value inside a given static array using binary search 
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int accept(int a[SIZE] , int n)
{
    int i;
    for(i=0 ; i<n ; ++i)
    {
        scanf("%d" ,&a[i]);
    }
}

void display(int a[SIZE] , int n)
{
    int i;
    for(i=0 ;i < n ; ++i)
   {
       printf("%3d" , a[i]);
   }
}

int search(int a[SIZE] , int val , int n)
{
    int i;
    for(i=0 ; i<n ;++i)
    {
        if(a[i] == val)
        {
            return i+1;
        }
    }

    return -1;

}

// MAIN FUNCTION HERE   
int main(int argc, char const *argv[])
{
    int a[SIZE] ;
    int n  , pos , val;

    printf("\n----SEARCH ARRAY----\n"); 
    printf("\nEnter how many elemenys yuou wanna insert [MAX  %d]: " , SIZE);
    scanf("%d" , &n);

    //accept elements  
    printf("\nEnter %d elements for array  : " , n);
    accept(a , n);   

    //display the array
    printf("\nEntered elements  are  : ");
    display(a , n);

    printf("\nEnter value to be searched in array  : ");
    scanf("%d" , &val);

    pos = search(a , val , n);
    if(pos != -1)
    {
        printf("\nEnterd value found at %d position " , pos);
    }
    else{
        printf("\nGiven ELement not found in array !!!");
    }
    return 0;
}
