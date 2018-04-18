#returns amount of change owed with fewest coins possible used
from cs50 import get_float

#prompt user for change until given
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break
#convert dollars to cents
change *= 100

#declare coins
quarter = 25
dime = 10
nickel = 5
penny = 1
coins = 0

#calculate how many coins will need to be used
while change >= quarter:
    change -= quarter
    coins += 1
while change >= dime:
    change -= dime
    coins += 1
while change >= nickel:
    change -= nickel
    coins += 1
while change >= penny:
    change -= penny
    coins += 1

print(f"Coins used: {coins}")