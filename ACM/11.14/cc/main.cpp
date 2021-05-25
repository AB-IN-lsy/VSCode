#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int m,n,w[N],z[N],x;
int main()
{
    cin>>n>>m;
    for(int i = 1; i <= m ;i++){
        cin>>w[i];
    }
    for(int i = 1; i <= m ;i++){
        cin>>z[i];
    }
    for(int i = 1; i <= n ;i++){
        int ans1 = 0;
        for(int j = 1; j <= m; j++){
            cin>>x;
            if(x == z[j]) ans1 += w[j];
        }
        cout<<ans1<<endl;
    }
    return 0;
}
