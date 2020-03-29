from cs50 import get_int

while True:
    height = get_int("height: ")
    if height >= 1 and height <= 8:
        break

dots = height
hashes = 1
for i in range(height):
    print(" " * (dots-1), end="")
    dots -= 1
    print("#" * hashes, end="")
    print("  ", end="")
    print("#" * hashes, end="")
    hashes += 1
    print()