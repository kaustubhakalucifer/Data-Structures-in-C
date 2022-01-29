#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_list(struct node *start);
struct node *insert_at_start(struct node *start, int data);
void insert_at_end(struct node *start, int data);
void display_list(struct node *start);

int main()
{
    int choice;
    struct node *start = NULL;
    start = create_list(start);
    while (1)
    {
        printf("\n1. Display list.");
        printf("\nEnter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display_list(start);
            break;
        }
    }
    return 0;
}

struct node *create_list(struct node *start)
{
    int data, total_nodes;
    printf("\nEnter total number of elements: ");
    scanf("%d", &total_nodes);
    if (total_nodes <= 0)
        return start;
    printf("\nEnter value 1: ");
    scanf("%d", &data);
    start = insert_at_start(start, data);
    for (int i = 2; i <= total_nodes; i++)
    {
        printf("\nEnter value %d: ",i);
        scanf("%d", &data);
        insert_at_end(start, data);
    }
    return start;
}

struct node *insert_at_start(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = start;
    start = temp;
    return start;
}

void insert_at_end(struct node *start, int data)
{
    struct node *temp, *p;
    p = start;
    while (p->next != NULL)
        p = p->next;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    p->next = temp;
}

void display_list(struct node *start)
{
    struct node *p;
    p = start;
    printf("\nList is -> ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}