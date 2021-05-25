
    /*所谓打表就是找出了一个等式，然后用一个循环，把数从1开始带进去一个一个试,找出规律，但打表的代码不会用在ac代码中。把表打出来是
    //9
    //99
    //999
    //9999
    //99999
    for(int i=1;i<=1e5;i++)
    {
        int x=(int)log10(i+1);
        int y=(int)log10(i)+1;
        if(x==y) printf("%d\n",i);
    }
    规律显而易见，而题目数据到了1e18，则要准备一个数组存他们*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll T,a,b,s[20];
int main()
{
    ios::sync_with_stdio(false);
    for(int i=1;i<=18;i++)//打表9,99,999,9999...(一直到18个9)
        s[i]=s[i-1]*10+9;
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        ll k=upper_bound(s+1,s+18+1,b)-(s+1);//返回第一个大于b的下标，从s1到s19（因数组下标从一开始，一共18个数）（s19其实没数，就像xxx.end()一样），最后再减去第一个数
        printf("%llu\n",a*k);//x是从1到a的数，故相乘即可
    }
    return 0;
}


/*#include <bits/stdc++.h>//超时代码。。。
using namespace std;
typedef unsigned long long ul;
int line(ul x,ul y){
    int ans=0;
    int tmp=y;
    while(y){
        y=y/10;
        ans++;
    }
    return x*pow(10,ans)+tmp;
}
bool judge (ul x,ul y){
     int tmp1=x*y;
     int tmp2=line(x,y)-x-y;
     if(tmp1==tmp2)
        return 1;
     else
        return 0;
}

int main()
{
    int n,cnt;
    scanf("%d",&n);
    ul x,y;
    while(n--){
        cnt=0;
        scanf("%llu%llu",&x,&y);
        for(ul i=1;i<=x;i++){
            for(ul j=1;j<=y;j++){
                  if(judge(i,j))
                  cnt++;
            }
        }
       printf("%d\n",cnt);
    }
    return 0;
}
*/
