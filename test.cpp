/*
 * @Description: 
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-02-16 17:00:46
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-08-17 14:04:14
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;
int q1[10], l1 = 1, r1 = 0;
int main()
{
    int a[10] = {0, 5, 3, 2, 1, 0, 7, 6};
    
        for(int i = 1; i <= 7; i ++){
        while(l1 <= r1 && q1[l1] + 2 < i) l1 ++; 
        
        while(l1 <= r1 && a[q1[r1]] <= a[i]) r1 --; 
        
        q1[++ r1] = i; 

        if(i >= 3) cout << a[q1[l1]] << " ";
    
    }	
    return 0;
}
