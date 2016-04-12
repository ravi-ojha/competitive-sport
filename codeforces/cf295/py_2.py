def solve():
	for tt in xrange(100):
		n,m = map(int,raw_input().split())
		if n >= m:
			print n-m
		else:
			res = 0
			mc = m
			while mc != n:
				if mc > n:
					if mc%2 == 0:
						mc = mc/2
						res += 1
					else:
						mc += 1
						res += 1
				else:
					mc += 1
					res += 1
			print res
solve()
