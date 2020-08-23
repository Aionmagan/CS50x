from cs50 import SQL
from sys import argv

# checking for arguments
if len(argv) < 2:
    print("error, usage: python roster.py gryffinder/sly...")
    exit()
# getting student names by house and last name
db = SQL("sqlite:///students.db")
students = db.execute("SELECT DISTINCT * FROM students WHERE house = (?) ORDER BY last", argv[1])

# print out the names of each students
for stud in students:
    if stud['middle'] == None:
        print("{} {}, born {}".format(stud['first'], stud['last'], stud['birth']))
    else:
        print("{} {} {}, born {}".format(stud['first'], stud['middle'], stud['last'], stud['birth']))