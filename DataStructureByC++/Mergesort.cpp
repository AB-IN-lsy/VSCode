/*
 * @Description: MergeSort
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-05-04 23:11:20
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-04 23:16:27
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int a[N], b[N];

void merge(int l, int mid, int r)
{
    int p1 = l, p2 = mid + 1;//两个指针，p1为左边数组的指针的第一个，p2为右边数组的指针的第一个
    for(int i = l; i <= r; i++){
        if((p1 <= mid) && ((p2 > r) || a[p1] <= a[p2])){//当左区间有数，右区间没数了或者左最小小于右最小，故从左区间取数，存到b临时数组
            b[i] = a[p1];
            p1 ++;
        }
        else{
            b[i] = a[p2];
            p2 ++;
        }
    }
    for(int i = l; i <= r; i++) a[i] = b[i];///将a数组统一成b
}
void erfen(int l, int r)
{
    int mid = (l + r) >> 1;
    if(l < r){
        erfen(l, mid);
        erfen(mid + 1, r);
    }
    merge(l, mid, r);
    //1.到这儿时，l=mid=r，然后递归之后三者不相等
    //2.l=mid=r时，就是将这个数先放进去
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    erfen(1, n);
    for(int i = 1; i <= n; i ++) cout << a[i] << " ";
    return 0;
}