def f(n):
    if n == 1:
        return 1

    table_f = [0]*(n+1)
    table_f[0] = 1; table_f[1] = 1
    i = 2

    while i <= n:
        if not table_f[i]:
            table_f[i] = table_f[i-1] + i 
        i += 1
    
    return table_f

def g(n):
    
    if n == 1:
        return 1

    table_f = f(n)

    table_g = [0]*(n+1)
    table_g[0] = 1; table_g[1] = 1
    i = 2
   
    while i <= n:
        if not table_g[i]:
            table_g[i] = table_g[i-1] + table_f[i] 
        i += 1
    return table_g

def main():

    n = int(input())
    if n == 1:
        print(1, 1)
    else:
        table_f = f(n)
        table_g = g(n)

        print(table_f[n], table_g[n])



while True:
    try:
        main()
    except:
        break

