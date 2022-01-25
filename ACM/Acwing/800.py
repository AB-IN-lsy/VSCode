'''
Author: NEFU AB-IN
Date: 2022-01-25 18:25:39
FilePath: \ACM\Acwing\800.py
LastEditTime: 2022-01-25 19:13:21
'''
if __name__ == "__main__":
    n, m, x = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    # 对于每个i都在B里找到一个j，使得a[i] + b[j] >= x，并且j是最靠左的一个
    # 所以就有了单调性，i往右走，j往左走

    j = m - 1
    for i in range(n):
        while j >= 0 and A[i] + B[j] > x:
            j -= 1
        if A[i] + B[j] == x:
            print(i, j)
            exit(0)