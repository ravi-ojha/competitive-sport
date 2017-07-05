def pr_potions():
	for t in xrange(input()):
		r,g,b,m = map(int,raw_input().split())
		a = []
		rlist = map(int,raw_input().split())
		a.append(max(rlist))
		glist = map(int,raw_input().split())
		a.append(max(glist))
		blist = map(int,raw_input().split())
		a.append(max(blist))
		for mm in xrange(m):
			maxv = max(a)
			maxi = a.index(maxv)
			a[maxi] /= 2
		print max(a)
pr_potions()
