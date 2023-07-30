//
// Created by ricar on 7/24/2023.
//

#include "stdbool.h"

#ifndef PROYECTO_VACACIONAL_USERMANAGMENT_H
#define PROYECTO_VACACIONAL_USERMANAGMENT_H

/**
 * User data structure
 * @param id: id of the user
 * @param user: username
 * @param password: password of the user
 * @param isAdmin: state of privileges of the user
 * */
typedef struct user_t {
    int id;
    char user[20];
    char password[20];
    bool isAdmin;
}User;

/**
 * Creates the user file
 * */
void createUsersFile();

/**
 * Create a new user and save it in the users.dat file
 * */
void signUpUser();

/**
 * Log the user (check if the user and password are correct in users.dat file) if the credentials are correct
 * let the user enter in the system, else, does not do anything
 * */
void logInUser (User *currentUser);

/**
 * List all the users in users.dat file
 * */
void listUsers();

/**
 * Let the current user modify the credentials of other user
 * */
void modifyUser ();

/**
 * Let the current user delete another user
 * */
void deleteUser ();

#endif //PROYECTO_VACACIONAL_USERMANAGMENT_H
