t = int(input())
for i in range(t):
	n = int(input())
	a = [int(i) for i in input().split()]
	a.sort()
	mx = 0
	for s in range (a[n-2]+a[n-1]+1):
		ans = 0
		p1 = 0
		p2 = n-1
		while p1<p2:
			if a[p1]+a[p2]==s:
				p1 += 1
				p2 -= 1
				ans += 1
			elif a[p1]+a[p2]>s:
				p2 -= 1
			else:
				p1 += 1
		mx = max(mx,ans)
		
	print(mx)
