//wap to reverse a string by using static stack 
#include<stdio.h>
#include "staticCharStack.h"
#include "dynamicCharstack.h"

// MAIN FUNCTION HERE   
int main(int argc, char const *argv[])
{
    S_stack s;
    D_stack sd;
    char str[SIZE] , revStr[SIZE];
    int ch , i;
    
    Init(&s);
    D_Init(&sd);

    printf("\n---reverse a string-----\n");
    //accept the string
    printf("\nEnter a string  : ");
    scanf("%s" , str);
    
    //display the stack according to user
    printf("\n[1]Static Stack Reverse string  : \n");
    printf("\n[2]Dynamic Stack Revrese string");
    printf("\nEnter yuour choice  : ");
    scanf("%d" , &ch);
    switch (ch)
    {
    case 1:
        //static
        for(i = 0 ;str[i] != '\0' ; ++i)
        {
            if(IsFull(&s))
            {
                printf("\nThe Stack is full !!!");
                break;
            }
            //esle keep pushing the elments 
            Push(&s , str[i]);
        }
        //pop out elements from stack and put em in new string
        i=0;
        while(!IsEmpty(&s))
        {
            revStr[i] = Pop(&s);
            ++i;
        }
        revStr[i] = '\0';

        //display the revsersed string
        printf("\nThe reversed string is  :  ");
        printf("\n%s\n" , revStr);
        break;
    case 2:
        
        //dynamic
        for(i = 0 ; str[i] != '\0' ; ++i)
        {
            D_Push(&sd , str[i]);
        }
        i=0;        
        
        //pop the elments out of the stack and store in new string
        while(!D_IsEmpty(&sd))
        {   
            revStr[i]= D_Pop(&sd);
            i++;
        }
        revStr[i] = '\0';

        printf("\nRevserse string using dynamic stack is  : ");
        printf("\n%s" , revStr);
        
        break;
    default:
        printf("\nEnter a valid option !!!");
        break;
    }  

    printf("\n----THANK YOU USE AGAIN -----\n");
    return 0;
}
