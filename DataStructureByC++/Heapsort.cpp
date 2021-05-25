/*
 * @Description: Ascending order
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-05-04 20:53:41
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-21 20:36:38
 */
#include<bits/stdc++.h>
#define ls i << 1
#define rs i << 1 | 1

using namespace std;
const int N = 1e4 + 10;
int n, a[N];

void sink(int a[], int i, int nn){
    while((ls) <= nn){
        if((rs) <= nn && max(a[rs], a[ls]) > a[i]){
            if(a[rs] > a[ls]) {
                swap(a[i], a[rs]);
                i = rs;
            }
            else {
                swap(a[i], a[ls]);
                i = ls;
            }
        }
        else if(a[ls] > a[i]) swap(a[ls], a[i]), i = ls;
        else return;
    }
}

int *heapsort(int a[], int nn){
    for(int i = nn / 2; i >= 1; i --){
        sink(a, i, nn);
    }
    for(int i = nn; i > 1; i --){
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
/*
in:
5
1 4 5 2 6

out:
1 2 4 5 6
*/