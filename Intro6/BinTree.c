/******************************************
*Student name: Yehonatan Menashe
*Student ID:206478067
*Exercise name: ex_6
******************************************/
#include "BinTree.h"

/************************************************************************
function name: generic int function
The Input: pointer to root and task to perform
The output: result int value depending on function
The Function operation: generic function with return value
*************************************************************************/
int generic_int_function(BinTree *root, int(*task)(void *)) {
    int result;
    result = task(root);
    return result;
}

/************************************************************************
function name: generic void function
The Input: pointer to root and task to perform
The output: depends on task
The Function operation: generic function without return value
*************************************************************************/
void generic_function(BinTree *root, void(*task)(void *)) {
    task(root);
}

/************************************************************************
function name: moshe's task
The Input: none - triggers on search for moshe if present
The output: moshe is silent
The Function operation: check to see if Moshe exists
*************************************************************************/
void moshe_task(void *val) {
    printf("%s quiet\n", (char *) val);
}

/************************************************************************
function name: normal child task
The Input: none - triggers on search for moshe
The output: the crying of a child
The Function operation: makes the child cry
*************************************************************************/
void child_task(void *val) {
    printf("%s cry waaaa\n", (char *) val);
}

/************************************************************************
function name: new child
The Input: pointer to root of tree / creating root
The output: none
The Function operation: creates a child with all needed info on child
*************************************************************************/
BinTree *newChild(BinTree *root) {
    int childId;
    char childName[MAX_NAME_INPUT], childGender;
    //memory allocation
    BinTree *newChild = (BinTree *) malloc(sizeof(BinTree));
    //memory allocation test
    if (newChild == NULL) {
        //memory error exits program
        emergencyExit(root);
        exit(FATAL_CODE_ERROR);
    }
    //child ID input for indexing
    printf("please enter child id:\n");
    scanf(" %d", &childId);
    newChild->id = childId;
    //child name input and memory allocation for array
    printf("please insert child name:\n");
    scanf(" %10s", childName);
    newChild->name = (char *) malloc(sizeof(char) * MAX_NAME_INPUT);
    if (newChild->name == NULL) {
        //memory error exits program
        emergencyExit(root);
        exit(FATAL_CODE_ERROR);
    }
    strcpy(newChild->name, childName);
    //child gender input
    printf("please insert child gender:\n");
    scanf(" %c", &childGender);
    newChild->gender = childGender;
    //declaring child's age for aging function
    newChild->age = NEW_CHILD_AGE;
    //declaring child action for their task
    newChild->action = newChild->name;
    //assigning task if child is Moshe or not
    if ((strcmp("Moshe", newChild->name) == STRCMP_TRUE) &&
        (newChild->gender == 'M')) {
        newChild->task = moshe_task;
    } else {
        newChild->task = child_task;
    }
    //tree leaves pointer initialization
    newChild->left = NULL;
    newChild->right = NULL;
    //tree indexing - new tree
    if (root == NULL) {
        return newChild;
    } else {
        //tree indexing - tree already exists
        BinTree *pointer = root;
        while (TRUE) {
            if (childId < pointer->id) {
                if (pointer->left == NULL) {
                    pointer->left = newChild;
                    break;
                }
                pointer = pointer->left;
            } else {
                if (pointer->right == NULL) {
                    pointer->right = newChild;
                    break;
                }
                pointer = pointer->right;
            }
        }
        //return root of tree for case of new tree
        return root;
    }
}

/************************************************************************
function name: searching for moshe - inorder
The Input: root of tree
The output: list of crying children
The Function operation: searches for moshe among children
*************************************************************************/
void searchInorder(void *root) {
    //in case no leaf is present - return
    BinTree *pointer = root;
    if (pointer == NULL) {
        return;
    }
    searchInorder(pointer->left);
    if ((strcmp("Moshe", pointer->name) == STRCMP_TRUE) &&
        (pointer->gender == 'M')) {
        moshe_task(pointer->action);
    } else {
        child_task(pointer->action);
    }
    searchInorder(pointer->right);
}

/************************************************************************
function name: searching for moshe - preorder
The Input: root of tree
The output: list of crying children
The Function operation: searches for moshe among children
*************************************************************************/
void searchPreorder(void *root) {
    //in case no leaf is present - return
    BinTree *pointer = root;
    if (pointer == NULL) {
        return;
    }
    if ((strcmp("Moshe", pointer->name) == STRCMP_TRUE) &&
        (pointer->gender == 'M')) {
        moshe_task(pointer->action);
    } else {
        child_task(pointer->action);
    }
    searchPreorder(pointer->left);
    searchPreorder(pointer->right);
}

/************************************************************************
function name: searching for moshe - postorder
The Input: root of tree
The output: list of crying children
The Function operation: searches for moshe among children
*************************************************************************/
void searchPostorder(void *root) {
    //in case no leaf is present - return
    BinTree *pointer = root;
    if (pointer == NULL) {
        return;
    }
    searchPostorder(pointer->left);
    searchPostorder(pointer->right);
    if ((strcmp("Moshe", pointer->name) == STRCMP_TRUE) &&
        (pointer->gender == 'M')) {
        moshe_task(pointer->action);
    } else {
        child_task(pointer->action);
    }
}

/************************************************************************
function name: searching for moshe - actual function
The Input: root of tree
The output: if found - kills all boys, else moshe wasn't found message
The Function operation: searches the tree to see if moshe exists
*************************************************************************/
int findMoshe(void *root) {
    //in case no leaf is present - return
    if (root == NULL) {
        return LIFE;
    }
    BinTree *pointer = root;
    int mosheFound;
    if ((strcmp(pointer->name, "Moshe") == STRCMP_TRUE) &&
        (pointer->gender == 'M')) {
        return MOSHE_FOUND;
    } else {
        if (pointer->left != NULL) {
            mosheFound = findMoshe(pointer->left);
            if (mosheFound == MOSHE_FOUND) {
                return MOSHE_FOUND;
            }
        }
        if (pointer->right != NULL) {
            mosheFound = findMoshe(pointer->right);
            if (mosheFound == MOSHE_FOUND) {
                return MOSHE_FOUND;
            }
        } else {
            return MOSHE_NOT_FOUND;
        }
    }
    return LIFE;
}

/************************************************************************
function name: aging function
The Input: root of tree
The output: none
The Function operation: ages everyone by 20 every iteration
*************************************************************************/
int aging(void *root) {
    BinTree *pointer = root;
    int rootRemove, died;
    //in case no leaf is present - return
    if (pointer == NULL) {
        return LIFE;
    }
    //goes over the tree to see if someone died of old age
    died = aging(pointer->left);
    if ((died == DEATH) || (died == ROOT_REMOVED)) {
        pointer->left = NULL;
    } else if (died == FREE_ISRAEL) {
        return FREE_ISRAEL;
    }
    died = aging(pointer->right);
    if ((died == DEATH) || (died == ROOT_REMOVED)) {
        pointer->right = NULL;
    } else if (died == FREE_ISRAEL) {
        return FREE_ISRAEL;
    }
    //actual age task
    pointer->age = (pointer->age) + AGE_INCREASE;
    //kill someone if they reach 120
    if (pointer->age >= MAX_AGE) {
        rootRemove = death(pointer);
        if (rootRemove == ROOT_REMOVED) {
            return ROOT_REMOVED;
        } else if (rootRemove == DEATH) {
            return DEATH;
        } else {
            return LIFE;
        }
    }
    //task to perform if Moshe is 80 and frees Israel
    if ((strcmp(pointer->name, "Moshe") == STRCMP_TRUE) &&
        (pointer->age >= MOSHE_MAX_AGE) &&
        (pointer->gender == 'M')) {
        printf("%s say: let my people go!", pointer->name);
        return FREE_ISRAEL;
    } else {
        return LIFE;
    }
}

/************************************************************************
function name: throw boys into river
The Input: root of tree
The output: none
The Function operation: removes all non-Moshe males from tree
*************************************************************************/
int throwIntoRiver(void *root) {
    BinTree *pointer = root;
    int rootRemove, died;
    //in case no leaf is present - return
    if (pointer == NULL) {
        return LIFE;
    }
    //goes over the tree in post-order
    died = throwIntoRiver(pointer->left);
    if ((died == DEATH) || (died == ROOT_REMOVED)) {
        pointer->left = NULL;
    }
    died = throwIntoRiver(pointer->right);
    if ((died == DEATH) || (died == ROOT_REMOVED)) {
        pointer->right = NULL;
    }
    //kill any child who is a male and not Moshe
    if ((pointer->gender == 'M') &&
        (strcmp(pointer->name, "Moshe") != STRCMP_TRUE)) {
        rootRemove = death(pointer);
        if (rootRemove == ROOT_REMOVED) {
            return ROOT_REMOVED;
        } else if (rootRemove == DEATH) {
            return DEATH;
        } else {
            return LIFE;
        }
    }
    return LIFE;
}

/************************************************************************
function name:death command
The Input: pointer of target to death
The output: none
The Function operation: fixes indexes after someone dies
*************************************************************************/
int death(void *root) {
    BinTree *tempSaver, *pointer = root, *fatherSaver;
    int leftCounter = NEW_COUNTER;
    free(pointer->name);
    pointer->name = NULL;
    //in case of no children - return
    if ((pointer->left == NULL) && (pointer->right == NULL)) {
        free(pointer);
        return ROOT_REMOVED;
    }
// in case of one child on right copy data and erase leaf
    if ((pointer->left == NULL) && (pointer->right != NULL)) {
        tempSaver = pointer->right;
        pointer->id = tempSaver->id;
        pointer->name = tempSaver->name;
        pointer->age = tempSaver->age;
        pointer->gender = tempSaver->gender;
        pointer->task = tempSaver->task;
        pointer->action = tempSaver->action;
        pointer->left = tempSaver->left;
        pointer->right = tempSaver->right;
        free(tempSaver);
        if (pointer->right != NULL) {
            if (pointer->right->id == pointer->id) {
                pointer->right = NULL;
            }
        }
        return LIFE;
    }
//in case of child on left copy data and erase leaf
    if ((pointer->left != NULL) && (pointer->right == NULL)) {
        tempSaver = pointer->left;
        pointer->id = tempSaver->id;
        pointer->name = tempSaver->name;
        pointer->age = tempSaver->age;
        pointer->gender = tempSaver->gender;
        pointer->task = tempSaver->task;
        pointer->action = tempSaver->action;
        pointer->left = tempSaver->left;
        pointer->right = tempSaver->right;
        free(tempSaver);
        if (pointer->left != NULL) {
            if (pointer->left->id == pointer->id) {
                pointer->left = NULL;
            }
        }
        return LIFE;
    }
//in case of two children copy data using algorithm and delete leaf
    if ((pointer->left != NULL) && (pointer->right != NULL)) {
        tempSaver = pointer->right;
        if (tempSaver->left == NULL) {
            pointer->id = tempSaver->id;
            pointer->name = tempSaver->name;
            pointer->age = tempSaver->age;
            pointer->gender = tempSaver->gender;
            pointer->task = tempSaver->task;
            pointer->action = tempSaver->action;
            pointer->right = tempSaver->right;
            free(tempSaver);
            return LIFE;
        }
        while (tempSaver->left != NULL) {
            fatherSaver = tempSaver;
            tempSaver = tempSaver->left;
            leftCounter++;
        }
        pointer->id = tempSaver->id;
        pointer->name = tempSaver->name;
        pointer->age = tempSaver->age;
        pointer->gender = tempSaver->gender;
        pointer->task = tempSaver->task;
        pointer->action = tempSaver->action;
        if (tempSaver->right != NULL) {
            fatherSaver->left = tempSaver->right;
            leftCounter = NEW_COUNTER;
        }
        free(tempSaver);
        if (leftCounter > NEW_COUNTER) {
            fatherSaver->left = NULL;
        }
        if (pointer->right != NULL) {
            if (pointer->right->id == pointer->id) {
                pointer->right = NULL;
            }
        }
        return LIFE;
    }
    return LIFE;
}

/************************************************************************
function name: free israel
The Input: root of tree
The output: none
The Function operation: frees all of israel and ends program
*************************************************************************/
void freeIsrael(BinTree *root) {
    //in case no leaf is present - return
    if (root == NULL) {
        return;
    }
    freeIsrael(root->left);
    freeIsrael(root->right);
    free(root->name);
    free(root);
}

/************************************************************************
function name: print israel - inorder
The Input: root of tree
The output: list of everyone inorder
The Function operation: prints a list of all people inorder
*************************************************************************/
void printInorder(void *root) {
    BinTree *pointer = root;
    //in case no leaf is present - return
    if (pointer == NULL) {
        return;
    }
    if (pointer->left != NULL) {
        printInorder(pointer->left);
    }
    printf("id: %d, name: %s, gender: %c, age: %d\n", pointer->id,
           pointer->name, pointer->gender, pointer->age);
    if (pointer->right != NULL) {
        printInorder(pointer->right);
    }
}

/************************************************************************
function name: print israel - preorder
The Input: root of tree
The output: list of everyone preorder
The Function operation: prints a list of all people preorder
*************************************************************************/
void printPreorder(void *root) {
    BinTree *pointer = root;
    //in case no leaf is present - return
    if (pointer == NULL) {
        return;
    }
    printf("id: %d, name: %s, gender: %c, age: %d\n", pointer->id,
           pointer->name, pointer->gender, pointer->age);
    if (pointer->left != NULL) {
        printPreorder(pointer->left);
    }
    if (pointer->right != NULL) {
        printPreorder(pointer->right);
    }
}

/************************************************************************
function name: print israel - postorder
The Input: root of tree
The output: list of crying children
The Function operation: searches for moshe among children
*************************************************************************/
void printPostorder(void *root) {
    BinTree *pointer = root;
    //in case no leaf is present - return
    if (pointer == NULL) {
        return;
    }
    if (pointer->left != NULL) {
        printPostorder(pointer->left);
    }
    if (pointer->right != NULL) {
        printPostorder(pointer->right);
    }
    printf("id: %d, name: %s, gender: %c, age: %d\n", pointer->id,
           pointer->name, pointer->gender, pointer->age);
}

/************************************************************************
function name: jew count
The Input: root of tree
The output: amount of jews
The Function operation: counts all jews
*************************************************************************/
int jewCount(void *root) {
    BinTree *pointer = root;
    //in case no leaf is present - return
    if (root == NULL) {
        return 0;
    }
    return 1 + jewCount(pointer->left) +
           jewCount(pointer->right);
}

/************************************************************************
function name: male jew count
The Input: root of tree
The output: amount of male jews
The Function operation: counts only male jews
*************************************************************************/
int maleCount(void *root) {
    BinTree *pointer = root;
    //in case no leaf is present - return
    if (root == NULL) {
        return 0;
    }
    if (pointer->gender == 'M') {
        return 1 + maleCount(pointer->left) +
               maleCount(pointer->right);
    } else {
        return 0 + maleCount(pointer->left) +
               maleCount(pointer->right);
    }
}

/************************************************************************
function name: female jew count
The Input: root of tree
The output: amount of female jews
The Function operation: counts only female jews
*************************************************************************/
int femaleCount(void *root) {
    BinTree *pointer = root;
    //in case no leaf is present - return
    if (root == NULL) {
        return 0;
    }
    if (pointer->gender == 'F') {
        return 1 + femaleCount(pointer->left) +
               femaleCount(pointer->right);
    } else {
        return 0 + femaleCount(pointer->left) +
               femaleCount(pointer->right);
    }
}

/************************************************************************
function name: emergency exit
The Input: root of tree
The output: none
The Function operation: frees all allocated memory in case of memory issue
*************************************************************************/
void emergencyExit(BinTree *root) {
    //in case no leaf is present - return
    if (root == NULL) {
        return;
    }
    emergencyExit(root->left);
    emergencyExit(root->right);
    free(root->name);
    free(root);
}