/*
 * @Author: Icey_dying
 * @Date: 2021-10-10 12:15:14
 * @LastEditors: Icey_dying
 * @LastEditTime: 2021-10-10 14:11:58
 * @FilePath: \Icey_dying\competition\2021\2021.10\2021.10.10\1006.cpp
 */
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 5;
char a[N];
int t, cnt[N];
long long nn[N], uu[N], hh[N], ee[N], ans1[N], ans2[N], ans3[N], ans4[N], ans5[N], ans6[N], ans7[N], ans8[N], ans9[N],
    emm[N];
int cnt1, cnt2, cnt3, cnt4;
int main()
{
    emm[0] = 0;
    emm[1] = 1;
    for (int i = 2; i <= 100000; i++)
        emm[i] = (2 * emm[i - 1] + 1) % mod;
    cin >> t;
    while (t--)
    {
        cin >> a + 1;
        int len = strlen(a + 1);
        memset(cnt, 0, sizeof(cnt));
        cnt1 = cnt2 = cnt3 = cnt4 = 0;
        for (int i = 1; i <= strlen(a + 1); i++)
        {
            cnt[i] = cnt[i - 1];
            if (a[i] == 'n')
                nn[++cnt1] = i;
            else if (a[i] == 'u')
                uu[++cnt2] = i;
            else if (a[i] == 'h')
                hh[++cnt3] = i;
            else if (a[i] == 'e')
                ee[++cnt4] = i;
            else if (a[i] == 'a')
                cnt[i]++;
        }
        if (!(cnt1 >= 2 && cnt2 >= 1 && cnt3 >= 4 && cnt4 >= 2))
        {
            cout << 0 << endl;
            continue;
        }
        // 最后一个h
        for (int i = cnt3; i >= 1; i--)
            ans1[i] = emm[cnt[len] - cnt[hh[i]]];
        for (int i = cnt3 - 1; i >= 1; i--)
            ans1[i] = (ans1[i] + ans1[i + 1]) % mod;
        // 最后一个e
        for (int i = cnt4; i >= 1; i--)
        {
            int wow = upper_bound(hh + 1, hh + 1 + cnt3, ee[i]) - hh;
            if (wow == cnt3 + 1)
                ans2[i] = 0;
            else
                ans2[i] = ans1[wow];
        }
        for (int i = cnt4 - 1; i >= 1; i--)
            ans2[i] = (ans2[i] + ans2[i + 1]) % mod;
        // 倒数第二个h
        for (int i = cnt3; i >= 1; i--)
        {
            int wow = upper_bound(ee + 1, ee + 1 + cnt4, hh[i]) - ee;
            if (wow == cnt4 + 1)
                ans3[i] = 0;
            else
                ans3[i] = ans2[wow];
        }
        for (int i = cnt3 - 1; i >= 1; i--)
            ans3[i] = (ans3[i] + ans3[i + 1]) % mod;
        // 倒数第三个h
        for (int i = cnt3; i >= 1; i--)
        {
            int wow = upper_bound(hh + 1, hh + 1 + cnt3, hh[i]) - hh;
            if (wow == cnt3 + 1)
                ans4[i] = 0;
            else
                ans4[i] = ans3[wow];
        }
        for (int i = cnt3 - 1; i >= 1; i--)
            ans4[i] = (ans4[i] + ans4[i + 1]) % mod;
        // 倒数第二个e
        for (int i = cnt4; i >= 1; i--)
        {
            int wow = upper_bound(hh + 1, hh + 1 + cnt3, ee[i]) - hh;
            if (wow == cnt3 + 1)
                ans5[i] = 0;
            else
                ans5[i] = ans4[wow];
        }
        for (int i = cnt4 - 1; i >= 1; i--)
            ans5[i] = (ans5[i] + ans5[i + 1]) % mod;
        // 倒数第四个h
        for (int i = cnt3; i >= 1; i--)
        {
            int wow = upper_bound(ee + 1, ee + 1 + cnt4, hh[i]) - ee;
            if (wow == cnt4 + 1)
                ans6[i] = 0;
            else
                ans6[i] = ans5[wow];
        }
        for (int i = cnt3 - 1; i >= 1; i--)
            ans6[i] = (ans6[i] + ans6[i + 1]) % mod;
        // 最后一个n
        for (int i = cnt1; i >= 1; i--)
        {
            int wow = upper_bound(hh + 1, hh + 1 + cnt3, nn[i]) - hh;
            if (wow == 1 + cnt3)
                ans7[i] = 0;
            else
                ans7[i] = ans6[wow];
        }
        for (int i = cnt1 - 1; i >= 1; i--)
            ans7[i] = (ans7[i] + ans7[i + 1]) % mod;
        // 最后一个u
        for (int i = cnt2; i >= 1; i--)
        {
            int wow = upper_bound(nn + 1, nn + cnt1 + 1, uu[i]) - nn;
            if (wow == cnt1 + 1)
                ans8[i] = 0;
            else
                ans8[i] = ans7[wow];
        }
        for (int i = cnt2 - 1; i >= 1; i--)
            ans8[i] = (ans8[i] + ans8[i + 1]) % mod;
        // 第一个n
        for (int i = cnt1; i >= 1; i--)
        {
            int wow = upper_bound(uu + 1, uu + 1 + cnt2, nn[i]) - uu;
            if (wow == cnt2 + 1)
                ans9[i] = 0;
            else
                ans9[i] = ans8[wow];
        }
        for (int i = cnt1 - 1; i >= 1; i--)
            ans9[i] = (ans9[i] + ans9[i + 1]) % mod;
        cout << ans9[1] << endl;
    }
    return 0;
}