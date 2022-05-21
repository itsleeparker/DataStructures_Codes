//wap to immplement dynamic stack and its operation with function display and peek
#include<stdio.h>
#include<stdlib.h>
#include"dynamicStack.h"

//MAIN FUNCITON HERE 
int main(int argc, char const *argv[])
{
    int ch , val;
    D_stack s;

    D_Init(&s);
    printf("\n--DYNAMIC STRUCT---\n");
    do{
        printf("\n--MENU--\n");
        printf("\n[1]Push");
        printf("\n[2]Pop");
        printf("\n[3]Display");
        printf("\n[4]Peek");
        printf("\n[5]Exit");

        printf("\nEnter an option : ");
        scanf("%d" , &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be pushed : ");
            scanf("%d" , &val);
            D_Push(&s , val);
            break;
        
        case 2:
            if(D_IsEmpty(&s))
            {
                printf("\nStack is empty !!!!");
                break;
            }

            //pop function here 
            val = D_Pop(&s);
            printf("\nThe Node with value %d was poped!!!" , val);
            break;
        
        case 3:
            if(IsEmpty(&s))
            {
                printf("\nStack is empty !!!!");
                break;
            }
            //display function here 
            printf("\nEntered elments are  : ");
            Display(&s);
            break;
        
        case 4:
            if(D_IsEmpty(&s))
            {
                printf("\nStack is empty !!!!");
                break;
            }
            //peek function here 
            val  = Peek(&s);
            printf("\nElement at the top stack is %d : " , val);            
            break;
        
        case 5:
            //exit 
            break;
        
        default:
            printf("\nEnter  a valid option !!");
            break;
        }
    }while(ch != 5);

    printf("\n---THANK YOU USE AGAIN---\n");
    return 0;
}