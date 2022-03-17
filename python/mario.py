from cs50 import get_int, get_string

# answer = get_string("What's your name?\n")
# print("hello, " + answer)

i = get_int("Hight: ")
if i <= 0:
    print("err, ", i)
    exit(1)
j = 1
while i > 0:
    print(" " * (i - 1), "#" * j, " ", "#" * j)
    i -= 1
    j += 1