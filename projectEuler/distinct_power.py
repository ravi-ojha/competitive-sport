def distinct_pow():
    a = []
    for i in range(2,101):
        for j in range(2,101):
            t = i**j
            if t not in a:
                a.append(t)
    print len(a)
distinct_pow()
