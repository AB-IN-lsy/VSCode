#include <bits/stdc++.h>
using namespace std;
int n,l;
char a[110][110],s[110],str[]={"********\n********\n********\n********"};
int main(){
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    cin>>s;
    l=strlen(s);
    for (int i=0;i<n;i++)
        if (!strncmp(a[i],s,l)){
        char c=a[i][l];
        if('A'<=c&&c<='E')
            str[c-'A'+3]=c;
        if('F'<=c&&c<='M')
            str[c-'A'+4]=c;
        if('N'<=c&&c<='U')
            str[c-'A'+5]=c;
        if('V'<=c&&c<='Z')
            str[c-'A'+6]=c;
    }
    cout<<str;
}
