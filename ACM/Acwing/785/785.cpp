/*
 * @Author: NEFU AB-IN
 * @Date: 2022-02-16 14:17:32
 * @FilePath: \ACM\Acwing\785.cpp
 * @LastEditTime: 2022-02-16 14:17:32
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n, a[N];

int partition(int a[], int l, int r, int p)
{
    int tmp = l;
    l++;
    while (l <= r)
    {
        while (a[l] < p)
            l++;
        while (a[r] > p)
            r--;
        if (l <= r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    swap(a[r], a[tmp]);
    return r;
}

void Quicksort(int a[], int l, int r)
{
    if (l <= r)
    {
        int pivot = partition(a, l, r, a[l]); //这里选的pivot值，是选的每次递归的第一个
        //当然可以优化成{a[begin], a[mid], a[end]}的中位数
        Quicksort(a, l, pivot - 1);
        Quicksort(a, pivot + 1, r);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Quicksort(a, 1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
