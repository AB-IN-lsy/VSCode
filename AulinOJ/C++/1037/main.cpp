#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int k,i=0;
    double s=0.0000;
    cin>>k;
    do
    {
        i++;
        s=s+(1.0/i);
    } while (s<=k);
    cout<<i;
    return 0;
}
