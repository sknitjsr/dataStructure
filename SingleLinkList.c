#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *insert_at_beginning(struct node* start , int data)
{
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data ;
  temp->link = start;
  start = temp;
  return start ;
}
struct node * insert_at_end(struct node * start,int n)
{
  struct node *p , *temp ;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = n;
  p = start;
  while(p->link!=NULL)
   {
     p = p->link ;
   }
  p->link = temp;
  temp->link = NULL ;
  return start ;
}
struct node* create(struct node *start)
{
    int d , num ,i;
   start = NULL;
   printf("Enter no. of nodes : ");
   scanf("%d" ,&num );

   printf("\n Enter Value of first node : ");
   scanf("%d" , &d);
   start = insert_at_beginning(start , d);
   for( i = 1 ; i<num ; i++)
   {
     printf("\n Enter Value of %d node : " , i+1);
     scanf("%d" , &d);
     start = insert_at_end(start , d);


   }
   return start ;
}



struct node * insert_at_pos(struct node * start,int pos,int data)
{
  struct node *p , *temp ;
  int count =1;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  p = start;
  if(pos==1)
    start = insert_at_beginning(start,data);
  else
    {
     while(count!= (pos - 1) && p->link!=NULL )
      {
        p = p->link ;
        count++;
      }
      temp->link = p->link;
      p->link = temp;
    }
  return start ;
}

struct node *delete_at_beginning(struct node* start)
{
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp = start;
  if(temp == NULL)
  {
      printf("\n\nCannot be deleted \n\n");
  }
  else
  {
      temp = start->link;
      start = temp;
  }
  return start ;
}

struct node * delete_at_end(struct node * start)
{
  struct node *p , *temp ;
  temp = (struct node*)malloc(sizeof(struct node));
  p = start;
  while(p->link!=NULL)
   {
     temp = p;
     p = p->link ;
   }
  temp->link = NULL ;
  return start ;
}

struct node * delete_at_pos(struct node * start,int pos)
{
  struct node *p , *temp ;
  int count =1;
  temp = (struct node*)malloc(sizeof(struct node));

  p = start;
  if(pos==1)
    start = delete_at_beginning(start);
  else
    {
        temp = p;
     while(count!= pos && p->link!=NULL )
      {
          temp = p;
        p = p->link ;
        count++;
      }
      temp->link = p->link;
    }
  return start ;
}

void display(struct node *start)
{
    struct node *p , *temp ;
    printf("\t------------------------------------------------\t\n");
    printf("\n\t\tList is : ");
    p = start;
    printf("%d  ",p->data);
   while(p->link!=NULL)
    {
        p = p->link ;
      printf("%d  ",p->data);

    }
    printf("\n\t------------------------------------------------\t\n");
}

void search(struct node *start , int element)
{  int flag = 1;
    struct node *p ;
    int count = 1;
    p =start;
    while(p!=NULL)
    {
        if(p->data==element)
        {
          printf("Element found at %d position\n" , count);
          flag = 0;
          return;
        }
        p = p->link;
        count++;

    }
    if(flag==1)
    {
    printf("Element not found \n" , count);
    return;
    }

}

int main()
{
    struct node *start;
    start=(struct node *)malloc(sizeof(struct node));
    int choice , d , i;
    while(1)
    {
      printf("1. Create list\n");
      printf("2. Add at end of the list \n");
      printf("3. Add at beginning of list\n");
      printf("4. Add at position of list\n");
      printf("5. Delete at end of the list \n");
      printf("6. Delete at beginning of list\n");
      printf("7. Delete at position  of list\n");
      printf("8. Search for an element \n");
      printf("9. Display list\n");
      printf("10. Quit\n");
      scanf("%d" , &choice);
      switch(choice)
      {
    case 1:
        start=create(start);
        break;
    case 2:
        printf("Enter the data : ");
        scanf("%d",&d);
        start = insert_at_end(start,d);
        break;
    case 3:
        printf("Enter the data : ");
        scanf("%d",&d);
        start = insert_at_beginning(start,d);
        break;
    case 4:
        printf("Enter the index at which you want to insert : ");
        scanf("%d",&i);
        printf("Enter the data: ");
        scanf("%d",&d);
        start = insert_at_pos(start,i,d);
        break;
    case 5:
        start = delete_at_end(start);
        break;
    case 6:
        start = delete_at_beginning(start);
        break;
    case 7:
        printf("Enter the index at which you want to insert : ");
        scanf("%d",&i);
        start = delete_at_pos(start,i);
        break;
    case 8:
        printf("Enter the element to search  : \n");
        scanf("%d" , &i);
        search(start , i);
        break;
    case 9:
        display(start);
        break;
    case 10:
        exit(0);
        break;
      }
    }
}
