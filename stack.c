
#include<stdio.h>
#define N 10
struct arraystack
{
    int top;
    int size;
    char *arr;
};

struct arraystack *create(struct arraystack *s)
{
    s = malloc(sizeof(struct arraystack));
    s->top = -1;
    s->size = N;
    s->arr = malloc(s->size * sizeof(char));
    return s ;

};
void push(struct arraystack *s , char c )
{
    if(s->top==s->size)
    {
        printf("Stack is Full");
        return;
    }
    else
        s->arr[++s->top] = c ;

}

int isEmpty(struct arraystack *s)
{
    return (s->top==-1);
}

int isFull(struct arraystack *s)
{
    return (s->top==s->size-1);
}

char peek(struct arraystack *s)
{
    return s->arr[s->top];

}

char pop(struct arraystack *s)
{
    char t ;
    t = s->arr[s->top--];
    return t ;
}
int main()
{
    struct arraystack *A;
    A = create(A);
    push(A , 'a');
    push(A , 'b');
    printf("%c" , peek(A));



}

