import math
label = 1
t = int(input())

for i in range(t):

    s1 = int(input(), 2)
    s2 = int(input(), 2)

    gcd = math.gcd(s1, s2)

    if gcd > 1:
        print(f'Pair #{label}: All you need is love!')
    else:
        print(f'Pair #{label}: Love is not all you need!')
    label += 1