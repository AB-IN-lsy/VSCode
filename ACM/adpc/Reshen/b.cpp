/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-27 17:54:17
 * @FilePath: \ACM\adpc\Reshen\b.cpp
 * @LastEditTime: 2022-03-27 17:54:49
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
const int N = 1e6 + 5;
int n, k, f[N], id[N], sum, ans;
// f[i]表示前i个数中，删除掉第i个数并且满足题目要求，删掉数最小是多少
int head, tail, q[N];
//队首指针，队尾指针，单调队列

signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        //正难则反，我们改变思路，
        //求每隔不超过k个数 就必须删去一个数 使得删去数的和最小
        f[i] = q[head] + x; //我们引入单调队列的思想，
        //单调队列即在队列中的值是单调的，要不递增要不递减，本题是递减，
        //因为想贪心的从最小的f[]数组继承过来，
        //而这个f[]数组依次保存在q[]队列中，我们取队首肯定最小
        while (head <= tail && q[tail] > f[i])
            tail--;
        //因为q[]队列里面的数是单调的，那么当我们把f[i]添加进队尾时，
        //如果队尾的元素比f[i]大，那么不保证单调了，所以把比f[i]大的队尾元素弹出，弹出即tail--
        q[++tail] = f[i], id[tail] = i;
        // f[i]加入队尾，id保存队列中元素之前在数组中的位置
        while (head <= tail && id[head] < i - k)
            head++;
        //队首的元素如果跟i已经超过了k的距离，
        //那么就不符合每隔最多k个数就必须删除一个数的规则了，故要将不合法的队首值弹出，即head++
    }
    for (int i = n - k; i <= n; i++)
        ans = max(ans, sum - f[i]); //答案为之前所有数的总和减去f[n-k~k]之间的最小值
    cout << ans << endl;
    return 0;
}
