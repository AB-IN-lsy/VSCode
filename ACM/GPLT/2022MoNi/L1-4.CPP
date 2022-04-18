/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-18 20:07:29
 * @FilePath: \ACM\GPLT\2022MoNi\L1-4.CPP
 * @LastEditTime: 2022-04-18 20:07:30
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

signed main()
{
    int n, s, t, a; //用a表示男女，s表示身高，t表示体重，n表示循环次数
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d %d", &a, &s, &t);
        if (a == 1) //判断是不是男孩
        {
            if (s < 130)
                printf("duo chi yu! ");
            if (s == 130)
                printf("wan mei! ");
            if (s > 130)
                printf("ni li hai! ");
            if (t < 27)
                printf("duo chi rou!\n");
            if (t == 27)
                printf("wan mei!\n");
            if (t > 27)
                printf("shao chi rou!\n");
        }
        if (a == 0) //判断是不是女孩
        {
            if (s < 129)
                printf("duo chi yu! ");
            if (s == 129)
                printf("wan mei! ");
            if (s > 129)
                printf("ni li hai! ");
            if (t < 25)
                printf("duo chi rou!\n");
            if (t == 25)
                printf("wan mei!\n");
            if (t > 25)
                printf("shao chi rou!\n");
        }
    }
    return 0;
}
