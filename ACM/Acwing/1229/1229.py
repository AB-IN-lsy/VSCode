'''
Author: NEFU AB-IN
Date: 2022-03-25 15:32:34
FilePath: \ACM\Acwing\1229.py
LastEditTime: 2022-03-25 15:32:34
'''
mouths = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def check(year, mouth, day):
    year, mouth, day = map(int, [year, mouth, day])
    if mouth != 2:
        return 1 <= mouth <= 12 and 0 < day <= mouths[mouth]
    else:
        leap = year % 100 and year % 4 == 0 or year % 400 == 0
        return day <= mouths[2] + leap


ans = []
start = "19600101"
end = "20591231"
yy = ["19", "20"]
a, b, c = input().split("/")
#年/月/日
for y in yy:
    year = y + a
    if check(year, b, c) and start <= (year + b + c) <= end:
        ans.append("-".join([year, b, c]))
#月/日/年
for y in yy:
    year = y + c
    if check(year, a, b) and start <= (year + a + b) <= end:
        ans.append("-".join([year, a, b]))
#日/月/年
for y in yy:
    year = y + c
    if check(year, b, a) and start <= (year + b + a) <= end:
        ans.append("-".join([year, b, a]))

ans = sorted(list(set(ans)))
for date in ans:
    print(date)
