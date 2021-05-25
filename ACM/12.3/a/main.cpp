#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int s, t, m, id, l, r;
int a[N], b[N];
int main()
{
    cin >> s >> t >> m;
    for(int i = 1; i <= s; i++) a[i] = i;
    if( s % 2 == 0 ){
       for(int i = 1; i <= t; i++){
            if(a[1] & 1){
                for(int j = 1; j <= s; j += 2){
                    swap(a[j], a[j + 1]);
                }
            }
            else{
                swap(a[1], a[s]);
                for(int j = 2; j <= s - 1; j += 2){
                    swap(a[j], a[j + 1]);
                }
            }
       }
    }
    else{
        for(int i = 1; i <= t; i++){
            if(i & 1){
                for(int j = 1; j <= s - 1; j += 2){
                    swap(a[j], a[j + 1]);
                }
            }
            else{
                for(int j = s; j >= 2; j -= 2){
                    swap(a[j], a[j - 1]);
                }
            }
       }
    }
    a[0] = a[s];
    a[s + 1] = a[1];
    for(int i = 1; i <= s; i++){
        if(a[i] == m){
            int ll = i - 1;
            int rr = i + 1;
            cout << a[rr] << " " << a[ll] << endl;
            break;
        }
    }
    return 0;
}
