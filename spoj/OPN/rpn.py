def rpn():
    t = input()
    operators = ['+','-','*','/','^']
    for p in xrange(t):
        rpn = []
        temp = []
        infix = raw_input()
        toCheck = 0
        for k in infix:
            if k == '(':
                toCheck += 1
            elif k == ')':
                toCheck -= 1
                if len(temp) != 0:
                    rpn.append(temp.pop(-1))
            elif k in operators:
                temp.append(k)
            else:
                rpn.append(k)
        print ''.join(rpn)
rpn()
