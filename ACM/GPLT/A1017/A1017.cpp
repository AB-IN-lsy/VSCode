/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-04 11:58:48
 * @FilePath: \GPLT\A1017\A1017.cpp
 * @LastEditTime: 2023-01-04 20:28:07
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
    }
    auto cmp = [&](const sa a, const sa b) {
        if (a.time != b.time)
            return a.time < b.time;
        else
            return a.ptime < b.ptime;
    };
    sort(a.begin(), a.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> q; // 存放结束时间
    for (int i = 0; i < k; i++)
        q.push(b); // 先把m个窗口安排好
    double res = 0;
    int cnt = 0;
    for (auto &[t, p, w] : a)
    {
        if (t > e)
            break;
        int t1 = q.top();
        q.pop();
        if (t1 > t)
            w += (t1 - t);
        q.push(max(t1, t) + p);
        res += w;
        cnt++;
        // cout << t << " ";
        // cout << w << '\n';
    }
    printf("%.1lf", res / cnt / 60.0);

    return 0;
}
/*
22409 6391
22667 6133
23444 5356
24069 4731
24431 4369
26412 5868
26423 5977
26663 5737
26737 5663
26988 5412
27483 5637
28001 5419
28048 5552
28961 5659
29994 5646
31514 4366
33954 2046
36166 14
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
35.2
*/