def py_submin():
    n = input()
    a = map(int,raw_input().split())
    q = input()
    for z in xrange(q):
        k = input()
        res = 0
        shift = 1
        while shift <= n:
            i = 0
            while i+shift <= n:
                if min(a[i:i+shift]) == k:
                    res += 1
                i += 1
            shift += 1
        print res
py_submin()
