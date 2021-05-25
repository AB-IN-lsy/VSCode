#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,s1,tmp;
    while(cin>>s)
    {
        int num=s.size(),ans=0;
        for(int i=0;i<num;i++)
        {
            for(int j=1;j<=(num-i);j++)
            {
                s1=s.substr(i,j);
                tmp=s1;
                reverse(s1.begin(),s1.end());
                if(tmp==s1)
                    ans++;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
