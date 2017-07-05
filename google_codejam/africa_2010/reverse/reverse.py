def reve():
    n = input()
    for i in range(1,n+1):
        mystr = raw_input()
        lst = mystr.split(' ')
        #print lst
        lst.reverse()
        #print lst
        print 'Case #{0}:'.format(i)," ".join(lst)
reve()
