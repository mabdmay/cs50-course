from cs50 import get_int
height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")
n = height
for i in range(height):
    for j in range(n-1):
        print(" ", end="")
    for j in range(i+1):
        print("#", end="")
    print("  ", end = "")
    for j in range(i+1):
        print("#", end = "")
    print("")
    n = n - 1