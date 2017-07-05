def mou1h():
    for t in xrange(input()):
        n = input()
        answer = (n*(n-1))/2
        a = map(int,raw_input().split())
        b = []
        c = []
        begin = 1
        while True:
            toSubtract = 0
            naruto = [0]*1000000
            sasuke = [0]*1000000
            for i in xrange(begin,n):
                temp = a[i] - a[i-1]
                b.append(temp)
                if temp < 0:
                    temp = -temp
                    if sasuke[temp] == 1:
                        toSubtract += 1
                    else:
                        sasuke[temp] = 1
                else:
                    if naruto[temp] == 1:
                        toSubtract += 1
                    else:
                        naruto[temp] = 1
            print toSubtract
            answer -= toSubtract
            a = b
            b = []
            n -= 1
            print a
            print b
            if toSubtract == 0:
                break
        print answer
mou1h()
