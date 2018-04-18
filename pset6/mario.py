#### creates a half pyramid of height specified by user ####

from cs50 import get_int

#prompt user for integer until they give one between 1 and 23
while True:
    height = get_int("Height: ")
    if height >= 0 and height < 24:
        break
#integer for the spaces
m = height - 1
#iterate through given height
for i in range(height):
    #print spaces
    for j in range(m):
        print(" ", end="")
    #print hashtags
    for k in range((i + 2)):
        print("#", end="")
    m -= 1
    #print next line
    print()