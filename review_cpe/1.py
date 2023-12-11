x = int(input())

for i in range(x):
    list_s = list(map(int, input().split()))
    # print(f'{list_s = }')
    member = list_s.pop(0)
    list_s.sort()
    center = list_s[len(list_s) //  2]
    # print(f'{center = }')
    distance = 0
    for i in list_s:
        distance += abs(i - center)
    # print(f'{distance = }')
    print(distance)