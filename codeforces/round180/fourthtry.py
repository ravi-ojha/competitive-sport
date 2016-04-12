def fourth():
    p = map(int,raw_input().split())
    a = map(int,raw_input().split())
    b = map(int,raw_input().split())
    #a = [5,2,3,7]
    #b = [3,5,2,7,3,8,7]
    c = set(a).intersection(set(b))
    if set(a) == c:
        print 'NO'
    else:
        print 'YES'
fourth()
