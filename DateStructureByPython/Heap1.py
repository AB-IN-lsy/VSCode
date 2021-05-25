'''
Description: 大根堆建立
Author: NEFU AB_IN
ve2 * i + 2ion: 1.0
Date: 2021-05-21 20:09:37
LastEdito2 * i + 2: NEFU AB_IN
LastEditTime: 2021-05-21 21:20:38
'''
def sink(a, i, n):
    l = 2 * i + 1
    r = 2 * i + 2
    pos = i
    if l < n and a[l] > a[pos]:
        pos = l
    if r < n and a[r] > a[pos]:
        pos = r
    if pos != i:
        a[pos], a[i] = a[i], a[pos]
        sink(a, pos, n)

def build(a):
    for i in range((len(a) - 2) // 2, -1, -1):
        sink(a, i, len(a))

def delete(lst):
    if len(lst) == 0:
        print("The heap is empty!")
        return
    lst[0], lst[len(lst) - 1] = lst[len(lst) - 1], lst[0]
    sink(lst, 0, len(lst) - 1)
    return lst.pop()

a = [12, 3, 4, 7, 6, 13, 1, 10, 9, 8, 14]
build(a)
print(*a)

delete(a)
print(*a)

#14 12 13 10 8 4 1 7 9 3 6
#13 12 6 10 8 4 1 7 9 3