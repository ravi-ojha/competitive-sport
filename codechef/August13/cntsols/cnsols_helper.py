def cntsols_helper():
    for i in xrange(10):
        for j in xrange(10):
            for k in xrange(10):
                if (i**2)%37 == 36:
                    print i, 0, 0
                elif (i**2 + j**2)%37 == 36:
                    print i, j, 0
                elif (i**2 +j**2 + k**2)%37 == 36:
                    print i, j, k
cntsols_helper()
