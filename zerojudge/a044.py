def ans(n):
    print(int(( n*(n**2 + 5) ) / 6 + 1))

while True:

    try:
        n = int(input())
        ans(n)

    except:
        pass
