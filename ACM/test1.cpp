#include <iostream>
using namespace std;
int MaxSubsequenceSum(const int array[], int n)
{
    int tempSum, maxSum;
    maxSum = 0;
    for (int i = 0; i < n; i++) // 子序列起始位置
    {
        for (int j = i; j < n; j++) // 子序列终止位置
        {
            tempSum = 0;
            for (int k = i; k < j; k++) // 子序列遍历求和
                tempSum += array[k];
            if (tempSum > maxSum) // 更新最大和值
                maxSum = tempSum;
        }
    }
    return maxSum;
}

int main()
{
    const int a[] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int maxSubSum = MaxSubsequenceSum(a, 8);
    cout << "The max subsequence sum of a is: " << maxSubSum << endl;
    system("pause");
    return 0;
}