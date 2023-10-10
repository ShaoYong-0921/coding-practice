from math import gcd
from sys import stdin

for n in stdin.readlines():
    n = int(n)
    if n == 0:
        break
    
    g = 0
    for i in range(1, n):
        for j in range(i + 1, n + 1):
            g += gcd(i, j)
    
    print(f'{g}')