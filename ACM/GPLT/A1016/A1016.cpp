/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-04 10:54:05
 * @FilePath: \GPLT\A1016\A1016.cpp
 * @LastEditTime: 2023-01-04 11:17:33
 */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int N = 1010, M = 31 * 1440 + 10;

int n;
int cost[24];
double sum[M]; // 存储一个月内所有分钟数的前缀和

struct records
{
    int minutes;        // 把时间转换为分钟
    string state;       // on-line or off-line
    string format_time; // 格式化时间

    bool operator<(const records &t) const
    {
        return minutes < t.minutes;
    }
};

map<string, vector<records>> persons;

int main()
{

    for (int i = 0; i < 24; i++)
        cin >> cost[i];

    // 计算一个月内所有分钟数对应的钱数
    for (int i = 0; i < M; i++)
        sum[i] = sum[i - 1] + cost[(i - 1) % 1440 / 60] / 100.0; // 减1，算前一个时刻所在分段

    cin >> n;

    // 读入数据
    char name[50], state[10], format_time[20];
    int month, day, hour, minute;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, state);

        int minutes = day * 1440 + hour * 60 + minute; // 算距离第一天的距离？？？

        sprintf(format_time, "%02d:%02d:%02d", day, hour, minute); // 格式化字符串

        persons[name].push_back({minutes, state, format_time});
    }

    for (auto &person : persons)
    {
        auto name = person.first;
        auto record = person.second;
        sort(record.begin(), record.end());

        // 然后开始找，一前一后是on和off对应的计算时间和话费
        double total_money = 0; // 总的钱数
        double each_money = 0;
        for (int i = 0; i + 1 < record.size(); i++)
        {
            auto a = record[i], b = record[i + 1];

            if (a.state == "on-line" && b.state == "off-line")
            {
                // 钱为0时，输出这个人名和月份。钱为0准定是新一个人了。
                if (!total_money)
                    printf("%s %02d\n", name.c_str(), month); // c_str()用来转成字符串

                cout << a.format_time << ' ' << b.format_time;

                each_money = sum[b.minutes] - sum[a.minutes]; // 不算a的钱
                printf(" %d $%.2lf\n", b.minutes - a.minutes, each_money);

                total_money += each_money;
            }
        }

        if (total_money)
            printf("Total amount: $%.2lf\n", total_money);
    }

    return 0;
}