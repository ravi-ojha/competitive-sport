def fourth():
    n = input()
    count = 0
    for t in xrange(n):
        x1,y1,x2,y2,x3,y3 = map(float,raw_input().split())
        a = (x1-x2)**2 + (y1-y2)**2
        b = (x2-x3)**2 + (y2-y3)**2
        c = (x1-x3)**2 + (y1-y3)**2
        if (a+b) == c or (b+c) == a or (a+c) == b:
            count += 1
    print count
fourth()
