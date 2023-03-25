#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int maxsize;
    int *arr;
} SeqList;

void init(SeqList *list, int n)
{
    list->maxsize = n;
    list->size = 0;
    list->arr = (int *)malloc(sizeof(int) * n);
    if (list->arr)
        printf("��ʼ�ɹ�");
    else
        printf("û�гɹ�");
}

int find(SeqList *arr, int x)
{
    for (int i = 0; i < arr->size; i++)
    {
        if (arr->arr[i] == x)
            return i + 1;
    }
    return 0;
}

int insert(SeqList *arr, int wr, int x)
{
    if ((arr->maxsize == arr->size) || wr >= arr->maxsize)
    {
        return 0;
    }
    if (wr == -1) // ֱ��β������
    {
        arr->arr[arr->size] = x;
        arr->size = arr->size + 1;
        return 1;
    }
    for (int i = wr; i < arr->size; i++) // �Զ������
    {
        arr->arr[i + 1] = arr->arr[i];
    }
    arr->arr[wr] = x;
    arr->size = arr->size + 1;
}

void show(SeqList *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->arr[i]);
    }
    printf("\n");
}

void modify(SeqList *arr, int wr, int x)
{
    if (wr >= arr->maxsize)
    {
        printf("��������\n");
        return;
    }
    arr->arr[wr] = x;
}

void delete(SeqList *arr, int x)
{
    for (int i = find(arr, x); i < arr->size; i++)
    {
        arr->arr[i] = arr->arr[i - 1];
    }
    arr->size = arr->size - 1;
}

void Destroy(SeqList *arr)
{
    arr->size = 0;
    arr->maxsize = 0;
    free(arr->arr);
}
void menu()
{
    printf("__________________________\n");
    printf("----1:��ʼ��˳���----\n");
    printf("----2:����Ԫ��----\n");
    printf("----3:����Ԫ��----\n");
    printf("----4:ɾ��Ԫ��----\n");
    printf("----5:�޸�Ԫ��----\n");
    printf("----6:���Ԫ��----\n");
    printf("----7:�������Ԫ��----\n");
    printf("__________________________\n");
}

int main()
{
    SeqList SL;
    int op, length, keys = 100, wo, wr; // wrλ�ã�wo��
    while (keys)
    {
        menu();
        printf("ѡ��\n");
        scanf("%d", &keys);
        switch (keys)
        {
        case 1:
            printf("�����ʼ����\n");
            scanf("%d", &length);
            init(&SL, length);
            printf("=======================\n");
            break;
        case 2:
            printf("������ҵ�Ԫ��\n");
            scanf("%d", &wo);
            if (find(&SL, wo))
                printf("%d���ҵ���\n", wo);
            else
                printf("%dû�ҵ�����û��\n", wo);
            printf("=======================\n");
            break;
        case 3:
            printf("��ǰΪ  = ");
            show(&SL);
            printf("����λ�úͲ���Ԫ��\n");
            scanf("%d%d", &wr, &wo);
            insert(&SL, wr, wo);
            printf("�����Ϊ  = ");
            show(&SL);
            printf("=======================\n");
            break;
        case 4:
            printf("��������<ɾ>��Ԫ��\n");
            scanf("%d", &wo);
            printf("��ǰΪ   = ");
            show(&SL);
            if (find(&SL, wo))
                delete (&SL, wo);
            printf("ɾ����Ϊ  = ");
            show(&SL);
            printf("=======================\n");
            break;
        case 5:
            printf("�����޸�λ��,��Ԫ��\n");
            scanf("%d%d", &wr, &wo);
            printf("��ǰΪ    = ");
            show(&SL);
            modify(&SL, wr, wo);
            printf("�޸ĺ�Ϊ   = ");
            show(&SL);
            printf("=======================\n");
        case 6:
            Destroy(&SL);
            printf("ȫ�����\n");
            printf("=======================\n");
        case 7:
            printf("ȫ�����  =");
            show(&SL);
        case 0:
            break;
        default:
            printf("�����ʽ����");
        }
    }
    return 0;
}