def cgame():
    t = input()
    for e in range(t):
        a = []
        w = map(int,raw_input().split())
        for f in range(w[0]):
            a.append(map(int,raw_input().split()))
        print a
cgame()
