def name1():
    t = input()
    for p in range(t):
        w = map(str,raw_input().split())
        s = w[0] + w[1]
        print s
        parent = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
        l = len(s)
        for k in range(l):
            parent[ord(s[k])-97] += 1
        n = input()
        i = 0
        while i<n:
            c = raw_input()
            l = len(c)
            for k in range(l):
                if parent[ord(c[k])-97] == 0:
                    
            
        
