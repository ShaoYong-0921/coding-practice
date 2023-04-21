def bangla_number(x):
    if x == 0:
        return 
    if x // 10000000:
        bangla_number(x // 10000000)
        print(' kuti',end='')
        x %= 10000000
    if x // 100000:
        bangla_number(x /100000)
        print(' lakh',end='')
        x %= 100000
    if x // 1000:
        bangla_number(x / 1000)
        print(' hajar', end='')
        x %= 1000
    if x // 100:
        bangla_number(x // 100 )
        print(' shata', end='')
        x %= 100
    if x:
        print(' {}'.format(x) ,end='')

#main
try:
    label = 1
    while True:
        n = int(input())
        print('{:4d}.'.format(label), end='')
        if n :
            bangla_number(n)
        else:
            print(' 0')
        print()
        label += 1
except EOFError:
    pass