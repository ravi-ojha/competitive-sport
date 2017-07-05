def prime():
    a = [2,3]
    k = 2
    i = 4
    flag = 0
    while k <10001:
        j = 2
        flag = 0
        while j*j <= i:
            if i%j == 0:
                flag = 1
                break
            j += 1
        if flag:
            i += 1
            continue
        else:
            a.append(i)
            k += 1
        i += 1
    print a
