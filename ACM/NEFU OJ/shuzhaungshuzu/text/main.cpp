#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * ����һ��������������Щ����������������ٵĲ�������
     * @param n int���� ����һ���ж�����
     * @param a int����vector ����n�����ֵ�ֵ
     * @return int����
     */
     map<int,int>vis;
    int solve(int n, vector<int>& a) {
        int cnt=0;
        // write code here
        sort(a.begin(),a.end(),less<int>());
        for(int i=0;i<a.size();i++)
        {
            cnt=0;
            if(a[i]&1) continue;
            else while(a[i]>1&&(!(a[i]&1))&&(!vis[a[i]]))
            {
                a[i]=a[i]/2;
                vis[a[i]]=1;
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution solution;
    vector<int>a;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++) cin>>x,a.push_back(x);
    cout<<solution.solve(n,a)<<endl;
    return 0;
}
