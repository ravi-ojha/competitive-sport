def pipel():
    n = map(int,raw_input().split(' '))
    m = n[1]-2
    ans = n[1]
    count = 1
    summ = ans*(ans+1)/2
    summ = summ - (ans-1)
    if(summ<n[0]):
        print -1
    else:
        while ans < n[0]:
            ans = ans + m
            count += 1
            m -= 1
        print count
pipel()
