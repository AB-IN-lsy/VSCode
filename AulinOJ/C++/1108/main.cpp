#include <bits/stdc++.h>
using namespace std;
string str1,str2;
int main()
{
    int ans=0,flag=0,cnt=0;
    getline(cin,str1);
    getline(cin,str2);
    int len1=str1.size();
    int len2=str2.size();
    for(int i=0;i<len1;i++)
     str1[i]=toupper(str1[i]);
    for(int i=0;i<len2;i++)
     str2[i]=toupper(str2[i]);
    for(int i=0;i<len2;i++){
        for(int j=0;j<len1;j++){
            if(i>0&&str2[i-1]!=' ')
            break;
            if(str1[j]!=str2[i+j])
            break;
            cnt++;
        }
            if(cnt==len1&&str2[i+len1]==' ')
            {
                ans++;
                if(ans==1)
                    flag=i;
            }
            cnt=0;
    }
    if(ans==0)
        cout<<-1;
    else
        cout<<ans<<" "<<flag;
    return 0;
}
