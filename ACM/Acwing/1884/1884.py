'''
Author: NEFU AB-IN
Date: 2022-01-22 21:11:33
FilePath: \ACM\Acwing\1884.py
LastEditTime: 2022-01-22 21:11:34
'''
if __name__ == '__main__':
    n = int(input())
    s = input()
    c, o, w = 0, 0, 0
    for i in s:
        if i == 'C':
            c += 1
        elif i == 'O':
            o += c
        else:
            w += o
    print(w)