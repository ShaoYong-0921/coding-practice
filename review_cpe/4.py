def algorithm(x):
    length = 1
    while True:
        # print(x)
        if x == 1:
            return length
        if x % 2 == 1:
            x = x * 3 + 1
        else:
            x /= 2
        length += 1

# print(algorithm(22))
try:
    while True:
        i, j = map(int, input().split())
        max_length = 1
        for n in range(i, j+1):
            length = algorithm(n)
            if length > max_length:
                max_length = length

        print(f'{i} {j} {max_length}')
except EOFError:
    pass
