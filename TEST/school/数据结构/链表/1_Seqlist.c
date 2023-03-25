// HeaderList.c:带表头结点的单链表的实现
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2   // Overflow 表示上溢
#define Underflow 3  // Underflow 表示下溢
#define NotPresent 4 // NotPresent 表示元素不存在
#define Duplicate 5  // Duplicate 表示有重复元素
typedef int Status;
typedef int ElemType;
typedef struct Node // 结点数据结构
{
    ElemType element;  // 结点的数据域
    struct Node *link; // 结点的指针域
} Node;

typedef struct
{
    Node *head;
    int n;
} HeaderList;

Status Init(HeaderList *h)
{
    h->head = (Node *)malloc(sizeof(Node));
    if (!h->head)
        return ERROR;
    h->head->link = NULL;
    h->n = 0;
    return OK;
}

Status Find(HeaderList h, int i, ElemType *x)
{
    Node *p;
    int j;
    if (i < 0 || i > h.n - 1) // 对i 进行越界检查
        return ERROR;
    p = h.head;
    for (j = 0; j <= i; j++) // 多循环一次
        p = p->link;         // 从头结点开始查找ai
    *x = p->element;         // 通过x 返回ai的值
    return OK;
}

Status Insert(HeaderList *h, int i, ElemType x)
{
    Node *p, *q;
    int j;
    if (i < -1 || i > h->n - 1)
        return ERROR;
    p = h->head;

    // 从头结点开始查找
    for (j = 0; j <= i; j++)
        p = p->link;

    // 生成新结点q
    q = (Node *)malloc(sizeof(Node));
    q->element = x;
    q->link = p->link;
    p->link = q;
    h->n++;
    return OK;
}

Status Delete(HeaderList *h, int i)
{
    int j;
    Node *p, *q;
    if (!h->n)
        return ERROR;
    if (i < 0 || i > h->n - 1)
        return ERROR;
    q = h->head;
    p = h->head;
    for (j = 0; j < i; j++) // q停止在待删除结点的前一个位置
        q = q->link;
    p = q->link;       // p 指向第i+1个结点，即待删除的结点处
    q->link = p->link; // 脱链
    free(p);           // 释放p 结点的存储空间
    h->n--;
    return OK;
}

Status reverse(HeaderList *h) // 带表头结点的单链表的逆置
{
    Node *p;
    if (!h->n) // 判断链表是否为空
        return ERROR;
    p = h->head->link;    // p指向第一个结点处
    h->head->link = NULL; // 头结点的指针域为空
    while (p)
    {
        Node *q = p->link;       // q指向待逆转结点的下一个结点处
        p->link = h->head->link; // p结点的指针调转方向‎
        h->head->link = p;       // 头指针的link域指向已经调整好的局部链表的第一个结点位置‎
        p = q;                   // 准备处理下一个结点‎
    }
    return OK;
}

Status Output(HeaderList *h)
{
    Node *p;
    if (!h->n) // 判断链表是否为空
        return ERROR;
    printf("Print all elements:\n");
    p = h->head->link; // 这条语句变了
    while (p)
    {
        printf("%d ", p->element);
        p = p->link;
    }
    printf("\n");
    return OK;
}

void Destroy(HeaderList *h)
{
    Node *p;
    while (h->head)
    {
        p = h->head->link;
        free(h->head);
        h->head = p;
    }
    h->n = 0;
}
/*
int main()
{
    int i, x;
    HeaderList list;
    Init(&list); //对链表初始化
    for (i = 0; i < 10; i++)
        Insert(&list, i - 1, i);    //链表中插入新元素
    printf("the linklist is:");
    Output(&list);
    Delete(&list, 0);
    printf("\nthe linklist is:");
    Output(&list);
    Find(list, 0, &x);
    printf("\nthe value is:");
    printf("%d ", x);
    Destroy(&list);
    return 0;
}
*/

void menu()
{
    printf("----1:初始化带表头结点的单链表----\n");
    printf("----2:插入元素----\n");
    printf("----3:查找元素----\n");
    printf("----4:删除元素----\n");
    printf("----5:输出所有元素----\n");
    printf("----6:链表逆置----\n");
    printf("----7:撤销链表----\n");
    printf("----0:退出程序----\n");
}

int main()
{
    int choice, pos, elem;
    HeaderList list;
    do
    {
        menu();
        printf("Please input one choice(0--6)\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Init(&list); // 对链表进行初始化
            break;
        case 2:
            printf("Please input position and element:\n");
            scanf("%d%d", &pos, &elem);
            if (!Insert(&list, pos, elem))
                printf("no space or error position!\n"); // 线性表中插入新元素
            break;
        case 3:
            printf("Please input position found:\n");
            scanf("%d", &pos);
            if (Find(list, pos, &elem))
                printf("the element is:%d\n", elem);
            else
                printf("the position does not exist\n");
            break;
        case 4:
            printf("Please input position found:\n");
            scanf("%d", &pos);
            if (Delete(&list, pos))
                printf("one element is deleted!\n");
            else
                printf("no element is deleted!\n");
            break;
        case 5:
            if (!Output(&list))
                printf("HeaderList is empty!\n");
            break;
        case 6:
            reverse(&list);
            break;
        case 7:
            Destroy(&list);
            printf("the list is destroyed!\n");
            break;
        case 0:
            break;
        default:
            printf("error input!\n");
        }
    } while (choice);
    return 0;
}
