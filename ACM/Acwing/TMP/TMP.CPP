/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-25 20:05:38
 * @FilePath: \Acwing\TMP\TMP.CPP
 * @LastEditTime: 2023-09-09 18:53:56
 */
#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int dp[N];

#define int long long
#undef int

#define SZ(X) ((int)(X).size())

class Solution {
public:

    cosnt int N = 1e5 + 10, M = 18;
    int dp[N][M], Log[N];

    void init(int n, vector<int>& nums){
        nums.insert(nums.begin(), 0);
        for(int j = 0; j < M; ++ j){
            for(int i = 1; i + (1 << j) - 1 <= n; ++ i){
                if(j == 0) dp[i][j] = nums[i];
                else dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1])
            }
        }
        for(int i = 2; i < N; ++ i) Log[i] = Log[i >> 1] + 1;
    }

    int jump(vector<int>& nums) {
        init(SZ(nums), nums);
    }
};


signed main()
{
    // freopen("Tests/input_1.txt", "r", stdin);
    IOS;

    int n;
    cin >> n;

    unordered_map<char, PII> mp;

    char A = 'A';
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        mp[A] = {x, y};
        A = A + 1;
    }

    int ans = 0;
    string s;
    cin >> s;
    stack<PII> st;

    for (auto i : s)
    {
        if (i == '(')
            continue;
        else if (i == ')')
        {

            auto a = st.top();
            st.pop();
            auto b = st.top();
            st.pop();

            ans += a.first * a.second * b.first;
            st.push({b.first, a.second});
        }
        else
        {
            st.push({mp[i].first, mp[i].second});
        }
    }

    cout << ans;

    return 0;
}