///////////////////
//////HEADER FILES
//////////////////

#include<stdio.h>
#define SIZE 20

int arr[SIZE] , n;                  //declare variables globaly , so they can be accessed easly
///////////////////
////MAIN FUNCTION 
//////////////////

int main(int argc, char const *argv[])
{
    void Accept();
    void Display();
    int bubbleSort();

    //take n from user
    printf("\nEnter n value  [Max: %d]: " , SIZE);
    scanf("%d" , &n);

    Accept();           //take array from user

    printf("\nEntered array is  : \n");
    Display();          //display the array

    if(n > 2)
    {
        bubbleSort();       //sort the array
    }
    
    printf("\nSorted array is  : \n");
    Display();          //display the sorted array
    
    printf("\n-----THANK YOU USE AGAIN-------\n");
    return 0;
}


void Accept()
{
    int i;

    printf("\nEnter %d elements for array  : " , n);
    for(i=0;i<n;++i)
    {
        scanf("%d" , &arr[i]);
    }
}

void Display()
{
    int i;

    for(i=0;i<n;++i)
    {
        printf("%2d" , arr[i]);
    }
}

// NOTE TO SELF:
// remember the bubble sort algorithim compares two values  at a __time_
// here the iteration i is not invovled in comaring the value but to count the 
// number of sorting needs to be done which is n-1 time since two values are being compares 
// at once , j checks the value of two items and then make changes accordingy
// The flag is the last resort , it saves some time for i where , sorting is completed it tells the 
// loop that array is already sorted and hence helps in breaking the loop

int bubbleSort()
{
    int i , j , flag , temp;

    for(i=0; i < n-1 ; ++i)
    {
        for(j=0 ; j<n-1-i; j++)
        {
            flag = 0;
            if(arr[j] > arr[j+1])
            {
                flag   = 1;
                temp   = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }

        }
            if(flag == 0)           //check if the current loop is already sorted or not
            {
                break;
            }
    }
}s