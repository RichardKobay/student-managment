//
// Created by ricar on 7/25/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentManagment.h"

void createStudentsFile() {
    Student student;
    FILE *file;
    file = fopen("students.dat", "wb");

    student.id = 0;
    strcpy(student.name, "\0");
    strcpy(student.matricula, "\0");
    student.age = 0;
    student.calculo = 0.0;
    student.programacion = 0.0;
    student.mantenimiento = 0.0;
    student.redes = 0.0;
    student.probabilidad = 0.0;
    student.valores = 0.0;
    student.averageGrade = 0.0;

    if (file == NULL)
        exit(1);

    fwrite(&student, sizeof(Student), 1, file);
    printf("\n\nThe students file was created successfully\n\n");
    fclose(file);
}

int lastStudentId() {
    FILE *file;
    Student student;
    int id = 0;
    file = fopen("students.dat", "rb");

    if (file == NULL) exit(1);

    fread(&student, sizeof(Student), 1, file);

    while (!feof(file)) {
        if (student.id != 0)
            id = student.id;
        fread(&student, sizeof(Student), 1, file);
    }

    return id;
}

float calcAverageGradeOfStudent(Student *student) {
    return (student->calculo + student->mantenimiento + student->probabilidad + student->programacion + student->redes +
            student->valores) / 6;
}

void addStudent() {
    Student newStudent;
    FILE *studentsFile;
    studentsFile = fopen("students.dat", "ab");

    newStudent.id = lastStudentId() + 1;

    GetData:
    fflush(stdin);
    printf("Give me the full name of the student: ");
    gets(newStudent.name);
    printf("Give me the tuition name of the student: ");
    gets(newStudent.matricula);
    printf("Give me the age of the student: ");
    scanf("%d", &newStudent.age);
    printf("Give me the grade of calculo of the student: ");
    scanf("%lf", &newStudent.calculo);
    printf("Give me the grade of programacion of the student: ");
    scanf("%lf", &newStudent.programacion);
    printf("Give me the grade of mantenimiento of the student: ");
    scanf("%lf", &newStudent.mantenimiento);
    printf("Give me the grade of redes of the student: ");
    scanf("%lf", &newStudent.redes);
    printf("Give me the grade of probabilidad of the student: ");
    scanf("%lf", &newStudent.probabilidad);
    printf("Give me the grade of valores of the student: ");
    scanf("%lf", &newStudent.valores);

    newStudent.averageGrade = calcAverageGradeOfStudent(&newStudent);
    printf("\nThe data of the student is: \n");
    printf("\nFull name: %s", newStudent.name);
    printf("\ntuition: %s", newStudent.matricula);
    printf("\nage: %d", newStudent.age);
    printf("\ngrade of calculo %lf", newStudent.calculo);
    printf("\nprogramacion: %lf", newStudent.programacion);
    printf("\nmantenimiento: %lf", newStudent.mantenimiento);
    printf("\nredes: %lf", newStudent.redes);
    printf("\nprobabilidad: %lf", newStudent.probabilidad);
    printf("\nvalores: %lf", newStudent.valores);
    printf("\nAverage grade: %lf", newStudent.averageGrade);
    printf("\nIs that correct?\n1.Yes\n2.No");
    int opc = 1;
    scanf("%d", &opc);
    if (opc != 1)
        goto GetData;


    if (studentsFile == NULL)
        exit(1);

    fwrite(&newStudent, sizeof(Student), 1, studentsFile);
    printf("Student added successfully");
    fclose(studentsFile);
}

void showAllStudents() {
    Student student;
    FILE *studentsFile;
    studentsFile = fopen("students.dat", "rb");

    if (studentsFile == NULL) exit(1);

    fread(&student, sizeof(Student), 1, studentsFile);

    while (!feof(studentsFile)) {
        if (student.id != 0) {
            printf("------------------------------------------------------------\n");
            printf("|id              %-42d|\n", student.id);
            printf("|matricula       %-42s|\n", student.matricula);
            printf("|name            %-42s|\n", student.name);
            printf("|age             %-42d|\n", student.age);
            printf("|calculo         %-42.1lf|\n", student.calculo);
            printf("|programacion    %-42.1lf|\n", student.programacion);
            printf("|mantenimiento   %-42.1lf|\n", student.mantenimiento);
            printf("|redes           %-42.1lf|\n", student.redes);
            printf("|probabilidad    %-42.1lf|\n", student.probabilidad);
            printf("|valores         %-42.1lf|\n", student.valores);
            printf("|averageGrade    %-42.1lf|\n", student.averageGrade);
            printf("------------------------------------------------------------\n");
        }
        fread(&student, sizeof(Student), 1, studentsFile);
    }
    fclose(studentsFile);
}

void searchStudent() {
    int opc;
    printf("How do you wanna search the student\n");
    printf("1. By ID\n");
    printf("2. By tuition\n");
    printf("3. By Name\n");
    scanf("%d", &opc);
    fflush(stdin);
    switch (opc) {
        case 1:
            searchStudentById();
            break;
        case 2:
            searchStudentByTuition();
            break;
        case 3:
            searchStudentByName();
            break;
        default:
            printf("Option not in menu\n");
            return;
    }
}

void searchStudentById() {
    int id;
    printf("Please insert the ID: ");
    scanf("%d", &id);

    Student student;
    FILE *studentsFile;

    studentsFile = fopen("students.dat", "rb");

    if (studentsFile == NULL)
        exit(1);

    fread(&student, sizeof(Student), 1, studentsFile);

    while (!feof(studentsFile)) {
        if (student.id == id) {
            printf("------------------------------------------------------------\n");
            printf("|id              %-42d|\n", student.id);
            printf("|matricula       %-42s|\n", student.matricula);
            printf("|name            %-42s|\n", student.name);
            printf("|age             %-42d|\n", student.age);
            printf("|calculo         %-42.1lf|\n", student.calculo);
            printf("|programacion    %-42.1lf|\n", student.programacion);
            printf("|mantenimiento   %-42.1lf|\n", student.mantenimiento);
            printf("|redes           %-42.1lf|\n", student.redes);
            printf("|probabilidad    %-42.1lf|\n", student.probabilidad);
            printf("|valores         %-42.1lf|\n", student.valores);
            printf("|averageGrade    %-42.1lf|\n", student.averageGrade);
            printf("------------------------------------------------------------\n");
            return;
        }
        fread(&student, sizeof(Student), 1, studentsFile);
    }
}

void searchStudentByName() {
    char name[100];
    printf("Please insert the Name: ");
    fflush(stdin);
    gets(name);

    Student student;
    FILE *studentsFile;

    studentsFile = fopen("students.dat", "rb");

    if (studentsFile == NULL)
        exit(1);

    fread(&student, sizeof(Student), 1, studentsFile);

    while (!feof(studentsFile)) {
        if (strcmp(student.name, name) == 0) {
            printf("------------------------------------------------------------\n");
            printf("|id              %-42d|\n", student.id);
            printf("|matricula       %-42s|\n", student.matricula);
            printf("|name            %-42s|\n", student.name);
            printf("|age             %-42d|\n", student.age);
            printf("|calculo         %-42.1lf|\n", student.calculo);
            printf("|programacion    %-42.1lf|\n", student.programacion);
            printf("|mantenimiento   %-42.1lf|\n", student.mantenimiento);
            printf("|redes           %-42.1lf|\n", student.redes);
            printf("|probabilidad    %-42.1lf|\n", student.probabilidad);
            printf("|valores         %-42.1lf|\n", student.valores);
            printf("|averageGrade    %-42.1lf|\n", student.averageGrade);
            printf("------------------------------------------------------------\n");
            return;
        }
        fread(&student, sizeof(Student), 1, studentsFile);
    }
}

void searchStudentByTuition() {
    char tuition[8];
    printf("Please insert the tuition: ");
    fflush(stdin);
    gets(tuition);

    Student student;
    FILE *studentsFile;

    studentsFile = fopen("students.dat", "rb");

    if (studentsFile == NULL)
        exit(1);

    fread(&student, sizeof(Student), 1, studentsFile);

    while (!feof(studentsFile)) {
        if (strcmp(student.matricula, tuition) == 0) {
            printf("------------------------------------------------------------\n");
            printf("|id              %-42d|\n", student.id);
            printf("|matricula       %-42s|\n", student.matricula);
            printf("|name            %-42s|\n", student.name);
            printf("|age             %-42d|\n", student.age);
            printf("|calculo         %-42.1lf|\n", student.calculo);
            printf("|programacion    %-42.1lf|\n", student.programacion);
            printf("|mantenimiento   %-42.1lf|\n", student.mantenimiento);
            printf("|redes           %-42.1lf|\n", student.redes);
            printf("|probabilidad    %-42.1lf|\n", student.probabilidad);
            printf("|valores         %-42.1lf|\n", student.valores);
            printf("|averageGrade    %-42.1lf|\n", student.averageGrade);
            printf("------------------------------------------------------------\n");
            return;
        }
        fread(&student, sizeof(Student), 1, studentsFile);
    }
}

void removeStudent() {
    FILE *studentsFile;
    studentsFile = fopen("students.dat", "r+b");
    Student student;

    if (studentsFile == NULL)
        exit(1);

    int id;
    printf("Insert the id of the student to delete: ");
    scanf("%i", &id);


    fread(&student, sizeof(Student), 1, studentsFile);

    while (!feof(studentsFile)) {
        if (id == student.id) {
            printf("Student to be deleted: \n");
            printf("------------------------------------------------------------\n");
            printf("|id              %-42d|\n", student.id);
            printf("|matricula       %-42s|\n", student.matricula);
            printf("|name            %-42s|\n", student.name);
            printf("|age             %-42d|\n", student.age);
            printf("|calculo         %-42.1lf|\n", student.calculo);
            printf("|programacion    %-42.1lf|\n", student.programacion);
            printf("|mantenimiento   %-42.1lf|\n", student.mantenimiento);
            printf("|redes           %-42.1lf|\n", student.redes);
            printf("|probabilidad    %-42.1lf|\n", student.probabilidad);
            printf("|valores         %-42.1lf|\n", student.valores);
            printf("|averageGrade    %-42.1lf|\n", student.averageGrade);
            printf("------------------------------------------------------------\n");
            printf("Are you sure you want to delete this student? This action can't be undone ");
            printf("\n1. Yes");
            printf("\n2. No");
            printf("\nYour answer here... ");
            int opt;
            scanf("%d", &opt);

            if (opt == 2)
                return;

            student.id = 0;
            strcpy(student.name, "\0");
            strcpy(student.matricula, "\0");
            student.age = 0;
            student.calculo = 0.0;
            student.programacion = 0.0;
            student.mantenimiento = 0.0;
            student.redes = 0.0;
            student.probabilidad = 0.0;
            student.valores = 0.0;
            student.averageGrade = 0.0;

            int pos = ftell(studentsFile) - sizeof(Student);
            fseek(studentsFile, pos, SEEK_SET);
            fwrite(&student, sizeof(Student), 1, studentsFile);
            printf("The student was deleted\n");
            break;
        }
        fread(&student, sizeof(Student), 1, studentsFile);
    }

    printf("User not found");

    fclose(studentsFile);
}

void updateStudentInfo() {
    FILE *studentsFile;
    studentsFile = fopen("students.dat", "r+b");
    Student student;

    if (studentsFile == NULL)
        exit(1);

    int id;
    printf("Ingrese el id del usuario a modificar: ");
    scanf("%i", &id);

    int userInFile = 0;

    fread(&student, sizeof(Student), 1, studentsFile);

    while (!feof(studentsFile)) {
        if (id == student.id) {
            printf("Student to be edited: \n");
            printf("------------------------------------------------------------\n");
            printf("|id              %-42d|\n", student.id);
            printf("|matricula       %-42s|\n", student.matricula);
            printf("|name            %-42s|\n", student.name);
            printf("|age             %-42d|\n", student.age);
            printf("|calculo         %-42.1lf|\n", student.calculo);
            printf("|programacion    %-42.1lf|\n", student.programacion);
            printf("|mantenimiento   %-42.1lf|\n", student.mantenimiento);
            printf("|redes           %-42.1lf|\n", student.redes);
            printf("|probabilidad    %-42.1lf|\n", student.probabilidad);
            printf("|valores         %-42.1lf|\n", student.valores);
            printf("|averageGrade    %-42.1lf|\n", student.averageGrade);
            printf("------------------------------------------------------------\n");
            printf("Are you sure you want to edit this student? This action can't be undone ");
            printf("\n1. Yes");
            printf("\n2. No");
            printf("\nYour answer here... ");
            int opt;
            scanf("%d", &opt);

            if (opt == 2)
                return;

            GetData:
            fflush(stdin);
            printf("Give me the full name of the student: ");
            gets(student.name);
            printf("Give me the tuition name of the student: ");
            gets(student.matricula);
            printf("Give me the age of the student: ");
            scanf("%d", &student.age);
            printf("Give me the grade of calculo of the student: ");
            scanf("%lf", &student.calculo);
            printf("Give me the grade of programacion of the student: ");
            scanf("%lf", &student.programacion);
            printf("Give me the grade of mantenimiento of the student: ");
            scanf("%lf", &student.mantenimiento);
            printf("Give me the grade of redes of the student: ");
            scanf("%lf", &student.redes);
            printf("Give me the grade of probabilidad of the student: ");
            scanf("%lf", &student.probabilidad);
            printf("Give me the grade of valores of the student: ");
            scanf("%lf", &student.valores);

            student.averageGrade = calcAverageGradeOfStudent(&student);
            printf("\nThe data of the student is: \n");
            printf("\nFull name: %s", student.name);
            printf("\ntuition: %s", student.matricula);
            printf("\nage: %d", student.age);
            printf("\ngrade of calculo %lf", student.calculo);
            printf("\nprogramacion: %lf", student.programacion);
            printf("\nmantenimiento: %lf", student.mantenimiento);
            printf("\nredes: %lf", student.redes);
            printf("\nprobabilidad: %lf", student.probabilidad);
            printf("\nvalores: %lf", student.valores);
            printf("\nAverage grade: %lf", student.averageGrade);
            printf("\nIs that correct?\n1.Yes\n2.No");
            int opc = 1;
            scanf("%d", &opc);
            if (opc != 1)
                goto GetData;


            int pos = ftell(studentsFile) - sizeof(Student);
            fseek(studentsFile, pos, SEEK_SET);
            fwrite(&student, sizeof(Student), 1, studentsFile);
            printf("The user was modified\n");
            userInFile = 1;
            break;
        }
        fread(&student, sizeof(Student), 1, studentsFile);
    }

    if (!userInFile) {
        printf("Student not in file...\n");
    }

    fclose(studentsFile);
}

void showAllStudentsByAverageGrade() {
    Student student;
    FILE *studentsFile;
    studentsFile = fopen("students.dat", "rb");

    if (studentsFile == NULL) exit(1);

    fread(&student, sizeof(Student), 1, studentsFile);

    while (!feof(studentsFile)) {
        if (student.id != 0) {
            printf("------------------------------------------------------------\n");
            printf("|id              %-42d|\n", student.id);
            printf("|matricula       %-42s|\n", student.matricula);
            printf("|name            %-42s|\n", student.name);
            printf("|averageGrade    %-42.1lf|\n", student.averageGrade);
            printf("------------------------------------------------------------\n");
        }
        fread(&student, sizeof(Student), 1, studentsFile);
    }
    fclose(studentsFile);
}

void showStatisticsOfStudent() {
    int id;
    printf("Please insert the ID: ");
    scanf("%d", &id);

    Student student;
    FILE *studentsFile;

    studentsFile = fopen("students.dat", "rb");

    if (studentsFile == NULL)
        exit(1);

    fread(&student, sizeof(Student), 1, studentsFile);

    while (!feof(studentsFile)) {
        if (student.id == id) {
            double highestGrade = 0;
            char sHighestGrade[20];
            if ((student.calculo > student.mantenimiento) &&
                (student.calculo > student.valores) &&
                (student.calculo > student.redes) &&
                (student.calculo > student.programacion) &&
                (student.calculo) > student.probabilidad) {
                highestGrade = student.calculo;
                strcpy(sHighestGrade, "Calculo");
            }

            if ((student.redes > student.mantenimiento) &&
                (student.redes > student.valores) &&
                (student.redes > student.calculo) &&
                (student.redes > student.programacion) &&
                (student.redes) > student.probabilidad) {
                highestGrade = student.redes;
                strcpy(sHighestGrade, "Redes");
            }

            if ((student.programacion > student.mantenimiento) &&
                (student.programacion > student.valores) &&
                (student.programacion > student.redes) &&
                (student.programacion > student.calculo) &&
                (student.programacion) > student.probabilidad) {
                highestGrade = student.programacion;
                strcpy(sHighestGrade, "Programación");
            }

            if ((student.probabilidad > student.mantenimiento) &&
                (student.probabilidad > student.valores) &&
                (student.probabilidad > student.redes) &&
                (student.probabilidad > student.calculo) &&
                (student.probabilidad) > student.probabilidad) {
                highestGrade = student.probabilidad;
                strcpy(sHighestGrade, "Probabilidad");
            }

            if ((student.mantenimiento > student.programacion) &&
                (student.mantenimiento > student.valores) &&
                (student.mantenimiento > student.redes) &&
                (student.mantenimiento > student.calculo) &&
                (student.mantenimiento) > student.probabilidad) {
                highestGrade = student.mantenimiento;
                strcpy(sHighestGrade, "Mantenimiento");
            }

            if ((student.valores > student.mantenimiento) &&
                (student.valores > student.programacion) &&
                (student.valores > student.redes) &&
                (student.valores > student.calculo) &&
                (student.valores) > student.probabilidad) {
                highestGrade = student.valores;
                strcpy(sHighestGrade, "Valores");
            }

            double lowestGrade = 0;
            char sLowestGrade[20];
            strcpy(sLowestGrade, "Calculo");
            lowestGrade = 100;
            if ((student.calculo < student.mantenimiento) &&
                (student.calculo < student.valores) &&
                (student.calculo < student.redes) &&
                (student.calculo < student.programacion) &&
                (student.calculo < student.probabilidad)) {
                lowestGrade = student.calculo;
                strcpy(sLowestGrade, "Calculo");
            }

            if ((student.redes < student.mantenimiento) &&
                (student.redes < student.valores) &&
                (student.redes < student.calculo) &&
                (student.redes < student.programacion) &&
                (student.redes < student.probabilidad)) {
                lowestGrade = student.redes;
                strcpy(sLowestGrade, "Redes");
            }

            if ((student.programacion < student.mantenimiento) &&
                (student.programacion < student.valores) &&
                (student.programacion < student.redes) &&
                (student.programacion < student.calculo) &&
                (student.programacion < student.probabilidad)) {
                lowestGrade = student.programacion;
                strcpy(sLowestGrade, "Programación");
            }

            if ((student.probabilidad < student.mantenimiento) &&
                (student.probabilidad < student.valores) &&
                (student.probabilidad < student.redes) &&
                (student.probabilidad < student.calculo) &&
                (student.probabilidad < student.probabilidad)) {
                lowestGrade = student.probabilidad;
                strcpy(sLowestGrade, "Probabilidad");
            }

            if ((student.mantenimiento < student.programacion) &&
                (student.mantenimiento < student.valores) &&
                (student.mantenimiento < student.redes) &&
                (student.mantenimiento < student.calculo) &&
                (student.mantenimiento < student.probabilidad)) {
                lowestGrade = student.mantenimiento;
                strcpy(sLowestGrade, "Mantenimiento");
            }

            if ((student.valores < student.mantenimiento) &&
                (student.valores < student.programacion) &&
                (student.valores < student.redes) &&
                (student.valores < student.calculo) &&
                (student.valores < student.probabilidad)) {
                lowestGrade = student.valores;
                strcpy(sLowestGrade, "Valores");
            }

            printf("------------------------------------------------------------\n");
            printf("|id              %-42d|\n", student.id);
            printf("|matricula       %-42s|\n", student.matricula);
            printf("|name            %-42s|\n", student.name);
            printf("|age             %-42d|\n", student.age);
            printf("|averageGrade    %-42.1lf|\n", student.averageGrade);
            printf("|Highest grade:  %-12s %-30.1lf|\n", sHighestGrade, highestGrade);
            printf("|Lowest grade:   %-12s %-30.1lf|\n", sLowestGrade, lowestGrade);
            printf("------------------------------------------------------------\n");
            return;
        }
        fread(&student, sizeof(Student), 1, studentsFile);
    }
}

void generateInform() {
    int id;
    printf("Please insert the ID: ");
    scanf("%d", &id);

    Student student;
    FILE *studentsFile;

    studentsFile = fopen("students.dat", "rb");

    if (studentsFile == NULL)
        exit(1);

    fread(&student, sizeof(Student), 1, studentsFile);

    while (!feof(studentsFile)) {
        if (student.id == id) {
            double highestGrade = 0;
            char sHighestGrade[20];
            if ((student.calculo > student.mantenimiento) &&
                (student.calculo > student.valores) &&
                (student.calculo > student.redes) &&
                (student.calculo > student.programacion) &&
                (student.calculo) > student.probabilidad) {
                highestGrade = student.calculo;
                strcpy(sHighestGrade, "Calculo");
            }

            if ((student.redes > student.mantenimiento) &&
                (student.redes > student.valores) &&
                (student.redes > student.calculo) &&
                (student.redes > student.programacion) &&
                (student.redes) > student.probabilidad) {
                highestGrade = student.redes;
                strcpy(sHighestGrade, "Redes");
            }

            if ((student.programacion > student.mantenimiento) &&
                (student.programacion > student.valores) &&
                (student.programacion > student.redes) &&
                (student.programacion > student.calculo) &&
                (student.programacion) > student.probabilidad) {
                highestGrade = student.programacion;
                strcpy(sHighestGrade, "Programación");
            }

            if ((student.probabilidad > student.mantenimiento) &&
                (student.probabilidad > student.valores) &&
                (student.probabilidad > student.redes) &&
                (student.probabilidad > student.calculo) &&
                (student.probabilidad) > student.probabilidad) {
                highestGrade = student.probabilidad;
                strcpy(sHighestGrade, "Probabilidad");
            }

            if ((student.mantenimiento > student.programacion) &&
                (student.mantenimiento > student.valores) &&
                (student.mantenimiento > student.redes) &&
                (student.mantenimiento > student.calculo) &&
                (student.mantenimiento) > student.probabilidad) {
                highestGrade = student.mantenimiento;
                strcpy(sHighestGrade, "Mantenimiento");
            }

            if ((student.valores > student.mantenimiento) &&
                (student.valores > student.programacion) &&
                (student.valores > student.redes) &&
                (student.valores > student.calculo) &&
                (student.valores) > student.probabilidad) {
                highestGrade = student.valores;
                strcpy(sHighestGrade, "Valores");
            }

            double lowestGrade = 0;
            char sLowestGrade[20];
            strcpy(sLowestGrade, "Calculo");
            lowestGrade = 100;

            if ((student.calculo < student.mantenimiento) &&
                (student.calculo < student.valores) &&
                (student.calculo < student.redes) &&
                (student.calculo < student.programacion) &&
                (student.calculo < student.probabilidad)) {
                lowestGrade = student.calculo;
                strcpy(sLowestGrade, "Calculo");
            }

            if ((student.redes < student.mantenimiento) &&
                (student.redes < student.valores) &&
                (student.redes < student.calculo) &&
                (student.redes < student.programacion) &&
                (student.redes < student.probabilidad)) {
                lowestGrade = student.redes;
                strcpy(sLowestGrade, "Redes");
            }

            if ((student.programacion < student.mantenimiento) &&
                (student.programacion < student.valores) &&
                (student.programacion < student.redes) &&
                (student.programacion < student.calculo) &&
                (student.programacion < student.probabilidad)) {
                lowestGrade = student.programacion;
                strcpy(sLowestGrade, "Programación");
            }

            if ((student.probabilidad < student.mantenimiento) &&
                (student.probabilidad < student.valores) &&
                (student.probabilidad < student.redes) &&
                (student.probabilidad < student.calculo) &&
                (student.probabilidad < student.probabilidad)) {
                lowestGrade = student.probabilidad;
                strcpy(sLowestGrade, "Probabilidad");
            }

            if ((student.mantenimiento < student.programacion) &&
                (student.mantenimiento < student.valores) &&
                (student.mantenimiento < student.redes) &&
                (student.mantenimiento < student.calculo) &&
                (student.mantenimiento < student.probabilidad)) {
                lowestGrade = student.mantenimiento;
                strcpy(sLowestGrade, "Mantenimiento");
            }

            if ((student.valores < student.mantenimiento) &&
                (student.valores < student.programacion) &&
                (student.valores < student.redes) &&
                (student.valores < student.calculo) &&
                (student.valores < student.probabilidad)) {
                lowestGrade = student.valores;
                strcpy(sLowestGrade, "Valores");
            }

            printf("------------------------------------------------------------\n");
            printf("|id              %-42d|\n", student.id);
            printf("|matricula       %-42s|\n", student.matricula);
            printf("|name            %-42s|\n", student.name);
            printf("|age             %-42d|\n", student.age);
            printf("|averageGrade    %-42.1lf|\n", student.averageGrade);
            printf("|Highest grade:  %-12s %-30.1lf|\n", sHighestGrade, highestGrade);
            printf("|Lowest grade:   %-12s %-30.1lf|\n", sLowestGrade, lowestGrade);
            printf("------------------------------------------------------------\n");
            return;
        }
        fread(&student, sizeof(Student), 1, studentsFile);
    }
}
