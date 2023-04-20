def ans(n, m):
    if m == n:
        return m
    if m < n:
        return m+1


while True:
    try:
        n, m = input().split()
        m = int(m)
        n = int(n)
        print(ans(n, m))
    except:
        break