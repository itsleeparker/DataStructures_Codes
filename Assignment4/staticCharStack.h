#define SIZE 10
typedef struct staticCharStack
{
    char data[SIZE];
    int top;
}S_stack;

void Init(S_stack *s)
{
    s->top = -1;
}

void Push(S_stack *s, char val)
{
    s->data[++s->top] = val;
}

char Pop(S_stack *s)
{    
    return s->data[s->top--];
}

int IsFull(S_stack *s)
{
    return (s->top == SIZE-1);
}

int IsEmpty(S_stack *s)
{
    return (s->top == -1);
}