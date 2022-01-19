'''
Author: NEFU AB-IN
Date: 2022-01-14 01:49:01
FilePath: \ACM\Acwing\2058.1.py
LastEditTime: 2022-01-14 01:53:48
'''


def solve():
    two = input()
    three = input()
    for i in range(len(two)):
        for j in range(len(three)):
            two1, three1 = int(two[i]), int(three[j])
            for o in range(2):
                for k in range(3):
                    if o != two1 and k != three1:
                        res1 = two[:i] + str(o) + two[i + 1:]
                        res2 = three[:j] + str(k) + three[j + 1:]
                        if int(res1, 2) == int(res2, 3):
                            print(int(res1, 2))
                            return


if __name__ == "__main__":
    solve()