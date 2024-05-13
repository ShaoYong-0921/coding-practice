from sys import stdin

for line in stdin:
    s, t = map(int, line.split())
    print(s * t * 2 )