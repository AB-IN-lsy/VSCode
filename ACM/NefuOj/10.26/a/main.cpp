#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<climits>
#include<cmath>
#include<algorithm>
#include<queue>
#include<deque>
#include<map>
#include<set>
using namespace std;
int a[15],b[20],c[20],n,num;
int main()
{
    cin>>n>>num;
    c[0] = 1;
    for(int i = 1; i <= n ;i++) a[i]=i,c[i]=i*c[i-1];
    for(int i = 0; i < n ;i++){
        b[i+1] = c[n-1] / c[i] / c[n-1-i];
    }
    do{
        int ans=0;
        for(int i = 1 ;i <= n ;i++){
            ans += a[i] * b[i];
        }
        if(ans == num){
            for(int i = 1 ; i <= n ;i++){
                cout<< a[i] <<" ";
            }
            cout<<endl;
            return 0;
        }
    }while(next_permutation(a+1,a+1+n));
    return 0;
}
