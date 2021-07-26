listA=[]
listB=[]
def fib(n):
    a,b=0,1
    while a < n:
        listA.append(a)
        a,b=b,a+b
        

fib(1000000)
x=int(input())
for i in range(0,x,1):
    
    y=int(input())
    listA.append(y)
    ans=listA.index(y)
    


            
    
    if listA.count(y) == 1:
        listB.append(-1)
    else:
        listB.append(ans)

e=""
for i in range (len(listB)):
    if i < (len(listB))-1:       
        e=e+str(listB[i])+"\n"
    else:
        e=e+str(listB[i])
print(e)
