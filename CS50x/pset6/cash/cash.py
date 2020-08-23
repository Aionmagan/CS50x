from cs50 import get_float
import numpy as np

# variables for program
coins = 0
money = 0.00
centAdded = 0.00

# array of cent amount to add
# np.arange(0., 1,  )
cents = np.array([0.25, 0.10, 0.05, 0.01], dtype=np.float)

# entering do while lood 
while True:
    # get input from user 
    money = get_float("Change owed: ")
    
    # iterate to next loop
    if money < 0.0:
        continue

    # calculate coins 
    for i in range(4):
        while True:
            # if less then add if more
            # subtract and break
            # if equal break
            if float('%.2f' % centAdded) < float('%.2f' % money):
                centAdded += cents[i]
                coins += 1
            elif float('%.2f' % centAdded) > float('%.2f' % money):
                centAdded -= cents[i]
                coins -= 1
                break
            else:  # if equal 
                break

    # break out of the do while            
    if money > 0.0:
        break
    
print(coins)