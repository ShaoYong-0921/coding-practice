from datetime import date

d1 = list(map(int, input().split()))
d1 = date(d1[0], d1[1], d1[2])

d2 = list(map(int, input().split()))
d2 = date(d2[0], d2[1], d2[2])

ans = d1-d2

print(abs(ans.days))