from cs50 import get_int


def checkValid(i):
    switch = {
        34: "AMEX",
        37: "AMEX",
        4: "VISA",
        51: "MASTERCARD",
        52: "MASTERCARD",
        53: "MASTERCARD",
        54: "MASTERCARD",
        55: "MASTERCARD"
    }
    return switch.get(i, "INVALID")
    
        
cc = -1

while cc < 0:
    # getting user input
    cc = get_int("Number: ")
    
    # get length of card number (not array)
    length = 1
    i = 1
    while (10 * i) < cc:
        length += 1
        i *= 10

    import array as arr
    digits = arr.array('i', [0] * length)
    # collect every digit in card
    j = 1
    for i in range(length):
        digits[i] = int((cc / j) % 10)
        j *= 10
    
    # visa is 4 hence the if 
    # for anything else it will be two digits collected
    firstCCdigits = int((digits[length - 1] * 10) + digits[length - 2])
    if digits[length - 1] == 4:
        if length >= 13:
            firstCCdigits = 4
        else:
            firstCCdigits = 0
    
    # start Luhn's Algorithm
    for i in range(length):
        if i % 2 == 1:
            digits[i] *= 2
            if digits[i] > 9:
                # adding digits that have two digits in one
                # index (00)
                digits[i] = int((digits[i] % 10) + (digits[i] / 10))
            
    # adding the remaining numbers here
    for i in range(length - 2, -1, -1):
        digits[length - 1] += digits[i]
        
    # if the last outcome has 0 in it then 
    # then we are good
    if (digits[length - 1] % 10) == 0:
        cardValid = ""
        cardValid = checkValid(firstCCdigits)
        print(cardValid)
    else:
        print("INVALID")