'''
Author: NEFU AB-IN
Date: 2021-12-09 20:06:58
FilePath: \DCAS\blockXor.py
LastEditTime: 2021-12-09 21:07:39
'''


def solve():
    plaintext = input("Please input plaintext: ")
    key = input("Please input key: ")
    multiple = len(plaintext) / len(key)
    if int(multiple) != multiple:
        print("len of string is not satisfied")
        return
    key = key * int(multiple)
    plaintext = int(plaintext, 16)
    key = int(key, 16)
    print("ciphertext as hex: " + hex(key ^ plaintext)[2:])


if __name__ == "__main__":
    solve()
