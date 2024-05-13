count = 0
n = int(input())


for i in range(n):
    count += 1
    x1, y1, x2, y2 = map(int, input().split())

    # X = Y + b
    b1 = 0
    while x1 + y1 != b1:
        b1 += 1
    
    b2 = 0
    while x2 + y2 != b2:
        b2 += 1
    # print(f'{b1 = }  {b2 = }')
    
    #line1
    step1 = 0
    for i in range(b1, 0, -1):
        step1 += i
    step1 += x1 
    # print(f'{step1 = }')

    #line2
    step2 = 0
    for i in range(b2, 0, -1):
        step2 += i
    step2 += x2 
    # print(f'{step2 = }')
    ans = step2 - step1
    print(f'Case {count}: {ans}')
