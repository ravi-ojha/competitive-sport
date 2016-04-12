import math
def py_2():
	r,x1,y1,x2,y2 = map(int,raw_input().split())
	d = 2.0*r
	x3 = abs(x1-x2)
	y3 = abs(y1-y2)
	dis = math.sqrt(x3**2 + y3**2)
	res = 0
	dd = 0
	while dd < dis:
		dd += d
		res += 1
	print res
py_2()
