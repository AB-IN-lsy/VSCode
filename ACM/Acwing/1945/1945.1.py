'''
Author: NEFU AB-IN
Date: 2022-02-09 16:59:54
FilePath: \ACM\Acwing\1945.1.py
LastEditTime: 2022-02-09 17:06:01
'''

lst = []

if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        x = int(input())
        lst.append(x)
    lst.sort()
    res = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            x = lst[j] - lst[i]
            l = j + 1  #两个端点从j+1开始往后取
            r = j + 1
            while l < n and lst[l] < lst[j] + x:
                l += 1
            while r < n and lst[r] <= lst[j] + 2 * x:  #小于等于就往后走
                r += 1
            res += r - l
    print(res)