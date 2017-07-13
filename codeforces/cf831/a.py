def solve():
    n = int(raw_input())
    a = map(int, raw_input().split())
    if n == 1:
        print "YES"
    else:
        i = 1
        while i < n and a[i] > a[i-1]:
            i += 1

        while i < n and a[i] == a[i-1]:
            i += 1

        while i < n and a[i] < a[i-1]:
            i += 1

        if i != n:
            print "NO"
        else:
            print "YES"

solve()
