#include <bits/stdc++.h>

using namespace std;


class Solution
{
	public:
		int solve(int n,vector<int> &a)
		{
			priority_queue<int> q;
			int t=0;
			for(int i=0;i<n;i++)
                if(a[i]%2==0)
                    q.push(a[i]);
			while(!q.empty())
			{
				int p=q.top();
				while(q.top()==p&&!q.empty())
                    q.pop();
				p/=2;
				t++;
				if(p%2==0)
                    q.push(p);
			}
			return t;
		}
};
int main()
{
    Solution solution;
    vector<int> a = {4,2,2,3};
    cout<<solution.solve(4,a);
    return 0;
}
