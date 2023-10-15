from sys import stdin

flag_n = True
count = 0
for line in stdin.readlines():    
    if flag_n:
        n = int(line)
        x = []
        flag_n = False 
        continue
    x.append(int(line))

    count += 1
    # print(f'{n = } {count = }')
    if count != n:
        continue

    x.sort()
    # print(x)
    if len(x) % 2 == 0:
        mid1 = x[len(x) // 2 - 1]
        mid2 = x[len(x) // 2]
    elif len(x) % 2 == 1:
        mid1 = mid2 = x[len(x) // 2]
    # print(f'{mid1 = } {mid2 = }')
    ans1 = mid1

    ans2 = 0
    for i in x:
        if i == mid1 or i == mid2:
            ans2 += 1

    ans3 = mid2 - mid1 + 1

    print(ans1, ans2, ans3)
    flag_n = True
    count = 0

