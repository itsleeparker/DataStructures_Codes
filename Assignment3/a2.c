//wap to search the element in the given static array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

// SEARCH FUNCTION HERE
int search(int a[]  , int val)
{
    int i;
    for(i=0;i<SIZE;++i)
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
    int a[SIZE] = {1 , 5 , 7 , 12 ,16 , 13 , 22 , 24};
    int val , pos;
    printf("\n----SEARCH THE ELEMENT------\n");
    printf("\nEnter the element to be searched  : ");
    scanf("%d" , &val);

    pos = search(a , val);
    if(pos != -1)
    {
       printf("\nThe elmenet is at the position %d \n" , pos); 
    }
    else{
        printf("\nGiven element not found inside array \n");
    }

    printf("\n---THANK YOU USE AGAIN----\n");
    return 0;
}
