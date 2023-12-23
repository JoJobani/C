/***************************************
Student name: Yehonatan Menashe
Student ID: 206478067
Exercise name: ex_3.c
****************************************/

#include <stdio.h>

#define NEW_COUNTER 0
#define DECIMAL_OPERATION 10
#define MIN_INPUT 0
#define MAX_DIGIT 9
#define STOP_FLAG 0
#define UPPERCASE_MIN 64
#define UPPERCASE_MAX 91
#define LOWERCASE_CONVERT 32
#define DECIMAL_MIN 48
#define DECIMAL_MAX 58
#define PROGRAM_RESET 1
#define TRUE 1
#define DECLARATION_RESET 0

/***************************************
* function name: error breaker.
* The Input: bad input from user.
* The Output: an error message.
* The Function operation: invalidates the rest of the input after invalid input.
  appears in a certain number.
***************************************/
void errorBreak(char badInput) {
    char newInput;
    if ((badInput == ' ') | (badInput == '\n')) {
        printf("You have a syntax error in your statement.\n");
        return;
    } else {
        scanf("%c", &newInput);
        errorBreak(newInput);
    }
}

/***************************************
* function name: digit counter.
* The Input: number being worked on, the digit, the original number.
* The Output: number being worked on, the digit, the original number.
* The Function operation: count the number of times a certain digit
  appears in a certain number.
***************************************/
void numCounter(int newNumber, int digit, int number, int counter) {
    int remainder;
    remainder = newNumber % DECIMAL_OPERATION;
    if (newNumber == STOP_FLAG) {
        printf("The digit %d appears %d times in the number %d\n",
               digit, counter, number);
    } else if (remainder == digit) {
        counter++;
        newNumber /= DECIMAL_OPERATION;
        numCounter(newNumber, digit, number, counter);
    } else {
        newNumber /= DECIMAL_OPERATION;
        numCounter(newNumber, digit, number, counter);
    }
}

/***************************************
* function name: GCD finder.
* The Input: larger number, smaller number, remainder.
* The Output: new larger and smaller numbers and the new remainder.
* The Function operation: use euclidean GCD algorithm to find the greatest
  common divider of two positive numbers.
***************************************/
void gcdFinder(int number1, int number2, int remainder) {
    int num1Step, num1Remainder;
    num1Remainder = number1 % number2;
    num1Step = number1 / number2;
    printf("%d*%d+%d = %d (num1=%d, num2=%d)\n", number2, num1Step,
           num1Remainder, number1, number1, number2);
    remainder = number1 % number2;
    number1 = number2;
    number2 = remainder;
    if (number2 == STOP_FLAG) {
        printf("GCD = %d\n", number1);
    } else {
        gcdFinder(number1, number2, remainder);
    }
}

int main() {
    while (1) {
        printf("Choose an option:\n");
        printf("\t 1: Logical Statement Calculator\n");
        printf("\t 2: Count digit in a number\n");
        printf("\t 3: GCD Calculator\n");
        printf("\t 4: Exit\n");
        int menu;
        menu = NEW_COUNTER;
        scanf("%d", &menu);
        //RUNTIME ERROR PREVENTION MEASURE
        getchar();
        switch (menu) {
            case 1: {
                int input1, input2, temp, firstPrint = TRUE;
                int logicCalc = TRUE, totalTrue = NEW_COUNTER;
                char not, rightBracket, leftBracket;
                char operator = NEW_COUNTER, statement;
                while (firstPrint == TRUE) {
                    printf("\nPlease write your logical statement: ");
                    firstPrint = STOP_FLAG;
                }
                //INPUT PHASE STARTS HERE
                //EVERY SINGLE LETTER WILL BE CHECKED FOR VALID INPUT
                while (logicCalc == TRUE) {
                    int false = NEW_COUNTER;
                    scanf(" %c", &not);
                    // TEST IF INPUT IS "NOT" SENTENCE
                    if (not == '~') {
                        scanf("%c", &leftBracket);
                        if (leftBracket != '(') {
                            errorBreak(leftBracket);
                            break;
                        }
                    } else {
                        leftBracket = not;
                        if (leftBracket != '(') {
                            errorBreak((char) leftBracket);
                            break;
                        }
                    }
                    input1 = getchar();
                    //TEST IF INPUT IS VALID
                    if ((input1 < DECIMAL_MIN) |
                        (input1 >= DECIMAL_MAX & input1 <= UPPERCASE_MIN)) {
                        errorBreak((char) input1);
                        break;
                    }
                    //UPPERCASE TO LOWERCASE CONVERSION AS NEEDED
                    if (input1 > UPPERCASE_MIN &
                        input1 < UPPERCASE_MAX) {
                        input1 += LOWERCASE_CONVERT;
                    }
                    //LARGE NUMBER CORRECTION
                    scanf("%c", &operator);
                    while (operator < DECIMAL_MAX & operator >= DECIMAL_MIN) {
                        input1 -= DECIMAL_MIN;
                        input1 *= DECIMAL_OPERATION;
                        operator -= DECIMAL_MIN;
                        temp = (int) operator;
                        input1 += temp;
                        operator = DECLARATION_RESET;
                        scanf("%c", &operator);
                    }
                    //OPERATOR VALIDITY TEST
                    if ((operator != '=') & (operator != '<') &
                        (operator != '>')) {
                        errorBreak(operator);
                        break;
                    }
                    //UPPERCASE TO LOWERCASE CONVERSION
                    input2 = getchar();
                    if (input2 > UPPERCASE_MIN & input2 < UPPERCASE_MAX) {
                        input2 += LOWERCASE_CONVERT;
                    }
                    //LARGER NUMBER CORRECTION
                    scanf("%c", &rightBracket);
                    while (rightBracket < DECIMAL_MAX &
                           rightBracket >= DECIMAL_MIN) {
                        input2 -= DECIMAL_MIN;
                        input2 *= DECIMAL_OPERATION;
                        rightBracket -= DECIMAL_MIN;
                        temp = (int) rightBracket;
                        input2 += temp;
                        rightBracket = DECLARATION_RESET;
                        scanf("%c", &rightBracket);
                    }
                    if (rightBracket != ')') {
                        errorBreak(rightBracket);
                        break;
                    }
                    // TESTING PHASE STARTS HERE
                    // EVERY ERROR WILL BE ADDED AS A FLAG
                    if (operator == '=' & not != '~') {
                        if (input1 != input2) {
                            false++;
                        }
                    } else if (operator == '=' & not == '~') {
                        if (input1 == input2) {
                            false++;
                        }
                    }
                    if (operator == '>' & not != '~') {
                        if (input1 < input2) {
                            false++;
                        }
                    } else if (operator == '>' & not == '~') {
                        if (input1 > input2) {
                            false++;
                        }
                    }
                    if (operator == '<' & not != '~') {
                        if (input1 > input2) {
                            false++;
                        }
                    } else if (operator == '<' & not == '~') {
                        if (input1 < input2) {
                            false++;
                        }
                    }
                    //FLAG TRIGGER IN CASE OF FALSE INPUT
                    if (false > NEW_COUNTER) {
                        totalTrue--;
                    } else if (false == NEW_COUNTER) {
                        totalTrue++;
                    }
                    //VALIDATION OF ONE OR MORE FALSE INPUTS IN A CASE OF "OR"
                    scanf("%c", &statement);
                    if (statement == '&') {
                        logicCalc = TRUE;
                        continue;
                        //CONTINUE ADDING SENTENCES AS NEEDED
                    } else if (statement == '|') {
                        totalTrue++;
                        logicCalc = PROGRAM_RESET;
                        continue;
                        //END OF INPUT TRIGGER
                    } else if (statement == '\n' | statement == ' ') {
                        logicCalc = STOP_FLAG;
                        //VALID INPUT CHECK
                    } else if (statement != '\n') {
                        errorBreak(statement);
                        continue;
                    }
                    //TEST CONCLUSION
                    if (totalTrue > NEW_COUNTER) {
                        printf("The statement is true.\n");
                        continue;
                    } else {
                        printf("The statement is false.\n");
                        continue;
                    }
                }
                continue;
            }
                //SECOND MENU PROGRAM IS TO CHECK THE NUMBER OF TIMES A CERTAIN
                //DIGIT APPEARS IN A CEERTAIN NUMBER
            case 2: {
                int number, digit, newNumber, counter = NEW_COUNTER;
                printf("\nEnter a number and a digit: ");
                scanf("%d %d", &number, &digit);
                //CHECKING FOR INVALID INPUT
                if (number < MIN_INPUT | digit < MIN_INPUT |
                    digit > MAX_DIGIT) {
                    printf("You should stay positive, and ");
                    printf("so should your input. \n");
                    continue;
                }
                //EDGE CASE OF ZERO AS BOTH DIGIT AND NUMBER
                if (number == 0) {
                    counter++;
                }
                //ACTUAL FUNCTION CALL
                newNumber = number;
                numCounter(newNumber, digit, number, counter);
                continue;
            }
            case 3: {
                //PROGRAM TO FIND THE GREATEST COMMON DIVIDER OF TWO NUMBERS
                int number1, number2, temp, remainder = NEW_COUNTER;
                printf("\nEnter two positive numbers: ");
                scanf("%d %d", &number1, &number2);
                //INPUT VALIDITY TEST
                if (number1 < MIN_INPUT | number2 < MIN_INPUT) {
                    printf("You should stay positive, and ");
                    printf("so should your input. \n");
                    continue;
                }
                //EDGE CASE OF ZERO AS BOTH INPUTS
                if (number1 == 0 & number2 == 0) {
                    printf("GCD = 0\n");
                    continue;
                    //EDGE CASES OF ZERO AS A SINGLE INPUT
                } else if (number1 == 0 & number2 != 0) {
                    printf("GCD = %d\n", number2);
                    continue;
                } else if (number1 != 0 & number2 == 0) {
                    printf("GCD = %d\n", number1);
                    continue;
                    //NUMBER SWAPPING SO THE FIRST NUMBER IS THE LARGEST
                } else if (number2 > number1) {
                    temp = number2;
                    number2 = number1;
                    number1 = temp;
                }
                //FUNCTION CALL
                gcdFinder(number1, number2, remainder);
            }
                continue;
                //MENU EXIT OPTION
            case 4: {
                printf("So Long, and Thanks for All the Fish!\n");
                break;
            }
                //INVALID MENU INPUT MESSAGE
            default: {
                printf("Fool of a Took!\n");
                printf("This is a serious journey, ");
                printf("not a hobbit walking-party.\n");
                printf("Throw yourself in next time, and then ");
                printf("you will be no further nuisance.\n");
                continue;
            }
        }
        break;
    }
    return 0;
}