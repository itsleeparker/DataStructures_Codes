//WAP to find the element in the given array using linear search

///////////////////////
///// HEADER FILES 
//////////////////////

#include<stdio.h>
#define SIZE 10

int main(int argc, char const *argv[])
{
    int Accept(int [SIZE] , int);       //accept array from user
    int Display(int[SIZE] , int);       //Display array
    int Find(int[SIZE] , int , int );   //Find the array 

    int arr[SIZE] , n , pos , num;

    //accept n value from user
    printf("\nEnter n value of array [MAX :%d]: ", SIZE);
    scanf("%d",&n);

    //check if the size of array is valid
    if(n>SIZE)
    {   
        printf("\nEnter value of n > %d only !!!!\n",SIZE);
        return 1;
    }

    Accept(arr , n);

    //display array
    Display(arr ,n);

    //accept the key to be find in array
    printf("\nEnter the number to find  : ");
    scanf("%d" , &num);

    //search the num
    pos = Find(arr , n , num);

    if(pos  == -1)
    {
        printf("\n%d Not found in the given array !!!\n\n" , num);
        return 1;
    }

    printf("\n%d Element found on the %d position !!!!" , num , pos+1);

    printf("\n----THANK USE AGIAN ------\n");
    return 0;
}


int Accept(int arr[SIZE] , int  n)
{
    int i;
    printf("\nEnter %d elements  : ",SIZE);

    for(i=0 ;i<n;++i)
    {
        scanf("%d",&arr[i]);
    }
}

int Display(int arr[SIZE]  , int n)
{
    int i;

    //display all the elmemnts in array
    printf("\nEntered elements are  : ");
    for(i=0;i<n;++i)
    {
        printf("%d" ,arr[i]);
    }
}

int Find(int arr[SIZE] , int n , int num)
{
    int pos=0;
    while(pos<=n && arr[pos] != num)
    {
        if(arr[pos] == num)
        {
            break;
        }
        ++pos;
    }

    //check if the element is not in the array
    if(pos == n)
    {
        return  -1;
    }

    return pos;
}