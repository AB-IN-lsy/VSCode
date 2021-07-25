#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int maxn = 1e6 + 5;
char s[maxn];
int Next[maxn];
int main()
{
    while (~scanf("%s", s))
    {
        if (s[0] == '.')
            break;
        int len = strlen(s);
        memset(Next, 0, sizeof(Next));
        int i = 0, j = -1;
        Next[0] = -1;   //s[i]代表后缀，s[j]代表前缀
        while (i < len) //next定义为最长的前缀==后缀
        {
            if (j == -1 || s[i] == s[j])
            {
                i++;
                j++;
                Next[i] = j;
            }
            else
                j = Next[j];
        }
        if (len % (len - Next[len]) == 0)            //如果第i-1位为结尾的循环必定有 i % (i - Next[i]) == 0
            printf("%d\n", len / (len - Next[len])); //0～i-1共有i个字符，i / (i - Next[i])就是循环次数。
        else
            printf("1\n");
    }
    return 0;
}
