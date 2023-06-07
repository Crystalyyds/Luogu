#include <stdio.h>
#include <math.h>
#define MaxSize 10
typedef int KeyType;
typedef struct entry // 数据元素
{
    KeyType key; // 排序关键字，KeyType为可比较类型
    //	DataType data;       //data包含数据元素中的其他数据项
} Entry;
typedef struct list // 顺序表
{
    int n;            // 待排序数据元素数量
    Entry D[MaxSize]; // 静态数组存储数据元素
} List;

void ReadIn(List *list, int n)
{
    int i;
    printf("Please input %d keys:\n", n);
    list->n = n;
    for (i = 0; i < list->n; i++)
        scanf("%d", &list->D[i].key);
}

void Output(List *list, int n) // 输出list中前n个元素
{
    int i;
    for (i = 0; i < n; i++)
        printf("%6d", list->D[i].key);
    printf("\n");
}

int FindMin(List list, int startIndex) // 寻找startIndex...n-1下标之间最小关键字值元素下标并返回
{
    int i, minIndex = startIndex;
    for (i = startIndex + 1; i < list.n; i++)
        if (list.D[i].key < list.D[minIndex].key)
            minIndex = i;
    return minIndex;
}

void Swap(Entry *D, int i, int j) // 交换i和j下标的两个元素值
{
    Entry temp;
    if (i == j) // 同一个位置不用交换
        return;
    temp = D[i];
    D[i] = D[j];
    D[j] = temp;
}

void SelectSort(List *list) // 简单选择法排序
{
    int minIndex, startIndex = 0;
    for (; startIndex < list->n - 1; startIndex++) // 控制趟
    {
        minIndex = FindMin(*list, startIndex);
        Swap(list->D, startIndex, minIndex);
        printf("第%d趟排序结果为：", startIndex + 1); // 增加这两行，输出每趟排序结果
        Output(list, list->n);
    }
}

void InsertSort(List *list) // 直接插入排序法
{
    int i, j;
    Entry insertItem;
    for (i = 1; i < list->n; i++) // i标识待插入元素下标,趟
    {
        insertItem = list->D[i];
        for (j = i - 1; j >= 0; j--)             // 从后向前比较
        {                                        // 不断将有序序列中元素向后移动，为待插入元素空出一个位置
            if (insertItem.key < list->D[j].key) // 定位移位同时进行
                list->D[j + 1] = list->D[j];
            else
                break;
        }
        list->D[j + 1] = insertItem;     // 待插入元素放至有序序列中
        printf("第%d趟排序结果为：", i); // 增加这两行，输出每趟排序结果
        Output(list, i + 1);             // 增加这句，输出每趟的结果
    }
}

void BubbleSort(List *list) // 冒泡排序
{
    int i, j;
    for (i = list->n - 1; i > 0; i--) // 每趟排序元素下标范围是0 ~ i
    {
        int isSwap = 0;         // 标记一趟排序中是否发生交换
        for (j = 0; j < i; j++) // 比较相邻元素，i对
            if (list->D[j].key > list->D[j + 1].key)
            {
                Swap(list->D, j, j + 1);
                isSwap = 1;
            }
        printf("第%d趟排序结果:", list->n - i); // 增加这两句，输出每趟排序结果
        Output(list, list->n);
        if (!isSwap) // 若本趟排序未发生交换，则排序完成
            break;
    }
}

int Partition(List *list, int low, int high)
{
    int i = low, j = high + 1;
    Entry pivot = list->D[low]; // pivot是分割元素
    do
    {
        do
        {
            i++;
        } while (list->D[i].key < pivot.key); // i前进
        do
        {
            j--;
        } while (list->D[j].key > pivot.key); // j前进
        if (i < j)
            Swap(list->D, i, j);
    } while (i < j);
    Swap(list->D, low, j);
    return j; // 此时j是分割元素下标
}

// 快速排序算法
void QuickSort(List *list, int low, int high) // 快排递归函数
{
    int k;
    if (low < high)
    { // 当前待排序列至少包含2个元素
        k = Partition(list, low, high);
        Output(list, list->n); // 增加此句输出排序结果
        QuickSort(list, low, k - 1);
        QuickSort(list, k + 1, high);
    } // low>=high
}
void QuickSortAll(List *list) // 快速排序算法的主调用函数
{
    QuickSort(list, 0, list->n - 1);
}

void Merge(List *list, Entry *temp, int low, int n1, int n2)
{
    int i = low, j = low + n1;                          // i和j分别指向两个合并序列的第一个元素
    while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1) // 两个序列都没有结束
    {
        if (list->D[i].key <= list->D[j].key)
            *temp++ = list->D[i++];
        else
            *temp++ = list->D[j++];
    }
    while (i <= low + n1 - 1)
        *temp++ = list->D[i++]; // 前一部分剩余部分存入temp
    while (j <= low + n1 + n2 - 1)
        *temp++ = list->D[j++];
}

void MergeSort(List *list)
{
    Entry temp[MaxSize];
    int low, n1, n2, i, size = 1;
    while (size < list->n) // 趟
    {
        low = 0;
        while (low + size < list->n) // 至少存在两个子序列需要合并
        {
            n1 = size;
            if (low + size * 2 < list->n) // 确定第二个子序列的长度
                n2 = size;
            else // 第2个子串长度不足
                n2 = list->n - low - size;
            Merge(list, temp + low, low, n1, n2);
            low += n1 + n2;
        }
        for (i = 0; i < low; i++)
            list->D[i] = temp[i];
        size *= 2;             // 子序列长度翻倍
        Output(list, list->n); // 增加此句输出排序结果
    }                          // endwhile1
}

void AdjustDown(Entry heap[], int current, int border)
{
    int p = current, maxChild;
    Entry temp;
    while (2 * p + 1 <= border) // p不是叶结点则调整
    {
        if ((2 * p + 2 <= border) && (heap[2 * p + 1].key < heap[2 * p + 2].key))
            maxChild = 2 * p + 2;
        else
            maxChild = 2 * p + 1;
        if (heap[p].key >= heap[maxChild].key)
            break;
        else
        {
            temp = heap[p];
            heap[p] = heap[maxChild];
            heap[maxChild] = temp;
            p = maxChild;
        }
    }
}

void HeapSort(List *hp)
{
    int i;
    Entry temp;
    for (i = (hp->n - 2) / 2; i >= 0; i--) // 调整为初始堆
        AdjustDown(hp->D, i, hp->n - 1);
    for (i = hp->n - 1; i > 0; i--) // 共n-1趟
    {
        Swap(hp->D, 0, i);                       // 交换堆顶和最后位置元素
        AdjustDown(hp->D, 0, i - 1);             // 重新调整为最大堆
        printf("第%d趟排序结果为：", hp->n - i); // 此两行为新增，输出每趟结果
        Output(hp, hp->n);
    }
}

void menu()
{
    printf("---1、输入所有关键字---\n");
    printf("---2、输出所有关键字---\n");
    printf("---3、简单选择排序---\n");
    printf("---4、直接插入排序---\n");
    printf("---5、冒泡排序---\n");
    printf("---6、快速排序---\n");
    printf("---7、两路合并排序---\n");
    printf("---8、堆排序---\n");
    printf("---0、退出---\n");
}

int main()
{
    List list, list2;
    int n, choice;

    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("input number of elements:\n");
            scanf("%d", &n);
            ReadIn(&list, n);
            list2 = list; // 用list2保留原来未排序的序列
            break;
        case 2:
            printf("now the array is :\n");
            Output(&list, list.n);
            break;
        case 3:
            list = list2;
            SelectSort(&list);
            break;
        case 4:
            list = list2;
            InsertSort(&list);
            break;
        case 5:
            list = list2;
            BubbleSort(&list);
            break;
        case 6:
            list = list2;
            QuickSortAll(&list);
            break;
        case 7:
            list = list2;
            MergeSort(&list);
            break;
        case 8:
            list = list2;
            HeapSort(&list);
            break;
        case 0:
            break;
        }

    } while (choice);
    return 0;
}
// 8
// 24  29  45  73  24  89  90  11