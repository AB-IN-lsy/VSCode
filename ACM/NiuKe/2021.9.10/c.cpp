/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-11 16:25:46
 * @FilePath: \Vscode\ACM\NiuKe\2021.9.10\c.cpp
 * @LastEditTime: 2021-09-11 16:30:10
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

namespace IO
{
    char ibuf[1 << 21], *ip = ibuf, *ip_ = ibuf;
    char obuf[1 << 21], *op = obuf, *op_ = obuf + (1 << 21);
    inline char gc()
    {
        if (ip != ip_)
            return *ip++;
        ip = ibuf;
        ip_ = ip + fread(ibuf, 1, 1 << 21, stdin);
        return ip == ip_ ? EOF : *ip++;
    }
    inline void pc(char c)
    {
        if (op == op_)
            fwrite(obuf, 1, 1 << 21, stdout), op = obuf;
        *op++ = c;
    }
    inline __int128_t read()
    {
        __int128_t x = 0, ch = gc(), w = 1;
        for (; ch < '0' || ch > '9'; ch = gc())
            if (ch == '-')
                w = -1;
        for (; ch >= '0' && ch <= '9'; ch = gc())
            x = x * 10 + ch - 48;
        return w * x;
    }
    template <class I>
    inline void write(I x)
    {
        if (x < 0)
            pc('-'), x = -x;
        if (x > 9)
            write(x / 10);
        pc(x % 10 + '0');
    }
    class flusher_
    {
    public:
        ~flusher_()
        {
            if (op != obuf)
                fwrite(obuf, 1, op - obuf, stdout);
        }
    } IO_flusher;
}
using namespace IO;

int n, k;
const __int128_t one = 1;

signed main()
{
    scanf("%d %d", &n, &k);
    __int128_t ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans ^= read();
    }
    write(max(ans, ans ^ ((one << k) - 1)));
    return 0;
}