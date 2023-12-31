// inOrder traversal in binary search tree always returns ascending order sorted array
// Left child chota node hota hai
// right child bada node hota hai

// Why do we make BST?
// Searching is a lot faster in BST. Searching space keeps on decreasing n/2 every time. eg: If we are searching in 50 elements, now we are searching in 25 elements

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL; // Does not change its value for every recursive call

    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }

        prev = root;
        return isBST(root->right);
    }

    else
    {
        return 1;
    }
}

int main()
{
    struct node *p = createNode(9);
    struct node *p2 = createNode(4);
    struct node *p3 = createNode(11);
    struct node *p4 = createNode(2);
    struct node *p5 = createNode(7);
    struct node *p6 = createNode(15);
    struct node *p7 = createNode(5);
    struct node *p8 = createNode(8);
    struct node *p9 = createNode(14);

    // Finally The tree looks like this:
    //      9
    //     / \
    //    4   11
    //   / \    \
    //  2   7   15
    //     / \  /
    //    5  8 14

    p->left = p2;
    p->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->right = p6;

    p5->left = p7;
    p5->right = p8;

    p6->left = p9;

    inOrder(p);
    printf("\n");
    printf("%d ", isBST(p));

    return 0;
}