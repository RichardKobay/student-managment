#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "userManagment.h"
#include "studentManagment.h"
#include "utils.h"

void welcomeAdmin(User *currentUser) {
    int opt = 0;
    welcomeAdminScreen:
    printf("What are we doing now?\n");
    printf("\n1. Add user");
    printf("\n2. Edit user");
    printf("\n3. Delete user");
    printf("\n4. Show users list");
    printf("\n5. Create a new student");
    printf("\n6. Show student list");
    printf("\n7. Search for a student");
    printf("\n8. Show students by average grade");
    printf("\n9. Delete an student");
    printf("\n10. Show statistics");
    printf("\n11. Update student info");
    printf("\n12. Generate an inform");
    printf("\n13. Log out and exit");
    printf("\nPlease select an option: ");
    scanf("%d", &opt);

    if (opt >= 1 && opt <= 15) {
        if (opt == 1)
            signUpUser();
        if (opt == 2)
            modifyUser();
        if (opt == 3)
            deleteUser();
        if (opt == 4)
            listUsers();
        if (opt == 5)
            addStudent();
        if (opt == 6)
            showAllStudents();
        if (opt == 7)
            searchStudent();
        if (opt == 8)
            showAllStudentsByAverageGrade();
        if (opt == 9)
            removeStudent();
        if (opt == 10)
            showStatisticsOfStudent();
        if (opt == 11)
            updateStudentInfo();
        if (opt == 12)
            generateInform();
        if (opt == 15) {
            printf("Bye!\n");
            exit(0);
        }
        continueApp();
    } else {
        printf("Option not in menu\n");
    }

    goto welcomeAdminScreen;
}

void welcomeNotAdmin(User *currentUser) {
    FILE *studentsFile;
    studentsFile = fopen("students.dat", "wb");

    if (studentsFile == NULL) {
        createUsersFile();
    }
    fclose(studentsFile);

    int opt = 0;
    welcomeNotAdminScreen:

    printf("What are we doing now?\n");
    printf("\n1. Show users list");
    printf("\n2. Show student list");
    printf("\n3. Search for a student");
    printf("\n4. Show students by average grade");
    printf("\n5. Show statistics");
    printf("\n6. Generate an inform");
    printf("\n7. Log out and exit");
    printf("\nPlease select an option: ");
    scanf("%d", &opt);

    if (opt >= 1 && opt <= 15) {
        if (opt == 1)
            listUsers();
        if (opt == 2)
            showAllStudents();
        if (opt == 3)
            searchStudent();
        if (opt == 4)
            showAllStudentsByAverageGrade();
        if (opt == 5)
            showStatisticsOfStudent();
        if (opt == 6)
            generateInform();
        if (opt == 7) {
            printf("Bye!\n");
            return;
        }
        continueApp();
    } else {
        printf("Option not in menu\n");
    }

    goto welcomeNotAdminScreen;
}