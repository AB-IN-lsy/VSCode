'''
Author: NEFU AB-IN
Date: 2022-03-30 19:22:26
FilePath: \ACM\Acwing\1235.1.py
LastEditTime: 2022-03-30 19:22:27
'''
n, s = map(int, input().split())  #从键盘输入人数和消费的金额
a = list(map(int, input().split()))  #将键盘输入的转换为列表
ave = s / n  #计算平均值
a.sort()  #排序
b = 0
for i in range(n):
    if a[i] <= s / (n - i):
        b += pow(a[i] - ave, 2)  #计算平方差
    else:
        b += pow(s / (n - i) - ave, 2) * (n - i)
        break
    s -= a[i]

b = (b / n)**0.5
print("{:.4f}".format(b))  #输出最小标准差
