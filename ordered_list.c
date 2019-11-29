#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

typedef struct
{
   Node *head;
}Ordered_list;


Ordered_list createList(void)
{
    Ordered_list list;
    list.head = NULL;
    return list;
}

int emptyList(Ordered_list list)
{
    return (!list.head);
}

int searchList(Ordered_list list, int target)
{
    Node *cur;

    if (emptyList(list))
      return 0;

    cur = list.head;
    while(cur != NULL)
      if (cur->data == target)
         return 1;
      else
         cur = cur->link;
    return 0;
}

void insert(Ordered_list *list, int data)
{
    Node *nd, *prev, *cur;

    nd = malloc(sizeof(Node));
    nd->data = data;
    nd->link = NULL;

    if (emptyList(*list))
    {
        list->head = nd;
        return;
    }
    else
    {
        cur = list->head;
        prev = NULL;
        while(cur != NULL)
          if (cur->data < data)
          {
              prev = cur;
              cur = cur->link;
          }
          else
          {
              nd->link = cur;
              if (prev == NULL)   //nd->data < head->data and it becomes the new head
                list->head = nd;
              else
                prev->link = nd;
              return;
          }
        prev->link = nd;  //cur is NULL, meaning the data to be inserted is greater than everything in the list
        return;
    }
}


void delete(Ordered_list *list, int target)
{
    Node *prev, *cur;

    if(emptyList(*list))
    {
        printf("Cannot delete from an empty list.");
        return;
    }


    prev = NULL;
    cur = list->head;
    while((cur != NULL) && (cur->data != target))
    {
        prev = cur;
        cur = cur->link;
    }

    if(cur == NULL)
    {
        printf("%d not in the list; cannot complete delete\n", target);
    }
    else
    {
        if (prev == NULL)  //target is the head of the list
            list->head = cur->link;
         else
            prev->link = cur->link;
        free(cur);
        return;
    }
}


void printList(Ordered_list list)
{
    Node *cur=list.head;

    if(emptyList(list))
    {
        printf("An empty list; nothing to be printed.");
        return;
    }
    printf("\nThe numbers in the list in sorted order are: ");
    while(cur!=NULL)
    {
         printf("%d ", cur->data);
         cur = cur->link;
    }
    printf("\n\n");
}

int main()
{
    int num;
    Ordered_list list=createList();

    for(int i=1; i<=5; i++)
    {
        printf("Enter a number to be inserted into the list: ");
        scanf("%d", &num);
        insert(&list, num);
    }
    printList(list);

    for(int i=1; i<=3; i++)
    {
        printf("Enter a number to be deleted from the list: ");
        scanf("%d", &num);
        delete(&list, num);
    }
    printList(list);
    return 0;
}
