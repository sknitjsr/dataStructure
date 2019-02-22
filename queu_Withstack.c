#include<stdio.h>
#define N 10
struct arraystack
{
    int top;
    int size;
   int *arr;
};

struct arraystack *create(struct arraystack *s)
{
    s = malloc(sizeof(struct arraystack));
    s->top = -1;
    s->size = N;
    s->arr = malloc(s->size * sizeof(int));
    return s ;

};
void push(struct arraystack *s , int c )
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

int peek(struct arraystack *s)
{
    return s->arr[s->top];

}

int pop(struct arraystack *s)
{
    int t ;
    t = s->arr[s->top--];
    return t ;
}

struct queue
{
    struct arraystack *s1;
    struct arraystack *s2;
};
struct queue *createq(struct queue *q)
{ q = malloc(sizeof(struct queue));
    q->s1 = create(q->s1);
    q->s2 = create(q->s2);
    return q  ;
};


void enqueue(struct queue *q , int data)
{
 push(q->s1 ,data );
}

int deque(struct queue *q)
{
    int temp;
    while(!isEmpty(q->s1))
    {
        push(q->s2 , pop(q->s1));
    }

    temp = pop(q->s2);

    while(!isEmpty(q->s2))
    {
        push(q->s1 , pop(q->s2));
    }

    return temp;
}

int main()
{
    struct queue *q ;
   q = createq(q);
enqueue(q , 90);
enqueue(q , 80);

enqueue(q , 20);
enqueue(q , 10);
printf("%d\t" , deque(q));

printf("%d\t" , deque(q));

enqueue(q , 70);
enqueue(q , 60);
enqueue(q , 50);
enqueue(q , 40);
enqueue(q , 30);
printf("%d\t" , deque(q));




}
