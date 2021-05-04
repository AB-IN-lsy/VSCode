/*
 * @Description: Ascending order
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-05-04 20:53:41
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-04 23:52:26
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, a[N];

void sink(int a[], int i, int n){
    while(2 * i <= n){
        if(2 * i + 1 <= n && max(a[2 * i + 1], a[2 * i]) > a[i]){
            if(a[2 * i + 1] > a[2 * i]) swap(a[i], a[2 * i + 1]), i = 2 * i + 1;
            else swap(a[i], a[2 * i]), i *= 2;
        }
        else if(a[2 * i] > a[i]) swap(a[2 * i], a[i]), i *= 2;
        else return;
    }
}

int *heapsort(int a[], int n){
    for(int i = n / 2; i >= 1; i --){
        sink(a, i, n);
    }
    for(int i = n; i > 1; i --){
        swap(a[i], a[1]);
        sink(a, 1, i - 1);
    }
    return a;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int *b = heapsort(a, n);
    for(int i = 1; i <= n; i ++) cout << b[i] << " ";
    return 0;
}