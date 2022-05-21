//wap to accept an array of length n and sort the array using quick sort

#include<stdio.h>
#define SIZE 10

/////////////////////
//////  functions here
///////////////////////
void Accept(int a[SIZE] , int n)
{
    int i;
    for(i=0 ;i<n ;++i)
    {
        printf("\nEnter number %d: " , i+1);
        scanf("%d",&a[i]);
    }
}

void Display(int a[SIZE] , int n)
{
    int i=0;
    while (i<n)
    {
        printf("%3d" , a[i]);
        ++i;
    }
    
}

int Partition(int a[SIZE] , int low , int high)
{
    int  i= low , j = high;
    int pivot , temp;
    pivot = a[low];
    while (i<j)
    {
        while (a[i] < pivot && i<=high)  //check if Ith element is greater then right side of array
        {
            i++;
        }
        
        while(a[j] > pivot && j>=low)   //check if pivot element is smaller then other side of array
        {
            j++;
        }
        
        //if the I < j that means a value is to be sorted 
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] =temp;
        }
    
    }

    //exchange the low with J since the j<a[low]
    a[low] = a[j];
    a[j] = pivot;

    return j;
}

int Quicksort(int a[SIZE] , int low , int high)
{
    int pos , count =0;
    while(low<high)
    {
        printf("\na");
        pos = Partition(a , low , high);
        Quicksort(a , low  , pos-1);            //use recretion to divide the array in 2 parts 
        Quicksort(a , pos+1 , high);
        count++;
        
        if(count >=high)
        {
            printf("\nSOmething went wrong !!!\n");
            return 1;
        }
    }
   return 0;     
}


///////////////////////
////MAIN FUNCTION
//////////////////////
int main()
{
    int arr[SIZE] , n;

    //accept the value of n from user
    printf("\nEnter value of n [MAX  : %d]: " , SIZE);
    scanf("%d" ,&n);
    if(n>SIZE)
    {
        printf("\nError Occured  : N size is greate then MAX !!!!\n");
        return -1;
    }

    //accept the array
    printf("\nEnter %d values for array : " , n);
    Accept(arr , n);

    //dipslay the array before the sort
    // printf("\nEntered array is  : \n");
    // Display(arr , n);

    //sort the array
    Quicksort(arr ,  0 , n);

    printf("\nSorted array is  :");
    Display(arr , n);
    printf("\n-----THANK YOU USE AGIAN-----\n");

    return 0;
}

