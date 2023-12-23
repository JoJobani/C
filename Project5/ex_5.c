/******************************************
*Student name: Yehonatan Menashe
*Student ID:206478067
*Exercise name: ex_5
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHONEBOOK_SIZE 26
#define MAX_INPUT 11
#define PHONEBOOK_SPOT 65

typedef struct Contact {
    char *firstName;
    char *lastName;
    char *phoneNum;
    struct Contact *next;
} Contact;

/************************************************************************
* function name: Main menu
* The Input: none
* The output: none
* The Function operation: Prints the main menu
*************************************************************************/
void printMenu() {
    printf("Welcome to the phone book manager! \n");
    printf("Choose an option: \n");
    printf("1. Add a new contact to the phone book. \n");
    printf("2. Delete a contact from the phone book. \n");
    printf("3. Find a contact in the phone book by phone number. \n");
    printf("4. Find a contact in the phone book by name. \n");
    printf("5. Update phone number for a contact. \n");
    printf("6. Print phone book. \n");
    printf("7. Exit. \n");
}

/************************************************************************
* function name: addContact
* The Input: the address of the phonebook array
* The output: none
* The Function operation: adds a person to the phonebook
*************************************************************************/
void addContact(Contact *phonebook[PHONEBOOK_SIZE]) {
    char firstTemp[MAX_INPUT], lastTemp[MAX_INPUT], phone_Temp[MAX_INPUT];
    printf("Enter a contact details (<first name> <last name> <phone number>): ");
    scanf(" %10s %10s %10s", firstTemp, lastTemp, phone_Temp);
    //creating index for contact ordering
    int index = lastTemp[0] - PHONEBOOK_SPOT;
    //memory allocation and contact information
    Contact *current = (Contact *) malloc(sizeof(Contact));
    current->firstName = (char *) malloc(sizeof(char) * MAX_INPUT);
    strcpy(current->firstName, firstTemp);
    current->lastName = (char *) malloc(sizeof(char) * MAX_INPUT);
    strcpy(current->lastName, lastTemp);
    current->phoneNum = (char *) malloc(sizeof(char) * MAX_INPUT);
    strcpy(current->phoneNum, phone_Temp);
    //memory allocation error
    if (current == NULL) {
        printf("The addition of the contact has failed! \n");
        return;
    }
    //name already exists check
    Contact *tester = phonebook[index];
    while (tester != NULL) {
        int firstTest = strcmp((char *) tester->firstName,
                               (char *) current->firstName);
        int secondTest = strcmp((char *) tester->lastName,
                                (char *) current->lastName);
        int result = firstTest + secondTest;
        if (result == 0) {
            printf("The addition of the contact has failed, since the ");
            printf("contact %s %s already exists! \n", firstTemp, lastTemp);
            //freeing allocated memory in case of it not being needed
            free(current->firstName);
            free(current->lastName);
            free(current->phoneNum);
            free(current);
            return;
        } else {
            tester = tester->next;
        }
    }
    //phone num already exists check
    for (int i = 0; i < PHONEBOOK_SIZE; ++i) {
        tester = phonebook[i];
        while (tester != NULL) {
            int phoneTest = strcmp((char *) tester->phoneNum,
                                   (char *) current->phoneNum);
            if (phoneTest == 0) {
                printf("The addition of the contact has failed, since the ");
                printf("phone number %s already exists! \n", phone_Temp);
                //freeing allocated memory in case of it not being needed
                free(current->firstName);
                free(current->lastName);
                free(current->phoneNum);
                free(current);
                return;
            } else {
                tester = tester->next;
            }
        }
    }
    //phonebook indexing
    if (phonebook[index] == NULL) {
        phonebook[index] = current;
        phonebook[index]->next = NULL;
    } else {
        Contact *saver = phonebook[index];
        phonebook[index] = current;
        phonebook[index]->next = saver;
    }
    printf("The contact has been added successfully! \n");
}

/************************************************************************
* function name: deleteContact
* The Input: the address of the phonebook array
* The output: none
* The Function operation: adds a person to the phonebook
*************************************************************************/
void deleteContact(Contact *phonebook[PHONEBOOK_SIZE]) {
    char firstTemp[MAX_INPUT], lastTemp[MAX_INPUT], confirmation;
    printf("Enter a contact name (<first name> <last name>): ");
    scanf(" %10s %10s", firstTemp, lastTemp);
    int index = lastTemp[0] - PHONEBOOK_SPOT;
    Contact *tester = phonebook[index];
    Contact *previous = NULL;
    while (tester != NULL) {
        //looking up the contact in the particular index
        int firstTest = strcmp((char *) tester->firstName, firstTemp);
        int secondTest = strcmp((char *) tester->lastName, lastTemp);
        if ((firstTest == 0) && (secondTest == 0)) {
            printf("Are you sure? (y/n) ");
            scanf(" %c", &confirmation);
            if (((confirmation == 'y') || (confirmation == 'Y')) &&
                previous != NULL) {
                //contact deletion and memory freeing - there are other contacts
                //in the index slot
                previous->next = tester->next;
                free(tester->firstName);
                free(tester->lastName);
                free(tester->phoneNum);
                free(tester);
                printf("The contact has been deleted successfully! \n");
                return;
            } else if (((confirmation == 'y') || (confirmation == 'Y')) &&
                       previous == NULL) {
                //contact deletion and memory freeing - there is no one else in
                //the index slot
                phonebook[index] = tester->next;
                free(tester->firstName);
                free(tester->lastName);
                free(tester->phoneNum);
                free(tester);
                printf("The contact has been deleted successfully! \n");
                return;
            } else {
                printf("The deletion of the contact has been canceled. \n");
                return;
            }
        }
        previous = tester;
        tester = tester->next;
    }
    printf("The deletion of the contact has failed! \n");
}

/************************************************************************
* function name: contactPhoneFinder
* The Input: the address of the phonebook array
* The output: none
* The Function operation: searches for a certain contact by phone number
*************************************************************************/

void contactPhoneFinder(Contact *phonebook[PHONEBOOK_SIZE]) {
    char phone_Temp[MAX_INPUT];
    printf("Enter a phone number: ");
    scanf(" %10s", phone_Temp);
    for (int i = 0; i < PHONEBOOK_SIZE; ++i) {
        Contact *tester = phonebook[i];
        while (tester != NULL) {
            //string comparisons to find a phone number across all indexes
            int phoneTest = strcmp((char *) tester->phoneNum, phone_Temp);
            if (phoneTest == 0) {
                printf("The following contact was found: %s %s %s \n ",
                       tester->firstName, tester->lastName, tester->phoneNum);
                return;
            } else {
                tester = tester->next;
            }
        }
    }
    printf("No contact with a phone number %s was found in the phone book \n",
           phone_Temp);
}

/************************************************************************
* function name: contactNameFinder
* The Input: the address of the phonebook array
* The output: none
* The Function operation: searches for a certain contact by name
*************************************************************************/
void contactNameFinder(Contact *phonebook[PHONEBOOK_SIZE]) {
    char firstTemp[MAX_INPUT], lastTemp[MAX_INPUT];
    printf("Enter a contact name (<first name> <last name>): ");
    scanf(" %10s %10s", firstTemp, lastTemp);
    int index = lastTemp[0] - PHONEBOOK_SPOT;
    Contact *tester = phonebook[index];
    while (tester != NULL) {
        //string comparison to find contact in a particular index
        int firstTest = strcmp((char *) tester->firstName, firstTemp);
        int secondTest = strcmp((char *) tester->lastName, lastTemp);
        int result = firstTest + secondTest;
        if (result == 0) {
            printf("The following contact was found: %s %s %s \n",
                   tester->firstName, tester->lastName,
                   tester->phoneNum);
            return;
        }
    }
    printf("No contact with a name %s %s was found in the phone book \n",
           firstTemp, lastTemp);
}

/************************************************************************
* function name: contactUpdate
* The Input: the address of the phonebook array
* The output: none
* The Function operation: replaces the number of a certain contact
*************************************************************************/
void contactUpdate(Contact *phonebook[PHONEBOOK_SIZE]) {
    char firstTemp[MAX_INPUT], lastTemp[MAX_INPUT], phone_Temp[MAX_INPUT];
    printf("Enter a contact name (<first name> <last name>): ");
    scanf(" %s %s", firstTemp, lastTemp);
    int index = lastTemp[0] - PHONEBOOK_SPOT;
    Contact *tester = phonebook[index];
    while (tester != NULL) {
        //looking up the contact by name by comparing strings
        int firstTest = strcmp((char *) tester->firstName, firstTemp);
        int secondTest = strcmp((char *) tester->lastName, lastTemp);
        if ((firstTest == 0) && (secondTest == 0)) {
            printf("The following contact was found: %s %s %s \n",
                   tester->firstName, tester->lastName, tester->phoneNum);
            printf("Enter the new phone number: ");
            scanf(" %10s", phone_Temp);
            //looking to find if the new phone already exists in the phonebook
            for (int i = 0; i < PHONEBOOK_SIZE; ++i) {
                Contact *localTester = phonebook[i];
                while (localTester != NULL) {
                    int phoneTest = strcmp((char *) localTester->phoneNum,
                                           phone_Temp);
                    if (phoneTest == 0) {
                        printf("The update of the contact has failed, since");
                        printf(" the phone number %s already exists! \n",
                               localTester->phoneNum);
                        return;
                    } else {
                        localTester = localTester->next;
                    }
                }
            }
            //updating the memory slot to contain the new number
            strcpy(tester->phoneNum, phone_Temp);
            printf("The contact has been updated successfully! \n");
            return;
        } else {
            tester = tester->next;
        }
    }
    printf("No contact with a name %s %s was found in the phone book \n",
           firstTemp, lastTemp);
}

int main() {
    //Initialization
    Contact *phonebook[PHONEBOOK_SIZE];
    for (int i = 0; i < PHONEBOOK_SIZE; ++i) {
        phonebook[i] = NULL;
    }
    //Main menu
    while (1) {
        int menu;
        printMenu();
        scanf("%d", &menu);
        while ((menu < 1) || (menu > 7)) {
            printf("Wrong option, try again: \n");
            scanf("%d", &menu);
        }
        switch (menu) {
            case 1: {
                addContact(phonebook);
                continue;
            }
            case 2: {
                deleteContact(phonebook);
                continue;
            }
            case 3: {
                contactPhoneFinder(phonebook);
                continue;
            }
            case 4: {
                contactNameFinder(phonebook);
                continue;
            }
            case 5: {
                contactUpdate(phonebook);
                continue;
            }
            case 6: {
                //printing the entire phonebook
                for (int i = 0; i < PHONEBOOK_SIZE; ++i) {
                    Contact *slot = phonebook[i];
                    while ((Contact *) slot != NULL) {
                        printf("%-11s ", slot->firstName);
                        printf("%-11s ", slot->lastName);
                        printf("%-11s \n", slot->phoneNum);
                        slot = slot->next;
                    }
                }
                continue;
            }
            case 7: {
                //deleting the entire phonebook before ending program
                Contact *previous = NULL;
                for (int i = 0; i < PHONEBOOK_SIZE; ++i) {
                    while ((Contact *) phonebook[i] != NULL) {
                        previous = phonebook[i];
                        free((Contact *) phonebook[i]->phoneNum);
                        free((Contact *) phonebook[i]->lastName);
                        free((Contact *) phonebook[i]->firstName);
                        phonebook[i] = (Contact *) phonebook[i]->next;
                        free(previous);
                    }
                    free(phonebook[i]);
                }
                printf("Bye!");
                exit(0);
            }
            default: {
                printf("Wrong option, try again: \n");
                continue;
            }
        }
    }
}
