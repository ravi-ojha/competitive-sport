def lelemonade():
    for t in xrange(input()):
        n,m = map(int,raw_input().split())
        vis = map(int,raw_input().split())
        a = []
        b = []
        result = 0
        freq = [0]*101
        for j in xrange(m):
            freq[vis[j]] += 1
        for i in xrange(n):
            temp = map(int,raw_input().split())
            a.append(temp[0])
            b.append((temp[1:temp[0]+1]))
            b[i].sort(reverse=True)
        for i in xrange(n):
            if freq[i] < a[i]:
                temp = sum(b[i][:freq[i]])
                result += temp
            else:
                temp = sum(b[i][:])
                result += temp
        #print a
        #print b
        #print freq[:n+1]
        print result
lelemonade()
