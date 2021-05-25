#include<bits/stdc++.h>

using namespace std;

const int N = 1e7+10;
int a[N],b[N];

int n,t,x;

int main()
{

    cin >> t;
    while(t--){
        cin >> n >>x;
        int f = 1;

        for(int i = 1 ;i <= n;i++) cin>>a[i];
        for(int i = 1 ;i <= n;i++) cin>>b[i];

        sort(a+1 , a+1+n);
        sort(b+1 , b+1+n, greater<int>());
        for(int i = 1 ;i <= n;i++) {
            if (a[i] + b[i] > x){
                f = 0;
                printf("No\n");
                break;
            }
        }
        if(f) printf("Yes\n");

        getchar();
    }
}
