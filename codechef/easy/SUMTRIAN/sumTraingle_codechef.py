def sumTriangle():
	t = input()
	for k in xrange(t):
	    n = input()
	    a = []
	    subA = []
	    for i in xrange(n):
		subA = map(int,raw_input().split())
		a.append(subA)
	    for i in xrange(1,n):
		for j in xrange(i+1):
		    if j == 0:
		        a[i][j] = a[i-1][j] + a[i][j]
		    elif j == i:
		        a[i][j] = a[i-1][j-1] + a[i][j]
		    else:
		        if a[i-1][j] > a[i-1][j-1]:
		            a[i][j] = a[i-1][j] + a[i][j]
		        else:
		            a[i][j] = a[i-1][j-1] + a[i][j]
	    print max(a[n-1])
sumTriangle()
