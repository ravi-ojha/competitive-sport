with_draw,balance = map(float,input().split())
with_draw=int(with_draw)
balance=float(balance)


if with_draw>balance or with_draw<0 or with_draw%5!=0 or balance-with_draw<.5 or balance< 0:
    print(balance)
else:
    balance-=with_draw
    balance-=0.5
    print(balance)
