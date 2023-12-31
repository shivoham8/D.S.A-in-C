#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int checkIfEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int checkIfFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char val)
{
    if (checkIfFull(ptr))
    {
        printf("Stack overflow!! \n");
    }

    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (checkIfEmpty(ptr))
    {
        printf("Stack underflow!! \n");
        return -1;
    }

    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;

        return val;
    }
}

int parenthesisMatch(char *exp)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 10;
    ptr->top = -1;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(ptr, '(');
        }

        else if (exp[i] == ')')
        {
            if (checkIfEmpty(ptr))
            {
                return 0;
            }
            pop(ptr);
        }
    }

    if (checkIfEmpty(ptr))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *exp = "((8(*--$$9)))";

    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching \n");
    }

    else
    {
        printf("The parenthesis is not matching \n");
    }

    return 0;
}