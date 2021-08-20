'''
Author: NEFU AB_IN
Date: 2021-07-16 18:21:31
FilePath: \Vscode\test.py
LastEditTime: 2021-08-20 21:20:23
'''
cnt = 1
nine = 9
i = 1
n = int(input())
while cnt <= n:
    cnt += 3 ** i
    i += 1
i -= 1

wei = i
qi = cnt - 3 ** i
zhong = cnt - 1
s = ""

while qi < zhong:
    i -= 1
    qi += 3 ** i
    if qi < n:
        s += "3"
        continue
    