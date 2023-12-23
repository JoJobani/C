/******************************************
*Student name: Yehonatan Menashe
*Student ID:206478067
*Exercise name: ex_6
******************************************/
#include "BinTree.h"

int main() {
    //root creation
    BinTree *root = NULL;
    while (TRUE) {
        //printing the menu and waiting for input
        printf("please choose action:\n");
        printf("(1) A child was born\n");
        printf("(2) Throw into the Nile\n");
        printf("(3) Find Moshe\n");
        printf("(4) Print All\n");
        printf("(5) Size of jews\n");
        printf("(6) Exit\n");
        int menuChoice, result;
        //main menu input
        scanf(" %d", &menuChoice);
        switch (menuChoice) {
            case 1: {
                //new child was born task
                root = newChild(root);
                //aging task
                result = generic_int_function(root, aging);
                if (result == FREE_ISRAEL) {
                    generic_function(root, (void *) freeIsrael);
                    exit(CODE_SUCCESS);
                    //root removed edge case
                } else if (result == ROOT_REMOVED) {
                    root = NULL;
                }
                printf("\n");
                continue;
            }
            case 2: {
                printf("\n");
                //throw all males into river
                result = generic_int_function(root, throwIntoRiver);
                //root removed edge case
                if (result == ROOT_REMOVED) {
                    root = NULL;
                }
                if (root != NULL) {
                    //aging task
                    result = generic_int_function(root, aging);
                    if (result == FREE_ISRAEL) {
                        generic_function(root, (void *) freeIsrael);
                        exit(CODE_SUCCESS);
                        //root removed edge case
                    } else if (result == ROOT_REMOVED) {
                        root = NULL;
                    }
                }
                continue;
            }
            case 3: {
                //looking for Moshe task
                int order, moshe;
                printf("please choose order:\n");
                printf("(1) preorder\n");
                printf("(2) inorder\n");
                printf("(3) postorder\n");
                scanf(" %d", &order);
                switch (order) {
                    case 1: {
                        //searches for moshe preorder
                        generic_function(root, searchPreorder);
                        moshe = generic_int_function(root, findMoshe);
                        if (moshe == MOSHE_FOUND) {
                            //if moshe found
                            result = generic_int_function(root,
                                                          throwIntoRiver);
                            if (result == ROOT_REMOVED) {
                                root = NULL;
                            }
                        } else {
                            //if moshe doesn't exist
                            printf("Moshe Not Found!\n");
                        }
                        break;
                    }
                    case 2: {
                        //searches for moshe inorder
                        generic_function(root, searchInorder);
                        moshe = generic_int_function(root, findMoshe);
                        //if moshe found
                        if (moshe == MOSHE_FOUND) {
                            result = generic_int_function(root,
                                                          throwIntoRiver);
                            if (result == ROOT_REMOVED) {
                                root = NULL;
                            }
                        } else {
                            //if moshe doesn't exist
                            printf("Moshe Not Found!\n");
                        }
                        break;
                    }
                    case 3: {
                        //searches for moshe postorder
                        generic_function(root, searchPostorder);
                        moshe = generic_int_function(root, findMoshe);
                        //if moshe found
                        if (moshe == MOSHE_FOUND) {
                            result = generic_int_function(root,
                                                          throwIntoRiver);
                            if (result == ROOT_REMOVED) {
                                root = NULL;
                            }
                        } else {
                            //if moshe doesn't exist
                            printf("Moshe Not Found!\n");
                        }
                        break;
                    }
                    default: {
                        //error message in case of bad input
                        printf("wrong order!\n");
                    }
                }
                //aging task
                result = generic_int_function(root, aging);
                //check if Moshe is 80
                if (result == FREE_ISRAEL) {
                    generic_function(root, (void *) freeIsrael);
                    exit(CODE_SUCCESS);
                    //root removed edge case
                } else if (result == ROOT_REMOVED) {
                    root = NULL;
                }
            }
                printf("\n");
                break;
            case 4: {
                //print the order of print task
                int order;
                printf("please choose order:\n");
                printf("(1) preorder\n");
                printf("(2) inorder\n");
                printf("(3) postorder\n");
                scanf(" %d", &order);
                switch (order) {
                    case 1: {
                        //print a list of Jews Preorder
                        generic_function(root, printPreorder);
                    }
                        break;
                    case 2: {
                        //print a list of Jews Inorder
                        generic_function(root, printInorder);
                    }
                        break;
                    case 3: {
                        //print a list of Jews Postorder
                        generic_function(root, printPostorder);
                    }
                        break;
                    default: {
                        //error message in case of bad input
                        printf("wrong order!\n");
                    }
                }
                //aging task
                result = generic_int_function(root, aging);
                //check if Moshe is 80
                if (result == FREE_ISRAEL) {
                    generic_function(root, (void *) freeIsrael);
                    exit(CODE_SUCCESS);
                    //root removed edge case
                } else if (result == ROOT_REMOVED) {
                    root = NULL;
                }
                printf("\n");
                continue;
            }
            case 5: {
                //counting Jews menu
                int choice;
                printf("please choose what you want to calculate:\n");
                printf("(1) All jews\n");
                printf("(2) Male\n");
                printf("(3) Female\n");
                scanf(" %d", &choice);
                switch (choice) {
                    case 1: {
                        //prints amount of all Jews
                        result = generic_int_function(root, jewCount);
                        printf("size of all jews is: %d\n", result);
                        break;
                    }
                    case 2: {
                        //prints amount of male jews
                        result = generic_int_function(root, maleCount);
                        printf("size of all male jews is: %d\n", result);
                        break;
                    }
                    case 3: {
                        //prints amount of female jews
                        result = generic_int_function(root, femaleCount);
                        printf("size of all female jews is: %d\n", result);
                        break;
                    }
                    default: {
                        //error message in case of bad input
                        printf("wrong order!\n");
                    }
                }
                //aging task
                result = generic_int_function(root, aging);
                //check if Moshe is 80
                if (result == FREE_ISRAEL) {
                    generic_function(root, (void *) freeIsrael);
                    exit(CODE_SUCCESS);
                    //root removed edge case
                } else if (result == ROOT_REMOVED) {
                    root = NULL;
                }
                printf("\n");
                continue;
            }
            case 6: {
                //frees israel and ends the program
                generic_function(root, (void *) freeIsrael);
                exit(CODE_SUCCESS);
            }
                //in case a non valid input was entered into menu choice
            default: {
                printf("wrong choose please choose again\n");
                result = generic_int_function(root, aging);
                //check if Moshe is 80
                if (result == FREE_ISRAEL) {
                    generic_function(root, (void *) freeIsrael);
                    exit(CODE_SUCCESS);
                    //root removed edge case
                } else if (result == ROOT_REMOVED) {
                    root = NULL;
                }
                printf("\n");
                continue;
            }
        }
    }
}
