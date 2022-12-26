/*
 * @Author: NEFU AB-IN
 * @Date: 2022-12-05 21:24:16
 * @FilePath: \Acwing\3756\3756.cpp
 * @LastEditTime: 2022-12-06 11:34:35
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

// #undef N
// const int N = 1e5 + 10;

// #undef int

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
#include <unordered_map>

class Solution
{
  public:
    ListNode *filterList(ListNode *head)
    {
        unordered_map<int, int> mp;
        auto p = head;
        // return head;
        mp[abs(p->val)] = 1;
        while (p->next)
        {
            auto t = p->next->val;
            if (mp.count(abs(t)))
            {
                auto tmp = p->next;
                p->next = tmp->next;
                delete tmp;
            }
            else
            {
                p = p->next;
                mp[abs(t)] = 1;
            }
        }
        return head;
    }
};

signed main()
{
    IOS;
    unordered_map<int, int> mp;
    return 0;
}