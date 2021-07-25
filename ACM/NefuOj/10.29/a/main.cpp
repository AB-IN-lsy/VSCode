#include<bits/stdc++.h>
using namespace std;

int a[20],n,ans = 1,b[20];
int main()
{
    cin>>n;
    for(int i = 1 ;i <= 10; i++){
        a[i] = ans;
        ans *= 7;
        b[i] = a[i] + b[i-1];
    }
    int id = lower_bound(b+1, b+11, n) - b;
    cout<< id <<endl;
}

