#include <stdlib.h>
#include <string.h>
#include "stdio.h"
#include "utils.h"
#include "userManagment.h"

void createUsersFile() {
    User user;
    FILE *file;
    file = fopen("users.dat", "wb");
    if (file == NULL)
        exit(1);

    user.id = 1;
    strcpy(user.user, "root");
    strcpy(user.password, "root");
    user.isAdmin = 1;

    fwrite(&user, sizeof (User), 1, file);

    fclose(file);
    continueApp();
}

int lastUserId () {
    FILE *file;
    User user;
    int id;
    file = fopen("users.dat", "rb");

    if (file == NULL) exit(1);

    fread(&user, sizeof (user), 1, file);

    while (!feof(file)) {
        id = user.id;
        fread(&user, sizeof (user), 1, file);
    }

    return id;
}

void signUpUser() {
    FILE *file;
    file = fopen("users.dat", "ab");

    if (file == NULL)
        exit(1);

    User user;
    int isAdmin;

    user.id = lastUserId() + 1;

    fflush(stdin);
    printf("Give me the user: ");
    gets(user.user);
    printf("Give me the password: ");
    gets(user.password);
    printf("Is the user an admin?\n 1. Yes\n0. No\nEnter your answer: ");
    scanf("%d", &isAdmin);
    if (isAdmin) {
        user.isAdmin = 1;
    } else {
        user.isAdmin = 0;
    }

    fwrite(&user, sizeof(user), 1, file);
    fclose(file);
}


void logInUser (User *currentUser) {
    FILE *file;
    file = fopen("users.dat", "rb");
    User user;

    if (file == NULL) {
        printf("Users file not found...\n");
        printf("The default user now will be \"root\" with password \"root\"\n");
        printf("Exiting...");
        createUsersFile();
        exit(1);
    }

    char sUser[20];
    char sPassword[20];

    fflush(stdin);
    printf("Give me your user: ");
    gets(sUser);
    printf("Give me your password: ");
    gets(sPassword);

    fread(&user, sizeof (user), 1, file);

    while (!feof(file)) {
        if ((strcmp(user.user, sUser) == 0) && (strcmp(user.password, sPassword) == 0)) {
            currentUser->id = user.id;
            strcpy(currentUser->user, user.user);
            strcpy(currentUser->password, user.password);
            currentUser->isAdmin = user.isAdmin;
            printf("Welcome %s ", currentUser->user);
            return;
        }
        fread(&user, sizeof (user), 1, file);
    }

    printf("User or password may incorrect.\n");
    printf("Exiting...");
    exit(1);
}


void listUsers() {
    FILE *file;
    file = fopen("users.dat", "rb");
    if (file == NULL)
        exit(1);

    User user;

    fread(&user, sizeof(user), 1, file);

    while (!feof(file)) {
        if (user.id != 0) {
            printf("%i, %s, %s, %i\n", user.id, user.user, user.password, user.isAdmin);
        }
        fread(&user, sizeof(user), 1, file);
    }
    fclose(file);
    continueApp();
}

void modifyUser () {
    FILE *file;
    file = fopen("users.dat", "r+b");
    User user;

    if (file == NULL)
        exit(1);

    int id;
    printf("Ingrese el id del usuario a modificar: ");
    scanf("%i", &id);

    int userInFile = 0;

    fread(&user, sizeof (User), 1, file);

    while (!feof(file)) {
        if (id == user.id) {
            char newUser[20];
            char newPass[20];
            printf("%i, %s, %s, %i\n", user.id, user.user, user.password, user.isAdmin);
            fflush(stdin);
            printf("Give me the new user: ");
            gets(user.user);
            printf("Give me the new password: ");
            gets(user.password);

            int pos = ftell(file) - sizeof (User);
            fseek(file, pos, SEEK_SET);
            fwrite(&user, sizeof (User), 1, file);
            printf("The user was modified\n");
            userInFile = 1;
            break;
        }
        fread(&user, sizeof (User), 1, file);
    }

    if (!userInFile) {
        printf("User not in file...");
    }

    fclose(file);
}

void deleteUser () {
    FILE *file;
    file = fopen("users.dat", "r+b");
    User user;

    if (file == NULL)
        exit(1);

    int id;
    printf("Insert the id of the user to delete: ");
    scanf("%i", &id);

    printf("Are you sure? this action can't be undone...\n 1. Yes\n 2. No");
    int opt;
    scanf("%d", &opt);
    if (opt != 1)
        return;


    int userInFile = 0;

    fread(&user, sizeof (User), 1, file);

    while (!feof(file)) {
        if (id == user.id) {
            char newUser[20];
            char newPass[20];
            printf("%i, %s, %s, %i\n", user.id, user.user, user.password, user.isAdmin);

            user.id = 0;
            strcpy(user.user, "\0");
            strcpy(user.password, "\0");
            user.isAdmin = 0;

            int pos = ftell(file) - sizeof (User);
            fseek(file, pos, SEEK_SET);
            fwrite(&user, sizeof (User), 1, file);
            printf("The user was deleted\n");
            userInFile = 1;
            break;
        }
        fread(&user, sizeof (User), 1, file);
    }

    if (!userInFile) {
        printf("User not in file...");
    }

    fclose(file);
}
