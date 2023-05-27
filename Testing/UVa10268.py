while True:
    try:
        x = int(input())
        list_a = [int(x) for x in input().split()]
        list_a.pop(-1)
        ans = 0
        

        power = len(list_a)
        
        
        for a in list_a:

            # print(f'{x = }; {power = }; {i = }; {a = }')
            ans *= x
            ans += a * power

            # print(f'{ans = }')
            power -= 1
                

            print(ans)

    except EOFError:
        break