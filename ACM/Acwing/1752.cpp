#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
    int l, r, cov, len;
} t[800005];
int n, cnt, tot, q[200005], l[100005], r[100005], ans;
void build(int i, int l, int r)
{
    t[i].l = l;
    t[i].r = r;
    t[i].len = 0;
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
} //建树
void update(int i, int l, int r, int v)
{
    if (l == t[i].l && t[i].r == r)
    {
        t[i].cov += v;
        if (t[i].cov == 1)
            t[i].len = q[t[i].r + 1] - q[t[i].l]; //对还未覆盖的区间进行修改
        if (!t[i].cov) //如果该区间为被覆盖，就从下面的子节点上传被覆盖的长度
            if (l == r)
                t[i].len = 0; //前面说到的如果说到了叶节点就不能上传
            else
                t[i].len = t[i << 1].len + t[i << 1 | 1].len;
        return;
    }
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)
        update(i << 1, l, r, v);
    else if (l > mid)
        update(i << 1 | 1, l, r, v);
    else
        update(i << 1, l, mid, v), update(i << 1 | 1, mid + 1, r, v);
    if (!t[i].cov)
        t[i].len = t[i << 1].len + t[i << 1 | 1].len; //上传
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &l[i], &r[i]);
        q[++tot] = l[i];
        q[++tot] = r[i]; //预存
    }
    sort(q + 1, q + tot + 1);                     //排序
    int cnt = unique(q + 1, q + tot + 1) - q - 1; //去重
    build(1, 1, cnt - 1);
    for (int i = 1; i <= n; i++)
    {
        l[i] = lower_bound(q + 1, q + cnt + 1, l[i]) - q;
        r[i] = lower_bound(q + 1, q + cnt + 1, r[i]) - q - 1;
        update(1, l[i], r[i], 1);
    } //离散化同时处理出最后的情况
    for (int i = 1; i <= n; i++)
    {
        update(1, l[i], r[i], -1);
        ans = max(ans, t[1].len);
        update(1, l[i], r[i], 1);
    } //枚举所有的情况并求出最大的答案
    printf("%d\n", ans);
    return 0;
}