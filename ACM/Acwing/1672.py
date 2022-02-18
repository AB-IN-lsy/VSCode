'''
Author: NEFU AB-IN
Date: 2022-02-15 14:25:51
FilePath: \ACM\Acwing\1672.py
LastEditTime: 2022-02-15 14:29:44
'''
if __name__ == "__main__":
    n = int(input())
    a = input()
    b = input()

    flag = 0  #处于不反转状态
    res = 0
    for i in range(n):
        if b[i] != a[i] and flag == 0:
            flag = 1
            res += 1
        elif b[i] == a[i] and flag == 1:
            flag = 0
    print(res)