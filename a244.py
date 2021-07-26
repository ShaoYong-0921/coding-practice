def solution(a, b ,c):
    if a == 1:
        print(b+c)
    elif a == 2:
        print(b-c)
    elif a == 3:
        print(b*c)
    elif a == 4:
        print(b//c)

n = int(input())
for i in range(n):
    a , b, c = input().split()
    a = int(a); b = int(b); c = int(c)
    solution(a, b, c)