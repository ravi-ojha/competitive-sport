def find(x):
    while p[x]!=x:
        x=p[x]
    return x
 
def uni(x,y):
    if(r[x]>r[y]):
        p[y]=x
        t[x]=t[x]+t[y]
        r[x]=r[x]+1
        return 1
    p[x]=y
    t[y]=t[y]+t[x]
    r[y]=r[y]+1
    return 1
 
T=int(raw_input())
for k in range(1,T+1):
    s=(raw_input())
    li=s.split(' ')
    N=int(li[0])
    M=int(li[1])
    p=[i for i in xrange(N+1)]
    t=[1 for i in xrange(N+1)]
    r=[0 for i in xrange(N+1)]
    print p
    print t
    print r
    for i in range(0,M):
        s=(raw_input())
        li=s.split(' ')
        x=int(li[0])
        y=int(li[1])
        x=find(x)
        y=find(y)
        if x!=y:
            uni(x,y)
    ans=0
    ans2=1
    for i in range(1,N+1):
        if p[i]==i:
            ans=ans+1
            ans2=ans2*t[i]
            ans2=ans2%1000000007L
    print "{0} {1}".format(ans,ans2)
    #print ans,ans2
