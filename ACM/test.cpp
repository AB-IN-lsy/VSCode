/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-25 10:13:38
 * @FilePath: \ACM\test.cpp
 * @LastEditTime: 2022-05-20 14:27:26
 */
#include <iostream>
using namespace std;

int rSum(int j)
{
    int sum = 0;
    while (j != 0)
    {
        sum = sum * 10 + (j % 10);
        j = j / 10;
    }
    return sum;
}

int main()
{
    int n, m, i;

    cin >> n >> m;
    for (i = n; i < m; i++)
        if (i == rSum(i))
            cout << i << ' ';
    cout << 56 * 1344;
    return 0;
}