#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userManagment.h"

/** The max length in the users.csv file row*/
#define MAX_USER_ROW 45
/** Delimiter for data*/
#define DELIMITER ","

void userLogIn(User *currentUser) {
    FILE *users = fopen("users.csv", "r");
    if (users == NULL) {
        FILE *fp;
        FILE *tempFp;
        printf("Failed to open users the file. Please reopen the app\n");
        printf("The default user now will be \"root\" with password \"root\"\n");
        fp = fopen("users.csv", "w+");
        tempFp = fopen("temp.csv", "w+");
        fprintf(fp, "%d,%s,%s,%d", 1, "root", "root", 1);
        return;
    }

    /**User entered by user*/
    char user[20];
    /**Password entered by user*/
    char password[20];
    printf("Gimme your username: ");
    scanf("%s", user);
    printf("Gimme your password: ");
    scanf("%s", password);

    /**Row of the .csv file*/
    char line[MAX_USER_ROW];
    /** Scroll through the users.csv file row per row **/
    while (fgets(line, sizeof(line), users)) {
        /**A substring of line (splits the line each ",")*/
        char *token = strtok(line, DELIMITER);
        /**Number of the actual column that is been reading*/
        int column = 0;
        /** Saves temporally the user in the row*/
        char userTemp[20];
        /** Saves temporally the password in the row*/
        char passwordTemp[20];
        /** Saves temporally the user id in the row*/
        int tempId;
        /** Saves temporally the user status (admin or not) in the row*/
        int tempIsAdmin;

        /**
         * Scroll through each substring of the row and depending the number of column saves the
         * user info in it's corresponding temporally variable
         * */
        while (token) {
            if (column == 0)
                tempId = atoi(token);

            if (column == 1)
                strcpy(userTemp, token);

            if (column == 2)
                strcpy(passwordTemp, token);

            if (column == 3)
                tempIsAdmin = atoi(token);

            token = strtok(NULL, ",");
            column++;
        }

        /**
         * Compares the user and password inserted by the user and the user and password of the row in the
         * .csv file, if it's found, will save the data into currentUser and if it's not found
         * It will advice and return
         * */
        if ((strcmp(user, userTemp) == 0) && (strcmp(password, passwordTemp) == 0)) {
            printf("Successfully logged in as: %s\n", user);
            currentUser->id = tempId;
            strcpy(currentUser->user, user);
            strcpy(currentUser->password, password);
            currentUser->isAdmin = tempIsAdmin;
            return;
        }
    }
    printf("User not found or password may be incorrect\n");
    fclose(users);
}

void welcomeAdmin(User *currentUser) {
    printf("Welcome %s\n", currentUser->user);
    int opt = 0;
    welcomeAdminScreen:
    printf("What are we doing now?\n");
    printf("\n1. Add user");
    printf("\n2. Edit user");
    printf("\n3. Delete user");
    printf("\n4. Show users list");
    printf("\n5. Create a new student");
    printf("\n6. Show student list");
    printf("\n7. Calculate average grade of a student");
    printf("\n8. Search for a student");
    printf("\n9. Show students by average grade");
    printf("\n10. Delete an student");
    printf("\n11. Show statistics");
    printf("\n12. Update student info");
    printf("\n13. Generate an inform");
    printf("\n14. Courses settings");
    printf("\n15. Log out and exit");
    scanf("%d", &opt);

    if (opt >= 1 && opt <= 15) {
        if (opt == 1)
            signUpUser();
        if (opt == 2)
            editUser();
        if (opt == 15) {
            printf("Bye!\n");
            return;
        }
    } else {
        printf("Option not in menu\n");
    }

    goto welcomeAdminScreen;
}

void welcomeNotAdmin(User *currentUser) {
    printf("Welcome %s\n", currentUser->user);
    int opt = 0;
    welcomeNotAdminScreen:

    printf("What are we doing now?\n");
    printf("\n1. Show users list");
    printf("\n2. Show student list");
    printf("\n3. Calculate average grade of a student");
    printf("\n4. Search for a student");
    printf("\n5. Show students by average grade");
    printf("\n6. Show statistics");
    printf("\n7. Generate an inform");
    printf("\n8. Log out and exit");
    scanf("%d", &opt);

    if (opt >= 1 && opt <= 15) {
        if (opt == 1) {
            printf("Option 1");
        }
        if (opt == 8) {
            printf("Bye!\n");
            return;
        }
    } else {
        printf("Option not in menu\n");
    }

    goto welcomeNotAdminScreen;
}

int lookForLastUserInFile () {
    FILE *users;
    users = fopen("users.csv", "r");

    char line[MAX_USER_ROW];
    int tempId = 0;
    while (fgets(line, sizeof(line), users)) {
        char *token = strtok(line, DELIMITER);
        int column = 0;
        while (token) {
            if (column == 0)
                tempId = atoi(token);

            token = strtok(NULL, ",");
            column++;
        }
    }
    return tempId;
}

void signUpUser () {
    FILE *usersFile;
    usersFile = fopen("users.csv", "a");

    char userRow[45];
    int userId = lookForLastUserInFile() + 1;
    char user[20];
    char password[20];
    int isAdmin;

    printf("Giveme the user: ");
    scanf("%s", user);
    printf("Giveme the password: ");
    scanf("%s", password);
    printf("Is the new user an admin? \n1.yes\n2.no\nEnter yur answer: ");
    scanf("%d", &isAdmin);

    if (isAdmin != 1)
        isAdmin = 0;

    sprintf(userRow, "%d,%s,%s,%d", userId, user, password, isAdmin);

    fprintf(usersFile, "\n%s", userRow);
    fclose(usersFile);
}

void editUser () {
    FILE *users;
    users = fopen("users.csv", "r+");

    char userId[4];
    printf("Giveme the id of the user: ");
    scanf("%s", userId);

    char line[MAX_USER_ROW];
    while (fgets(line, sizeof(line), users)) {
        char *token = strtok(line, DELIMITER);
        int column = 0;
        while (token) {
            if (column == 0)
                if(strcmp(token,userId) == 0) {
                    fputs("users", users);
                }
            token = strtok(NULL, ",");
            column++;
        }
    }
}
