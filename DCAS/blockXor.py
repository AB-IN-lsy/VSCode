'''
Author: NEFU AB-IN
Date: 2021-12-09 20:06:58
FilePath: \DCAS\blockXor.py
LastEditTime: 2021-12-16 11:10:38
'''


def xor(x, k):
    x = int(x, 16)
    k = int(k, 16)
    return hex(x ^ k)[2:]


def solve():
    plaintext = input("Please input plaintext (16 Base): ")
    key = input("Please input key (16 Base): ")
    multiple = len(plaintext) / len(key)
    if int(multiple) != multiple:
        print("len of string is not satisfied")
        return
    ans = ""
    index = 0
    multiple = int(multiple)
    for i in range(0, len(plaintext), len(key)):
        ans += xor(plaintext[index:index + len(key)], key)
        index += len(key)
    print("ciphertext as hex (16 Base): " + ans)


if __name__ == "__main__":
    solve()
