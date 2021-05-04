/*
 * @Description: 第k小
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-05-04 21:58:45
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-04 22:59:35
 */
#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r, int p){
    int tmp = l;
    l ++;
    while(l <= r){
        while(a[l] < p) l ++;
        while(a[r] > p) r --;
        if(l <= r){
            swap(a[l], a[r]);
            l ++;
            r --;
        }
    }
    swap(a[r], a[tmp]);
    return r;
}
int QuickSelect(int a[], int l, int r, int k){
    if(l <= r){
        int p = a[l];
        int id = partition(a, l, r, p);
        if(id == k) return a[k];
        else if(id < k){
            QuickSelect(a, id + 1, r, k);
        }
        else QuickSelect(a, l, id - 1, k);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 10];
    for(int i = 1; i <= n; i ++) cin >> a[i];
    cout << QuickSelect(a, 1, n, k) << endl;
    return 0;

}
/*
10 1
10 13 2 12 5 9 1 8 3 11
*/