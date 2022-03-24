'''
Author: NEFU AB-IN
Date: 2022-03-23 21:38:44
FilePath: \ACM\Acwing\1714.py
LastEditTime: 2022-03-23 21:41:19
'''
c1, m1 = map(int, input().split())
c2, m2 = map(int, input().split())
c3, m3 = map(int, input().split())

for i in range(33):
    m1_1 = max(0, m1 - (c2 - m2))
    m2 = min(m2 + m1, c2)
    m1 = m1_1

    m2_1 = max(0, m2 - (c3 - m3))
    m3 = min(m3 + m2, c3)
    m2 = m2_1

    m3_1 = max(0, m3 - (c1 - m1))
    m1 = min(m1 + m3, c1)
    m3 = m3_1

m1_1 = max(0, m1 - (c2 - m2))
m2 = min(m2 + m1, c2)
m1 = m1_1

print(m1)
print(m2)
print(m3)
