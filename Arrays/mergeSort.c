//wap to accept an array and sort it using merge sort
#include<stdio.h>
#define SIZE 10

int main(int argc, char const *argv[])
{
    void Accept(int[SIZE] , int);
    void Display(int[SIZE]  , int );
    void MergeSort(int [SIZE] , int , int);

    int n , arr[SIZE];

    printf("\nEnter the value of n [MAX SIZE : %d]: " , SIZE);
    scanf("%d" , &n);
    if(n>SIZE)
    {
        printf("\nGiven value exceeds the max size !!! .Program Abort!!");
        return -1;
    }

    //accept the number into array 
    printf("\nEnter %d elements for array  : " , n);
    Accept(arr , n );

    //display the given unsorted array 
    printf("\nEntered array is  : \n");
    Display(arr ,n);
    
    //sort the array and display it 
    MergeSort(arr ,  0 , n-1);

    printf("\nSorted array is  : \n");
    Display(arr , n);

    printf("\n-----THAKN YOU USE AGAIN-------\n");
    return 0;
}


void Accept(int arr[SIZE] , int n)
{
    int i;
    for(i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }
}

void Display(int arr[SIZE] , int n)
{
    int i;
    for(i=0;i<n;++i)
    {
        printf("%3d" ,arr[i]);
    }
}

void Merge(int arr[SIZE] , int low ,int mid ,int high)
{

    int k = 0  , i = low , j = mid +1;
    int b[SIZE];

    while (i<=mid && j<=high)
    {
        if(arr[i] < arr[j])
        {
            b[k++] =  arr[i++];
        }
        
        else
        {
            b[k++] = arr[j++];
        }

    }

    while (i<=mid)
    {
        b[k++] = arr[i++];
    }

    while (j<=high)
    {
        b[k++] = arr[j++];
    }
    
    //copy the array in the original array
    for(i=low ,k=0 ; i<=high ; ++i , ++k )
    {
        arr[i] = b[k];
    }

}   

void MergeSort(int arr[SIZE] , int low , int high)
{
    int mid;
    
    if (low < high)
    {
        mid = ( low + high ) /2;

        MergeSort(arr , low , mid);       
        MergeSort(arr ,  mid+1 , high);        
        Merge(arr , low  ,mid , high);
    }  
}