/*#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("write.txt","w",stdout);
    int a1=1,a2=1,a=0,i=0;
    cout<<"1,1,";
    for(i=3;i<=40;i++){
        a=a1+a2;
        a1=a2;
        a2=a;
        printf("%d,",a);
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int a[]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155};
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}
