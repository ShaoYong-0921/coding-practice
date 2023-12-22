n = int(input())

counties = {}

for i in range(n):
    string = list(map(str, input().split()))
    if string[0] in counties:
        counties[string[0]] += 1
    else:
        counties[string[0]] = 1

ans = sorted(counties)

for i in ans:
    print(i, counties[i])
