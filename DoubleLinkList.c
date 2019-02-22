#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *insert_at_beginning(int data)
{
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data ;
  temp->prev = NULL;
  temp->next = NULL;
  if(head == NULL )
  {
      head =temp;
      tail = head;
  }
  else
  {
      temp->prev = NULL;
      temp->next = head;
      head->prev = temp;
      head = temp;
  }
  return head ;
}

struct node * insert_at_end(int n)
{
  struct node *p , *temp ;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = n;
  p = head;
  if(head == NULL)
  {
      head = insert_at_beginning(n);
  }
  else
  {
      temp->prev = tail;
      tail->next = temp;
      temp->next = NULL;
      tail = temp;
  }
  return head;
}


struct node* create()
{
  struct node *temp;
  int i , d , num;
  temp = (struct node*)malloc(sizeof(struct node));
  temp = NULL;
  head = temp;
  tail = temp;
  printf("List Created Successfully !! Start inserting Value !! \n");
  printf("Enter no. of nodes : ");
  scanf("%d" , &num);
  printf("\nEnter value of first node : ");
  scanf("%d" , &d);
  insert_at_beginning(d);
  for(i = 1 ; i< num ; i++)
  {
      printf("\nEnter value of %d node : " , i+1);
      scanf("%d" , &d);
      insert_at_end(d);

  }
  return head ;
}



struct node * insert_at_mid(int i,int d)
{
  struct node *p , *temp ;
  int count =1;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = d;
  p = head;
  if(i==1)
    head = insert_at_beginning(d);
  else
    {
     while(count!= (i-1)  && p != tail )
      {
        p = p->next ;
        count++;
      }
      if( p == tail)
      {
          printf("\n\nInserting it at the END.\n\n");
          head = insert_at_end(d);
      }
      else
      {
          temp->prev = p;
          temp->next = p->next;
          p->next -> prev = temp;
          p->next = temp;
      }
    }
  return head ;
}

struct node *delete_at_beginning()
{

  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp = head;
  if(temp == NULL)
  {
      printf("\n\nCannot be deleted \n\n");
  }
  else
  {
      temp = head->next;
      temp->prev = NULL;
      head = temp;
  }
  return head;
}

struct node * delete_at_end()
{
  tail =tail->prev;
  tail->next = NULL;
  return head;
}

struct node * delete_at_mid(int i)
{
  struct node *p , *temp ;
  int count =1;
  temp = (struct node*)malloc(sizeof(struct node));

  p = head;
  if(i==1)
    head = delete_at_beginning();
  else
     {
     while(count!= (i-1)  && p != tail )
      {
        p = p->next ;
        count++;
      }
      if( p == tail )
      {
          printf("\n\nDeleting it from the END.\n\n");
          head = delete_at_end();
      }
      else
      {
          p->next =p->next->next;
          p->next->prev = p;
      }
    }
  return head ;
}

void display(struct node *head)
{
    struct node *p ;
    printf("\t------------------------------------------------\t\n");
    printf("\n\t\tList is : ");
    p = head;
    if(p != NULL)
    {
              printf("  %d  ",p->data);
              while(p->next!= NULL)
                {
                    p = p->next ;
                    printf("%d  ",p->data);

                }
    }


    printf("\n\t------------------------------------------------\t\n");
}
void display_reverse(struct node *tail)
{
    struct node *p ;
    printf("\t------------------------------------------------\t\n");
    printf("\n\t\tList is : ");
    p = tail;
    if(p != NULL)
    {
              printf("  %d  ",p->data);
              while(p->prev!= NULL)
                {
                    p = p->prev ;
                    printf("%d  ",p->data);

                }
    }


    printf("\n\t------------------------------------------------\t\n");
}
void search(struct node *head , int element)
{  int flag = 1;
    struct node *p ;
    int count = 1;
    p =head;
    while(p!=NULL)
    {
        if(p->data==element)
        {
          printf("Element found at %d position\n" , count);
          flag = 0;
          return;
        }
        p = p->next;
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
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    int choice , d , i;
    while(1)
    {
      printf("1. Create list\n");
      printf("2. Add at end of the list \n");
      printf("3. Add at beginning of list\n");
      printf("4. Add at some index of list\n");
      printf("5. Delete at end of the list \n");
      printf("6. Delete at beginning of list\n");
      printf("7. Delete at some index  of list\n");
      printf("8. Display list\n");
      printf("9. Displaying list in reverse order\n");
      printf("10. Search in List\n");
      printf("11. Quit\n");
      scanf("%d" , &choice);
      switch(choice)
      {
    case 1:
        head=create();
        break;
    case 2:
        printf("Enter the data : ");
        scanf("%d",&d);
        head = insert_at_end(d);
        break;
    case 3:
        printf("Enter the data : ");
        scanf("%d",&d);
        head = insert_at_beginning(d);
        break;
    case 4:
        printf("Enter the index at which you want to insert : ");
        scanf("%d",&i);
        printf("Enter the data: ");
        scanf("%d",&d);
        head = insert_at_mid(i,d);
        break;
    case 5:
        head = delete_at_end();
        break;
    case 6:
        head = delete_at_beginning();
        break;
    case 7:
        printf("Enter the index at which you want to insert : ");
        scanf("%d",&i);
        head = delete_at_mid(i);
        break;
    case 8:
        display(head);
        break;
    case 9:
        display_reverse(tail);
        break;
    case 10:
        printf("\n Enter Element to Search : ");
        scanf("%d" , &d);
        search(head , d);
       break;
    case 11:
        exit(0);
        break;
      }
    }


}

