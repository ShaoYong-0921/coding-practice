from sys import stdin

n = int(stdin.readline().strip())
for i in range(n):
    m, p = map(int, stdin.readline().split())
    output = ''

    x = (p - m) * 100000 / m 
    if x > 0:
        x += 0.0000001
        if x > 10000:
            print(format(x/1000,'.2f')+ '%' + ' dispose')
        else:
            print(format(x/1000,'.2f')+ '%' + ' keep')
    elif x == 0:
        print('0.00%' + ' keep')
    else:
        x -= 0.0000001
        if x < -7000:
            print(format(x/1000,'.2f')+ '%' + ' dispose')
        else:
            print(format(x/1000,'.2f')+ '%' + ' keep')