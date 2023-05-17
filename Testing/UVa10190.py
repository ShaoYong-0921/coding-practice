try:
    while True:
        boring = False

        n, m = map(int, input().split())
        print(f'{n = } {m = }')
        if n == 0 or m == 0:
            boring = True
        
        num_list = [n]

        while n > 1:
            if boring:
                break

            n = n // m
            # print(f'{n = }')
            num_list.append(n)

            if n == 1 or m == 1:
                break

            if n % m != 0:
                boring = True
                break

        # print(f'{num_list = }')
        if len(num_list) <= 2:
            boring = True

        if boring:
            print('Boring!')
        else:
            first = False
            for i in num_list:
                if first:
                    print(end=' ')
                print(f'{i}', end='')
                first = True
            print()
except EOFError:
    pass