def primitive():
    o = 1
    z = 0
    N = int(raw_input())
    r = 2
    while r<N:
        k = r**o
        k %= N
        while k>1:
            o += 1
            k *= r
            k %= N
        if (o == (N-1)):
            z += 1
        o = 1
        r += 1
    print z
primitive()
