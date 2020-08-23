from cs50 import get_int

# collect variables
block = 0
half = 0

# start do while loop
while True:
    # get user input
    block = get_int("Height: ")

    # ittorate to next loop
    if block < 1 or block > 8:
        continue

    # half = block * 2
    half = block

    # print out pyramid
    for i in range(block):
        for j in range(block + (i + 3)):
            # print invisible area of pyramid
            if j == half or j == half + 1 or j >= half + (i + 3) or j <= half - (i + 2):
                print(" ", end="")
            else:
                print("#", end="")
        # print new line
        print()
    # break out of do while loop
    if block in range(9):
        break