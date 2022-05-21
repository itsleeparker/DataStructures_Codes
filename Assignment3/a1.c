//wap to find a given number from a given array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int search(int a[SIZE] , int val)
{
    int i;
    for(i=0 ;i<SIZE ;++i)
    {
        if(a[i] == val)
        {
            return i+1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int a[] = {1 , 2, 3  , 4 , 5};
    int val , pos;

    printf("\n--SEARCH IN STATIC ARRAY---\n");
    
    //take the searching value from user
    printf("\nEnter value to be searched  : ");
    scanf("%d" , &val);

    pos = search(a , val);
    if(pos == -1)
    {
        printf("\nThe given vlaue %d not found in array !!" ,val);
    }
    else{
        printf("\nThe Given value is present at %d position " , pos);
    }
    return 0;
}
