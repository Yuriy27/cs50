import cs50

height = 0
while True:
    height = cs50.get_int()
    if height >= 0 and height <= 23:
        break
width = height + 1
for i in range(height):
    print(" "*(height - i - 1), end="")
    print("#"*(i + 2))
