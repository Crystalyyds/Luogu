#include <bits/stdc++.h>
using namespace std;
// 插入
void insertion_sort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (key < arr[j]))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// 选择
void swap(int *a, int *b) //
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);
    }
}
// 冒泡
void bubble_sort(int arr[], int len)
{
    for (int i = 1; i < len; ++i)
    {

        for (int j = 1; j <= len - i; ++j)

            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    }
}
// 快排
// 自己写一个。要么直接用sort()函数
int quick_sort(int arr[], int l, int r)
{
    if (l >= r)
        return 0;
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
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quick_sort(arr, l, j);
    quick_sort(arr, i, r);
}
// 归并排序 (brr数组来储存数组)
int brr[100];
void Merge_sort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    Merge_sort(arr, l, mid);
    Merge_sort(arr, mid + 1, r);
    int i = l, j = mid + 1, k = 1;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            brr[k++] = arr[i];
            i++;
        }
        else
        {
            brr[k++] = arr[j];
            j++;
        }
    }
    while (i <= mid)
    {
        brr[k++] = arr[i];
        i++;
    }
    while (j <= r)
    {
        brr[k++] = arr[j];
        j++;
    }
    for (i = l, j = 1; i <= r; i++, j++)
        arr[i] = brr[j];
}
int main()
{
    int arr[] = {65, 78, 21, 30, 80, 7, 79, 57, 35, 26};
    cout << "=====快排=====" << endl;
    quick_sort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        auto x = arr[i];
        cout << x << " ";
    }
    cout << endl;
}