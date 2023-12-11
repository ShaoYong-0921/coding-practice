def solution(x):
    if x == 0:
        return print()

    if x // 10000000:
        solution(x // 10000000)
        print(" kuti", end="")
        x %= 10000000
    if x // 100000:
        solution(x // 100000)
        print(" lakh", end="")
        x %= 100000
    if x // 1000:
        solution(x // 1000)
        print(" hajar", end="")
        x %= 1000
    if x // 100:
        solution(x // 100)
        print(" shata", end="")
        x %= 100
    if x:
        print(f' {x}', end="")

try:
    count = 1
    while True:
        x = int(input())
        print(f"{count}.", end="")
        solution(x)
        count += 1
except EOFError:
    pass
        
