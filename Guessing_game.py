import math


print ('''
        Welcome user!
        Its the most exciting guessing game you have
        ever played!!!
       
        name your number range
        the number of guess you get will ber set by us
        Goood luck!!
        ''')
import random as rand
lower_range = input('Print your lower range: ')
lower_range = int(lower_range)
if lower_range < 0:
    print("give a number bigger or equal to 0")
    lower_range = input('Print your lower range: ')
upper_range = input('Print your upper range: ')
upper_range = int(upper_range)
if upper_range < 0 or upper_range <= lower_range:
    if upper_range < 0:
        print("give a number bigger or equal to 0")
    if upper_range < lower_range:
        print("give a number bigger than the lower range")
    upper_range = input('Print your upper range: ')

lower_range = int(lower_range)
upper_range = int(upper_range)


lucky_num = rand.randint(lower_range, upper_range)
turns = round(math.log(lucky_num, 2))
turns *= turns
turns = int(turns)
f = False
while turns:
    print(f'Number of guess you can do: {turns}')
    x = input("What is your lucky number? ")
    x = int(x)
    if x > lucky_num:
        print("Smaller! ")
    if x < lucky_num:
        print("Bigger! ")
    if x == lucky_num:
        f = True
    if f:
        break
    else:
        turns -= 1


if turns == 0:
    print("YOU LOSE!")
if f:
    print("YOU WON :)")
