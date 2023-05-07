def f(x, list):
    power = len(list)-1
    y = 0
    for i in list:
        if power == 0:
            break
        y += i * power * ( x ** (power - 1 ))
        # print(f'{ power = } {y = }')
        power -= 1

    return y

while True:
    try:
        x = int(input())
        a = list(map(int, input().split()))
        ans = f(x, a)
        print(ans)

    except EOFError:
        break