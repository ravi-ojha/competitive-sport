def py_1():
	n,k = map(int,raw_input().split())
	a = map(int,raw_input().split())
	b = []
	for i in xrange(n):
		b.append([a[i],i])
	b.sort(key=lambda x: x[0])
	#print b
	res = 0
	ans = []
	i = 0
	while i < n and res < k:
		res += b[i][0]
		ans.append(str(b[i][1] + 1))
		i += 1
	if res > k:
		i -= 1
		del ans[-1]
	print i
	print ' '.join(ans)
py_1()
