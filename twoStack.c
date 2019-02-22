
#include<stdio.h>
#define N 10
#define M 10
struct arraystack
{
    int top1 , top2;
    int size1 , size2;
    char *arr;
};

struct arraystack *create(struct arraystack *s)
{
    s = malloc(sizeof(struct arraystack));
    s->size1 = N;
    s->size2 = M ;
    s->top1 = -1;
    s->top2 = s->size1+s->size2 ;

    s->arr = malloc(s->size1 + s->size2 * sizeof(char));
    return s ;

};
void push(struct arraystack *s , char c , int x )
{
    if(s->top1==s->top2)
    {
        printf("Stack is Full");
        return;
    }
    if(x==1)
    {
        s->arr[++s->top1] = c ;
    }
    else
    {
       s->arr[--s->top2] = c ;
    }

}

int isEmpty(struct arraystack *s , int x )
{
    if(x==1)
    return (s->top1==-1);
    else
        return (s->top2==s->size1+s->size2);
}

int isFull(struct arraystack *s )
{
    return (s->top1==s->top2);
}



char pop(struct arraystack *s , int x)


{
    if(x==1)
    {
        char t ;
    t = s->arr[s->top1--];
    return t ;
    }
    else
    {
       char t ;
    t = s->arr[s->top2++];
    return t ;
    }

}
int main()
{
    struct arraystack *A;
    A = create(A);
    push(A , 'a' , 1);
    push(A , 'b' , 2);
     push(A , 'c' , 1);
    push(A , 'd' , 2);
    char t = pop(A ,1 );
    printf("%c" , t);



}


