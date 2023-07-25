//
// Created by ricar on 7/24/2023.
//

#include "stdbool.h"

#ifndef PROYECTO_VACACIONAL_USERMANAGMENT_H
#define PROYECTO_VACACIONAL_USERMANAGMENT_H

typedef struct user_t {
    int id;
    char user[20];
    char password[20];
    bool isAdmin;
}User;

/**
 * Check if the user can access to the program.\n
 * - If the user exists in the .csv file, it will save the data in the current user\n
 * - If the user doesn't exists in the .csv file will print it and return
 * @param currentUser: Struct to the curren user data
 * @param users: file of the users
 * */
void userLogIn(User *currentUser);

/**
 * Welcome screen for admin user
 * */
void welcomeAdmin(User *currentUser);


/**
 * Welocme screen for not admin users
 * */
void welcomeNotAdmin(User *currentUser);

void signUpUser ();

void editUser ();

int lookForLastUserInFile ();


#endif //PROYECTO_VACACIONAL_USERMANAGMENT_H
