#include <stdio.h>
#include "userManagment.h"
#include "studentManagment.h"
#include "menus.h"

int main() {

    FILE *studentsFile;
    studentsFile = fopen("students.dat", "rb");

    if (studentsFile == NULL) {
        createStudentsFile();
    }

    fclose(studentsFile);

    setbuf(stdout, 0);
    User currentUser;
    currentUser.id = 999999;

    logInUser(&currentUser);


    if (currentUser.id == 999999) {
        printf("\nExiting...");
        return 1;
    }

    if (currentUser.id == 1)
        welcomeAdmin(&currentUser);
    else
        welcomeNotAdmin(&currentUser);

    return 0;
}
