#b860


def f(c,w,complete):
    
    while c >= 12:
        
        c = c-12
        w -= 1
        complete += 1
        c += 1

    print(c,w,complete)

    return (c,w,complete)



#main
complete =0
c = int(input())
w = int(input())
x = f(c,w,complete)

print(f(complete))

if complete >= 1 :

     t = complete*4
     c = c+t
        
