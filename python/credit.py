
card = ''
while card.isdigit() == False or len(card) < 13 or len(card) == 14 or len(card) > 16:
    card = str(input("Введите номер карты: "))

ss = []
summ = []
g = 0
for i in card[-2::-2]:
    summ.append(int(i)*2)
for s in str(summ):
    ss += s
for f in ss:
    if f.isdigit():
        g += int(f)
for i in card[-1::-2]:
    g += int(i)
if g%10 == 0:
    if card[0] == '4':
        print('VISA')
    elif card[0] == '5' and (card[1] == '1' or card[1] == '2' or card[1] == '3' or card[1] == '4' or card[1] == '5'):
        print('MASTERCARD')
    elif card[0] == '3' and (card[1] == '4' or card[1] == '7'):
        print('AMEX')
else:
    print('INVALID')
