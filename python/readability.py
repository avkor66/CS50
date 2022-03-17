text = input('Text: ')
words = 0
characters = 0
sentences = 0
for t in text:
    if t.isalpha():
        characters += 1
    if t == ' ':
        words += 1
    if t == '.' or t == '!' or t == '?':
        sentences += 1
else:
    words += 1

print(characters, words, sentences)
L = (characters / words) * 100
S = (sentences / words) * 100

index = 0.0588 * L - 0.296 * S - 15.8
print(index)
def int_r(num):
    num = int(num + (0.5 if num > 0 else -0.5))
    return num
if index > 16:
    print('Grade 16+')
elif index <= 0:
    print('Before Grade 1')
else:
    print('Grade ', int_r(index))