'''
Author: NEFU AB-IN
Date: 2022-01-14 00:43:59
FilePath: \ACM\Acwing\2058.py
LastEditTime: 2022-01-14 01:37:18
'''

two_lst = []
three_lst = []


def solve():
    two = list(input())
    three = list(input())
    for i in range(len(two)):
        if two[i] == '0':
            two[i] = '1'
            two_lst.append((hash("".join(two)), "".join(two)))
            two[i] = '0'
        if two[i] == '1':
            two[i] = '0'
            two_lst.append((hash("".join(two)), "".join(two)))
            two[i] = '1'

    for i in range(len(three)):
        if three[i] == '0':
            three[i] = '1'
            tmp = bin(int("".join(three), 3))[2:]
            three_lst.append((hash("".join(tmp)), "".join(tmp)))
            three[i] = '2'
            tmp = bin(int("".join(three), 3))[2:]
            three_lst.append((hash("".join(tmp)), "".join(tmp)))
            three[i] = '0'
        if three[i] == '1':
            three[i] = '0'
            tmp = bin(int("".join(three), 3))[2:]
            three_lst.append((hash("".join(tmp)), "".join(tmp)))
            three[i] = '2'
            tmp = bin(int("".join(three), 3))[2:]
            three_lst.append((hash("".join(tmp)), "".join(tmp)))
            three[i] = '1'
        if three[i] == '2':
            three[i] = '0'
            tmp = bin(int("".join(three), 3))[2:]
            three_lst.append((hash("".join(tmp)), "".join(tmp)))
            three[i] = '1'
            tmp = bin(int("".join(three), 3))[2:]
            three_lst.append((hash("".join(tmp)), "".join(tmp)))
            three[i] = '2'

    for i in two_lst:
        for j in three_lst:
            if i[0] == j[0]:
                print(int(i[1], 2))
                return


if __name__ == "__main__":
    solve()
