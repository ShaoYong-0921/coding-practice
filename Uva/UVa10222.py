string = input().lower()

# keyboard = '234567890-=ertyuiop[]dfghjkl;\'cvbnm,./'
# translate = '`1234567890qwertyuiopasdfghjklzxcvbnm,'

table = '`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./'
# print(keyboard.index('e'))

for i in string:
    if i == ' ':
        print(end=' ')
    else:
        # print(i)
        index = table.index(i)
        print(table[index-2], end='')

#??
print('')