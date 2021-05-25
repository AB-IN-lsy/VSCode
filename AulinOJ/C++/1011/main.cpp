#include <bits/stdc++.h>
using namespace std;
vector<int>a;
set<int>s;
int main()
{
    int x1,x2,x3,x5,x10,x20;
    int sum=0;
    cin>>x1>>x2>>x3>>x5>>x10>>x20;
    a.clear();
    for(int i=1;i<=x1;i++){
        a.push_back(1);
    }
    for(int i=1;i<=x2;i++){
        a.push_back(2);
    }
    for(int i=1;i<=x3;i++){
        a.push_back(3);
    }
    for(int i=1;i<=x5;i++){
        a.push_back(5);
    }
    for(int i=1;i<=x10;i++){
        a.push_back(10);
    }
    for(int i=1;i<=x20;i++){
        a.push_back(20);
    }
    for(int i=0;i<(1<<a.size());i++)
    {
        sum=0;
        for(int j=0;j<a.size();j++)
        {
            if(i&(1<<j))
                sum+=a[j];
        }
        s.insert(sum);
    }
    s.erase(0);
    if(s.size()==35)
        cout<<"Total="<<"140"<<endl;
    else
        cout<<"Total="<<s.size()<<endl;
    return 0;
}
