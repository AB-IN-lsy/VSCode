'''
Author: NEFU AB-IN
Date: 2022-02-08 16:10:23
FilePath: \ACM\Acwing\1752.1.py
LastEditTime: 2022-02-09 09:22:21
'''

lst = []

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        lst.append(list(map(int, input().split())))
    lst.sort()
    res = 0
    for i in range(n):  #枚举删哪个数
        cnt = 0
        st, ed = -1, -1  #设置维护的区间的起始和终止
        for j in range(n):
            if i != j:
                if ed < lst[j][0]:  #当维护的区间终点比枚举的区间起点小时，说明这个区间已经不会有别的区间和它交集了
                    #那么就记录区间，并设置新的起始和终止
                    if st != -1 and ed != -1:
                        cnt += ed - st
                    st = lst[j][0]
                    ed = lst[j][1]
                else:
                    #否则更新区间终止点的最大值
                    ed = max(ed, lst[j][1])
        #别忘了记录最后一个区间的
        if st != -1 and ed != -1:
            cnt += ed - st
        res = max(res, cnt)
    print(res)