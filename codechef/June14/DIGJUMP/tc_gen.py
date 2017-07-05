import random
def tc_gen_1():
    a = []
    for i in xrange(100000):
        tmp = random.randrange(1)
        a.append(str(tmp))
    print ''.join(a)
tc_gen_1()
