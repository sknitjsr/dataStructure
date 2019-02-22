#include<stdio.h>
void mergeSort(int* , int , int);
void merge(int* , int , int , int);
void display(int* , int);



int main()
{
    int *p ,  i , size ;
    printf("Enter size of array : \n");
    scanf("%d" , &size);
    p = (int*)malloc(size * sizeof(int));
    for(i = 0 ; i<size ; i++)
        scanf("%d" , p+i);
   mergeSort(p , 0 ,size-1);


}

void mergeSort(int* arr, int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left+right)/2;


        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

void display(int *p , int size)
{
    int i ;
    for(i = 0 ; i<size ; i++)
        printf("%d\t" , *(p+i));

        printf("\n");

}

void merge(int *p , int left , int mid , int right)
{
 int i, j, k;
    int n1 = mid - left + 1;
    int n2 =  right - mid;
int *l , *r ;
l = (int*)malloc(n1 * sizeof(int));
r = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        *(l+i) =  *(p+left+i);
for (j = 0; j < n2; j++)
    *(r+j) =  *(p+mid+1+j);

    display(l , n1);
    display(r , n2);



    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (*(l+i) <= *(r+j))
        {
            *(p+k) = *(l+i);

            i++;
        }
        else
        {
             *(p+k) = *(r+j);


            j++;
        }
        k++;
    }



    while (i < n1)
    {
        *(p+k) = *(l+i);

        i++;
        k++;
    }



    while (j < n2)
    {
        *(p+k) = *(r+j);

        j++;
        k++;
    }






}






