#include <stdio.h>
#include <stdlib.h>

typedef char Element;
typedef struct BTNode
{
    Element val;
    struct BTNode *lChild, *rChild;
} BTNode;
typedef struct BinaryTree
{
    struct BTNode *root;
} BinaryTree;

int Max(int a, int b)
{
    return a > b ? a : b;
}

void CreateBinaryTree(BinaryTree *bt)
{
    bt->root = NULL;
}

BTNode *NewNode(const Element *element, BTNode *l, BTNode *r)
{
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->val = *element;
    node->lChild = l;
    node->rChild = r;
    return node;
}

void MakeTree(BinaryTree *bt, Element element, BinaryTree *l, BinaryTree *r)
{
    if (bt->root || l == r)
        return;
    bt->root = NewNode(&element, l->root, r->root);
    l->root = r->root = NULL;
}

void PreOrder(const BTNode *node)
{
    if (node == NULL)
        return;
    printf("%c ", node->val);
    PreOrder(node->lChild);
    PreOrder(node->rChild);
}

void PreOrderTree(const BinaryTree *bt)
{
    if (!bt->root)
        return;
    PreOrder(bt->root);
    puts("");
}

void InOrder(const BTNode *node)
{
    if (node == NULL)
        return;
    InOrder(node->lChild);
    printf("%c ", node->val);
    InOrder(node->rChild);
}

void InOrderTree(const BinaryTree *bt)
{
    if (!bt->root)
        return;
    InOrder(bt->root);
    puts("");
}

void PostOrder(const BTNode *node)
{
    if (!node)
        return;
    PostOrder(node->lChild);
    PostOrder(node->rChild);
    printf("%c ", node->val);
}

void PostOrderTree(const BinaryTree *bt)
{
    if (!bt->root)
        return;
    PostOrder(bt->root);
    puts("");
}

int NodeSum(const BTNode *node)
{
    if (!node)
        return 0;
    return NodeSum(node->lChild) + NodeSum(node->rChild) + 1;
}

int TreeNodeSum(const BinaryTree *bt)
{
    if (!bt->root)
        return 0;
    return NodeSum(bt->root);
}

int Depth(const BTNode *node)
{
    if (!node)
        return 0;
    return Max(Depth(node->lChild), Depth(node->rChild)) + 1;
}

int TreeDepth(const BinaryTree *bt)
{
    if (!bt->root)
        return 0;
    return Depth(bt->root);
}

int LeafNodeSum(const BTNode *node)
{
    if (!node)
        return 0;
    if (!node->lChild && !node->rChild)
        return 1;
    return LeafNodeSum(node->lChild) + LeafNodeSum(node->rChild);
}

int TreeLeafNodeSum(const BinaryTree *bt)
{
    if (!bt->root)
        return 0;
    return LeafNodeSum(bt->root);
}

void Exchange(BTNode *node)
{
    if (!node)
        return;
    if (node->lChild || node->rChild)
    {
        BTNode *tmp = node->lChild;
        node->lChild = node->rChild;
        node->rChild = tmp;
    }
}

void TreeExchange(const BinaryTree *bt)
{
    if (!bt->root)
        return;
    Exchange(bt->root);
}

int main()
{
    BinaryTree a, b, x, y, z;
    CreateBinaryTree(&a);
    CreateBinaryTree(&b);
    CreateBinaryTree(&x);
    CreateBinaryTree(&y);
    CreateBinaryTree(&z);
    MakeTree(&y, 'E', &a, &b);
    MakeTree(&z, 'F', &a, &b);
    MakeTree(&x, 'C', &y, &z);
    MakeTree(&y, 'D', &a, &b);
    MakeTree(&z, 'B', &y, &x);

    puts("PreOrder:");
    PreOrderTree(&z);
    puts("InOrder:");
    InOrderTree(&z);
    puts("PostOrder:");
    PostOrderTree(&z);

    printf("NodeSum:\t%d\n", TreeNodeSum(&z));
    printf("Depth:\t%d\n", TreeDepth(&z));
    printf("LeafNodeSum:\t%d\n", TreeLeafNodeSum(&z));

    puts("");

    puts("Exchange:");
    TreeExchange(&z);

    puts("PreOrder:");
    PreOrderTree(&z);
    puts("InOrder:");
    InOrderTree(&z);
    puts("PostOrder:");
    PostOrderTree(&z);

    return 0;
}