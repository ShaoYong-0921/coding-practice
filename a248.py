while True:    
    try:
        a, b ,n = input().split()
        a = int(a); b = int(b); n = int(n)

        value = a/b
        ans1 = f'{value:.{n}f}'

        print(ans1)
    except Exception as e:
        print(e)
        break
