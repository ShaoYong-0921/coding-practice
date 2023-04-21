def bangla_number(x):
    if x == 0:
        return 
    if x // 10000000:
        bangla_number(x)
        print(' kuti',end='')
        x %= 10000000
    if x // 100000:
        bangla_number(x)
        print(' lakh',end='')
        x %= 100000
    if x // 1000:
        bangla_number(x)
        print(' hajar', end='')
        x %= 1000
    if x // 100:
        bangla_number(x)
        print(' shata', end='')
    if x:
        print(' {}'.format(x))

#main
try:
    label = 1
    while True:
        n = int(input())
        print('{4d:}'.format(n))
        if n :
            bangla_number(n)
        else:
            print('0')
        print()
        label += 1
except EOFError:
    pass
