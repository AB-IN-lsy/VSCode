'''
Author: NEFU AB-IN
Date: 2021-11-05 19:16:12
FilePath: \ACM\test.py
LastEditTime: 2021-11-05 19:37:19
'''


def f(x):
    if x == '1':
        return '0'
    else:
        return '1'


for i in range(100):
    s = list(str(bin(i))[2:])
    x = i
    cnt = 0
    while x:
        if s.count('1') & 1:
            s[len(s) - 1] = f(s[len(s) - 1])
        else:
            s[0] = f(s[0])
        count = 0
        if s != ['0']:
            for i in range(len(s)):
                if s[i] == '0':
                    count += 1
                else:
                    break
        s = s[count:]
        s = "".join(s)
        x = int(s, 2)
        s = list(s)
        cnt += 1
    print(f'{i} :{cnt}')
