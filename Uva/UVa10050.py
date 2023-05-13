# day = 100
# party_days = [12, 15, 25, 40]

t = int(input())
for i in range(t):
    day = int(input())

    party = int(input())
    party_days = []
    for i in range(party):
        party_days.append(int(input()))
    
    # print(f'{day = } {party = } {party_days = }')

    day_set = set()

    for i in party_days:
            for j in range(i, day+1, i):
                weekend = False

                if (j % 7 == 6) or (j % 7 == 0):
                    weekend = True

                if not weekend:
                    day_set.add(j)


    print(f'{len(day_set)}')