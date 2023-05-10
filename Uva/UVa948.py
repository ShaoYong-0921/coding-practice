index = 0
n = 0
fib = [0, 1]
while n < 100000000:
    n = fib[index] + fib[index+1]
    # print(f'{n = }')
    fib.append(n)
    index += 1
fib.pop(0)
fib.pop(1)
# print(fib)


t = int(input())
for i in range(t):
    num = int(input())
    n = num

    for i in range(len(fib)):
        if fib[i] <= n < fib[i+1]:
            # print(f'{fib[i] =} ; {fib[i+1] =}')
            binary_index = i

    ans = ''
    for i in range(binary_index, -1, -1):
        # print(f'{i = }')
        if (n // fib[i]):
            n %= fib[i]
            ans += '1'
            # print(f'{n = }')
        else:
            ans += '0'
    print(f'{num} = {ans} (fib)')
    