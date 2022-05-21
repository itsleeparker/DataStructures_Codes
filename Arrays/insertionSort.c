//wap to sort an array using the insertion sort algorithim 

#include<stdio.h>
// #include<bool.h>
#define SIZE 10

int a[SIZE] , n; 

int main(int argc, char const *argv[])
{
    void Accept();          //accept array 
    void Display();         //display array
    void InsertionSort();   //insertion sort 


    //accept the value of n
    printf("\nEnter the value of n [Max : %d]: " ,SIZE);
    scanf("%d" , &n);

    if(n>SIZE)
    {
        printf("\nEntered array size exceeds size  :  %d !!!!" ,SIZE);
        return 1;
    }

    Accept();
    if(n<2)
    {
        printf("\nEntered Array is : ");
        Display();          //if array is smaller then 2 , then display it directly
        return 0;
    }

    printf("\nEntered array is : \n");
    Display();

    InsertionSort();        //sort the array

    printf("\nSorted array is  : \n");
    Display();
   
    printf("\n------THANK YOU USE AGIAN--------\n");
    return 0;
}

void Accept()
{
    int i;

    printf("\nEnter %d elements  : " , n);
    for(i=0 ; i<n ; ++i)
    {
        scanf("%d" , &a[i]);
    }
}

void Display()
{
    int i;
    for(i=0 ; i<n ; ++i)
    {
        printf("\t%d" , a[i]);
    }
}

void InsertionSort()
{
    int i , j  , temp;

    for(i=1 ; i<n ;++i)         //go through the whole array 
    {
        j = i-1;                //place the j next to i in all cases
        temp = a[i];
        while(j>=0 && a[i] >= temp)
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] =temp;
    }
}