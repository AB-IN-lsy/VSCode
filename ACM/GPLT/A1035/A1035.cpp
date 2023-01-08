/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-08 18:49:01
 * @FilePath: \GPLT\A1035\A1035.cpp
 * @LastEditTime: 2023-01-08 18:49:25
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
struct sa
{
    string id, word;
};

unordered_map<char, char> mp = {{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};
vector<sa> v;

signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string id, word;
        cin >> id >> word;
        int flag = 0;
        for (int i = 0; i < SZ(word); ++i)
        {
            if (mp.count(word[i]))
            {
                word[i] = mp[word[i]];
                flag = 1;
            }
        }
        if (flag)
            v.push_back({id, word});
    }
    if (SZ(v))
    {
        cout << SZ(v) << '\n';
        for (auto [id, word] : v)
            cout << id << " " << word << '\n';
    }
    else
    {
        if (n > 1)
            printf("There are %lld accounts and no account is modified", n);
        else
            printf("There is 1 account and no account is modified");
    }
    return 0;
}