from collections import Counter
listA = []

x = input()

listA = list(map(int,input().split()))



integer_counts = Counter(listA)
least = integer_counts.most_common(1)
print(integer_counts)
print(least)