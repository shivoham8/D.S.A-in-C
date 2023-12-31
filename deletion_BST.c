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

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    struct node *inPre;

    if (root == NULL)
    {
        return NULL;
    }

    if (root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }

    // Searching for node to be deleted
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }

    if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }

    // Deletion strategy when the node is found
    else
    {
        inPre = inOrderPredecessor(root);
        root->data = inPre->data;
        root->left = deleteNode(root->left, inPre->data);
    }

    return root;
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
    deleteNode(p, 8);
    inOrder(p);

    return 0;
}