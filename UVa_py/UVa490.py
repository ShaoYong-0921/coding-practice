sentences = []

try:
    while True:
        line = input()
        # print(lines)
        sentences.append([x for x in line])
except EOFError:
    pass

sentences.reverse()

# print(sentences)

max_len = 0
for i in sentences:
    if len(i) > max_len:
        max_len = len(i)

row = max_len
column = len(sentences)
# print(f'{column = } ; { row = }')

table = [[' ' for i in range(column)] for j in range(row)]

column = 0
for char_list in sentences:
    row = 0
    for char in char_list:
        # print(f'{column = } ; {row =}')
        table[row][column] = char
        row += 1
    column += 1

    # for _ in table:
    #     print(_)
    # print()

# row = len(sentences)
# print('max =',max_len)

for i in table:
    for j in i:
        print(j,end='')
    print()