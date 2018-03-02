import cs50

print("O hai! How much change is owed")
n = cs50.get_float()
while n < 0:
    print("How much change is owed?")
    n = cs50.get_float()
cents = round(n * 100)
coins = 0
if (cents // 25 != 0):
    coins += cents // 25
    cents -= (cents // 25) * 25
if (cents // 10 != 0):
    coins += cents // 10
    cents -= (cents // 10) * 10
if (cents // 5 != 0):
    coins += cents // 5
    cents -= (cents // 5) * 5
coins += cents
print(int(coins))