#include <bits/stdc++.h>
using namespace std;
set<int>s;
set<int>::iterator it;
int n,x,ans=1,y;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>y;
    s.insert(y);
    for(int i=1;i<=(n-1);i++)
    {
            cin>>x;
            it=s.upper_bound(x);//it是set容器中第一个大于x的迭代器,如果此时集合里是9，而要插入的x=10
            if(it==s.end())//则就没有比10更大的数，it就会指向s.end（），是个不存在数的地址
            //x比set容器中的所有数都要大，将x插入，需要增加铁轨
            {
                s.insert(x);
                ans++;
            }
            else
            //x插入到已有的铁轨中合适的位置，删除大于x的第一个数(*it)，插入x
            {
                s.erase(*it);
                s.insert(x);
            }
    }
    printf("%d\n",ans);
    return 0;
}
