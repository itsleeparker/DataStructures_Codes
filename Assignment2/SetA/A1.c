//wap to accept  , display and sort 5 nUmbers using bubble Sort

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

// DISPLAY FUNCTION HERE 
void display(int a[SIZE]  , int n)
{
    int i;
    for(i=0 ; i<n;++i){
        printf("%3d" , a[i]);
    }
    printf("\n");
}

//ACCEPT FUNCTION HERE
void Accept(int a[SIZE] , int n)
{
    int i;
    for(i=0;i<n;++i){
        scanf("%d" , &a[i]);
    }
}

// PARTITION FUNCTION HERE 

int partition(int a[SIZE] , int low   , int high)
{   
    int i , j , temp ,pivot;
    pivot = a[low];
     i = low;
     j = high;

     //check for the elements
     while (i<j)
     {
         while (a[i]<=pivot && i<=high)
         {
             i++;
         }

         while (a[j]>pivot && j>=low)
         {
            j--;
         }
         
         //check if i is still smaller then j
         if(i<j){
            temp=a[i];
            a[i] = a[j];
            a[j] = temp;
         }
         
     }

     a[low] = a[j];
     a[j] = pivot;
     
     return j;
}

// QUICK SORT FUNCTION HERE 

int QuickSort(int a[SIZE] , int low , int high)
{
    int pos;
    if (low<high)
    {
            pos = partition(a , low , high);
            QuickSort(a , low , pos-1);
            QuickSort(a , pos+1 , high);
    }
    
}    
// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    int n=SIZE , a[SIZE];

    printf("\n----SORT THE NUMBER USING BUUBLE SORT-----\n");
    
    printf("\nEnter %d Numbes  : " , SIZE);
    Accept(a , n);

    printf("\nEntered Number are : \n");
    display(a , n);

    QuickSort(a , 0 , n);
    printf("\nThe sorted Numbers are  : ");
    display(a , n);
    return 0;
}
