//
// Created by ricar on 7/25/2023.
//

#ifndef PROYECTO_VACACIONAL_STUDENTMANAGMENT_H
#define PROYECTO_VACACIONAL_STUDENTMANAGMENT_H

typedef struct student_t {
    int id;
    char matricula[8];
    char name[100];
    int age;
    double calculo;
    double programacion;
    double mantenimiento;
    double redes;
    double probabilidad;
    double valores;
    double averageGrade;
} Student;

void createStudentsFile();
void addStudent();
void removeStudent();
void updateStudentInfo();
void showAllStudents();
void showAllStudentsByAverageGrade();
void searchStudent();
void searchStudentById();
void searchStudentByName();
void searchStudentByTuition();
void showStatisticsOfStudent();
void generateInform();
int lastStudentId ();
float calcAverageGradeOfStudent (Student *student);

#endif //PROYECTO_VACACIONAL_STUDENTMANAGMENT_H
