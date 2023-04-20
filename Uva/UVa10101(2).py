def banga_number(x):
    print('{}x'.format(x), end='')
    if x == 0:
        print('y')
        return 
    
    if x >= 10000000:
        banga_number(x // 10000000)
        print(' kuti ', end='')
        x %= 10000000
        
    if x >= 100000:
        banga_number(x // 100000)
        print( ' lakh ', end='')
        x %= 100000
        
    if x >= 1000:
        banga_number(x // 1000)
        print(' hajar ', end='')
        x %= 1000
        
    if x >= 100:
        banga_number(x // 100)
        print(' shata ', end='')
        x %= 100
 
    return print(x, end='') 


try:
    label = 1
    while True:
        x = int(input())
        print('{}. '.format(label), end='')
        if x == 0:
            print('0')
        else:    
            banga_number(x)
            print()
        label += 1
        
except EOFError:
    pass