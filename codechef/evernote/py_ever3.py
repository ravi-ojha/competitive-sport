def ever3():
    buff = input()
    a = []
    cnt = 0
    s = map(str,raw_input().split())
    while s[0] != 'Q':
        if s[0] == 'A':
            n = int(s[1])
            i = 0
            while i < n:
                a.append(raw_input())
                i += 1
                if len(a) > buff:
                    a = a[1:]
        elif s[0] == 'R':
            n = int(s[1])
            a = a[n:]
        elif s[0] == 'L':
            for i in a:
                print i
        s = map(str,raw_input().split())
ever3()
