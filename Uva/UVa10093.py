base = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
list_base = [base[i] for i in range(len(base))]

# print(list_base)


try:
    while True:
        status = True
        sum = 0
        n = str(input().strip(' -+'))
        # list_n = [n[i] for i in range(len(n))]
        # print(f'{n = }. ;')

        for char in n:
            sum += list_base.index(char)
            
            if char not in list_base:
                status = False
                break
        
        max_n = list_base.index(max(n))
        # print(f'{sum = } ; {max_n =}')
        

        for i in range(max_n, 63):
            if sum == 0:
                print('2')
                break
            if sum % i == 0:
                print(i+1)
                break
        if i == 62:
            print('such number is impossible!')
            
except EOFError:
    pass