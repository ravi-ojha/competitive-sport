def kame():
    for t in xrange(input()):
        n = input()
        rows = []
        rlen = []
        cols = []
        clen = []
        for i in xrange(n):
            rflag = True
            cflag = True
            x,y = map(int,raw_input().split())
            for j in xrange(len(rows)):
                if rows[j][0] == x:
                    rflag = False
                    rows[j].append(y)
                    rlen[j] = rlen[j] + 1
            for j in xrange(len(cols)):
                if cols[j][0] == y:
                    cflag = False
                    cols[j].append(x)
                    clen[j] = clen[j] + 1
            if rflag:
                rows.append([x,y])
                rlen.append(2)
            if cflag:
                cols.append([y,x])
                clen.append(2)
        temp_res_1 = len(cols)
        temp_res_2 = len(rows)
##        print rows
##        print rlen
##        print cols
##        print clen
        res = 0
        while clen != []:
            cmx = max(clen)
            rmx = max(rlen)
            if cmx >= rmx:
                p = clen.index(cmx)
                for q in cols[p][1:]:
                    for z in xrange(len(rows)):
                        if rows[z][0] == q:
                            break
                    del rows[z][rows[z][1:].index(cols[p][0]) + 1]
                    rlen[z] -= 1
                    if rlen[z] == 1:
                        del rlen[z]
                        del rows[z]
                del cols[p]
                del clen[p]
            else:
                p = rlen.index(rmx)
                for q in rows[p][1:]:
                    for z in xrange(len(cols)):
                        if cols[z][0] == q:
                            break
                    del cols[z][cols[z][1:].index(rows[p][0]) + 1]
                    clen[z] -= 1
                    if clen[z] == 1:
                        del clen[z]
                        del cols[z]
                del rows[p]
                del rlen[p]
            res += 1
##        print rows
##        print rlen
##        print cols
##        print clen
        print min(res,temp_res_1,temp_res_2)
kame()
