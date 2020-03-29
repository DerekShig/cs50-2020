import csv
from cs50 import SQL
from sys import argv, exit

db = SQL("sqlite:///students.db")

if len(argv) != 2:

    print("Invalid use.")
    exit(1)

with open(argv[1], "r") as file:

    reader = csv.DictReader(file)

    for row in reader:
        name = row["name"].split()
        if len(name) == 2:
            db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)", name[0], name[1], row["house"], row["birth"])
        if len(name) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", name[0], name[1], name[2], row["house"], row["birth"])

exit(0)