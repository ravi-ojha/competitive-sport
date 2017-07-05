def sum_of_pow():
    res = 0
    for i in range(10,100):
        s = str(i)
        if i == (int(s[0])**5 +  int(s[1])**5):
            print i
            res += i
    for i in range(100,1000):
        s = str(i)
        if i == (int(s[0])**5 +  int(s[1])**5 +  int(s[2])**5):
            print i
            res += i
    for i in range(1000,10000):
        s = str(i)
        if i == (int(s[0])**5 +  int(s[1])**5 +  int(s[2])**5 +  int(s[3])**5):
            print i
            res += i
    for i in range(10000,100000):
        s = str(i)
        if i == (int(s[0])**5 +  int(s[1])**5 +  int(s[2])**5 +  int(s[3])**5 +  int(s[4])**5):
            print i
            res += i
    for i in range(100000,1000000):
        s = str(i)
        if i == (int(s[0])**5 +  int(s[1])**5 +  int(s[2])**5 +  int(s[3])**5 +  int(s[4])**5 + int(s[5])**5):
            print i
            res += i
    print res
sum_of_pow()
