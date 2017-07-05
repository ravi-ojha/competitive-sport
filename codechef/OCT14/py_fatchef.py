MOD = 1000000009
def fatchef():
	for t in xrange(input()):
		n,m = map(int,raw_input().split())
		a = []
		for i in xrange(m):
			tmp = map(str,raw_input().split())
			tmp[1] = int(tmp[1])
			a.append([tmp[1],tmp[0]])
		a.sort()
		res = 1
		for i in xrange(1,m):
			if a[i][1] != a[i-1][1]:
				res = res*(a[i][0] - a[i-1][0])
				res %= MOD
		print res
fatchef()
