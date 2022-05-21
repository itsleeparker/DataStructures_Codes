//wap to implement static stack and its operation with display and peek functions
#include<stdio.h>
#include"staticStack.h"

//MAIN FUNCITON HERE 
int main(int argc, char const *argv[])
{
    int ch , val;
    S_stack s;
    Init(&s);
    printf("\n---STATIC STACK----\n");
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
            if( IsFull(&s) )
            {
                printf("\nThe stack is full pop some elments first !!!");
                break;
            }
            printf("\nEnter the element to be pushed : ");
            scanf("%d" , &val);
            Push(&s , val);
            break;
        
        case 2:
            if(IsEmpty(&s))
            {
                printf("\nStack is empty !!!!");
                break;
            }

            //pop function here 
            val = Pop(&s);
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
            if(IsEmpty(&s))
            {
                printf("\nStack is empty !!!!");
                break;
            }
            //peek function here 
            Peek(&s);            
            break;
        
        case 5:
            //exit 
            break;
        
        default:
            printf("\nEnter  a valid option !!");
            break;
        }
    }while(ch != 5);

    printf("\n---THANK YOU USE AGIAN----\n");
    return 0;
}
