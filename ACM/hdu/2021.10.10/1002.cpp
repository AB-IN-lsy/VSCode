/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-13 18:33:55
 * @FilePath: \ACM\Hdu\2021.10.10\1002.cpp
 * @LastEditTime: 2021-10-13 18:33:56
 */
#include <bits/stdc++.h>
#define fo(a, b, c) for (int a = b; a < c; a++)
using namespace std;
typedef long long ll;

int main()
{
    int t;
    double a, b, c, X0, X1, Y0, Y1, Y2;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> X0 >> X1 >> Y0 >> Y1 >> Y2;
        double p = b * b - 4 * a * (c - Y0);
        if (p <= 0)
        {
            cout << "No" << endl;
            continue;
        }
        double x2 = (-b + sqrt(p)) / (2 * a);
        double x1 = (-b - sqrt(p)) / (2 * a); //右
        if (x2 >= X0 || x1 <= X0 || x1 == X1)
        {
            cout << "No" << endl;
            continue;
        }
        if (x1 > X0 && x1 < X1)
        {
            cout << "Yes" << endl;
            continue;
        }
        double yu = a * X1 * X1 + b * X1 + c;
        if (yu > Y2)
        {
            cout << "No" << endl;
            continue;
        }
        if (x1 > X1 && x1 < 2 * X1 - X0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
