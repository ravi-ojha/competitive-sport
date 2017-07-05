import re
def isPrime(n):
    return re.match(r'^1?$|^(11+?)\1+$', '1' * n) == None
