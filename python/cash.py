from cs50 import get_float
ch = 0
while ch <= 0:
    ch = int(get_float("Введите сдачу: ")*100)

t25 = 0
t10 = 0
t5 = 0
t1 = 0
while ch >= 25:

    ch = ch - 25
    t25+=1

while ch >= 10:
    ch = ch - 10
    t10+=1

while ch >= 5:
    ch = ch - 5
    t5+=1

while ch >= 1:
    ch = ch - 1
    t1+=1

print(t25+t10+t5+t1)

