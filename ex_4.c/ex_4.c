/********************************************************************
*Student name: Yehonatan Menashe
*Student ID: 206478067
*Exercise name: ex_4.c
********************************************************************/

#include <stdio.h>

#define FALSE 0
#define BOARD_DIMENSIONS 4
#define NEW_COUNTER 0
#define TRUE 1
#define LAST_CHAR 3
#define ALL_SLOTS 62
#define NO_WINNER_ROUND 2
#define MIN_INPUT 0
#define MAX_INPUT 3

int main() {
    int gameStart, game = FALSE, setup = TRUE, inputDump, code = TRUE;
    int x = BOARD_DIMENSIONS, y = BOARD_DIMENSIONS, z = BOARD_DIMENSIONS;
    char answer, restart;
    int board[x][y][z], xWin = NEW_COUNTER, oWin = NEW_COUNTER;
    int tieCounter = NEW_COUNTER;
    printf("Would you like to start? (y/n) \n");
    while (code) {
        //GAME MENU
        gameStart = getchar();
        while (setup == TRUE) {
            if (gameStart == 'n') {
                printf("YEET\n");
                code = FALSE;
                break;
            } else {
                //GAME BOARD CREATION
                for (int i = NEW_COUNTER; i < BOARD_DIMENSIONS; ++i) {
                    for (int j = NEW_COUNTER; j < BOARD_DIMENSIONS; ++j) {
                        for (int k = NEW_COUNTER; k < BOARD_DIMENSIONS; ++k) {
                            board[i][j][k] = '*';
                        }
                    }
                }
                setup = FALSE;
                game = TRUE;
                printf("Please enter your game sequence. \n");
            }
        }
        //INPUT PHASE
        while (game == TRUE) {
            //FIRST PLAYER INPUT
            scanf("%d %d %d", &x, &y, &z);
            if ((board[x][y][z] != '*') || (x < MIN_INPUT || x > MAX_INPUT) ||
                (y < MIN_INPUT || y > MAX_INPUT) ||
                (z < MIN_INPUT || z > MAX_INPUT)) {
                printf("Input incorrect. \n");
                game = FALSE;
                printf("Would you like to continue? (y/n) \n");
                scanf(" %c", &answer);
                if (answer == 'y') {
                    setup = TRUE;
                    break;
                } else if (answer == 'n') {
                    printf("YEET \n");
                    code = FALSE;
                    break;
                }
            } else {
                board[x][y][z] = 'X';
            }
            //ROW WIN TESTING FOR X
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if ((board[i][j][0] == 'X') && (board[i][j][1] == 'X') &&
                        (board[i][j][2] == 'X') && (board[i][j][3] == 'X')) {
                        xWin++;
                    }
                }
            }
            //COLUMN WIN TESTING FOR X
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if ((board[i][0][j] == 'X') && (board[i][1][j] == 'X') &&
                        (board[i][2][j] == 'X') && (board[i][3][j] == 'X')) {
                        xWin++;
                    }
                }
            }
            //LOCAL DIAGONAL TEST FOR X
            for (int i = 0; i < 4; ++i) {
                if ((board[i][0][0] == 'X') && (board[i][1][1] == 'X') &&
                    (board[i][2][2] == 'X') && (board[i][3][3] == 'X')) {
                    xWin++;
                }
            }
            for (int i = 0; i < 4; ++i) {
                if ((board[i][0][3] == 'X') && (board[i][1][2] == 'X') &&
                    (board[i][2][1] == 'X') && (board[i][3][3] == 'X')) {
                    xWin++;
                }
            }
            //BIG DIAGONAL WIN TESTING FOR X
            if ((board[0][0][0] == 'X') && (board[1][1][1] == 'X') &&
                (board[2][2][2] == 'X') && (board[3][3][3] == 'X')) {
                xWin++;
            }
            if ((board[0][0][3] == 'X') && (board[1][1][2] == 'X') &&
                (board[2][2][1] == 'X') && (board[3][3][0] == 'X')) {
                xWin++;
            }
            if ((board[0][3][0] == 'X') && (board[1][2][1] == 'X') &&
                (board[2][1][2] == 'X') && (board[3][0][3] == 'X')) {
                xWin++;
            }
            if ((board[0][3][3] == 'X') && (board[1][2][2] == 'X') &&
                (board[2][1][1] == 'X') && (board[3][0][0] == 'X')) {
                xWin++;
            }
            //SECOND PLAYER INPUT
            if (xWin == NEW_COUNTER) {
                scanf("%d %d %d", &x, &y, &z);
                if ((board[x][y][z] != '*') ||
                    (x < MIN_INPUT || x > MAX_INPUT) ||
                    (y < MIN_INPUT || y > MAX_INPUT) ||
                    (z < MIN_INPUT || z > MAX_INPUT)) {
                    printf("Input incorrect. \n");
                    game = FALSE;
                    printf("Would you like to continue? (y/n) \n");
                    scanf(" %c", &answer);
                    if (answer == 'y') {
                        setup = TRUE;
                        break;
                    } else if (answer == 'n') {
                        printf("YEET \n");
                        code = FALSE;
                        break;
                    }
                } else {
                    board[x][y][z] = 'O';
                }
            }
            //ROW WIN TESTING FOR O
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if ((board[i][j][0] == 'O') && (board[i][j][1] == 'O') &&
                        (board[i][j][2] == 'O') && (board[i][j][3] == 'O')) {
                        oWin++;
                    }
                }
            }
            //COLUMN WIN TESTING FOR O
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if ((board[i][0][j] == 'O') && (board[i][1][j] == 'O') &&
                        (board[i][2][j] == 'O') && (board[i][3][j] == 'O')) {
                        oWin++;
                    }
                }
            }
            //LOCAL DIAGONAL TEST FOR O
            for (int i = 0; i < 4; ++i) {
                if ((board[i][0][0] == 'O') && (board[i][1][1] == 'O') &&
                    (board[i][2][2] == 'O') && (board[i][3][3] == 'O')) {
                    oWin++;
                }
            }
            for (int i = 0; i < 4; ++i) {
                if ((board[i][0][3] == 'X') && (board[i][1][2] == 'X') &&
                    (board[i][2][1] == 'X') && (board[i][3][3] == 'X')) {
                    oWin++;
                }
            }
            //BIG DIAGONAL WIN TESTING FOR O
            if ((board[0][0][0] == 'O') && (board[1][1][1] == 'O') &&
                (board[2][2][2] == 'O') && (board[3][3][3] == 'O')) {
                oWin++;
            }
            if ((board[0][0][3] == 'O') && (board[1][1][2] == 'O') &&
                (board[2][2][1] == 'O') && (board[3][3][0] == 'O')) {
                oWin++;
            }
            if ((board[0][3][0] == 'O') && (board[1][2][1] == 'O') &&
                (board[2][1][2] == 'O') && (board[3][0][3] == 'O')) {
                oWin++;
            }
            if ((board[0][3][3] == 'O') && (board[1][2][2] == 'O') &&
                (board[2][1][1] == 'O') && (board[3][0][0] == 'O')) {
                oWin++;
            }
            //WINNER DECLARATION (IF NEEDED)
            if (xWin > NEW_COUNTER) {
                //X VICTORY
                printf("X is the winner. \n");
                for (int i = NEW_COUNTER; i < BOARD_DIMENSIONS; ++i) {
                    for (int j = NEW_COUNTER; j < BOARD_DIMENSIONS; ++j) {
                        for (int k = NEW_COUNTER; k < BOARD_DIMENSIONS; ++k) {
                            if (k == NEW_COUNTER) {
                                printf("(%d %d %d) ", i, j, k);
                                printf("(%d %d %d) ", i, j, k + 1);
                                printf("(%d %d %d) ", i, j, k + 2);
                                printf("(%d %d %d) ", i, j, k + 3);
                            }
                            printf("%c ", board[i][j][k]);
                            if (k == LAST_CHAR) {
                                printf("\n");
                            }
                        }
                        if (j == LAST_CHAR) {
                            printf("\n");
                        }
                    }
                }
                inputDump = getchar();
                while (inputDump != '\n') {
                    inputDump = getchar();
                }
                game = FALSE;
                printf("Would you like to continue? (y/n) \n");
                scanf("%c", &restart);
                if (restart == 'y') {
                    xWin = NEW_COUNTER;
                    setup = TRUE;
                    break;
                } else if (restart == 'n') {
                    printf("YEET \n");
                    code = FALSE;
                }
                //O VICTORY
            } else if ((xWin == NEW_COUNTER) && (oWin > NEW_COUNTER)) {
                printf("O is the winner. \n");
                for (int i = NEW_COUNTER; i < BOARD_DIMENSIONS; ++i) {
                    for (int j = NEW_COUNTER; j < BOARD_DIMENSIONS; ++j) {
                        for (int k = NEW_COUNTER; k < BOARD_DIMENSIONS; ++k) {
                            if (k == NEW_COUNTER) {
                                printf("(%d %d %d) ", i, j, k);
                                printf("(%d %d %d) ", i, j, k + 1);
                                printf("(%d %d %d) ", i, j, k + 2);
                                printf("(%d %d %d) ", i, j, k + 3);
                            }
                            printf("%c ", board[i][j][k]);
                            if (k == LAST_CHAR) {
                                printf("\n");
                            }
                        }
                        if (j == LAST_CHAR) {
                            printf("\n");
                        }
                    }
                }
                inputDump = getchar();
                while (inputDump != '\n') {
                    inputDump = getchar();
                }
                game = FALSE;
                printf("Would you like to continue? (y/n) \n");
                scanf(" %c", &restart);
                if (restart == 'y') {
                    setup = TRUE;
                    oWin = NEW_COUNTER;
                    break;
                } else if (restart == 'n') {
                    printf("YEET \n");
                    code = FALSE;
                }
                //TIE SITUATION
            } else if (tieCounter >= ALL_SLOTS) {
                printf("Tie. \n");
                for (int i = NEW_COUNTER; i < BOARD_DIMENSIONS; ++i) {
                    for (int j = NEW_COUNTER; j < BOARD_DIMENSIONS; ++j) {
                        for (int k = NEW_COUNTER;
                             k < BOARD_DIMENSIONS; ++k) {
                            if (k == NEW_COUNTER) {
                                printf("(%d %d %d) ", i, j, k);
                                printf("(%d %d %d) ", i, j, k + 1);
                                printf("(%d %d %d) ", i, j, k + 2);
                                printf("(%d %d %d) ", i, j, k + 3);
                            }
                            printf("%c ", board[i][j][k]);
                            if (k == LAST_CHAR) {
                                printf("\n");
                            }
                        }
                        if (j == LAST_CHAR) {
                            printf("\n");
                        }
                    }
                }
                game = FALSE;
                printf("Would you like to continue? (y/n) \n");
                scanf(" %c", &restart);
                if (restart == 'y') {
                    setup = TRUE;
                    xWin = NEW_COUNTER;
                    oWin = NEW_COUNTER;
                    break;
                } else if (restart == 'n') {
                    printf("YEET \n");
                    code = FALSE;
                    break;
                }
            } else {
                //GAME GOES ON
                tieCounter += NO_WINNER_ROUND;
            }
        }
    }
    return 0;
}