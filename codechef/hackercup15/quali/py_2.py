def list_powerset2(lst):
    return reduce(lambda result, x: result + [subset + [x] for subset in result],
                  lst, [[]])
def py_1():
	tt = input()
	for t in xrange(1,tt+1):
		gp,gc,gf = map(int,raw_input().split())
		n = input()
		tmp = []
		for i in xrange(n):
			tmp.append(i)
		all_sets = list_powerset2(tmp)
		data = []
		for i in xrange(n):
			d = map(int,raw_input().split())
			data.append(d)
		flag = 0
		for curr_set in all_sets:
			tp = 0
			tc = 0
			tf = 0
			for i in curr_set:
				tp += data[i][0]
				tc += data[i][1]
				tf += data[i][2]
			if tp == gp and tc == gc and tf == gf:
				flag = 1
				break
		if flag:
			print "Case #%d:"%t,"yes"
		else:
			print "Case #%d:"%t,"no"
py_1()
