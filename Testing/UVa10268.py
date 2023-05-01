def f(x, list):
    power = len(list)-1
    y = 0
    for i in list:
        if power == 0:
            break
        y += i * power * ( x ** (power - 1 ))
        # print(f'{ power = } {y = }')
        power -= 1

        
    return y
import time
import sys
time1 = time.time()

bool = True
try:
    
    while True:
        x = int(input())
        a = list(map(int, input().split()))
        ans = int(f(x, a))
        print(ans)

except EOFError:
    pass