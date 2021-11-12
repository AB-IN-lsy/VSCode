'''
Author: NEFU AB-IN
Date: 2021-11-05 19:16:12
FilePath: \ACM\test.py
LastEditTime: 2021-11-05 19:53:59
'''


def f(x):
    if x == '1':
        return '0'
    else:
        return '1'


d = dict()

for _ in range(int(input())):
    i = int(input())
    s = list(str(bin(i))[2:])
    x = i
    cnt = 0
    flag = 0
    while x:
        if s.count('1') & 1:
            s[len(s) - 1] = f(s[len(s) - 1])
        else:
            s[0] = f(s[0])
        count = 0
        if s != ['0']:
            for j in range(len(s)):
                if s[j] == '0':
                    count += 1
                else:
                    break
        s = s[count:]
        s = "".join(s)
        x = int(s, 2)
        s = list(s)
        try:
            cnt += 1
            if d[x]:
                cnt += d[x]
                flag = 1
        except:
            continue
        if flag:
            break
    d[i] = cnt
    print(cnt)
