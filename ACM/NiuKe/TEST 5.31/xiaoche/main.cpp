#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --)
    {
        int n, a, b;
        scanf("%d", &n);
        set <int> sta;
        map <int, int> aa, bb;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d%d", &a, &b);
            sta.insert(a);
            sta.insert(b);
            aa[a] ++;
            bb[b] ++;
        }
        int mp = 0, np = 0;
        set<int>::iterator it;
        for(it = sta.begin(); it != sta.end(); it ++)
        {
            int j = *it;
            np += aa[j] - bb[j];
            if (np > mp)
                mp = np;
        }
        printf("%d %d\n", sta.size(), mp);
    }
    return 0;
}
