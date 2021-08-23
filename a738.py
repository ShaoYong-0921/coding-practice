from math import gcd
from sys import stdin

while True:
    try:

        x, y = map(int, stdin.readline().split())
        ans = gcd(x, y)
        print(ans)

    except:
        break