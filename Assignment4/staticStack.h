//wap to staticly implement stack with all of its operation
#define SIZE 10

//struct heere
typedef struct staticStack{

    int data[SIZE];
    int top;
}S_stack;

//init function for stack
void Init(S_stack *s)
{
    s->top = -1;
}

//psuh operation here
void Push(S_stack *s  , int val)
{
    s->data[++s->top] = val;
}

//PoP function here
int Pop(S_stack *s)
{
    return s->data[s->top--];
}

int IsEmpty(S_stack *s)
{
    return(s->top == -1);
}

int IsFull(S_stack *s)
{
    return(s->top == SIZE-1);
}

void Display(S_stack *s)
{
    int  n = s->top;
    
    while(n>=0)
    {
        //display output
        printf("%3d" , s->data[n]);
        n--;
    }
}

void Peek(S_stack *s)
{
    //display the chracter with top most element
    printf("\nTop element is  : %d\n" , s->data[s->top]);
}