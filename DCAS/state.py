'''
Author: NEFU AB-IN
Date: 2021-12-15 22:17:33
FilePath: \DCAS\state.py
LastEditTime: 2021-12-15 23:26:58
'''


def ex0(x):
    if len(x) <= 1:
        x = '0' * (2 - len(x)) + x
    return x


def solve():
    s = input("Please input the plaintext (ASCII): ")
    key_0 = [
        '66', '83', 'BE', 'E7', 'B3', '9C', '30', '98', '77', '17', '1A', '2A',
        '15', '70', 'A7', '94'
    ]
    l = len(s)
    cnt = 0
    state_num = l // 16
    if l % 16 != 0:
        print(
            "The len of plain text is not satisfy the mutiple of 16. So we pad as 00"
        )
    state_num += 1
    for k in range(state_num):
        array = [[0 for j in range(4)] for i in range(4)]
        for j in range(4):
            for i in range(4):
                if cnt < l:
                    array[i][j] = ex0(hex(ord(s[cnt]))[2:])
                else:
                    array[i][j] = '00'
                    if i == 3 and j == 3:
                        array[i][j] = ex0(hex(cnt - l)[2:])
                cnt += 1
        print(f'state{k + 1} (16 Base): ')
        for i in range(4):
            for j in range(4):
                print(array[i][j], end=" ")
            print()

        index = 0
        print(f'state{k + 1} after Round 0 (16 Base): ')
        for j in range(4):
            for i in range(4):
                ans = int(array[i][j], 16) ^ int(key_0[index], 16)
                array[i][j] = ex0(hex(ans)[2:])
                index += 1
        for i in range(4):
            for j in range(4):
                print(array[i][j], end=" ")
            print()
    return


if __name__ == "__main__":
    solve()