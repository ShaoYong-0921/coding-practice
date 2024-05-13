
def f(x, total, borrow):
    # print(f'{x = }')
    total += x // 3
    x = (x // 3) + (x % 3)
    if x<= 3 and borrow == 3:
        return x, total

    if x < 3:
        return x, total

    return f(x, total, borrow)
    
while True:
    try:
        n = total = int(input())
        borrow = 3 - (n % 3)
        total += borrow
        
        empty, total = f(total, total, borrow)
        if empty < borrow:
            borrow = 0
            empty, total = f(n , n, borrow)
        print(total - borrow)

    except EOFError:
        break