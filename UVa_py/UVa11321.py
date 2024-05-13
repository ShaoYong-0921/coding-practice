while True:
    n, m = map(int, input().split())
    print(n, m)
    if (n == 0) and (m == 0):
        break
    mod = [[] for i in range(-m, m)]
    # print(f'{mod = }')

    for i in range(n):
        x = int(input())
        if x < 0 and x % m != 0:
            mod[x % m].append(x)
        else:
            mod[x % m + m].append(x)
    # print(f'{mod = }')
    ans = []
    for list_n in mod:
        odd = [] 
        even = []
        for n in list_n:

            if n % 2 == 1:
                odd.append(n)
            elif n % 2 == 0:
                even.append(n)
        # print(f'{odd = } {even = }')
        ans.append(sorted(odd, reverse=True))
        ans.append(sorted(even))

    for i in ans:
        for j in i:
            print(j)
    # print(ans)
