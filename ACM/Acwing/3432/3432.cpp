/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-28 00:12:27
 * @FilePath: \Acwing\3432\3432.cpp
 * @LastEditTime: 2022-07-28 00:12:57
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    function<int(int, int)> dfs = [&](int x, int y) {
        if (x == y)
            return x;
        if (x > y)
            swap(x, y);
        return dfs(x, y / 2);
    };

    cout << dfs(x, y) << '\n';
}