while(True):
	a=input()
	a=a.split('.')
	f=True
	if len(a)==4:
			for x in a:#x为a里的元素，即全遍历一遍
				try:
					b=int(x)
				except ValueError:#判断是不是字母
					f=False
					break
				if 0<=b<=255:
					pass
				else:
					f=False
					break
	else:
			f=False
	if f:
			print('Y')
	else:
			print('N')
