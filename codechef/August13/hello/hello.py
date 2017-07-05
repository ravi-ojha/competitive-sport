def hello():
    for t in xrange(input()):
        a = map(float,raw_input().split())
        plans = int(a[2])
        options = []
        options.append(a[0]*a[1])
        for p in xrange(plans):
            b = map(float,raw_input().split())
            options.append((b[2]/b[0]) + b[1]*a[1])
        val, idx = min((val, idx) for (idx, val) in enumerate(options))
        print idx
hello()
