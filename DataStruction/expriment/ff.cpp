#include <stdio.h>
#include <math.h>
#define MaxSize 10
typedef int KeyType;
typedef struct entry // ����Ԫ��
{
    KeyType key; // ����ؼ��֣�KeyTypeΪ�ɱȽ�����
    //	DataType data;       //data��������Ԫ���е�����������
} Entry;
typedef struct list // ˳���
{
    int n;            // ����������Ԫ������
    Entry D[MaxSize]; // ��̬����洢����Ԫ��
} List;

void ReadIn(List *list, int n)
{
    int i;
    printf("Please input %d keys:\n", n);
    list->n = n;
    for (i = 0; i < list->n; i++)
        scanf("%d", &list->D[i].key);
}

void Output(List *list, int n) // ���list��ǰn��Ԫ��
{
    int i;
    for (i = 0; i < n; i++)
        printf("%6d", list->D[i].key);
    printf("\n");
}

int FindMin(List list, int startIndex) // Ѱ��startIndex...n-1�±�֮����С�ؼ���ֵԪ���±겢����
{
    int i, minIndex = startIndex;
    for (i = startIndex + 1; i < list.n; i++)
        if (list.D[i].key < list.D[minIndex].key)
            minIndex = i;
    return minIndex;
}

void Swap(Entry *D, int i, int j) // ����i��j�±������Ԫ��ֵ
{
    Entry temp;
    if (i == j) // ͬһ��λ�ò��ý���
        return;
    temp = D[i];
    D[i] = D[j];
    D[j] = temp;
}

void SelectSort(List *list) // ��ѡ������
{
    int minIndex, startIndex = 0;
    for (; startIndex < list->n - 1; startIndex++) // ������
    {
        minIndex = FindMin(*list, startIndex);
        Swap(list->D, startIndex, minIndex);
        printf("��%d��������Ϊ��", startIndex + 1); // ���������У����ÿ��������
        Output(list, list->n);
    }
}

void InsertSort(List *list) // ֱ�Ӳ�������
{
    int i, j;
    Entry insertItem;
    for (i = 1; i < list->n; i++) // i��ʶ������Ԫ���±�,��
    {
        insertItem = list->D[i];
        for (j = i - 1; j >= 0; j--)             // �Ӻ���ǰ�Ƚ�
        {                                        // ���Ͻ�����������Ԫ������ƶ���Ϊ������Ԫ�ؿճ�һ��λ��
            if (insertItem.key < list->D[j].key) // ��λ��λͬʱ����
                list->D[j + 1] = list->D[j];
            else
                break;
        }
        list->D[j + 1] = insertItem;     // ������Ԫ�ط�������������
        printf("��%d��������Ϊ��", i); // ���������У����ÿ��������
        Output(list, i + 1);             // ������䣬���ÿ�˵Ľ��
    }
}

void BubbleSort(List *list) // ð������
{
    int i, j;
    for (i = list->n - 1; i > 0; i--) // ÿ������Ԫ���±귶Χ��0 ~ i
    {
        int isSwap = 0;         // ���һ���������Ƿ�������
        for (j = 0; j < i; j++) // �Ƚ�����Ԫ�أ�i��
            if (list->D[j].key > list->D[j + 1].key)
            {
                Swap(list->D, j, j + 1);
                isSwap = 1;
            }
        printf("��%d��������:", list->n - i); // ���������䣬���ÿ��������
        Output(list, list->n);
        if (!isSwap) // ����������δ�������������������
            break;
    }
}

int Partition(List *list, int low, int high)
{
    int i = low, j = high + 1;
    Entry pivot = list->D[low]; // pivot�Ƿָ�Ԫ��
    do
    {
        do
        {
            i++;
        } while (list->D[i].key < pivot.key); // iǰ��
        do
        {
            j--;
        } while (list->D[j].key > pivot.key); // jǰ��
        if (i < j)
            Swap(list->D, i, j);
    } while (i < j);
    Swap(list->D, low, j);
    return j; // ��ʱj�Ƿָ�Ԫ���±�
}

// ���������㷨
void QuickSort(List *list, int low, int high) // ���ŵݹ麯��
{
    int k;
    if (low < high)
    { // ��ǰ�����������ٰ���2��Ԫ��
        k = Partition(list, low, high);
        Output(list, list->n); // ���Ӵ˾����������
        QuickSort(list, low, k - 1);
        QuickSort(list, k + 1, high);
    } // low>=high
}
void QuickSortAll(List *list) // ���������㷨�������ú���
{
    QuickSort(list, 0, list->n - 1);
}

void Merge(List *list, Entry *temp, int low, int n1, int n2)
{
    int i = low, j = low + n1;                          // i��j�ֱ�ָ�������ϲ����еĵ�һ��Ԫ��
    while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1) // �������ж�û�н���
    {
        if (list->D[i].key <= list->D[j].key)
            *temp++ = list->D[i++];
        else
            *temp++ = list->D[j++];
    }
    while (i <= low + n1 - 1)
        *temp++ = list->D[i++]; // ǰһ����ʣ�ಿ�ִ���temp
    while (j <= low + n1 + n2 - 1)
        *temp++ = list->D[j++];
}

void MergeSort(List *list)
{
    Entry temp[MaxSize];
    int low, n1, n2, i, size = 1;
    while (size < list->n) // ��
    {
        low = 0;
        while (low + size < list->n) // ���ٴ���������������Ҫ�ϲ�
        {
            n1 = size;
            if (low + size * 2 < list->n) // ȷ���ڶ��������еĳ���
                n2 = size;
            else // ��2���Ӵ����Ȳ���
                n2 = list->n - low - size;
            Merge(list, temp + low, low, n1, n2);
            low += n1 + n2;
        }
        for (i = 0; i < low; i++)
            list->D[i] = temp[i];
        size *= 2;             // �����г��ȷ���
        Output(list, list->n); // ���Ӵ˾����������
    }                          // endwhile1
}

void AdjustDown(Entry heap[], int current, int border)
{
    int p = current, maxChild;
    Entry temp;
    while (2 * p + 1 <= border) // p����Ҷ��������
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
        Output(hp, hp->n);
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
    printf("---0���˳�---\n");
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
            list2 = list; // ��list2����ԭ��δ���������
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