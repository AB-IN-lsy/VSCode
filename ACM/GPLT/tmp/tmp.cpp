/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-19 17:55:57
 * @FilePath: \ACM\GPLT\tmp.cpp
 * @LastEditTime: 2022-04-21 21:12:14
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

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_run(int year)
{
    return (year % 100 && year % 4 == 0) || year % 400 == 0;
}

bool check(int year, int month, int day)
{
    if (year < 1900 || year > 2050)
        return false;
    if (month != 2)
    {
        return (1 <= month && month <= 12) && (0 < day && day <= months[month]);
    }
    else
    {
        bool leap = check_run(year);
        return day <= months[2] + leap;
    }
}

signed main()
{
    int year, month, day;
    printf("Please input the date (format as xxxx-xx-xx): ");
    scanf("%lld-%lld-%lld", &year, &month, &day);
    if (!check(year, month, day))
    {
        printf("0-%lld-%lld\n", month, day);
        return 0;
    }
    day -= 1;
    if (day == 0)
    {
        month -= 1;
        if (month == 0)
        {
            year -= 1;
            month = 12;
        }
        day = months[month] + (month == 2 ? check_run(year) : 0);
    }
    if (check(year, month, day))
    {
        printf("%lld-%lld-%lld\n", year, month, day);
    }
    else
    {
        printf("0-%lld-%lld\n", month, day);
    }
    return 0;
}