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

int checkIfEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int checkIfFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

struct node *push(struct node *top, int data)
{
    if (checkIfFull(top))
    {
        printf("Stack overflow!! \n");
    }

    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));

        p->data = data;
        p->next = top;
        top = p;

        return top;
    }
}

struct node *pop(struct node **top)
{
    if (checkIfEmpty(*top))
    {
        printf("Stack underflow!! \n");
    }

    else
    {
        struct node *p = *top;
        *top = (*top)->next;
        int val = p->data;
        free(p);

        return val;
    }
}

int main()
{
    struct node *top = NULL;

    top = push(top, 2);
    top = push(top, 7);
    top = push(top, 11);
    top = push(top, 17);
    top = push(top, 23);
    top = push(top, 29);

    linkedListTraversal(top);

    int element = pop(&top);
    printf("%d has been popped from the stack \n", element);
    linkedListTraversal(top);

    return 0;
}