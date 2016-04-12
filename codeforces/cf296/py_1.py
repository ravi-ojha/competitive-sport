def solve():
	a, b = map(int,raw_input().split())
	big = max(a,b)
	small = min(a,b)
	res = 0
	while small != 0:
		res += big//small
		a = big%small
		b = small
		big = max(a,b)
		small = min(a,b)
	print res
solve()
