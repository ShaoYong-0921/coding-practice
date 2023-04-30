while True:
    try:
        a = list(map(int, input().split()))
        n = a[0]
        a = a[1:]
 
        d = [0 for _ in range(n)]
        for i in range(1, n):
            delta = abs(a[i] - a[i-1])
            if delta <= n-1:
                d[delta] += 1
 
        flag = True
        for i in range(1, n):
            if d[i] != 1:
                flag = False
                break
 
        if flag:
            print("Jolly")
        else:
            print("Not jolly")
    except:
        break