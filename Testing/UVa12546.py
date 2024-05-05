import math


T = int(input())

for case in range(1, T+1):
    num_list = [1]
    n = 1
    c = int(input())
    for _ in range(c):
        p, a = map(int, input().split())
        for _ in range(a):
            num_list.append(p)
        n *= p ** a
    print(f'{num_list = }, {n = }')
    