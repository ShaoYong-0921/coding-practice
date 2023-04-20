def count(n, m):
    count = 1
    sum = n 

    while sum <= m :
        n += 1
        count += 1
        sum += n
        #print(f'{sum=},{n=},{count=}') 
    return count


while True:
    try:        
        n, m = input().split()
        n = int(n); m = int(m)
        print(count(n, m))
    except:
        break

