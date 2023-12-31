#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *deleteAtFirst(struct node *head)
{
    struct node *p = head;

    head = head->next;
    free(p);

    return head;
}

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);

    return head;
}

struct node *deleteAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

struct node *deleteAtValue(struct node *head, int val)
{
    struct node *p = head;
    struct node *q = head->next;

    while (p->data != val)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 2;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 17;
    fourth->next = NULL;

    linkedListTraversal(head);

    printf("Updated linked list is: \n");

    // head = deleteAtFirst(head);

    // head = deleteAtIndex(head, 2);

    // head = deleteAtEnd(head);

    head = deleteAtValue(head, 11);
    linkedListTraversal(head);

    return 0;
}