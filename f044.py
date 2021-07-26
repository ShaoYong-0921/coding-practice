def f(x):
    count = 0
    while x > 1:
           
        x =x//2
        count += 1
        
        #print(f"x={x},count={count}")
        
    return count
#main
text =[]
text = list(map(int,input().split()) )
n = text[0]
t = text[1]

x = t/n
x += 1
#print(x)

print(f(x))

    
    
