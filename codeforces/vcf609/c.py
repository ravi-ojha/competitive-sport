# def solve():
#     n = int(raw_input())
#     m = map(int, raw_input().split())

#     total = sum(m)

#     if total <= n:
#         fair_amount = 1
#         res = 0
#         for i in m:
#             if i > fair_amount:
#                 res = res + (i - fair_amount)
#         print res

#     else:

#         fair_amount = total/n

#         res = 0
#         for i in m:
#             if i < fair_amount:
#                 res += (fair_amount-i)
#         print res
# solve()


def solve():
    n = int(raw_input())
    m = map(int, raw_input().split())
    total = sum(m)

    fair_m = [0]*n

    if total % n == 0:
        fair_amount = total/n
        for i in xrange(n):
            fair_m[i] = fair_amount
    else:
        fair_amount = total/n
        rem = total % n
        for i in xrange(n):
            fair_m[i] = fair_amount
        for i in xrange(rem):
            fair_m[i] += 1

    m.sort(reverse=True)
    res = 0
    for i in xrange(n):
        res = res + (abs(fair_m[i] - m[i]))
    print res/2

solve()
