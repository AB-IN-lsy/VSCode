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

class MyCircularDeque
{
  public:
#define SZ(X) ((int)(X).size())
    vector<int> q;
    int hh = 0, tt = 0;
    // 左闭右开，也就是tt表示队列最后一个元素的下一个

    int get(int x)
    {
        return (x + SZ(q)) % SZ(q);
    }

    MyCircularDeque(int k)
    {
        q.resize(k + 1);
        // 用tt和hh的差值表示状态，从0到k需要表示k+1种状态，所以需要开k+1大小的数组
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        hh = get(hh - 1);
        q[hh] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        q[tt] = value;
        tt = get(tt + 1);
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        hh = get(hh + 1);
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        tt = get(tt - 1);
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return q[hh];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return q[get(tt - 1)];
    }

    bool isEmpty()
    {
        return hh == tt;
    }

    bool isFull()
    {
        return hh == get(tt + 1);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

signed main()
{
    IOS;

    return 0;
}