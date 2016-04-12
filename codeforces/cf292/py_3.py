def py_3():
	mymap = {}
	mymap['0'] = "";
	mymap['1'] = "";
	mymap['2'] = "2";
	mymap['3'] = "3";
	mymap['4'] = "322";
	mymap['5'] = "5";
	mymap['6'] = "53";
	mymap['7'] = "7";
	mymap['8'] = "7222";
	mymap['9'] = "7333";
	slen = input()
	s = raw_input()
	res = []
	for i in xrange(slen):
		res.append(mymap[s[i]])
	ans = ''.join(res)
	ans = list(ans)
	ans.sort(reverse=True)
	print ''.join(ans)
py_3()
