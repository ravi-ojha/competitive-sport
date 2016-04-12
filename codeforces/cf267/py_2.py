def second():
	n = input()
	a = []
	for i in xrange(n):
		tmp = map(int,raw_input().split())
		a.append(tmp)
	xmax = 0
	ymax = 0
	i = 0
	while i < n:
		j = i
		curr = a[i][0]
		curr2 = a[i][1]
		while j < n:
			ymax = max(abs(curr - a[j][0]), ymax)
			xmax = max(abs(curr2 - a[j][1]), xmax)
			j += 1
		i += 1
	res = max(xmax,ymax)
	print res*res
second()
