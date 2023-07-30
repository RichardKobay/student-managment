//
// Created by ricar on 7/25/2023.
//

#ifndef PROYECTO_VACACIONAL_STUDENTMANAGMENT_H
#define PROYECTO_VACACIONAL_STUDENTMANAGMENT_H

/**
 * @typedef
 * Structure for the student
 * @param id: id of the user
 * @param matricula: tuition of the student
 * @param name: name of the user
 * @param age: age of the user
 * @param calculo: calculo grade of the user
 * @param programacion: programación grade of the student
 * @param mantenimiento: mantenimiento grade of the student
 * @param redes: redes grade of the student
 * @param probabilidad: probabilidad grade of the student
 * @param valores: valores grade of the student
 * @param averageGrade: averageGrade of the student
 * */
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

/**
 * Create the students file
 * */
void createStudentsFile();

/**
 * Add a new student to the file
 * */
void addStudent();

/**
 * Remove a student in the file
 * */
void removeStudent();

/**
 * Let the current user modify the data of an student
 * */
void updateStudentInfo();

/**
 * List all the students in the file
 * */
void showAllStudents();

/**
 * Show all the students by it's name, id and average grade
 * */
void showAllStudentsByAverageGrade();

/**
 * Ask the user whether they want to search by id, name, or tuition, and then execute the corresponding function.\n
 *
 * This function prompts the user for input and based on their choice, it calls one of the following functions:\n
 * - searchStudentById(): to search for records by ID.\n
 * - searchStudentByName(): to search for records by name.\n
 * - searchStudentByTuition(): to search for records by tuition.\n
 *
 * The selected function will handle the search operation and display the results.
 */
void searchStudent();

/**
 * Search a student by it's id and show the info to the user
 * */
void searchStudentById();

/**
 * Search a student by it's name and show the info to the user
 * */
void searchStudentByName();

/**
 * Search a student by it's tuition and show the info to the user
 * */
void searchStudentByTuition();

/**
 * Show statistics of a student and show it to the user
 * */
void showStatisticsOfStudent();

/**
 * Generates an inform of a student
 * */
void generateInform();

/**
 * Check in the students.dat file for the last student id and returns it
 * @returns int: last student id
 * */
int lastStudentId ();

/**
 * Calculates the average grade of a student
 * */
float calcAverageGradeOfStudent (Student *student);

#endif //PROYECTO_VACACIONAL_STUDENTMANAGMENT_H
