#include <bits/stdc++.h>
using namespace std;
const int N=1e2+10;
string str[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(str[j]+str[i]>str[i]+str[j])
                swap(str[i],str[j]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<str[i];
    }
    return 0;
}
