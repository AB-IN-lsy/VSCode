'''
Author: NEFU AB-IN
Date: 2022-02-10 15:18:39
FilePath: \ACM\Acwing\1696.py
LastEditTime: 2022-02-10 15:22:25
'''
if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    res = 0
    for i in range(n - 2, -1, -1):
        if a[i] > a[i + 1]:
            res = i + 1
            break
    print(res)