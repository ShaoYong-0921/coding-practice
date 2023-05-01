s = int(input())
for _ in range(s):
    n, p, i = map(float, input().split())
    n = int(n); i = int(i)
    if p:
        ans = (1 - p)**(i - 1) * p / (1 - (1 - p) ** n)
    else:
        ans = 0
    print(format(ans, '.4f'))