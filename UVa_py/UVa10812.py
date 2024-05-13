try:
    n = int(input())
    for i in range(n):
        s, d = map(int, input().split())

        a = s+d
        b = s-d

        if a % 2 != 0:
            print('impossible')

        elif b < 0:
            print('impossible')

        else:
            print(int(a/2) , int(b/2))

except EOFError:
    pass