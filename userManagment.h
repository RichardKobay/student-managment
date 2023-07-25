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

void createUsersFile();
void signUpUser();
void logInUser (User *currentUser);
void listUsers();
void modifyUser ();
void welcomeAdmin(User *currentUser);
void welcomeNotAdmin(User *currentUser);

#endif //PROYECTO_VACACIONAL_USERMANAGMENT_H
