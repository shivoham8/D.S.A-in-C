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
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueueR(struct queue *q, int val)
{
    if (checkIfFull(q))
    {
        printf("Queue is full \n");
    }

    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueuing element %d \n", val);
    }
}

void enqueueF(struct queue *q, int val)
{
    if (checkIfFull(q))
    {
        printf("Queue is full \n");
    }

    else
    {
        q->arr[q->f] = val;
        q->f--;
        printf("Enqueuing element %d \n", val);
    }
}

int dequeueF(struct queue *q)
{
    int val = -1;
    if (checkIfEmpty(q))
    {
        printf("Queue is empty \n");
        return -1;
    }

    else
    {
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

int dequeueR(struct queue *q)
{
    int val = -1;
    if (checkIfEmpty(q))
    {
        printf("Queue is empty \n");
        return -1;
    }

    else
    {
        val = q->arr[q->r];
        q->r--;
    }
    return val;
}

int main()
{
    struct queue q;
    q.size = 2;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueueR(&q, 2);
    enqueueF(&q, 7);
    enqueueR(&q, 11);

    printf("Dequeuing element %d \n", dequeueF(&q));
    printf("Dequeuing element %d \n", dequeueR(&q));
    printf("Dequeuing element %d \n", dequeueR(&q));

    return 0;
}