'''
Author: NEFU AB-IN
Date: 2021-12-18 20:54:00
FilePath: \DCAS\substitution.py
LastEditTime: 2021-12-18 21:40:04
'''


def printD(d):
    print(list(d.keys()))
    print(list(d.values()))


def solve():
    # plaintext = input("Please input the plaintext: ")
    plaintext = "VACCINATION IMMUNISES"
    ciphertext = input("Please input the ciphertext: ")
    d = dict()
    cnt_cipher = dict()
    for i in range(ord("A"), ord("Z") + 1):
        d.setdefault(chr(i), '0')
        cnt_cipher.setdefault(chr(i), 0)
    for i in range(len(plaintext)):
        if not plaintext[i].isalpha():
            continue
        if d[plaintext[i]] != '0' and d[plaintext[i]] != ciphertext[i]:
            print("There exists collsion")
            print(
                f"{plaintext[i]} -> old : {d[plaintext[i]]} , new : {ciphertext[i]}"
            )
        if d[plaintext[i]] == '0':
            if cnt_cipher[ciphertext[i]] != 0:
                print(f"There exists collsion on cipher {ciphertext[i]}")
        cnt_cipher[ciphertext[i]] = 1
        d[plaintext[i]] = ciphertext[i]
    printD(d)
    return


if __name__ == "__main__":
    solve()