import math

prime = [ True for i in range(1000000)]
prime[0] = False
prime[1] = False

for i in range(2,1000000):
    if prime[i]:
        for j in range( i * i, 1000000, i):
            # print(f'{i = }{j = }')
            prime[j] = False
        


while True:
    try:
        n = str(input())

        if prime[int(n)]:
            
            if prime[int(n[::-1])] and n != n[::-1]:
                print(n, 'is emirp.')
                continue
            
            print(n, 'is prime.')
        else:
            print(n, 'is not prime.')
            
        # print(f'{n[::-1] = }')
    except EOFError:
        break