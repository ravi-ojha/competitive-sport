def solve():
	t = input()
	for tt in xrange(t):
		a = input()
		n = input()
		b = map(int,raw_input().split())
		c1 = list(str(a))
		res1 = 0
		c11 = int(''.join(c1))
		for i in b:
			res1 += c11%i
		c2 = list(str(a))
		c2.sort()
		res2 = 0
		c22 = int(''.join(c2))
		for i in b:
			res2 += c22%i
		c3 = list(str(a))
		c3.sort(reverse=True)
		res3 = 0
		c33 = int(''.join(c3))
		for i in b:
			res3 += c33%i
		res = min([res1,res2,res3])
		if res == res1:
			print c11
		elif res == res2:
			print c22
		elif res == res3:
			print c33
solve()
