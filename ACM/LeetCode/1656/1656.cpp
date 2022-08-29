/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-24 14:38:01
 * @FilePath: \LeetCode\1656\1656.cpp
 * @LastEditTime: 2022-08-24 14:39:13
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

class OrderedStream
{
#define SZ(X) ((int)(X).size())
  public:
    vector<string> q;
    int ptr = 1;

    OrderedStream(int n)
    {
        q.resize(n + 1);
    }

    vector<string> insert(int idKey, string value)
    {
        q[idKey] = value;
        int i = 1;
        for (auto v : q)
        {
            if (i == ptr)
                break;
            ++i;
        }
        vector<string> ans;
        if (i == SZ(q))
            return ans;
        for (; i < SZ(q); ++i)
        {
            if (q[i] != "")
                ans.push_back(q[i]);
            else
                break;
        }
        ptr = i;
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
signed main()
{
    IOS;

    return 0;
}