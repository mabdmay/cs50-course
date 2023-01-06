from cs50 import get_string
text = get_string("Text: ")
characters = 0
words = 1
sentences = 0


for char in text:
    if char != '.' and char != "," and char != " " and char != "?" and char!= "!":
        characters += 1
    if char == " " or char == ". " or char == "'":
        words += 1
    if char == "." or char == "!" or char == "?":
        sentences += 1

L = characters * (100/words)
S = sentences * (100/words)

print (f"{characters} {words} {sentences}")

index = round((0.0588 * L) - (0.296 * S) - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
