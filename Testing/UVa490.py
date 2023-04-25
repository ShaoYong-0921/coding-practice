sentences = []
column = 0
row = 0

try:
    while True:
        lines = ''
        line = input()
        lines += line
        print(lines)
        sentences.append([x for x in line])
except EOFError:
    pass

max_len = int()
for i in sentences:
    if len(i) > max_len:
        max_len = len(i)
row = max_len
column = len(sentences)
print(f'{column = } ; { row = }')
table = [[' ' for i in range(column)] for j in range(row)]
# row = len(sentences)
# print('max =',max_len)


for i in table:
    print(i)

for i in range(row):
    for j in range(column):
        table[i][j] = sentences[j][i]

for i in table:
    print(i)
