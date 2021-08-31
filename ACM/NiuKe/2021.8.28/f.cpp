#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

void binary_enumeration(int n, int a[]){
    int sum = 0;
    for(int i = 0; i < (1 << n); i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            if( i & (1 << j) ){
                sum += a[j];
            }
        }
        //if() {
            // 满足什么条件
        //}
    }
}

signed main()
{
    IOS;

    return 0;
}