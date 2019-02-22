
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

void pop(struct arraystack *s)
{
    s->top--;

}
int main()
{

    char str[50];
    gets(str);
    struct arraystack *A;
    A = create(A);

    int flag = 1 , i ;
    for(i=0 ; str[i]!='\0' ; i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            {


            push(A , str[i]);}
        else if (str[i]==')')
        {
            if(peek(A)=='{'|| peek(A)=='[')
                {


                flag = 0;
                break;
                }
                else
                {
                    pop(A);
                }
        }
        else if (str[i]=='}')
        {
            if(peek(A)=='('|| peek(A)=='[')
                {flag = 0;
                  break;
                }
                else
                {
                    pop(A);
                }
        }
        else if (str[i]==']')
        {
            if(peek(A)=='{'|| peek(A)=='(')
               {
                 flag = 0;
                 pop(A);
               }
               else
               {
                   pop(A);
               }
        }
        else
        {

        }



    }

    if(isEmpty(A)&&flag==1)
        printf("\n Valid");
    else
         printf("\n Invalid");







}


