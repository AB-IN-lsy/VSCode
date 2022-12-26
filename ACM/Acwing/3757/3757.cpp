/*
 * @Author: NEFU AB-IN
 * @Date: 2022-12-06 11:34:45
 * @FilePath: \Acwing\3757\3757.cpp
 * @LastEditTime: 2022-12-06 17:35:24
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
void print(ListNode *head)
{
    for (ListNode *p = head; p; p = p->next)
    {
        cout << p->val << " ";
    }
    cout << '\n';
}
class Solution
{
  public:
    void rearrangedList(ListNode *head)
    {
        if (!head->next)
            return;

        int len = 0;
        for (auto p = head; p; p = p->next)
            len++;

        int left = (len + 1) / 2;

        auto a = head;
        // 跳到一半的地方
        for (int i = 0; i < left - 1; ++i)
            a = a->next;
        auto b = a->next, c = b->next;
        a->next = NULL, b->next = NULL;

        // 反转后半段
        while (c)
        {
            auto p = c->next;
            c->next = b;
            b = c, c = p;
        }

        // 合并链表，由于q少，故q为空时断
        for (auto p = head, q = b; q;)
        {
            auto o = q->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
            q = o;
        }
    }
};
signed main()
{
    IOS;
    Solution Solution;
    ListNode *head = new ListNode(1);
    ListNode *a1 = new ListNode(2);
    ListNode *a2 = new ListNode(3);
    ListNode *a3 = new ListNode(4);
    head->next = a1;
    a1->next = a2;
    a2->next = a3;
    Solution.rearrangedList(head);
    return 0;
}