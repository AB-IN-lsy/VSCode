'''
Author: NEFU AB-IN
Date: 2022-03-25 16:31:10
FilePath: \ACM\Acwing\1231.py
LastEditTime: 2022-03-25 16:32:35
'''
for _ in range(int(input())):
    ans = 0
    for _ in range(2):
        a = list(input().split())
        for i in range(len(a)):
            if i == 2:
                ans += (int(a[i][2]) * 24 * 3600)
            else:
                h, m, s = map(int, a[i].split(":"))
                ans += ((-1)**(i + 1)) * (h * 3600 + m * 60 + s)
    ans //= 2
    print(f"{ans // 3600:02d}:{ans % 3600 // 60:02d}:{ans % 60:02d}")
