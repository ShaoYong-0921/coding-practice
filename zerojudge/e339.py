x = int(input())
A = []
B = []
A = list(map (int,input().split()))
value = 0

for i in range(len(A)):
    
    value += A[i]
    #print(f"value = {value}")
        
    B.append(value)
    
for stdout in B:
    print(stdout,end=" ")
