#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int checkIfEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int checkIfFull(struct queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (checkIfFull(q))
    {
        printf("Queue overflow!! \n");
    }

    else
    {
        q->r = (q->r + 1) % q->size; // --> Circular increment
        q->arr[q->r] = val;
        printf("Enqueuing element %d \n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (checkIfEmpty(q))
    {
        printf("Queue underflow!! \n");
        return -1;
    }

    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 3;
    q.f = q.r = 0; // --> -1 kabhi achieve ni hoga
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 2);
    enqueue(&q, 7);

    if (checkIfFull(&q))
    {
        printf("Queue is full \n");
    }

    printf("Dequeuing element %d \n", dequeue(&q));
    printf("Dequeuing element %d \n", dequeue(&q));

    if (checkIfEmpty(&q))
    {
        printf("Queue is empty \n");
    }

    if (checkIfFull(&q))
    {
        printf("Queue is full \n");
    }

    return 0;
}