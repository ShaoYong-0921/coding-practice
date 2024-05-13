while True:
    try:
        n, m = map(int, input().split())
        status = True
        a = [n]
            
        while n > 1:
            # print(f'{ n // m = }')
            if m == 1 or m == 0:
                status = False
                break
            
            if n % m == 0:
                a.append(n//m)
            else:
                status = False
                # print('Boring!')
                break

            n //= m

        if len(a) == 1:
            status = False
        
        if status:
            # print(f'{a = }')
            first = True
            for n in a:
                if first:
                    print(n,end='')
                    first = False
                else:
                    print(f' {n}', end='')
            print()
    
        else:
            print('Boring!')
    
    except EOFError:
        break