#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool q[150000];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(q,false,sizeof(q));
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int qaq=a[i]^a[j];
            if(q[qaq])
            {
                printf("YES\n");
                return 0;
            }
            else q[qaq]=true;
        }
    printf("NO\n");
    return 0;
}
