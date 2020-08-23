from cs50 import SQL
from csv import reader
from sys import argv

# open students.db using sql (i think?)
db = SQL("sqlite:///students.db")

# check for agrv length 
if len(argv) < 2:
    print("error, usage: python import.py charaters.csv")
    exit()
    
# open csv file for ordering
with open(argv[1], newline="") as characterFile:
    characters = reader(characterFile)
    
    # for every name we check if the name = name 
    for char in characters:
        if char[0] == 'name':
            continue
        
        # split the name in all possible spaces (first, middle and last)
        fullName = char[0].split()
        
        # insert the names into student.db
        if len(fullName) < 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], None, fullName[1], char[1], char[2])

        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullName[0], fullName[1], fullName[2], char[1], char[2])