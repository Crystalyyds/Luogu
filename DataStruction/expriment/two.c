#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    int val;
    struct BTNode *lChild, *rChild;
} BTNode;
typedef struct BinaryTree
{
    struct BTNode *root;
} BinaryTree;

void CreatNullTree(BinaryTree *tree)
{
    tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    tree->root = NULL;
    printf("???");
}

BTNode *CreateNode(int x)
{
    BTNode *p = (BTNode *)malloc(sizeof(BTNode));
    p->val = x;
    p->lChild = p->rChild = NULL;
    return p;
}

int Insert(BinaryTree *tree, int x)
{
    BTNode *p = tree->root, *q, *r;
    while (p)
    {
        q = p;
        if (x < p->val)
            p = p->lChild;
        else if (x > p->val)
            p = p->rChild;
        else
            return 0;
    }
    r = CreateNode(x);
    if (!tree->root)
    {
        tree->root = r;
        printf("?????");
    }
    else if (x < q->val)
        q->lChild = r;
    else
        q->rChild = r;
    return 1;
}

int main()
{
    BinaryTree *tree;
    CreatNullTree(tree);
    if (tree->root == NULL)
    {
        printf("454");
    }
    else
    {
        printf("232");
    }
}
