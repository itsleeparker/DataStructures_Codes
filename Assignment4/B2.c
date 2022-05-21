//wap to reverse a stack of given numbers and display the output , write the same operation for static and dynamic stack
#include<stdio.h>
#include"dynamicStack.h"
#include"staticStack.h"

// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    S_stack s , s_num;
    D_stack sd , d_num ;
    int ch , num , rem , op , i ,val;

    Init(&s);
    Init(&s_num);
    D_Init(&sd);

    printf("\n----- Reverse Number ----\n");
    printf("\nEnter a number : ");
    scanf("%d" , &num);
    
    printf("\n[1]Statically reverse the number \n");
    printf("\n[2]Dyamically reversed number  \n");
    
    printf("\nEnter your choice  : ");
    scanf("%d" , &ch);

    switch (ch)
    {
    case 1:
        //static implementation
        op = num;
        while(num != 0)
        {
            if( IsFull(&s) )
            {
                printf("\nStack is full !!!\n");
                break;
            }
            
            rem = num%10;
            Push(&s  , rem);
            num = num/10;
        }

        while (!IsEmpty(&s))
        {
            Push(&s_num , Pop(&s));
        }

        printf("\nThe reverse of %d is  : " , op);
        while (!IsEmpty(&s_num))
        {
            printf("%d" , Pop(&s_num));
        }
            
        break;
    
    case 2:
        //dyamic implementation
        op = num ;
        while (num!=0)
        {
            rem = num%10;
            D_Push(&sd , rem);
            num = num/10;
        }

        //put the revsersed number in another stack and display stack 
        while (! D_IsEmpty(&sd) )
        {
            D_Push(&d_num , D_Pop(&sd));
        }

        printf("\nThe Reverse of given number %d is  : " , op);
        while (!D_IsEmpty(&d_num))
        {
         i = 1;
	    //change the logic for reversing the number accept the num from stack and multiply it with 10 to get proper number	
           val = i * D_Pop(&sd);
           i=10;
        }
        printf("%d" , val);
        
        break;
    
    default:
            printf("\nEnter a valid choice !!!");      
        break;
    }

    printf("\n---THANK YOU USE AGIAN----\n");
    return 0;
}
