'''
Author: NEFU AB-IN
Date: 2021-12-01 22:39:31
FilePath: \DCAS\test.py
LastEditTime: 2021-12-16 11:28:04
'''


def f(x):
    ans = 1
    for i in range(1, x + 1):
        ans *= i
    return ans


# print(f(26))

# print(len(str(403291461126605635584000000)))

for i in range(20):
    print(7**i % 13)

print(7**(16 * 11) % 13)
