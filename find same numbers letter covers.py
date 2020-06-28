import random

random_list = []
random_table = []
index_list = []
index_table = []
game_conroller = [1,2,3,4,5,6]      #game controller - line 73 and 87
step = 1

print('Find the same numbers')
print('----------------------')
print('Enter numbers 1 to 6 for each list')
print()

#random numbers for random_list
for i in range(1,7):
    n = random.randint(1,6)
    while n in random_list:
        n = random.randint(1,6)
    else:
        random_list.append(n)

#random numbers for random_table
for i in range(1,7):
    x = random.randint(1,6)
    while x in random_table:
        x = random.randint(1,6)
    else:
        random_table.append(x)

# 'X' cover for random_list
random1 = []
index = 1
for a in range(1,7):
    random1.append(f'X{index}')
    index += 1
print('First List:  ', random1)

# 'O' cover for random_table
random2 = []
index = 1
for a in range(1,7):
    random2.append(f'O{index}')
    index += 1
print('Second List: ', random2)

print()

while True:
    print(f'[step {step}]\n')
    num = int( input("Enter first number : X"))
    num2 = int (input('Enter second number : O'))
    num -=1
    num2 -=1
    print()

    if num > 8 or num2 > 8 or num < 0 or num2 < 0 or num in index_list or num2 in index_table:
        print('Alert!')
        if num > 8 or num2 > 8 or num < 0 or num2 < 0:
            print('\nEntered numbers are out of range')
        if num in index_list:
            print('X',num+1,'is used before')
        if num2 in index_table:
            print('O',num2+1,'is used before')
        print('Try Again!\n')
        step -= 1

    else:
        if random_list[num] == random_table[num2]:
            print(f'\t||[True:  {random_list[num]} && {random_table[num2]}]||\n')
            random1[num] = random_list[num]
            random2[num2] = random_table[num2]
            game_conroller.pop()
            index_list.append(num)
            index_table.append(num2)
            print('First List:  ', random1)
            print('Second List: ', random2, '\n')

        else:
            print(f'\t{random_list[num]} && {random_table[num2]}\n')
            print('Not True. Try Again!\n')
            print('First List:  ', random1)
            print('Second List: ', random2, '\n')

    step += 1
            
    if not game_conroller:
        print('You solved the game.\nWell done!')
        print('\nby Ali Ahmad Ataie\n@iamaliataie')
        break