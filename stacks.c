#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int checkIfEmpty(struct stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    return 0;
}

int checkIfFull(struct stack *st)
{
    if (st->top == st->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *st, int val)
{
    if (checkIfFull(st))
    {
        printf("Stack overflow!! %d cannot be pushed to stack \n", val);
    }

    else
    {
        st->top++;
        st->arr[st->top] = val;
    }
}

int pop(struct stack *st)
{
    if (checkIfEmpty(st))
    {
        printf("Stack undeflow!! \n");
        return -1;
    }

    else
    {
        int val = st->arr[st->top];
        st->top--;

        return val;
    }
}

int peek(struct stack *st, int i) // --> Here i signifies position
{
    int arrayInd = st->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack \n");
        return -1;
    }

    else
    {
        return st->arr[arrayInd];
    }
}

int stackTop(struct stack *st)
{
    return st->arr[st->top];
}

int stackBottom(struct stack *st)
{
    return st->arr[0];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // printf("Before pushing Empty --> %d \n", checkIfEmpty(s));
    // printf("Before pushing Full --> %d \n", checkIfFull(s));

    push(s, 2);
    push(s, 7);
    push(s, 11);
    push(s, 17);
    push(s, 23);
    push(s, 29);
    push(s, 35);
    push(s, 41);
    push(s, 47);

    // printf("%d has been popped from the stack \n", pop(s));
    // printf("%d has been popped from the stack \n", pop(s));

    // printf("After pushing Empty --> %d \n", checkIfEmpty(s));
    // printf("After pushing Full --> %d \n", checkIfFull(s));

    for (int i = 1; i <= s->top + 1; i++)
    {
        printf("The value at position %d is %d \n", i, peek(s, i));
    }

    printf("\n The bottom most element of the stack is %d \n", stackBottom(s));
    printf("\n The top most element of the stack is %d \n", stackTop(s));

    return 0;
}