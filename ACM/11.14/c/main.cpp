#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param k int整型 表示完全k叉树的叉数k
     * @param a int整型vector 表示这棵完全k叉树的Bfs遍历序列的结点编号
     * @return long长整型
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
