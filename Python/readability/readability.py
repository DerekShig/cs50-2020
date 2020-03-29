text = input("Text: ")

letters = 0
sentences = 0
words = 0

for i in text:

    if i.isalpha() == True:
        letters += 1
    if i == "." or i == "!" or i == "?":
        sentences += 1
    if i == " ":
        words += 1

L = ((letters * 100) / (words * 100)) * 100
S = ((sentences * 100) / (words * 100)) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Grade Before Grade 1")
elif index > 16:
    print("Grade 16")
else:
    print(f"Grade {index}")