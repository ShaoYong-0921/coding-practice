from collections import OrderedDict

ordered_dict = OrderedDict()

n = int(input())

for letter in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
    ordered_dict[letter] = 0
    
# print(ordered_dict)

# n = int(input())
# table = {}
# A = chr(65) ; Z = chr(90)
# for i in range(65,90):
#         d[chr(i)] = 0

for i in range(n):
	string = input()
	string = string.upper()
	for j in string:
		# print(j)
		if j in ordered_dict:
			ordered_dict[j] += 1

# print(ordered_dict)

sorted_dict = sorted(ordered_dict.items(), key=lambda ordered_dict:ordered_dict[1], reverse=True)

# print(sorted_dict)

for i in sorted_dict:
    if i[1] == 0:
        break
    print(i[0], i[1])