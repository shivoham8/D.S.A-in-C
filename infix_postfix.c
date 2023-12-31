#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

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

int precedence(char ch)
{
    if (ch == '(' || ch == ')')
    {
        return 4;
    }

    if (ch == '*' || ch == '/')
    {
        return 3;
    }

    if (ch == '+' || ch == '-')
    {
        return 2;
    }

    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

char *infixToPostfix(char *infix)
{
    // Initializing the stack
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char));
    // Creating postfix character with size equal to that of infix
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    // Creating counter to run loops
    int i = 0; // --> Tracks infix traversal
    int j = 0; // --> Tracks postfix addition

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }

        else
        {
            if (precedence(infix[i]) > precedence(stackTop(ptr)))
            {
                push(ptr, infix[i]);
                i++;
            }

            else
            {
                postfix[j] = pop(ptr);
                j++;
            }
        }
    }
    while (!checkIfEmpty(ptr))
    {
        postfix[j] = pop(ptr);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *infix = "p-q-r/a";
    printf("Postfix is %s", infixToPostfix(infix));

    return 0;
}