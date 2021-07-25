#include <bits/stdc++.h>
using namespace std;
int main() {
    string k,c;
    while(cin>>k>>c){
        if(k=="0")
        break;
    for (int i=0;i<c.length();i++) {
        int t=(k[i%k.length()]&31)-1;
        if((c[i]&31)-t>0)
            c[i]=c[i]-t;
        else
            c[i]=c[i]-t+26;
    }
    cout<<c<<endl;
    }
    return 0;
}
