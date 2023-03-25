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
        printf("初始成功");
    else
        printf("没有成功");
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
    if (wr == -1) // 直接尾部插入
    {
        arr->arr[arr->size] = x;
        arr->size = arr->size + 1;
        return 1;
    }
    for (int i = wr; i < arr->size; i++) // 自定义插入
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
        printf("超出长度\n");
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
    printf("----1:初始化顺序表----\n");
    printf("----2:查找元素----\n");
    printf("----3:插入元素----\n");
    printf("----4:删除元素----\n");
    printf("----5:修改元素----\n");
    printf("----6:清空元素----\n");
    printf("----7:输出所有元素----\n");
    printf("__________________________\n");
}

int main()
{
    SeqList SL;
    int op, length, keys = 100, wo, wr; // wr位置，wo数
    while (keys)
    {
        menu();
        printf("选择\n");
        scanf("%d", &keys);
        switch (keys)
        {
        case 1:
            printf("输入初始长度\n");
            scanf("%d", &length);
            init(&SL, length);
            printf("=======================\n");
            break;
        case 2:
            printf("输入查找的元素\n");
            scanf("%d", &wo);
            if (find(&SL, wo))
                printf("%d被找到了\n", wo);
            else
                printf("%d没找到就是没有\n", wo);
            printf("=======================\n");
            break;
        case 3:
            printf("当前为  = ");
            show(&SL);
            printf("输入位置和插入元素\n");
            scanf("%d%d", &wr, &wo);
            insert(&SL, wr, wo);
            printf("插入后为  = ");
            show(&SL);
            printf("=======================\n");
            break;
        case 4:
            printf("输入你想<删>的元素\n");
            scanf("%d", &wo);
            printf("当前为   = ");
            show(&SL);
            if (find(&SL, wo))
                delete (&SL, wo);
            printf("删除后为  = ");
            show(&SL);
            printf("=======================\n");
            break;
        case 5:
            printf("输入修改位置,和元素\n");
            scanf("%d%d", &wr, &wo);
            printf("当前为    = ");
            show(&SL);
            modify(&SL, wr, wo);
            printf("修改后为   = ");
            show(&SL);
            printf("=======================\n");
        case 6:
            Destroy(&SL);
            printf("全部清空\n");
            printf("=======================\n");
        case 7:
            printf("全部输出  =");
            show(&SL);
        case 0:
            break;
        default:
            printf("输入格式不对");
        }
    }
    return 0;
}