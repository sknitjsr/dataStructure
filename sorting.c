#include<stdio.h>
void selection(int* , int);
void bubble(int* , int);
void merge(int* , int);
void insertion(int* , int);
void display(int * , int);

int main()
{
    int *p , i , size ;
    printf("Enter size of array : \n");
    scanf("%d" , &size);
    p = (int*)malloc(size * sizeof(int));
    for(i = 0 ; i<size ; i++)
        scanf("%d" , p+i);
   selection(p , size);
  display(p , size);

}

void display(int *p , int size)
{
    int i ;
    for(i = 0 ; i<size ; i++)
        printf("%d\t" , *(p+i));

}

void bubble(int *p , int size)
{
    int temp , i , j ;
    for(i = 0 ; i < size-1 ; i++)
        for(j = i+1 ; j<size ; j++)
                if(*(p+i) > *(p+j))
    {
        temp = *(p+i);
        *(p+i) = *(p+j);
        *(p+j) = temp;


    }
}

void insertion(int *p , int size)
{
    int temp , i , j ;
    for(i = 1 ; i < size ; i++)
    {
        temp = *(p+i) ;


        for(j = i-1 ; (j>=0) && (*(p+j)>temp) ; j--)
                *(p+j+1) = *(p+j) ;

                *(p+j+1) = temp;
}
}

void selection(int *p , int size)
{
    int temp , i , j , min , pos ;
    for(i = 0 ; i < size ; i++)
    {
           min = *(p+i);
           pos = i ;

        for(j = i+1 ; j<size ; j++)
                if(*(p+j) < min)
                {
                    pos = j ;
                }
    if(pos!=i)
    {


    temp = *(p+pos);
        *(p+pos) = *(p+i);
        *(p+i) = temp;

    }
    }
}


















