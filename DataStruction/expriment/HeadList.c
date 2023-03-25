// HeaderList.c:带表头结点的单链表的实现
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int element;
    struct Node *link;
} Node;

typedef struct
{
    Node *head;
    int n;
} HeadList;

void init(HeadList *HL)
{
    HL->head = (Node *)malloc(sizeof(Node));
    if (!HL->head)
    {
        printf("初始失败\n");
    }
    else
    {
        printf("初始成功\n");
        HL->head->link = NULL;
        HL->n = 0;
    }
}
int insert(HeadList *h, int i, int x)
{
    Node *p, *q;
    int j;
    if (i < -1 || i > h->n - 1)
        return 0;
    p = h->head;

    for (j = 0; j <= i; j++)
        p = p->link;
    q = (Node *)malloc(sizeof(Node));
    q->element = x;
    q->link = p->link;
    p->link = q;
    h->n++;
    printf("< %d >插入成功\n", x);
    return 1;
}

int find(HeadList *HL, int x)
{
    Node *P;
    int j = 0;
    P = HL->head;
    int key = 0;
    while (P)
    {
        if (P->element == x)
        {
            key = 1;
            printf("< %d >被找到了\n", x);
            return j;
        }
        P = P->link;
        j++;
    }
    if (key)
        ;
    else
    {
        printf("< %d >没有被找到\n", x);
        return -1;
    }
}

void modify(HeadList *HL, int a, int x)
{
    Node *p;
    p = HL->head;
    while (p)
    {
        if (p->element == a)
        {
            p->element = x;
            printf("该值< %d >已经被修改为< %d >\n", a, x);
            return;
        }
        p = p->link;
    }
    printf("没有< %d >该元素,修改不成功\n", a);
}

void out(HeadList *HL, int x)
{
    Node *p, *temp;
    temp = HL->head;
    p = HL->head;
    int j = find(HL, x);
    printf("j=%d\n", j);
    printf("n=%d\n", HL->n);
    if (j < 1 || j > HL->n)
    {
        // printf("你有运行\n");
        printf("没有查找< %d >到该元素\n", x);
        return;
    }
    for (int i = 1; i <= j - 1; i++)
    {
        p = p->link;
        temp = temp->link;
        // printf("ele=%d\n", p->element);
    }
    temp = temp->link;
    // printf("temp=%d", temp->element);
    p->link = temp->link;
    free(temp);
    printf("删除< %d >该元素成功\n", x);
}

void show(HeadList *HL)
{
    Node *p;
    p = HL->head->link;
    printf("链表 = ");
    while (p)
    {
        printf("%d ", p->element);
        p = p->link;
    }
    printf("\n");
    return;
}
void clear(HeadList *HL)
{
    Node *p;
    while (HL->head)
    {
        p = HL->head->link;
        free(HL->head);
        HL->head = p;
    }
    HL->n = 0;
}

void sort(HeadList *HL)
{
    int arr[100];
    Node *p;
    int i = 0;
    p = HL->head->link;
    while (p)
    {
        arr[i++] = p->element;
        p = p->link;
    }
    if (SortFun(arr, 0, i - 1))
        printf("链表排序成功\n");
    p = HL->head->link;
    i = 0;
    while (p)
    {

        p->element = arr[i++];
        p = p->link;
    }
}

int SortFun(int arr[], int l, int r)
{
    if (l >= r)
        return 1;
    int i = l;
    int j = r;
    int mid = arr[(l + r) / 2];
    while (i <= j)
    {
        while (arr[i] < mid)
            i++;
        while (arr[j] > mid)
            j--;
        if (i <= j)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j--;
        }
    }
    SortFun(arr, l, j);
    SortFun(arr, i, r);
}

void reverse(HeadList *HL)
{
    Node *p;
    if (!HL->n)
        return;
    p = HL->head->link;
    HL->head->link = NULL;
    while (p)
    {
        Node *q = p->link;
        p->link = HL->head->link;
        HL->head->link = p;
        p = q;
    }
}
void menu()
{
    printf("________________________\n");
    printf("       1初始化链表       \n");
    printf("       2插入新元素       \n");
    printf("       3查找某元素       \n");
    printf("       4修改某元素       \n");
    printf("       5清空全元素       \n");
    printf("       6排序全元素       \n");
    printf("       7逆置全元素       \n");
    printf("       0退出菜单栏       \n");
    printf("________________________\n");
}

int main()
{
    HeadList HL;
    int op = 100, adress, value, value1;
    while (op)
    {
        menu();
        printf("选择功能\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            init(&HL);
            break;
        case 2:
            printf("输入插入位置和数字。< -1 >代表头部插入\n");
            scanf("%d%d", &adress, &value);
            insert(&HL, adress, value);
            show(&HL);
            break;
        case 3:
            printf("输入查找数字。\n");
            scanf("%d", &value);
            find(&HL, value);
            break;
        case 4:
            printf("输入修改的元素和元素1...(前为被修改，后为修改为).\n");
            scanf("%d%d", &value, &value1);
            modify(&HL, value, value1);
            show(&HL);
            break;
        case 5:
            printf("清空\n");
            clear;
            break;
        case 6:
            printf("排序\n");
            printf("排序前===》");
            show(&HL);
            sort(&HL);
            printf("排序后===》");
            show(&HL);
            break;
        case 7:
            printf("逆置\n");
            printf("逆置前===》");
            show(&HL);
            reverse(&HL);
            printf("逆置后===》");
            show(&HL);
            break;
        case 0:
            printf("已经推出\n");
            break;
        default:
            printf("错误输入.\n");
            break;
        }
    }
    return 0;
}

// int main()
// {
//     HeadList HL;
//     init(&HL);
//     insert(&HL, -1, 3);
//     insert(&HL, 0, 8);
//     insert(&HL, 0, 5);
//     insert(&HL, 0, 7);
//     show(&HL);
//     find(&HL, 5);
//     show(&HL);
//     // // clear(&HL);
//     // insert(&HL, 0, 7);
//     sort(&HL);
//     // reverse(&HL);
//     show(&HL);
//     return 0;
// }
