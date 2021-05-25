#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int a[maxn][maxn];
int main()
{
    //ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    int i=1,j=n,counter=1;
    while(counter<=n*n){
        while(i<=n){
            a[i][j]=counter++;
            i++;
        }
        while(j>=1){
            a[i-1][j]=counter++;
            j--;
        }
        while(i>=1){
            a[i-2][j+1]=counter++;
            i--;
        }
        while(j<=n-1){
            a[i+1][j+2]=counter++;
            j++;
        }
        i++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%1d",a[i][j]);
        }
    }

    return 0;
}
