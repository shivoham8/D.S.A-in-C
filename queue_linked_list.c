#include <stdio.h>
#include <stdlib.h>
 
// Global variable bana diya kyuki front or rare ki copy ja rahi thi function ko or kuch change nahi ho raha tha enqueue or dequeue mei 
struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Queue is full \n");
    }

    else
    {
        ptr->data = val;
        ptr->next = NULL;
        if (f == NULL)
        {
            f = r = ptr;
        }
        else
        {
            r->next = ptr;
            r = ptr;
        }
    }
}

int dequeue()
{
    int val = -1;
    if (f == NULL)
    {
        printf("Queue is empty \n");
        return -1;
    }

    else
    {
        struct node *ptr = f;
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);

    return 0;
}