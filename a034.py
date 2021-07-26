def main(n):
    num = []
    while True:
        a = n // 2
        b = n % 2
        num.append(str(b))
        n = a
        if n == 0:
            break
    return ''.join(num[::-1])

while True:
    try:
        n = int(input())
        print(main(n)) 
    except:
        break

