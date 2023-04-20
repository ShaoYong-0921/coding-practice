try:
    while True:
        num1, num2 = map(int, input().split())
        print(abs(num2 - num1))
except EOFError:
    pass
