#include <algorithm>
#include <cstring>
#include <iostream>
#define SZ(X) ((int)X.size())
using namespace std;

typedef pair<int, int> PII;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    auto judge = [&](int k, int i, int j) {
        int x = a[k];
        if (x > 0)
        {
            if (x == i || x == j)
                return 1;
            return 0;
        }

        x = -x;
        if (x == i || x == j)
            return 0;
        return 1;
    };

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int s = judge(i, i, j) + judge(j, i, j);
            if (s != 1)
                continue;

            s = 0;
            for (int k = 1; k <= n; ++k)
            {
                s += judge(k, i, j);
            }
            if (s != 2)
                continue;

            cout << i << " " << j << '\n';
            return 0;
        }
    }
    cout << "No Solution";

    return 0;
}