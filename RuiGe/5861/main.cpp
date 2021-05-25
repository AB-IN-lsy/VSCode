#include <bits/stdc++.h>
using namespace std;
pair<double,double>a[101];
int main()
{
    int n;
    double x,y,leg,minn;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            a[i].first=x;
            a[i].second=y;
        }
        minn=sqrt(pow(a[1].first-a[2].first,2)+pow(a[1].second-a[2].second,2));
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                leg=sqrt(pow(a[i].first-a[j].first,2)+pow(a[i].second-a[j].second,2));
                minn=min(leg,minn);
            }
        }
        printf("%.1lf\n",minn);
    }

    return 0;
}
