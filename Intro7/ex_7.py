"""
*Student name: Yehonatan Menashe
*Student ID: 206478067
*Exercise name: ex_7
"""
import math

EXIT_PROGRAM = 0
FIRST_PROGRAM = 1
SECOND_PROGRAM = 2
MINIMUM_PRIME = 2
RANGE_START = 1
RANGE_END = 101
NO_REMAINDER = 0
MAX_RANGE_FIXER = 1


def is_prime_first_complexity(num):
    """
    find if num is a prime number using first complexity
    Keyword argument:
    num - number input from user
    Return - none
    """
    # edge case of 1 or 0
    if num < MINIMUM_PRIME:
        print("NO")
    else:
        # flag declaration
        is_prime = True
        # for loop from 2 to number to find if prime
        for i in range(MINIMUM_PRIME, int(num)):
            if (num % i) == NO_REMAINDER:
                # prime flag trigger
                is_prime = False
        # print result based on flag status
        if is_prime:
            print("YES")
        else:
            print("NO")


def is_prime_second_complexity(num):
    """
    find if num is a primary number using second complexity
    Keyword argument:
    num - number input from user
    Return - none
    """
    # edge case of 1 or 0
    if num < MINIMUM_PRIME:
        print("NO")
    else:
        # flag declaration
        is_prime = True
        # for loop to go over numbers from 2 to square root of input
        for i in range(MINIMUM_PRIME, int(math.sqrt(num)) + MAX_RANGE_FIXER):
            if (num % i) == NO_REMAINDER:
                # flag trigger
                is_prime = False
        # print result based on flag status
        if is_prime:
            print("YES")
        else:
            print("NO")


def number_divider(first_num, second_num):
    """
    put all numbers from 1 to 100 which can be divided by first or second input
    Keyword argument:
    first_num - first input
    second_num - second input
    Return - none
    """
    # list initialization
    number_list = []
    # for loop to go over all numbers from 1 to 100
    for i in range(RANGE_START, RANGE_END):
        if (i % first_num) == NO_REMAINDER or (i % second_num) == NO_REMAINDER:
            number_list.append(i)
    # prints the list
    print(number_list)


def main():
    # while loop so program doesn't end after a mission unless intended
    while True:
        # menu input from user
        menu = int(input("please enter a mission number:\n"))
        # press 0 to exit program
        if menu == EXIT_PROGRAM:
            exit(EXIT_PROGRAM)
        # press 1 for the first program
        if menu == FIRST_PROGRAM:
            # take input from user for complexity choice
            prime_func = input("please enter the mission type:\n")
            if prime_func == 'a':
                # first complexity function
                num = int(input("please enter a number:\n"))
                is_prime_first_complexity(num)
            elif prime_func == 'b':
                # second complexity function
                num = int(input("please enter a number:\n"))
                is_prime_second_complexity(num)
            else:
                # in case of bad input and return to main menu
                continue
        # press 2 for the second program
        if menu == SECOND_PROGRAM:
            # take two inputs from user
            first_num, second_num = input(
                "please enter two numbers:\n").split()
            # send the inputs as integers to the second mission function
            number_divider(int(first_num), int(second_num))
        else:
            # in case of bad input return to main menu
            continue


if __name__ == '__main__':
    main()
