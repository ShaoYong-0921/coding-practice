def f(x):
    if int(x) < 10:
        return int(x)
    else:
        total = sum([int(i) for i in x])
        return f(str(total))


while True:
    x = str(input())
    
    if x == '0':
        break
    
    else:
        print(f(x))
