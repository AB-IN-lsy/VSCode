'''
Author: NEFU AB-IN
Date: 2022-03-24 20:34:28
FilePath: \ACM\Acwing\466.py
LastEditTime: 2022-03-24 20:50:12
'''
months = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


#再判断日期是否合法
def check(s):
    s = str(s)
    year = int(s[:4])
    month = int(s[4:6])
    day = int(s[6:])

    if month != 2:
        if 1 <= month <= 12 and 0 < day <= months[month]:
            return 1
        else:
            return 0
    else:
        judge = (year % 100 and year % 4 == 0) or year % 400 == 0
        return day <= months[2] + judge


start = input()
end = input()

ans = 0
#先枚举所有的回文串
for i in range(1000, 10000):
    s = str(i) + str(i)[::-1]
    #再判断是否在合法区间
    if start <= s <= end:
        ans += check(s)

print(ans)