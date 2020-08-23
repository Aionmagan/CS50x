from cs50 import get_string


def Main():

    # get user Input
    text = get_string("Text: ")

    # variables
    s = 0.0
    l = 0.0

    l = CheckLetter(text)
    s = CheckSentences(text)
    
    index = ((0.0588 * l) - (0.296 * s) - 15.8)
    
    if index < 1:
        index = 1
        
    if index > 16:
        print("Grade 16+")
    elif index < 2:
        print("Before Grade 1")
    else:
        print("Grade", int(round(index)))

    
def CheckLetter(text):
    # letter and words
    letter = 0
    words = 1
    # adding words and letters
    for i in range(0, len(text), 1):
        if text[i] == ' ':
            words += 1
        elif not CheckTable(text[i], False):
            letter += 1
            # print(text[i], letter)
    # return letter avarage
    # print((float(letter) / words * (100-1.5)))
    return (float(letter) / words * 100)
    

def CheckSentences(text):
    # getting sentence
    # getting words
    # period_check is to make sure double .(U.S.)
    sentences = 0
    word = 1
    periodCheck = -1
    secondPeCheck = 0

    for i in range(0, len(text), 1):
        if text[i] == " ":
            word += 1
        elif CheckTable(text[i], True):
            # period checking
            if i + 2 < len(text):
                secondPeCheck = i + 2
            else:
                secondPeCheck = 0
                
            if text[i] == "." and text[secondPeCheck] == "." and secondPeCheck != i:
                periodCheck = i + 2
            elif periodCheck < i:
                sentences += 1
    # print((float(sentences) / word * 100))
    return (float(sentences) / word * 100)
    

def CheckTable(char, isSentence):
    # checking the table
    # i hate the face that
    # switch case don't exist...
    listA = ['!', '?', '.']
    listB = [',', ':', ';', '\'', '\0']
    if isSentence == True:
        if char in listA:
            return True
    else:
        if char in listB or char in listA:
            return True
    # else return false
    return False

    
Main()