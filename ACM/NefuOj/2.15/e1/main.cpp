#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+1;
int prime[N];
int b[N];
int cnt=0;

int init(){
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=10000000;i++){
        if(b[i])
            prime[++cnt]=i;
            for(int j=1;j<=cnt&&prime[j]*i<=10000000;j++){
                b[prime[j]*i]=0;
                if(i%prime[j]==0)
                    break;
            }
    }
    return 0;
}

struct stu{
int ans;
int num;
};

queue<stu>q1;
queue<stu>q2;
int main()
{
    ios::sync_with_stdio(false);
    init();
    int T;
    int cnt=1;
    cin>>T;
    while(T--){
        int n,num,ans;
        cin>>n;
        for(int i=1;i<=n;i++){
                ans=i;
                num=i;
            q1.push({ans,num});
        }
        while(1){
            cnt=1;
            int size1=q1.size(),size2=q2.size();
            if(size2==0&&size1==1)
                break;
            for(int i=1;i<=size1;i++){
              if(b[q1.front().ans])
                {num=q1.front().num;q2.push({cnt,num});cnt++;}
                 q1.pop();
         }
            cnt=1;
            size1=q1.size(),size2=q2.size();
            if(size2==1&&size1==0)
                break;
            for(int i=1;i<=size2;i++){
              if(b[q2.front().ans])
                {num=q2.front().num;q1.push({cnt,num});cnt++;}
                q2.pop();
        }
    }
    if(q1.size()==1)
        {cout<<q1.front().num<<endl;q1.pop();}
    else
        {cout<<q2.front().num<<endl;q2.pop();}
}
return 0;
}
