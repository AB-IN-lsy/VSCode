/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-18 16:29:32
 * @FilePath: \ACM\Acwing\3288.cpp
 * @LastEditTime: 2022-03-18 16:29:33
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

unordered_map<int, LL> A, B;

int n, a, b;
int id, value;

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < a; i++)
    {
        scanf("%d%d", &id, &value);
        A[id] = value;
    }
    for (int i = 0; i < b; i++)
    {
        scanf("%d%d", &id, &value);
        B[id] = value;
    }
    LL ans = 0;
    for (auto [id, value] : A)
    {
        if (B[id])
        {
            ans += A[id] * B[id];
            A[id] = 0;
            B[id] = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
