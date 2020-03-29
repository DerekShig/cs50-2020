from cs50 import get_float

counter = 0

while True:
    coins = get_float("Change Owed: ")
    if coins > 0:
        coins *= 100
        break

while coins >= 25:
    coins -= 25
    counter += 1

while coins >= 10:
    coins -= 10
    counter += 1

while coins >= 5:
    coins -= 5
    counter += 1

while coins >= 1:
    coins -= 1
    counter += 1

print(counter)