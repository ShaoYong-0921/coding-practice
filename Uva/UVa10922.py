def solution(n):
    total = 0
    for i in range(len(n)):
        total += int(n[i])
    return str(total)
while True:

    s = str(input())
    if s == '0':
        break
    
    n = s
    ans = 0

    while len(n) >= 2:
        n = solution(n)
        # print(f'{n = }')
        ans += 1
        
    n = int(n)

    if n % 9 == 0:
    else:
        print(f'{s} is not a multiple of 9.')
