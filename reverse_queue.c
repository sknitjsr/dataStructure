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



typedef struct queue
{
int capacity ;
int front , rear ;
int *arr;
};

struct  queue *createq(int size ,  struct queue *s )
{

    s = malloc(sizeof(struct queue));
    s->capacity = size;
    s->front = s->rear = -1;
    s->arr = malloc(sizeof(int)*s->capacity);

    return s;

}

int isEmptyqueue(struct queue *q)
{
return (q->front==-1);

}

int isFullqueue(struct queue *q)
{
return ((q->rear+1) % q->capacity == q->front);

}

void enqueue(struct queue *q , int data)
{
if(isFullqueue(q))
printf("full");
else
{
q->rear = (q->rear+1)%q->capacity;
q->arr[q->rear] = data;

if(q->front== -1)
q->front = q->rear;
}
}

int deque(struct queue *q )
{
int data = 0 ;
if(isEmptyqueue(q))
{
printf("Empty");

}
else
{

data = q->arr[q->front];
if(q->front==q->rear)
     q->front = -1;
else
q->front = (q->front+1)%q->capacity;
}
return data;
}

void display(struct queue *q)
{
    int temp = q->front;
    while(temp!=q->rear)
    {
        printf("%d\t" , q->arr[temp]);
        temp++;
    }
    printf("%d\n\n" , q->arr[temp]);
}

void reverse(struct queue *q ,struct queue *q1 , struct arraystack *s ,   int k)
{
    while(!isEmptyqueue(q))
    {
        if(q->front<k)
            push(s , deque(q));
        else
            enqueue(q1 , deque(q));

    }
    while(!isEmpty(s))
    {
        enqueue(q , pop(s));
    }
    while(!isEmptyqueue(q1))
    {
        enqueue(q , deque(q1));
    }


}


int main()
{
struct queue *q  , *q1;
q = createq(20 , q);
q1 = createq(20 , q1);
struct arraystack *s ;
s = create(s);
enqueue(q , 90);
enqueue(q , 80);
enqueue(q , 70);
enqueue(q , 60);
enqueue(q , 50);
enqueue(q , 40);
enqueue(q , 30);
enqueue(q , 20);
enqueue(q , 10);
display(q);
reverse(q , q1 , s , 4);
display(q);
}
