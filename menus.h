//
// Created by ricar on 7/25/2023.
//

#ifndef PROYECTO_VACACIONAL_MENUS_H
#define PROYECTO_VACACIONAL_MENUS_H

#include "userManagment.h"

/**
 * Show a menu for the available options for an admin user
 * */
void welcomeAdmin(User *currentUser);

/**
 * Show a menu for the available options for a non admin user
 * */
void welcomeNotAdmin(User *currentUser);

#endif //PROYECTO_VACACIONAL_MENUS_H
