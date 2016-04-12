def first():
    n = input()
    a = map(int,raw_input().split())
    first = 0
    last = n-1
    i = 0
    sereja = 0
    dima = 0
    flag = 1
    if n == 1:
        print a[0],'0'
    else:
        while i < n:
            if a[first] > a[last]:
                if flag:
                    sereja += a[first]
                    flag = 0
                else:
                    dima += a[first]
                    flag = 1
                first += 1
            else:
                if flag:
                    sereja += a[last]
                    flag = 0
                else:
                    dima += a[last]
                    flag = 1
                last -= 1
            i += 1
        print sereja,dima
first()
