'''
Author: NEFU AB-IN
Date: 2022-03-25 17:43:49
FilePath: \ACM\Acwing\1241.py
LastEditTime: 2022-03-25 17:45:24
'''


class Order():
    def __init__(self, time, shop):
        self.time = time
        self.shop = shop

    def __lt__(self, t):
        if self.shop != t.shop:
            return self.shop < t.shop
        return self.time < t.time


def judge(shop, cnt):
    if cnt <= 3:
        q[shop] = 0
    if cnt > 5:
        q[shop] = 1


n, m, t = map(int, input().split())
orders = []
st = [0] * (n + 1)
q = [0] * (n + 1)
for i in range(m):
    time, shop = map(int, input().split())
    orders.append(Order(time, shop))

orders.sort()
cnt = 0

for i in range(m):
    if st[orders[i].shop]:
        continue
    if i != m - 1 and orders[i].shop == orders[i + 1].shop:
        if t < orders[i].time:
            st[orders[i].shop] = 1
            break
        cnt += 2
        judge(orders[i].shop, cnt)
        if orders[i].time <= t < orders[i + 1].time:
            cnt -= (t - orders[i].time)
            judge(orders[i].shop, cnt)
            st[orders[i].shop] = 1
            break
        cnt -= (orders[i + 1].time - orders[i].time - 1)
        cnt = max(0, cnt)
        judge(orders[i].shop, cnt)
    else:
        cnt += 2
        cnt -= (t - orders[i].time)
        judge(orders[i].shop, cnt)
        st[orders[i].shop] = 1
        cnt = 0

ans = 0
for i in range(1, n + 1):
    ans += q[i]
print(ans)