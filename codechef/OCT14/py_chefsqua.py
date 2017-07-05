from sets import Set
from sys import stdin
def py_chefsqua():
	data = (line for line in stdin.read().splitlines())
	n = int(next(data))
	a = []
	for i in xrange(n):
		x,y = map(int,next(data).split())
		a.append((x,y))
	b = Set(a)
	res = 2
	if n == 0:
		res = 4
	elif n == 1:
		res = 3
	elif n == 2:
		res = 2
	else:
		for i in xrange(n):
			for j in xrange(i+1,n):
				midX = (a[i][0] + a[j][0])/2.0
				midY = (a[i][1] + a[j][1])/2.0
				diffX = (a[i][0] - a[j][0])/2.0
				diffY = (a[i][1] - a[j][1])/2.0
				p = [1000001,1000001]
				q = [1000001,1000001]
				if(round(midX-diffY) == (midX-diffY)):
					p[0] = int(midX-diffY)
				if(round(midY+diffX) == (midY+diffX)):
					p[1] = int(midY+diffX)
				if(round(midX+diffY) == (midX+diffY)):
					q[0] = int(midX+diffY)
				if(round(midY-diffX) == (midY-diffX)):
					q[1] = int(midY-diffX)
				tmp = 0
				p = tuple(p)
				q = tuple(q)
				if p in b:
					tmp += 1
				if q in b:
					tmp += 1
				if res > (2-tmp):
					res = 2-tmp
	print res
py_chefsqua()
