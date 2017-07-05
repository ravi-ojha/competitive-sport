def meatballs():
    t = input()
    for k in range(t):
        w = map(int,raw_input().split())
        a = map(int,raw_input().split())
        a.sort()
        i = 0
        res = 0
        while i<w[0] and res < w[1]:
            res = res + a[-1-i]
            i += 1
        if i == w[0]:
            if res < w[1]:
                print -1
            else:
                print i
        else:
            print i
meatballs()
