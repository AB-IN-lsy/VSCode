#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * @param k int���� ��ʾ��ȫk�����Ĳ���k
     * @param a int����vector ��ʾ�����ȫk������Bfs�������еĽ����
     * @return long������
     */
    long long tree2(int k, vector<int>& a) {
        // write code here
        int n = a.size(), x = 0, num = 1;
        long long ans = 0;
        while(n > 0){
            for(int j = 1; j <= num; j++){
                for(int i = 1; i <= k; i++){
                    int id = x + i + num + (k * (j - 1)) - 1;
                    if(id >= a.size()) return ans;
                    ans += (a[x] ^ a[id]);
                }
                x ++;
            }
            x += (num - 1);
            n -= num;
            num *= k;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> a = {1,2,3,4,5};
    cout<<solution.tree2(2,a);
    return 0;
}
