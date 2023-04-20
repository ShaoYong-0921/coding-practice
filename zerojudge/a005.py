listA=[]
n=int(input())
for i in range(n):
    listA=list(map(int,input().split()))
    
    if (listA[0]-listA[1])!=(listA[2]-listA[3]):
        x=listA[3]/listA[2]
        
        y=listA[3]*x
        listA.append(y)
    else:
        x=listA[1]-listA[0]
       
        y=listA[3]+x
        listA.append(y)
    for j in range(5):
        print(int(listA[j]),end=" ")
    print()
        
        
    
    
    
        
    
