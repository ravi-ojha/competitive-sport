MOD = 1000000007
f = [1]
def fact():
    for i in xrange(1,111):
        f.append((f[i-1]*i)%MOD)
def fast_power(a,n):
    result = 1
    value = a
    power = n
    while power > 0:
        if power % 2 == 1:
            result = result * value
            result %= MOD
        value = value * value
        value %= MOD
        power = power/2
    return result
def inv(x):
    return fast_power(x,MOD-2)
def py_1():
	fact()
	t = input()
	for tt in xrange(t):
		res = 0
		m,n = map(int,raw_input().split())
		for i in xrange(m):
			num = f[m]
			din = f[m-i]*f[i]
			din %= MOD
			tmp = num*inv(din)
			res = res + fast_power(-1,i)*tmp*fast_power(m-i,n)
			res %= MOD
		print 'Case #{0}:'.format(tt+1),str(res)
py_1()
