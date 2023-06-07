// HeaderList.c:����ͷ���ĵ������ʵ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2   // Overflow ��ʾ����
#define Underflow 3  // Underflow ��ʾ����
#define NotPresent 4 // NotPresent ��ʾԪ�ز�����
#define Duplicate 5  // Duplicate ��ʾ���ظ�Ԫ��
typedef int Status;
typedef int ElemType;
typedef struct Node // ������ݽṹ
{
    ElemType element;  // ����������
    struct Node *link; // ����ָ����
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
    if (i < 0 || i > h.n - 1) // ��i ����Խ����
        return ERROR;
    p = h.head;
    for (j = 0; j <= i; j++) // ��ѭ��һ��
        p = p->link;         // ��ͷ��㿪ʼ����ai
    *x = p->element;         // ͨ��x ����ai��ֵ
    return OK;
}

Status Insert(HeaderList *h, int i, ElemType x)
{
    Node *p, *q;
    int j;
    if (i < -1 || i > h->n - 1)
        return ERROR;
    p = h->head;

    // ��ͷ��㿪ʼ����
    for (j = 0; j <= i; j++)
        p = p->link;

    // �����½��q
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
    for (j = 0; j < i; j++) // qֹͣ�ڴ�ɾ������ǰһ��λ��
        q = q->link;
    p = q->link;       // p ָ���i+1����㣬����ɾ���Ľ�㴦
    q->link = p->link; // ����
    free(p);           // �ͷ�p ���Ĵ洢�ռ�
    h->n--;
    return OK;
}

Status reverse(HeaderList *h) // ����ͷ���ĵ����������
{
    Node *p;
    if (!h->n) // �ж������Ƿ�Ϊ��
        return ERROR;
    p = h->head->link;    // pָ���һ����㴦
    h->head->link = NULL; // ͷ����ָ����Ϊ��
    while (p)
    {
        Node *q = p->link;       // qָ�����ת������һ����㴦
        p->link = h->head->link; // p����ָ���ת����6�0
        h->head->link = p;       // ͷָ���link��ָ���Ѿ������õľֲ�����ĵ�һ�����λ�Á6�0
        p = q;                   // ׼��������һ�����6�0
    }
    return OK;
}

Status Output(HeaderList *h)
{
    Node *p;
    if (!h->n) // �ж������Ƿ�Ϊ��
        return ERROR;
    printf("Print all elements:\n");
    p = h->head->link; // ����������
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
    Init(&list); //�������ʼ��
    for (i = 0; i < 10; i++)
        Insert(&list, i - 1, i);    //�����в�����Ԫ��
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
    printf("----1:��ʼ������ͷ���ĵ�����----\n");
    printf("----2:����Ԫ��----\n");
    printf("----3:����Ԫ��----\n");
    printf("----4:ɾ��Ԫ��----\n");
    printf("----5:�������Ԫ��----\n");
    printf("----6:��������----\n");
    printf("----7:��������----\n");
    printf("----0:�˳�����----\n");
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
            Init(&list); // ��������г�ʼ��
            break;
        case 2:
            printf("Please input position and element:\n");
            scanf("%d%d", &pos, &elem);
            if (!Insert(&list, pos, elem))
                printf("no space or error position!\n"); // ���Ա��в�����Ԫ��
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
