typedef struct  stacks
{
    char ch[SIZE];
    int top;
}node;

int Init(int top)
{
    top = -1;
    return top;
}

int IsFull(node *s)
{
    return(s->top == SIZE-1);
}

int IsEmpty(node *s)
{
    return(s->top == -1);
}

void Push(node *s , char val)
{
    s->ch[++s->top] = val;
}

char Pop(node *s )
{
    return s->ch[s->top--];
}

int checkExpr(char *str)
{
    int n;
    for( n = 0; str[n] != '\0' ; ++n);
    if(str[0] != '(' && str[n-1] != ')')
    {
        printf("\nSomething went wrong\n");
        exit(1);
    }
}

void generateExpression(char *pfix , node *s)
{
    
}