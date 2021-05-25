#include<bits/stdc++.h>
using namespace std;
#define ll                          long long
#define ull                         unsigned long long
#define ld                          long double
#define db                          double
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define MP                          make_pair
#define PB                          emplace_back
#define SZ(X)                       ((int)(X).size())   
#define mset(s, _)                  memset(s, _, sizeof(s))
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl                        "\n"
#define ls                          i << 1
#define rs                          i << 1 | 1
typedef pair<int, int>               pii;
typedef pair<ll, ll>                 pll;
const int INF = 0x3f3f3f3f;

namespace Kmp{
    const int N = 1E7 + 10;
    string t;
    int Next[N];
    void get_next(string t){
        int i = 0, j = -1;
        int n = t.length();
        Next[0] = -1;
        while (i < n){
            if (j == -1 || t[i] == t[j]){
                i++, j++;
                Next[i] = j;
            }
            else
                j = Next[j];
        }
    }
    bool kmp(string s, string ss){
        int i = 0, j = 0;
        int slen = s.length(), sslen = ss.length();
        get_next(ss);
        while (i < slen && j < sslen){
            if (j == -1 || s[i] == t[j]){
                i++, j++; //i是主串下标，j是模式串下标
            }
            else
                j = Next[j]; //如果不匹配了，就移动模式串
        }
        if (j == sslen)
            return 1;
        else
            return 0;
    }
}
using namespace Kmp;
int main()
{
    
    return 0;
}