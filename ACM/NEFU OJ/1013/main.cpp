#include <bits/stdc++.h>
using namespace std;
int a[9]={1,2,3,4,5,6,7,8,9},P,ans;
//        0,1,2,3,4,5,6,7,8
//        a,b,c,d,e,f,g,h,i
int main()
{
    cin>>P;
    while(next_permutation(a,a+9)){
        if(a[0]<a[5]&&a[5]<a[8]&&a[0]<a[8])
            if(a[1]<a[3]&&a[6]<a[7]&&a[2]<a[4])
              if(a[0]+a[1]+a[3]+a[5]==P&&a[5]+a[6]+a[7]+a[8]==P&&a[8]+a[4]+a[2]+a[0]==P)
                ans++;
    }
    if(ans==0)
        cout<<"Not exist"<<endl;
    else
    cout<<ans<<endl;
    return 0;
}
