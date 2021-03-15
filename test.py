'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-01-28 23:02:48
LastEditors: NEFU AB_IN
LastEditTime: 2021-03-15 18:48:27
'''

while True:
    try:
        import re
        d = {}
        words = input()
        lst = re.split('[!\'"#$%&()*+,-./:;<=>?@^_`{|}~]',words)
        for i in lst:
            ll = list(i.split())
            h = []
            touzimu = ""
            for j in ll:
                if len(j) > 1 and j[0].isupper() and j[1:].islower():
                    h.append(j)
                    touzimu += j[0]
                else:
                    if len(h) >= 2:
                        d[" ".join(h)] = touzimu
                    h = []
                    touzimu = ""
            if len(h) >= 2:
                d[" ".join(h)] = touzimu
        cnt = 0
        for i in d:
            tmp = words.find(i)
            words = words.replace(i, str(cnt))
            cnt += 1
        nl = list(d.items())
        for i in range(cnt):
            words = words.replace(str(i), f"{nl[i][1]} ({nl[i][0]})")
        print(words)
    except:
        break
    