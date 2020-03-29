from sys import argv, exit
import csv
import re

if len(argv) != 3:
    print("Incorrect arguments.")
    exit(1)

dna_file = open(argv[2], "r")

dna = ""
for i in dna_file:
    dna += i

if argv[1] == "databases/small.csv":
    AGATC = 1
    AATG = 1
    TATC = 1
    for i in dna:
        if ("AGATC" * AGATC) in dna:
            AGATC += 1
        if ("AATG" * AATG) in dna:
            AATG += 1
        if ("TATC" * TATC) in dna:
            TATC += 1


    with open(argv[1]) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        line_count = 0
        for row in csv_reader:
            if line_count == 0:
                line_count += 1
            else:
                if int(row[1]) == AGATC - 1 and int(row[2]) == AATG - 1 and int(row[3]) == TATC - 1:
                    print(row[0])
                    exit(0)

    print("No match")
    exit(1)

#AGATC,TTTTTTCT,AATG,TCTAG,GATA,TATC,GAAA,TCTG

elif argv[1] == "databases/large.csv":
    AGATC = 0
    TTTTTTCT = 0
    AATG = 0
    TCTAG = 0
    GATA = 0
    TATC = 0
    GAAA = 0
    TCTG = 0

    for i in dna:
        if ("AGATC" * AGATC) in dna:
            AGATC += 1
        if ("TTTTTTCT" * TTTTTTCT) in dna:
            TTTTTTCT += 1
        if ("AATG" * AATG) in dna:
            AATG += 1
        if ("TCTAG" * TCTAG) in dna:
            TCTAG += 1
        if ("GATA" * GATA) in dna:
            GATA += 1
        if ("TATC" * TATC) in dna:
            TATC += 1
        if ("GAAA" * GAAA) in dna:
            GAAA += 1
        if ("TCTG" * TCTG) in dna:
            TCTG += 1

    with open(argv[1]) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        line_count = 0
        for row in csv_reader:
            if line_count == 0:
                line_count += 1
            else:
                if int(row[1]) == AGATC - 1 and int(row[2]) == TTTTTTCT - 1 and int(row[3]) == AATG - 1 and int(row[4]) == TCTAG - 1 and int(row[5]) == GATA - 1 and int(row[6]) == TATC - 1 and int(row[7]) == GAAA - 1 and int(row[8]) == TCTG - 1:
                    print(row[0])
                    exit(0)

    print("No match")
    exit(1)