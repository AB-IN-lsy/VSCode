#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * @param n int����
     * @param k int����
     * @param Point int����vector
     * @return int����vector
     */
    vector<int> city(int n, int k, vector<int>& Point) {
        // write code here
        double mod = 1000000007;
        int a[n + 1];
        vector <int> b;
        for(int i = 0; i <= n; i++) b.push_back(0);
        int ans = 0;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= k; i++) a[i] = i;

        do{
            int mx = -1, index = -1;
            for(int i = 1; i <= n; i++){
                if(a[i] && Point[i - 1] > mx){
                    mx = Point[i];
                    index = i;
                }
            }
            ans ++;
            b[index] ++;
        }while(next_permutation(a + 1, a + 1 + n));

        for(int i = 1; i <= n; i++){
            b[i] = ((double) (b[i] / ans) * mod);
        }
        return b;
    }
};
int main()
{
    Solution solution;
    vector <int> l = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    vector <int> b;
    b = solution.city(9, 2, l);
    return 0;
}
