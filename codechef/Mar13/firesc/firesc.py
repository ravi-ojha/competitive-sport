def firesc():
    T = input()
    for i in range(T):
        n = map(int,raw_input().split(' '))
        a = []
        b = []
        for j in range(n[1]):
            a.append(map(int,raw_input().split(' ')))
            
            print a
firesc()
