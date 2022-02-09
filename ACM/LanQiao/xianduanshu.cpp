/*
 * @Author: NEFU AB-IN
 * @Date: 2022-02-08 09:41:13
 * @FilePath: \ACM\LanQiao\xianduanshu.cpp
 * @LastEditTime: 2022-02-08 09:55:19
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 1e5 + 10;

//定义根结点是tree[1]，即编号为1的结点是根
int tree[N * 4]; //用tree[i]记录线段i的最值或区间和
//满足下面的父子关系。结点p是父，结点ls(p)是左儿子，rs(p)是右儿子
int ls(int p)
{
    return p << 1;
} //左儿子，编号是 p*2
int rs(int p)
{
    return p << 1 | 1;
} //右儿子，编号是 p*2+1

void push_up(int p)
{ //从下往上传递区间值
    // tree[p] = tree[ls(p)] + tree[rs(p)];      //区间和
    tree[p] = max(tree[ls(p)], tree[rs(p)]); //区间最大值
}
void build(int p, int pl, int pr)
{ //结点编号p指向区间[pl, pr]
    if (pl == pr)
    { //到达最底层的叶子，存叶子的值
        tree[p] = -INF;
        return;
    }
    int mid = (pl + pr) >> 1;  //分治：折半
    build(ls(p), pl, mid);     //递归左儿子
    build(rs(p), mid + 1, pr); //递归右儿子
    push_up(p);                //从下往上传递区间值
}
void update(int p, int pl, int pr, int L, int R, int d)
{
    //区间修改,更新[L, R]内最大值
    if (L <= pl && pr <= R)
    {
        //完全覆盖，直接返回这个结点，它的子树不用再深入了
        tree[p] = d;
        return;
    }
    int mid = (pl + pr) >> 1;
    if (L <= mid)
        update(ls(p), pl, mid, L, R, d); //递归左子树
    if (R > mid)
        update(rs(p), mid + 1, pr, L, R, d); //递归右子树
    push_up(p);                              //更新
    return;
}

int query(int p, int pl, int pr, int L, int R)
{ //在查询区间[L, R]的最大值
    int res = -INF;
    if (L <= pl && pr <= R) //完全覆盖
        return tree[p];
    int mid = (pl + pr) >> 1;
    if (L <= mid)
        res = max(res, query(ls(p), pl, mid, L, R));
    // L与左部分有重叠
    if (R > mid)
        res = max(res, query(rs(p), mid + 1, pr, L, R));
    // R与右部分有重叠
    return res;
}
signed main()
{
    IOS;

    return 0;
}