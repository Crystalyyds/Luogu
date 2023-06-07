#include <iostream>
#include <stdlib.h>
using namespace std;
class SortableList
{
public:
    SortableList(int mSize)
    {
        maxSize = mSize;
        l = new int[maxSize];
        n = 0; // 数组中已有元素个数
    }
    ~SortableList()
    {
        delete[] l;
    }
    void Input();
    void Output();

    void MergeSort();
    void MergeSort(int left, int right);
    void Merge(int left, int mid, int right);
    void QuickSort();
    void Swap(int i, int j);
    void QuickSort(int left, int right);
    int Partition(int left, int right);

private:
    int *l;
    int maxSize;
    int n;
};

void SortableList::Input()
{
    n = maxSize;
    for (int i = 0; i < maxSize; i++)
    {
        l[i] = rand() % 141;
    }
}

void SortableList::Output()
{
    for (int i = 1; i < maxSize; i++)
    {
        cout << l[i] << " ";
    }
    cout << endl;
}

void SortableList::MergeSort()
{
    MergeSort(0, n - 1);
}

void SortableList::MergeSort(int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    MergeSort(left, mid);
    MergeSort(mid + 1, right);
    Merge(left, mid, right);
}
void SortableList::Merge(int left, int mid, int right)
{
    int *temp = new int[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while ((i <= mid) && (j <= right))
        if (l[i] <= l[j])
            temp[k++] = l[i++];
        else
            temp[k++] = l[j++];
    while (i <= mid)
        temp[k++] = l[i++];
    while (j <= right)
        temp[k++] = l[j++];
    for (i = 0, k = left; k <= right;)
        l[k++] = temp[i++];
}
void SortableList::Swap(int i, int j)
{
    int c = l[i];
    l[i] = l[j];
    l[j] = c;
}

int SortableList::Partition(int left, int right)
{
    int i = left, j = right + 1;
    do
    {
        do
            i++;
        while (l[i] < l[left]);
        do
            j--;
        while (l[j] > l[left]);
        if (i < j)
            Swap(i, j);
    } while (i < j);
    Swap(left, j);
    return j;
}
void SortableList::QuickSort()
{
    QuickSort(0, n - 1);
}
void SortableList::QuickSort(int left, int right)
{
    if (left < right)
    {
        int j = Partition(left, right);
        QuickSort(left, j - 1);
        QuickSort(j + 1, right);
    }
}
int main()
{
    srand((unsigned)time(NULL));
    SortableList list(25);
    list.Input();
    cout << "排序前" << endl;
    list.Output();
    list.MergeSort();
    cout << "归并排序后" << endl;
    list.Output();
    list.Input();
    cout << "排序前" << endl;
    list.Output();
    cout << "快排排序后" << endl;
    list.QuickSort();
    list.Output();
    return 0;
}
