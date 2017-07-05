def prladdu():
	for t in xrange(input()):
		n = input()
		a = map(int,raw_input().split())
		tmp = 0
		ans = 0
		for i in a:
			tmp += i
			if tmp > 0:
				ans += tmp
			else:
				ans -= tmp
		print ans
prladdu()
