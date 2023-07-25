#include <stdio.h>
#include "userManagment.h"

int main() {
    setbuf(stdout, 0);
    User currentUser;
    currentUser.id = 999999;

    userLogIn(&currentUser);

    if (currentUser.id == 999999) {
        printf("\nExiting...");
        return 1;
    }

    if (currentUser.isAdmin == 1) {
        welcomeAdmin(&currentUser);
    } else {
        welcomeNotAdmin(&currentUser);
    }

    return 0;
}
