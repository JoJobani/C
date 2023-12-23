/******************************************
*Student name: Yehonatan Menashe
*Student ID: 206478067
*Exercise name: ex_2.c
******************************************/

#include <stdio.h>
#include <math.h>

#define DECIMAL 10
#define OCTAL 8
#define OCTAL_TEST 7
#define HEX_CONVERSION 9
#define MASK 15
#define BYTE_SIZE 4
#define BINARY_REMAINDER 2

int main() {
    int menu;
    while (1) {
        printf("Choose an option:\n");
        printf("1. octal to hex\n");
        printf("2. binary addition\n");
        printf("3. print HI\n");
        printf("4. count bits\n");
        printf("5. decimal to binary\n");
        printf("6. Zig-Zag bits\n");
        printf("7. exit\n");

        scanf("%d", &menu);
        // main menu starts here
        switch (menu) {
            case 1: {
                // convert an octal number to a hex number
                long int decimal = 0, octal = 0, mask;
                int powerCount = 0, reverse = 0, remainder, testLength;
                int testRemainder, testError = 0, trail = 1;
                char hex;
                printf("Please enter number in octal base: ");
                scanf("%ld", &octal);
                testLength = octal;
                //test if the number is octal
                while (testLength > OCTAL_TEST) {
                    testRemainder = testLength % DECIMAL;
                    if (testRemainder > OCTAL_TEST) {
                        testError++;
                    }
                    testLength = testLength / DECIMAL;
                }
                if (testError >= 1) {
                    printf("Invalid input!\n");
                    continue;
                }
                // reverse the octal input
                while (octal != 0) {
                    remainder = octal % DECIMAL;
                    reverse = reverse * DECIMAL + remainder;
                    octal /= DECIMAL;
                }
                // convert the octal to decimal
                while (reverse != 0) {
                    decimal = (long int) (decimal +
                                          (reverse % DECIMAL) *
                                          pow(OCTAL, powerCount++));
                    reverse = reverse / DECIMAL;
                }
                // convert decimal to hex using masks
                for (int j = sizeof(decimal) * 2 - 1;
                     j >= 0; j--) {
                    mask = MASK << (j * BYTE_SIZE);
                    hex = (char) ((decimal & mask) >> (j * BYTE_SIZE));
                    if (hex > HEX_CONVERSION) {
                        hex -= DECIMAL;
                        hex += 'A';
                    } else {
                        hex += '0';
                    }
                    if (hex != '0') {
                        trail = 0;
                    }
                    if (trail) {
                        continue;
                    }
                    printf("%c", hex);
                }
                printf("\n");
            }
                continue;
            case 2: {
                // combine two binary numbers
                unsigned long long int binary1, binary2, testError = 0;
                unsigned long long int larger, smaller, binarySum = 0, sizeTest;
                unsigned long long int binaryTest, remainderTest;
                int sizeCount = 0, remainder = 0, binaryTimes = 0;
                printf("Please enter two binary numbers: ");
                scanf("%lld", &binary1);
                // test if the numbers really are binary
                binaryTest = binary1;
                while (binaryTest > 1) {
                    remainderTest = binaryTest % DECIMAL;
                    if (remainderTest > 1) {
                        testError++;
                    }
                    binaryTest = binaryTest / DECIMAL;
                }
                scanf("%lld", &binary2);
                binaryTest = binary2;
                while (binaryTest > 1) {
                    remainderTest = binaryTest % DECIMAL;
                    if (remainderTest > 1) {
                        testError++;
                    }
                    binaryTest = binaryTest / DECIMAL;
                }
                if (binary1 < 0 || binary2 < 0) {
                    printf("Invalid input!");
                    testError++;
                }
                if (testError >= 1) {
                    printf("Invalid input!\n");
                    continue;
                }
                // decide the order of the numbers with the smaller being first
                if (binary1 > binary2) {
                    larger = binary1;
                    smaller = binary2;
                } else if (binary1 < binary2) {
                    larger = binary2;
                    smaller = binary1;
                } else {
                    smaller = binary1;
                    larger = binary2;
                }
                sizeTest = larger;
                while (sizeTest != 0) {
                    sizeCount++;
                    sizeTest /= DECIMAL;
                }
                //combine the two binary numbers one digit at a time
                while (binary1 != 0 || binary2 != 0) {
                    binarySum +=
                            ((binary1 % DECIMAL + binary2 % DECIMAL +
                              remainder) % BINARY_REMAINDER) *
                            pow(DECIMAL, binaryTimes);
                    remainder = ((binary2 % DECIMAL + binary1 % DECIMAL) +
                                 remainder) / BINARY_REMAINDER;
                    binaryTimes++;
                    binary1 /= DECIMAL;
                    binary2 /= DECIMAL;
                }
                // add zeroes to the left of the smaller number
                if (remainder > 0) {
                    binarySum += remainder * pow(DECIMAL, binaryTimes);
                }
                printf("%0*lld + %lld = %lld\n", sizeCount, smaller, larger,
                       binarySum);
                continue;
            }
            case 3: {
                // print "HI"
                int x;
                printf("Please enter size: ");
                scanf("%d", &x);
                if (x < 0) {
                    printf("Invalid input!\n");
                    continue;
                } else {
                    for (int i = 0; i < x + 2; ++i) {
                        printf("#");
                    }
                    for (int i = 0; i < x + 1; ++i) {
                        printf(" ");
                    }
                    for (int i = 0; i < x + 2; ++i) {
                        printf("#");
                    }
                    printf("  ");
                    for (int i = 0; i < x + 2; ++i) {
                        printf("#");
                    }
                    printf("\n");
                    for (int j = 0; j < x; ++j) {
                        printf("#");
                        for (int i = 0; i < x; ++i) {
                            printf("*");
                        }
                        printf("#");
                        for (int i = 0; i < x + 1; ++i) {
                            printf(" ");
                        }
                        printf("#");
                        for (int i = 0; i < x; ++i) {
                            printf("*");
                        }
                        printf("#");
                        for (int i = 0; i < 2; ++i) {
                            printf(" ");
                        }
                        printf("#");
                        for (int i = 0; i < x; ++i) {
                            printf("*");
                        }
                        printf("#\n");
                    }
                    printf("#");
                    for (int i = 0; i < x; ++i) {
                        printf("*");
                    }
                    for (int i = 0; i < x + 3; ++i) {
                        printf("#");
                    }
                    for (int i = 0; i < x; ++i) {
                        printf("*");
                    }
                    printf("#");
                    printf("  ");
                    printf("#");
                    for (int i = 0; i < x; ++i) {
                        printf("*");
                    }
                    printf("#\n");
                    for (int j = 0; j < x; ++j) {
                        printf("#");
                        for (int i = 0; i < 3 * x + 3; ++i) {
                            printf("*");
                        }
                        printf("#");
                        for (int i = 0; i < 2; ++i) {
                            printf(" ");
                        }
                        printf("#");
                        for (int i = 0; i < x; ++i) {
                            printf("*");
                        }
                        printf("#\n");
                    }
                    printf("#");
                    for (int i = 0; i < x; ++i) {
                        printf("*");
                    }
                    for (int i = 0; i < x + 3; ++i) {
                        printf("#");
                    }
                    for (int i = 0; i < x; ++i) {
                        printf("*");
                    }
                    printf("#");
                    for (int i = 0; i < 2; ++i) {
                        printf(" ");
                    }
                    printf("#");
                    for (int i = 0; i < x; ++i) {
                        printf("*");
                    }
                    printf("#\n");
                    for (int j = 0; j < x; ++j) {
                        printf("#");
                        for (int i = 0; i < x; ++i) {
                            printf("*");
                        }
                        printf("#");
                        for (int i = 0; i < x + 1; ++i) {
                            printf(" ");
                        }
                        printf("#");
                        for (int i = 0; i < x; ++i) {
                            printf("*");
                        }
                        printf("#");
                        for (int i = 0; i < 2; ++i) {
                            printf(" ");
                        }
                        printf("#");
                        for (int i = 0; i < x; ++i) {
                            printf("*");
                        }
                        printf("#\n");
                    }
                    for (int i = 0; i < x + 2; ++i) {
                        printf("#");
                    }
                    for (int i = 0; i < x + 1; ++i) {
                        printf(" ");
                    }
                    for (int i = 0; i < x + 2; ++i) {
                        printf("#");
                    }
                    printf("  ");
                    for (int i = 0; i < x + 2; ++i) {
                        printf("#");
                    }
                    printf("\n");
                }
                continue;
            }
            case 4: {
                // count the number "1" appears in a binary input
                int binary, count = 0, remainder=0, error = 0;
                printf("Please enter a binary number: ");
                scanf("%d", &binary);
                while (binary > 0) {
                    remainder = binary % DECIMAL;
                    if (remainder > 1) {
                        error++;
                        binary /=DECIMAL;
                    } else if (remainder == 1) {
                        count++;
                        binary /= DECIMAL;
                    } else {
                        binary /= DECIMAL;
                    }
                }
                if (error >= 1) {
                    printf("Invalid input!\n");
                    continue;
                }
                printf("%d\n", count);
                continue;
            }
            case 5: {
                // convert a decimal input to a binary number
                long int binary = 0;
                int power = 0, input, num;
                printf("Enter a non negative decimal number: ");
                scanf("%d", &input);
                if (input < 0) {
                    printf("Invalid input!\n");
                    continue;
                }
                num = input;
                while (input > 0) {
                    int remainder = input % BINARY_REMAINDER;
                    int binaryTemp = (long int) pow(DECIMAL, power);
                    binary += (remainder * binaryTemp);
                    power++;
                    input /= BINARY_REMAINDER;
                }
                printf("%d => %ld\n", num, binary);
                continue;
            }
            case 6: {
                // convert a decimal input to a binary number
                long int binary = 0;
                int power = 0, num;
                printf("Enter a non negative decimal number: ");
                scanf("%d", &num);
                if (num == 0) {
                    printf("true");
                    break;
                } else if (num < 0) {
                    printf("Invalid input!\n");
                    continue;
                }
                while (num > 0) {
                    int remainder = num % BINARY_REMAINDER;
                    int binaryTemp = (long int) pow(DECIMAL, power);
                    binary += (remainder * binaryTemp);
                    power++;
                    num /= BINARY_REMAINDER;
                }
                // check if a zig-zag does happen in the binary number
                int remainder, zigzag = 1;
                while (binary > 1) {
                    remainder = binary % DECIMAL;
                    binary /= DECIMAL;
                    if (remainder == zigzag) {
                        printf("false\n");
                        break;
                    }
                    zigzag = remainder;
                }
                if (binary == 1) {
                    printf("true\n");
                    break;
                }
                continue;
            }
            case 7: {
                // exit program
                printf("Bye!\n");
                break;
            }
            default: {
                //Invalid input!
                printf("Invalid input!\n");
                continue;
            }
        }
        break;
    }
    return 0;
}
