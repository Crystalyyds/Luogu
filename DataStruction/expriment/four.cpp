#include <stdio.h>
#include <math.h>
#include <time.h>
const int MaxSize = 1e5;
typedef int KeyType;
typedef struct entry
{
    KeyType key;
} Entry;
typedef struct list
{
    int n = 10;
    Entry D[10];
} List;

List list, list2;
int n, choice;
int arr[10] = {235, 87, 18, 43, 121, 7, 98, 66, 54, 31};

void randin(List *list, int t)
{
    list->n = t;
    for (int i = 0; i < list->n; i++)
    {
        list->D[i].key = rand();
    }
}

void ReadIn(List *list, int n)
{
    int i;
    // printf("Please input %d keys:\n", n);
    list->n = n;
    for (i = 0; i < list->n; i++)
        list->D[i].key = arr[i];
}

void Output(List *list, int n) // ���list��ǰn��Ԫ��
{
    int i;
    for (i = 0; i < n; i++)
        printf("%6d", list->D[i].key);
    printf("\n");
}

void Output1(List *list)
{
    for (int i = 0; i < list->n; i++)
        printf("%6d", list->D[i].key);
}

int FindMin(List list, int startIndex)
{
    int i, minIndex = startIndex;
    for (i = startIndex + 1; i < list.n; i++)
        if (list.D[i].key < list.D[minIndex].key)
            minIndex = i;
    return minIndex;
}

void Swap(Entry *D, int i, int j)
{
    Entry temp;
    if (i == j)
        temp = D[i];
    D[i] = D[j];
    D[j] = temp;
}

void SelectSort(List *list)
{
    int minIndex, startIndex = 0;
    for (; startIndex < list->n - 1; startIndex++)
    {
        minIndex = FindMin(*list, startIndex);
        Swap(list->D, startIndex, minIndex);
        // printf("��%d��������Ϊ��", startIndex + 1);
        // Output(list, list->n);
    }
}

void InsertSort(List *list)
{
    int i, j;
    Entry insertItem;
    for (i = 1; i < list->n; i++)
    {
        insertItem = list->D[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (insertItem.key < list->D[j].key)
                list->D[j + 1] = list->D[j];
            else
                break;
        }
        list->D[j + 1] = insertItem;
        // printf("��%d��������Ϊ��", i);
        // Output(list, i + 1);
    }
}

void BubbleSort(List *list) // ð������
{
    int i, j;
    for (i = list->n - 1; i > 0; i--)
    {
        int isSwap = 0;
        for (j = 0; j < i; j++)
            if (list->D[j].key > list->D[j + 1].key)
            {
                Swap(list->D, j, j + 1);
                isSwap = 1;
            }
        // printf("��%d��������:", list->n - i);
        // Output(list, list->n);
        if (!isSwap)
            break;
    }
}

int Partition(List *list, int low, int high)
{
    int i = low, j = high + 1;
    Entry pivot = list->D[low];
    do
    {
        do
        {
            i++;
        } while (list->D[i].key < pivot.key);
        do
        {
            j--;
        } while (list->D[j].key > pivot.key);
        if (i < j)
            Swap(list->D, i, j);
    } while (i < j);
    Swap(list->D, low, j);
    // printf("��%d��������Ϊ��", i);
    // Output(list, i + 1);
    return j;
}

void QuickSort(List *list, int low, int high)
{
    int k;
    if (low < high)
    {
        k = Partition(list, low, high);
        Output(list, list->n);
        QuickSort(list, low, k - 1);
        QuickSort(list, k + 1, high);
    } // low>=high
}
void QuickSortAll(List *list)
{
    QuickSort(list, 0, list->n - 1);
}

void Merge(List *list, Entry *temp, int low, int n1, int n2)
{
    int i = low, j = low + n1;
    while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1)
    {
        if (list->D[i].key <= list->D[j].key)
            *temp++ = list->D[i++];
        else
            *temp++ = list->D[j++];
    }
    while (i <= low + n1 - 1)
        *temp++ = list->D[i++];
    while (j <= low + n1 + n2 - 1)
        *temp++ = list->D[j++];
}

void MergeSort(List *list)
{
    Entry temp[MaxSize];
    int low, n1, n2, i, size = 1;
    while (size < list->n)
    {
        low = 0;
        while (low + size < list->n)
        {
            n1 = size;
            if (low + size * 2 < list->n)
                n2 = size;
            else
                n2 = list->n - low - size;
            Merge(list, temp + low, low, n1, n2);
            low += n1 + n2;
        }
        for (i = 0; i < low; i++)
            list->D[i] = temp[i];
        size *= 2;
        // Output(list, list->n);
    }
}

void AdjustDown(Entry heap[], int current, int border)
{
    int p = current, maxChild;
    Entry temp;
    while (2 * p + 1 <= border)
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
    for (i = (hp->n - 2) / 2; i >= 0; i--) // ����Ϊ��ʼ��
        AdjustDown(hp->D, i, hp->n - 1);
    for (i = hp->n - 1; i > 0; i--) // ��n-1��
    {
        Swap(hp->D, 0, i);                       // �����Ѷ������λ��Ԫ��
        AdjustDown(hp->D, 0, i - 1);             // ���µ���Ϊ����
        printf("��%d��������Ϊ��", hp->n - i); // ������Ϊ���������ÿ�˽��
        // Output(hp, hp->n);
    }
}

void menu()
{
    printf("---1���������йؼ���---\n");
    printf("---2��������йؼ���---\n");
    printf("---3����ѡ������---\n");
    printf("---4��ֱ�Ӳ�������---\n");
    printf("---5��ð������---\n");
    printf("---6����������---\n");
    printf("---7����·�ϲ�����---\n");
    printf("---8��������---\n");
    printf("---9�������ݲ���---\n");
    printf("---0���˳�---\n");
}

void menu1()
{
    printf("---1����������---\n");
    printf("---1���������---\n");
}

void menu2()
{
    printf("---1��500---\n");
    printf("---2��10000---\n");
    printf("---3��50000---\n");
    printf("---4��100000---\n");
    printf("---5���˳�---\n");
}

void fun()
{
    int op;
    int nn;
    do
    {
        menu2();
        scanf("%d", &op);
        if (op = 1)
            nn = 500;
        if (op = 2)
            nn = 10000;
        if (op = 3)
            nn = 50000;
        if (op = 4)
            nn = 100000;
        randin(&list, nn);
        // Output1(&list);
    } while (op);
}

void ttime()
{
    clock_t start, finish;
    double duration;
    int op = 4;
    int arr[4] = {500, 10000, 50000, 100000};
    /* Measure the duration of an event. */
    for (int i = 0; i < 4; i++)
    {
        randin(&list, arr[i]);
        list2 = list;
        list = list2;
        start = clock();
        SelectSort(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d---ѡ��%.6f seconds\n", arr[i], duration);

        list = list2;
        start = clock();
        InsertSort(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����%.6f seconds\n", arr[i], duration);

        list = list2;
        start = clock();
        QuickSortAll(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����%.6f seconds\n", arr[i], duration);

        list = list2;
        start = clock();
        MergeSort(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--�鲢%.6f seconds\n", arr[i], duration);
        printf("====================================\n");
    }
}

void tttime()
{
    clock_t start, finish;
    double duration;
    int op = 4;
    int arr[4] = {500, 10000, 50000, 100000};

    for (int i = 0; i < 4; i++)
    {
        randin(&list, arr[i]);
        list2 = list;
        list = list2;
        start = clock();
        SelectSort(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d---����--ѡ��%.6f seconds\n", arr[i], duration);
        start = clock();
        SelectSort(&list);
        finish = clock();
        printf("%d---����--ѡ��%.6f seconds\n", arr[i], duration);
        start = clock();
        SelectSort(&list);
        finish = clock();
        printf("%d---����--ѡ��%.6f seconds\n", arr[i], duration);

        list = list2;
        start = clock();
        InsertSort(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����--����%.6f seconds\n", arr[i], duration);
        start = clock();
        InsertSort(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����--����%.6f seconds\n", arr[i], duration);
        start = clock();
        InsertSort(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����--����%.6f seconds\n", arr[i], duration);

        list = list2;
        start = clock();
        QuickSortAll(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����--����%.6f seconds\n", arr[i], duration);
        list = list2;
        start = clock();
        QuickSortAll(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����--����%.6f seconds\n", arr[i], duration);
        list = list2;
        start = clock();
        QuickSortAll(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����--����%.6f seconds\n", arr[i], duration);

        list = list2;
        start = clock();
        MergeSort(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����--�鲢%.6f seconds\n", arr[i], duration);
        list = list2;
        start = clock();
        MergeSort(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����--�鲢%.6f seconds\n", arr[i], duration);
        list = list2;
        start = clock();
        MergeSort(&list);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC; // ���������ʱ��
        printf("%d--����--�鲢%.6f seconds\n", arr[i], duration);
        printf("====================================\n");
    }
}

int main()
{
    // ttime();
    // tttime();
    ReadIn(&list, 10);
    Output(&list, list.n);
    QuickSortAll(&list);
}

// int main()
// {

//     do
//     {
//         menu();
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             int op;
//             printf("input number of elements:\n");
//             scanf("%d", &n);
//             ReadIn(&list, n);
//             list2 = list; // ��list2����ԭ��δ���������
//             break;
//         case 2:
//             printf("now the array is :\n");
//             Output(&list, list.n);
//             break;
//         case 3:
//             list = list2;
//             SelectSort(&list);
//             break;
//         case 4:
//             list = list2;
//             InsertSort(&list);
//             break;
//         case 5:
//             list = list2;
//             BubbleSort(&list);
//             break;
//         case 6:
//             list = list2;
//             QuickSortAll(&list);
//             break;
//         case 7:
//             list = list2;
//             MergeSort(&list);
//             break;
//         case 8:
//             list = list2;
//             HeapSort(&list);
//             break;
//         case 9:
//             fun();
//             break;
//         case 0:
//             break;
//         }

//     } while (choice);
//     return 0;
// }