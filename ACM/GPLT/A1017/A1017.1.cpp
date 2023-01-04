/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-04 18:37:41
 * @FilePath: \GPLT\A1017\A1017.1.cpp
 * @LastEditTime: 2023-01-04 18:46:44
 */
/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-04 11:58:48
 * @FilePath: \GPLT\A1017\A1017.cpp
 * @LastEditTime: 2023-01-04 12:19:00
 */
#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())

using namespace std;

struct sa
{
    int time;
    int ptime;
    int wtime;
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<sa> a(n);
    int b = 8 * 60 * 60;
    int e = 17 * 60 * 60;
    for (int i = 0; i < n; ++i)
    {
        int hh, mm, ss;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &a[i].ptime);
        a[i].ptime = min(a[i].ptime, 60);
        a[i].ptime *= 60;
        a[i].time = hh * 60 * 60 + mm * 60 + ss;
        if (a[i].time < b)
        {
            a[i].wtime = b - a[i].time;
            a[i].time = b;
        }
    }
    auto cmp = [&](const sa a, const sa b) {
        if (a.time != b.time)
            return a.time < b.time;
        else
            return a.ptime < b.ptime;
    };
    sort(a.begin(), a.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> q; // 存放结束时间
    double res = 0;
    int cnt = 0; // 超时人
    for (auto &[t, p, w] : a)
    {
        if (t >= e)
        {
            cnt++;
            continue;
        }
        if (SZ(q) < k)
        {
            q.push(t + p);
        }
        else
        {
            int t1 = q.top();
            q.pop();
            if (t1 > t)
                w += (t1 - t);
            q.push(max(t1, t) + p);
        }
        res += w;
        cout << t << " ";
        cout << w << '\n';
    }
    res /= 60.0;
    printf("%.1lf", res / (n - cnt));

    return 0;
}

/*
28800 1812
28800 2377
28800 2137
28800 752
28800 2063
28800 2037
28800 7411
28800 3588
28800 2839
28800 6951
28800 9136
28800 8869
28800 10933
28961 5479
29994 4626
31514 4306
33954 2226
36166 374
38463 0
40097 0
41169 0
41615 0
42574 0
42985 0
43421 0
45192 0
46014 0
46587 0
46957 0
48266 0
49420 0
50181 0
51572 0
52755 0
54059 0
54066 0
54161 0
54470 0
54705 810
55895 0
58852 0
59656 0
59827 0
30.5
*/