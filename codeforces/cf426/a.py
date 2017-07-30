def solve():
    cc = {
        chr(118): 0, # v
        chr(60): 1, # <
        chr(94): 2, # ^
        chr(62): 3, # >
    }

    q = ['v', '<', '^', '>']
    q2 = ['v', '>', '^', '<', ] # in reverse

    a, b = map(str, raw_input().split())
    n = int(raw_input())
    n = n%4

    ans1 = 0
    c = a
    i = q.index(c)
    while c != b:
        i += 1
        i = i % 4
        c = q[i]
        ans1 += 1

    ans2 = 0
    c = a
    i = q2.index(c)
    while c != b:
        i += 1
        i = i % 4
        c = q2[i]
        ans2 += 1


    #print ans1, ans2

    if ans1 == n and ans2 != n:
        print 'cw'
    elif ans2 == n and ans1 != n:
        print 'ccw'
    else:
        print 'undefined'

solve()
