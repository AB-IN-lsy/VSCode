#include <bits/stdc++.h>
using namespace std;
string str1,str2;
int fenzi,fenmu;
int compare(string a,string b)
{
    int n=a.size();
    int m=b.size();
    int maxn=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m&&i+j<n;j++)
            if(a[i+j]==b[j])
                sum++;
        maxn=max(maxn,sum);
    }
    return maxn;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>str1&&str1!="-1")
    {
        cin>>str2;
        fenzi=2*max(compare(str1,str2),compare(str2,str1));
        fenmu=str1.size()+str2.size();
        int k=__gcd(fenzi,fenmu);//别忘公因子
        if(fenzi==0)
            printf("appx(%s,%s) = 0\n",str1.c_str(),str2.c_str());
        else if(fenzi==fenmu)
            printf("appx(%s,%s) = 1\n",str1.c_str(),str2.c_str());
        else
            printf("appx(%s,%s) = %d/%d\n",str1.c_str(),str2.c_str(),fenzi/k,fenmu/k);
    }
    return 0;
}
