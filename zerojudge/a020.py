dict1 = { 'A': 10, 'B':11, 'C': 12, 'D': 13, 'E': 14, 'F': 15, 'G': 16,
           'H': 17, 'I': 34, 'J': 18,'K': 19,'L': 20,'M': 21,'N': 22,
          'O': 35,'P':23, 'P': 23, 'Q': 24, 'R': 25, 'S': 26,'T': 27,
          'U': 28, 'V': 29, 'W': 32, 'X': 30, 'Y': 31,'Z': 33}
listA = []
sum1 = 0 
id_text = input()

for i in id_text:
    listA.append(i)
    
frist_id = listA[0]

del listA[0]
    
x = dict1[frist_id]


listA = list(map(int, listA))
listA.reverse()

for i in range (1,9):
    
    y =listA[i]
    sum1 += y*i
    

sum1 += (x%10)*9  + (x//10 ) + listA[0]
#print(sum1)
if sum1%10 == 0:
    print("real")
else:
    print("fake")
