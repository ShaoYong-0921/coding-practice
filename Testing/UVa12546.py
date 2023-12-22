import math


t = int(input())

for case in range(1, t+1):
    nums = [1]; n = 1
    # print(f'{t = }')
    c = int(input())
    for _ in range(c):
        p, a = map(int, input().split())
        # print(f'{p = } {a = }')
        nums.append(p ** a)
    # print(f"nums = ")
    for i in nums:
        n *= i
    
    i = 1; 
    factor = []
    a = set()
    # print(f"{n = } | {int(n*0.5) + 1}")
    f_range = int(n / 0.5) + 1
    while (i <= f_range):
        i += 1
        if (n % i == 0):
            a.add(i)
            a.add(n // i)
    print(f'{n = }, {factor = }')
    ans = 0
    for i in a:
        factor.append(i)
    length = len(factor)
    for i in range(length):
        for j in range(i, length):
            # print(f'{factor[i] = } {factor[j] = }' )
            if math.lcm(factor[i], factor[j]) == n:
                ans += factor[i] + factor[j]
                # print(f'{ans = }')

    print(f'Case {case}: {ans}')
