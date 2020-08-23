from cs50 import get_int

block = 0

while True:
    # get user input
    block = get_int("Height: ")

    # check if block is not withint range
    if block < 1 or block > 8:
        continue

    # loop around and print the blocks
    for i in range(block):
        for j in range(block):
            # make sure to only print necesary blocks
            if j >= (block - (i + 1)):
                print("#", end="")
            else:
                print(" ", end="")
        # print new line
        print()
        
    # break from while loop
    if block in range(9):
        break