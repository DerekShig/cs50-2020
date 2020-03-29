import csv
from cs50 import SQL
from sys import argv, exit

db = SQL("sqlite:///students.db")

if len(argv) != 2:

    print("Invalid use.")
    exit(1)


gry = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last ASC, first ASC", argv[1])
for i in gry:
    if i["middle"] == None:
        print(i["first"] + " "  + i["last"] + ", born " + str(i["birth"]))
    else:
        print(i["first"] + " " + i["middle"] + " " + i["last"] + ", born " + str(i["birth"]))