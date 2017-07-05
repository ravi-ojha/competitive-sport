def ams():
    t = input()
    for p in range(t):
        w = map(int,raw_input().split())
        s = raw_input()
        r = raw_input()
        final = 0
        for l in range(1,w[0]+1):
            for i in range(0,w[0]-l+1):
                for j in range(0,w[0]-l+1):
                    c = [x != y for (x, y) in zip(s[i:i+l],r[j:j+l])].count(True)
                    #print c
                    if c<=w[1]:
                        final += 1
        print final
ams()
