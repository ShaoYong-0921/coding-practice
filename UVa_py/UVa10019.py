# n = 265
t = int(input())
for i in range(t):
    n = int(input())
    x = str(bin(n))
    list_x = [i for i in x]
    b1 = list_x.count('1')

    str_n = str(n)
    len_n = len(str_n)

    x2 = 0
    for i in range (len_n):
        x2 += 16 ** i * int(str_n[len_n - 1 - i])
        # print(f'{i = } {x2 = }')
    x = str(bin(x2))
    list_x = [i for i in x]
    b2 = list_x.count('1')

    print(f'{b1} {b2}')