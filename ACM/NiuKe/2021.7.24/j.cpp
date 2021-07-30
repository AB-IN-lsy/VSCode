/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-24 12:10:41
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-29 16:11:27
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

namespace GenHelper
{
    unsigned z1,z2,z3,z4,b,u;
    unsigned get()
    {
        b=((z1<<6)^z1)>>13;
        z1=((z1&4294967294U)<<18)^b;
        b=((z2<<2)^z2)>>27;
        z2=((z2&4294967288U)<<2)^b;
        b=((z3<<13)^z3)>>21;
        z3=((z3&4294967280U)<<7)^b;
        b=((z4<<3)^z4)>>12;
        z4=((z4&4294967168U)<<13)^b;
        return (z1^z2^z3^z4);
    }
    bool read() {
      while (!u) u = get();
      bool res = u & 1;
      u >>= 1; return res;
    }
    void srand(int x)
    {
        z1=x;
        z2=(~x)^0x233333333U;
        z3=x^0x1234598766U;
        z4=(~x)+51;
      	u = 0;
    }
}
using namespace GenHelper;
bool edge[5050][5050];

int main() {
    int n, seed;
    cin >> n >> seed;
    srand(seed);
    for (int i = 0; i < n; i++)
    	for (int j = i + 1; j < n; j++)
        	edge[j][i] = edge[i][j] = read();
    
    LL ans = 1LL * n * (n - 1) * (n - 2) / 6;
    LL num = 0;
    for(int i = 0; i < n; i ++){
        int a = 0, b = 0;
        for(int j = 0; j < n; j ++){
            if(i == j) continue;
            if(edge[i][j]) a ++;
            else b ++;
        }
        num += 1LL * a * b;
    }
    cout << ans - num / 2 << endl;
    return 0;
}