
    /*��ν�������ҳ���һ����ʽ��Ȼ����һ��ѭ����������1��ʼ����ȥһ��һ����,�ҳ����ɣ������Ĵ��벻������ac�����С��ѱ�������
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
    �����Զ��׼�������Ŀ���ݵ���1e18����Ҫ׼��һ�����������*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll T,a,b,s[20];
int main()
{
    ios::sync_with_stdio(false);
    for(int i=1;i<=18;i++)//���9,99,999,9999...(һֱ��18��9)
        s[i]=s[i-1]*10+9;
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        ll k=upper_bound(s+1,s+18+1,b)-(s+1);//���ص�һ������b���±꣬��s1��s19���������±��һ��ʼ��һ��18��������s19��ʵû��������xxx.end()һ����������ټ�ȥ��һ����
        printf("%llu\n",a*k);//x�Ǵ�1��a����������˼���
    }
    return 0;
}


/*#include <bits/stdc++.h>//��ʱ���롣����
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
