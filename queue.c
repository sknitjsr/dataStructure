#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
int capacity ;
int front , rear ;
int *arr;
};

struct  queue *create(int size ,  struct queue *s )
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


void reverse (struct queue *q)
{
int data , temp ;
if(q->front==q)
return;
data = deque(q);
reverse(q);
insert_at_front(q , data);


}


void insert_at_front(struct queue *q , int data)
{
int temp;
if(isEmptyqueue(q))
{
enqueue(q, data);
return;
}

enqueue(q , data);


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

int main()
{
struct queue *q ;
q = create(20 , q);
int choice , data;

while(1)
{
    printf(" 1. Enqueue\n 2. Dequeue \n 3. Display \n 4. Reverse\n 5. Exit\n");
    scanf("%d" , &choice);
    switch(choice)
    {
    case 1 :
        printf("Enter Data :");
        scanf("%d" , &data);
        enqueue(q , data);
        break;
    case 2:
        deque(q);
        printf("Success\n");
        break;
    case 3 :
        if(isEmptyqueue(q))
        {
            printf("Empty");
            break;
        }
        else{
            display(q);
break;
    }
    case 4 :
        reverse(q);
        break;
    case 5 :
        exit(1);



}

}

}


