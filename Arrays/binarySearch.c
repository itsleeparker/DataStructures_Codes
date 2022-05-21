//WAP to find a given item in a given set of array using binary search 

/////////////////////////
////////HEADER FILES
///////////////////////

#include<stdio.h>
#define SIZE 10

////////////////////////
///////MAINN FUNCTION 
///////////////////////

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



////////////////////
////ACCEPT ARRAY
///////////////////

int Accept(int arr[SIZE] , int n)
{
    int i;
    printf("\nEnter %d elements in ascending order only ! : " , n);
    for(i=0 ;i<n ; ++i)
    {
        scanf("%d",&arr[i]);
    }
}

/////////////////////
//////DISPLAY ARRAY 
/////////////////////

int Display(int arr[SIZE] , int  n)
{
    int i;

    printf("\nEntered array is  : ");
    for(i=0 ; i< n ;++i)
    {
        printf("%2d",arr[i]);
    }
}


////////////////////////
////FIND NUM IN ARRAY 
///////////////////////

int Find(int arr[SIZE] , int n , int num)
{
    int low = 0 , high = n-1  ,mid;     //low will take care of lower bound of array  , while high will be upper bound of array
    mid = (low+high)/2;
    
    while(low<=high && arr[mid] != num)
    {
        if(arr[mid] < num)
        {
            low = mid + 1;
        }
        else{
            high = mid -1;
        }

        mid = (high+low)/2;
    }

    //check if the element is not found
    if(low>high)
    {
        return -1;
    }
    return mid;
}