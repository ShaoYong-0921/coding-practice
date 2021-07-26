def main(n):
    
    if n <= 10:
        return n*6
    elif 10 < n <= 20:
        return 60 + (n-10)*2
    elif 20 < n <= 40:
        return 80 + (n-20)*1
    else:
        return 100

n = int(input())
print(main(n))

