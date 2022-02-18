'''
Author: NEFU AB-IN
Date: 2022-02-12 17:45:15
FilePath: \ACM\Acwing\2014.py
LastEditTime: 2022-02-13 11:06:41
'''

xs = []  #原数组去重
a = []  #排序数组

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        x = int(input())
        xs.append(x)

    xs = [xs[i] for i in range(n) if i == 0 or xs[i - 1] != xs[i]]  #去重相邻元素
    xs = [0, *xs, 0]
    a = [[xs[i], i] for i in range(1, len(xs) - 1)]
    a.sort()  #所以说a排完序之后，可能还会有相同的数相邻（是原数组里隔开的两个相同的数）

    # 注意 c++里的去重，是先将数组排好序，再用unique去重相邻元素，就是将数组中的数都去重了
    # 但如果只用unique，只会去重相邻元素
    # python里的去重，list(set(xs))，直接将数组中的数都去重了
    # 这里需要的只是去重相邻元素! 故不能用list(set(xs))

    res, cnt = 1, 1
    for i in range(len(a) - 1):
        id = a[i][1]
        if xs[id] > xs[id + 1] and xs[id] > xs[id - 1]:
            cnt -= 1
        if xs[id] < xs[id + 1] and xs[id] < xs[id - 1]:
            cnt += 1

        if a[i][0] != a[i + 1][0]:  #相同时不更新，要等到不相同时才更新
            res = max(res, cnt)

    print(res)