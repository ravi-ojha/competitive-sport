def helper():
    s = raw_input()
    z = s[0]
    i = 0
    c = 0
    a = []
    n = len(s)
    while i < n:
        c = 0
        while i < n and s[i] == z:
            c += 1
            i += 1
        a.append([z,c])
        if i >= n:
            break
        z = s[i]
    print a
helper()
