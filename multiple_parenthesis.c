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

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }

    if (a == '{' && b == '}')
    {
        return 1;
    }

    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(ptr, exp[i]);
        }

        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (checkIfEmpty(ptr))
            {
                return 0;
            }
            popped_ch = pop(ptr);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
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
    char *exp = "[4-6]((8){(9-8)})";

    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is balanced");
    }
    else
    {
        printf("The parenthesis is not balanced");
    }

    return 0;
}