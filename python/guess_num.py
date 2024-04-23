'''
生成随机数猜大小
'''

import random

guess_right = 0
num = random.randrange(1, 101)

while guess_right == 0:
    print('input: ')
    guess = int(input())
    if guess < num:
        print('小了')
    elif guess > num:
        print('大了')
    else:
        print('正确')
        guess_right = 1
