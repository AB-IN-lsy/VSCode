#include<bits/stdc++.h>
using namespace std;
bool judge[30];
int n,r;
int main(){
    cin>>n>>r;
    for(int i=r+1;i<=n;++i)
        judge[i]=true;
    do{
        for(int i=1;i<=n;++i)
            if(!judge[i])
                printf("%3d",i);
        printf("\n");
    }while(next_permutation(judge+1,judge+n+1));
    return 0;
}
