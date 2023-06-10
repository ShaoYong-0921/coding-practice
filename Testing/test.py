import math


prime = [ True for i in range(1000)]
print(prime)
prime[0] = False
prime[1] = False

for i in range(2,100):
    if prime[i]:
        for j in range( i * i, 1000, i):
            # print(f'{i = }{j = }')
            prime[j] = False

for i in range(len(prime)):
    print(f'{i = } {prime[i]}')