/******************************************
*Student name: Yehonatan Menashe
*Student ID:206478067
*Exercise name: ex_6
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct BinTree BinTree;
BinTree *newChild(BinTree *root);
void generic_function(BinTree *root, void(*task)(void *));
int generic_int_function(BinTree *root, int(*task)(void *));
void child_task(void* val);
void moshe_task(void* val);
int throwIntoRiver(void *root);
int aging (void *root);
void searchInorder (void *root);
void searchPreorder (void *root);
void searchPostorder (void *root);
int findMoshe (void *root);
int death (void *root);
void freeIsrael(BinTree *root);
void printInorder (void *root);
void printPreorder (void *root);
void printPostorder (void *root);
int jewCount (void *root);
int maleCount (void *root);
int femaleCount (void *root);
void emergencyExit(BinTree *root);

#define NEW_CHILD_AGE (-20)
#define MAX_NAME_INPUT 11
#define STRCMP_TRUE 0
#define LIFE 0
#define ROOT_REMOVED 2
#define MAX_AGE 120
#define MOSHE_MAX_AGE 80
#define DEATH 1
#define MOSHE_FOUND 1
#define MOSHE_NOT_FOUND 0
#define FREE_ISRAEL 3
#define CODE_SUCCESS 0
#define FATAL_CODE_ERROR 1
#define NEW_COUNTER 0
#define TRUE 1
#define AGE_INCREASE 20

typedef struct BinTree {
    int id;
    char *name;
    int age;
    char gender;
    void (*task)(void *val);
    void *action;
    struct BinTree *left;
    struct BinTree *right;
} BinTree;
