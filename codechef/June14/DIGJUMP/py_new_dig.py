import Queue
# def new_digjump():
s = raw_input()
slen = len(s)
if slen == 1:
    print '0'
else:
    v = []
    for i in xrange(10):
        v.append([])
    for i in xrange(slen):
        v[ord(s[i]) - ord('0')].append(i)
    a = [0]*100010
    vis = [False]*100010
    used = [False]*11
    fifo = Queue.Queue()
    a[0] = 0
    fifo.put(0)
    vis[0] = True
    while not fifo.empty():
        curr = fifo.get()
        if curr == (slen-1):
            print a[slen-1]
            break
        idx = ord(s[curr]) - ord('0')
        i = 0
        while i < len(v[idx]) and used[idx] == False:
            if vis[v[idx][i]]:
                i += 1
                continue
            vis[v[idx][i]] = True
            a[v[idx][i]] = a[curr] + 1
            fifo.put(v[idx][i])
            i += 1
        if curr > 0 and vis[curr-1] == False and used[ord(s[curr-1]) - ord('0')] == False and s[curr] != s[curr-1]:
            vis[curr-1] = True
            a[curr-1] = a[curr] + 1
            fifo.put(curr-1)
        if curr < (slen-1) and vis[curr+1] == False and used[ord(s[curr+1]) - ord('0')] == False and s[curr] != s[curr+1]:
            vis[curr+1] = True
            a[curr+1] = a[curr] + 1
            fifo.put(curr+1)
        used[idx] = True
# new_digjump()
