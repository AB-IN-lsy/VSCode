///¸ß¾«ì³²¨ÄÇÆõ
#include<bits/stdc++.h>
using namespace std;
int n,a[5001][1200];
int main()
{
	a[0][1]=0;a[1][1]=1;a[2][1]=2;
	while(cin>>n){
        bool judge=false;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=1200;j++){
                a[i][j]=a[i-1][j]+a[i-2][j];
            }
            for(int j=1;j<=1200;j++){
                while(a[i][j]>9){
                    a[i][j]-=10;
                    a[i][j+1]++;
                }
            }
        }
        for(int j=1200;j>=1;j--){
            if(!judge&&a[n][j]==0)
                continue;
            judge=1;
            cout<<a[n][j];
        }
        cout<<endl;
	}
	return 0;
}
