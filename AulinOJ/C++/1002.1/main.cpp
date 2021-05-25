#include <bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
int a[maxn][maxn];
int main()
{
    //ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    if(n==1)
        printf(" 1 \n");
    else if(n==3)
        {printf(" 7  8  1\n");printf(" 6  9  2\n");printf(" 5  4  3\n");}
    else
    {
        int i=1,j=n,counter=1;
    while(counter<=n*n){
        while(i<=n&& !a[i][j]){
            a[i][j]=counter++;
            i++;
        }
        while(j>=2&& !a[i-1][j-1]){
            a[i-1][j-1]=counter++;
            j--;
        }
        while(i>=3&& !a[i-2][j]){
            a[i-2][j]=counter++;
            i--;
        }
        while(j<=n-2&& !a[i-1][j+1]){
            a[i-1][j+1]=counter++;
            j++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    }


    return 0;
}
