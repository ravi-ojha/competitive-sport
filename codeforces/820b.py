def solve():
    n, a = map(int, raw_input().split())
    # I have to find the value for index 2
    res = ['1', '2', '3']

    largest_angle = 180 - 360.0/n


    incr = largest_angle/(n-2)
    i = 3
    next_angle = largest_angle
    diff = abs(next_angle - a)
    while i < n:
        i += 1
        next_angle = next_angle - incr
        #print next_angle
        if abs(next_angle - a) < diff:
            res[2] = str(i)
            diff = abs(next_angle - a)

    print ' '.join(res)

solve()
