from sys import stdin
import math

def f(s, d):
    return int(math.ceil((-1 +((1 - 4  * (-(s ** 2) + s - 2* d ))) ** 0.5) / 2))

for line in stdin:
    s, d = map(int, line.split())
    ans = f(s, d)
    print(ans)