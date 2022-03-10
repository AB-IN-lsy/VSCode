#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int get(int n)
{ // 求数n的位数
    int res = 0;
    while (n)
        res++, n /= 10;
    return res;
}

int count(int n, int i)
{ // 求从1到数n中数i出现的次数
    int res = 0, dgt = log10(n) + 1;

    for (int j = 1; j <= dgt; ++j)
    {
        /* p为当前遍历位次(第j位)的数大小 <10^(右边的数的位数)>, Ps:从左往右(从高位到低位)
            l为第j位的左边的数，r为右边的数，dj为第j位上的数 */
        int p = pow(10, dgt - j), l = n / p / 10, r = n % p, dj = n / p % 10;

        // ps:下文的xxx、yyy均只为使读者眼熟，并不严格只是三位数啊~ 然后后续的...就代表省略的位数啦~
        /* 求要选的数在i的左边的数小于l的情况：
（即视频中的xxx1yyy中的xxx的选法） --->
    1)、当i不为0时 xxx : 0...0 ~ l - 1, 即 l * (右边的数的位数) == l * p 种选法
    2)、当1位0时 由于不能有前导零 故xxx: 0....1 ~ l - 1,
                    即 (l-1) * (右边的数的位数) == (l-1) * p 种选法 */
        if (i)
            res += l * p;
        else
            res += (l - 1) * p;

        /* 求要选的数在i的左边的数等于l的情况：(即视频中的xxx == l 时)
    （即视频中的xxx1yyy中的yyy的选法）--->
                        1)、i > dj时 0种选法
                        2)、i == dj时 yyy : 0...0 ~ r 即 r + 1 种选法
                        3)、i < dj时 yyy : 0...0 ~ 9...9 即 10^(右边的数的位数) == p 种选法 */
        if (i == dj)
            res += r + 1;
        if (i < dj)
            res += p;
    }

    return res; // 返回结果
}

int main()
{
    int a, b;
    while (cin >> a >> b, a)
    { // 输入处理，直到输入为0停止
        if (a > b)
            swap(a, b); // 预处理-->让a为较小值，b为较大值
        for (int i = 0; i <= 9; ++i)
            cout << count(b, i) - count(a - 1, i) << ' ';
        // 输出每一位数字(0 ~ 9)分别在[a,b]中出现的次数<利用前缀和思想：[l,r]的和=s[r] - s[l - 1]>
        cout << endl; //换行
    }

    return 0; // 惯例：结束快乐~
}
