#include <stdio.h>
#include <stdlib.h>

struct node *create_list(struct node *start);
struct node *insert_in_beginning(struct node *start, int data);
void insert_at_end(struct node *start, int data);
void display_list(struct node *start);
void total_nodes(struct node *start);

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int choice;
    struct node *start = NULL;
    start = create_list(start);
    while(1) {
        printf("\n1. Display list.");
        printf("\n2. Count total nodes");
        printf("\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1: display_list(start); break;
            case 2: total_nodes(start); break;
        }
    }
    return 0;
}

struct node *create_list(struct node *start)
{
    printf("\nEnter total number of nodes: ");
    int total_nodes, data;
    scanf("%d", &total_nodes);
    // Check if n is not less than equal to zero
    if (total_nodes <= 0)
    {
        return start;
    }
    printf("\nEnter element 1: ");
    scanf("%d", &data);
    start = insert_in_beginning(start, data);
    for (int i = 2; i <= total_nodes; i++)
    {
        printf("\nEnter element %d : ",i);
        scanf("%d",&data);
        insert_at_end(start, data);
    }
    return start;
}

struct node *insert_in_beginning(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = start;
    start = temp;
    return start;
}

void insert_at_end(struct node *start, int data) {
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    p = start;
    while(p->next != NULL) {
        p=p->next;
    }
    p->next=temp;
    temp->next=NULL;
}

void display_list(struct node *start) {
    struct node *p;
    p = start;
    printf("\n List is -> ");
    while(p != NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

void total_nodes(struct node *start) {
    struct node *p;
    int counter;
    p = start;
    while(p->next != NULL) {
        counter++;
        p = p->next;
    }
    printf("\nTotal number of nodes: %d",counter);
}