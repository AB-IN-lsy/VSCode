
    vector<int> ans[N];
    int mx = 0;
    for (int i = 1; i <= n; ++i)
    {
        dfs(-1, i);
        mx = max(mx, d);
        ans[d].push_back(i);
        d = 0;
    }

    printf("%lld", ans[mx][0]);
    for (int i = 1; i < SZ(ans[mx]); ++i)
    {
        printf(" %lld", ans[mx][i]);
    }