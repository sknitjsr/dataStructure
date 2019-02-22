
#include<stdio.h>
#define N 50
struct arraystack
{
    int top;
    int size;
    char *arr;
};
int pref(char t )
{
    if(t=='^')
        return 3 ;
    else if(t=='*'||t=='/')
        return 2 ;
    else if(t=='+'||t=='-')
        return 1 ;
    else
        return -1 ;
    }
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

void infix_to_postfix(struct arraystack *s , char src[] , char tgt[])
{  int i , k=0;
    for(i = 0 ; src[i]!='\0'; i++)
    {
        if(src[i]>='a' && src[i]<='z')
            tgt[k++]=src[i];
        else if(src[i]=='(')
                    push(s , src[i]);
        else if (!isEmpty(s) && src[i]==')')
        {
            while(!isEmpty(s) && peek(s)!='(')
            {    char t = pop(s);
                  tgt[k++] = t ;
            }

            if(peek(s)=='(')
                {char t;
                t = pop(s);
        } }
        else
        {

            while(!isEmpty(s) && pref(peek(s)) >= pref(src[i]))
            {
                char t = pop(s);
                tgt[k++]=t;

            }
            push(s , src[i]);

        }
        }

    while(!isEmpty(s))
    {
        tgt[k++]=pop(s);
    }

   puts(tgt);
}
int main()
{
    struct arraystack *A;
    A = create(A);
    char src[50] , tgt[50] ;
    gets(src);
    strcpy(tgt , " ");
    infix_to_postfix(A , src , tgt);



}


