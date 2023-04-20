def maximumWealth(self, accounts: list[list[int]]) -> int:
    wealth = []
    for customer in accounts:
        sum = 0
        for i in customer:
            sum += i
        wealth.append(sum)
    return max(wealth)
    