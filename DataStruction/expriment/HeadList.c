// HeaderList.c:����ͷ���ĵ������ʵ��
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
        printf("��ʼʧ��\n");
    }
    else
    {
        printf("��ʼ�ɹ�\n");
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
    printf("< %d >����ɹ�\n", x);
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
            printf("< %d >���ҵ���\n", x);
            return j;
        }
        P = P->link;
        j++;
    }
    if (key)
        ;
    else
    {
        printf("< %d >û�б��ҵ�\n", x);
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
            printf("��ֵ< %d >�Ѿ����޸�Ϊ< %d >\n", a, x);
            return;
        }
        p = p->link;
    }
    printf("û��< %d >��Ԫ��,�޸Ĳ��ɹ�\n", a);
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
        // printf("��������\n");
        printf("û�в���< %d >����Ԫ��\n", x);
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
    printf("ɾ��< %d >��Ԫ�سɹ�\n", x);
}

void show(HeadList *HL)
{
    Node *p;
    p = HL->head->link;
    printf("���� = ");
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
        printf("��������ɹ�\n");
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
    printf("       1��ʼ������       \n");
    printf("       2������Ԫ��       \n");
    printf("       3����ĳԪ��       \n");
    printf("       4�޸�ĳԪ��       \n");
    printf("       5���ȫԪ��       \n");
    printf("       6����ȫԪ��       \n");
    printf("       7����ȫԪ��       \n");
    printf("       0�˳��˵���       \n");
    printf("________________________\n");
}

int main()
{
    HeadList HL;
    int op = 100, adress, value, value1;
    while (op)
    {
        menu();
        printf("ѡ����\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            init(&HL);
            break;
        case 2:
            printf("�������λ�ú����֡�< -1 >����ͷ������\n");
            scanf("%d%d", &adress, &value);
            insert(&HL, adress, value);
            show(&HL);
            break;
        case 3:
            printf("����������֡�\n");
            scanf("%d", &value);
            find(&HL, value);
            break;
        case 4:
            printf("�����޸ĵ�Ԫ�غ�Ԫ��1...(ǰΪ���޸ģ���Ϊ�޸�Ϊ).\n");
            scanf("%d%d", &value, &value1);
            modify(&HL, value, value1);
            show(&HL);
            break;
        case 5:
            printf("���\n");
            clear;
            break;
        case 6:
            printf("����\n");
            printf("����ǰ===��");
            show(&HL);
            sort(&HL);
            printf("�����===��");
            show(&HL);
            break;
        case 7:
            printf("����\n");
            printf("����ǰ===��");
            show(&HL);
            reverse(&HL);
            printf("���ú�===��");
            show(&HL);
            break;
        case 0:
            printf("�Ѿ��Ƴ�\n");
            break;
        default:
            printf("��������.\n");
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
