//wap to implement polish notation and display the expression
#include<stdio.h>
#include<stdlib.h>
#define SIZE 15
#include"structure.h"
// MAIN FUNCTION HERE 
int main(int argc, char const *argv[])
{
    char pfix[SIZE] , expr[SIZE];
    node s;
    s.top  = Init(s.top);                   //intilaize stack
    printf("\n---PREFIX EXPRESSION----\n");
    
    //accept the infix expression from user 
    printf("\nEnter Infix expression : ");
    scanf("%s" , expr);
    checkExpr(expr);                //check if user has entered proper parethesis
    generateExpression(expr  , &s);
    
    return 0;
}
