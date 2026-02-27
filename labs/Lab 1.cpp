/*
* Robert Pace
* COSC 1436-21005
* Lab 1
* Spring 2026
*/

//git add .
//git commit -m "required message goes here"
//git push
//git pull --rebase origin main 
//OR MORE LIKELY:
//git pull --rebase main

#include <iostream>
#include <iomanip>
#include <string>

void main() {

std::cout << "Robert Pace\n";
std::cout << "COSC 1436-21005\n";
std::cout << "Spring 2026\n";
std::cout << "Lab 1: Student Grades and Weights\n\n\n";

std::string studentName;

struct labGrades {
    double labOne;
    double labTwo;
    double labThree;
    double labFour;
};
struct examGrades{
    double examOne;
    double examTwo;
    double examThree;
};

labGrades labs;
examGrades exams;

double participation, finalExam;

std::cout << "Enter student name: ";
std::getline(std::cin, studentName);

std::cout << "Enter 4 Lab grades below (1-100, then press Enter after inputting each one):\n";
std::cout << "Lab 1: ";
std::cin >> labs.labOne;
std::cout << "Lab 2: ";
std::cin >> labs.labTwo;
std::cout << "Lab 3: ";
std::cin >> labs.labThree;
std::cout << "Lab 4: ";
std::cin >> labs.labFour;

std::cout << "Next, enter the 3 Exam grades below (1-100, then press Enter after inputting each one):\n";
std::cout << "Exam 1: ";
std::cin >> exams.examOne;
std::cout << "Exam 2: ";
std::cin >> exams.examTwo;
std::cout << "Exam 3: ";
std::cin >> exams.examThree;

std::cout << "Enter the Participation grade: ";
std::cin >> participation;

std::cout << "Enter the Final Exam grade: ";
std::cin >> finalExam;

std::cout << "\n-----------------------------------\n";
std::cout << "Final Results\n";
std::cout << "-----------------------------------\n";
std::cout << "Student Name: " << studentName << "\n\n";

std::cout << "Here's your Lab grades, " << studentName << ":\n";
std::cout << "Lab 1: " << labs.labOne << std::endl; //swap with \n if this don't work
std::cout << "Lab 2: " << labs.labTwo << std::endl;
std::cout << "Lab 3: " << labs.labThree << std::endl;
std::cout << "Lab 4: " << labs.labFour << std::endl;
std::cout << std::endl;

std::cout << "Here's your Exam grades, " << studentName << ":\n";
std::cout << "Exam 1: " << exams.examOne << std::endl; //swap with \n if this don't work
std::cout << "Exam 2: " << exams.examTwo << std::endl; //swap with \n if this don't work
std::cout << "Exam 3: " << exams.examThree << std::endl; //swap with \n if this don't work
std::cout << std::endl;

std::cout << "Your other grades are below, " << studentName << ":\n";
std::cout << "Participation: " << participation << "\n";
std::cout << "Final Exam: " << finalExam << "\n";

double labTotal = labs.labOne + labs.labTwo + labs.labThree +labs.labFour;
double labAverage = labTotal / 4.0;

double examTotal = exams.examOne + exams.examTwo + exams.examThree;
double examAverage = examTotal / 3.0;

 double weightedFinal = (labAverage * 0.65) +
                        (examAverage * 0.20) +
                        (participation * 0.05) +
                        (finalExam * 0.10);

std::cout << std::fixed << std::setprecision(2);
std::cout << "\nHere's your final Class Grade calculations, " << studentName << ":\n";
std::cout << "-----------------------------------\n";
std::cout << "Lab Average (65% weight): " << labAverage << "%\n";
std::cout << "Exam Average (20% weight): " << examAverage << "%\n";
std::cout << "Participation (5% weight): " << participation << "%\n";
std::cout << "Final Exam (10% weight): " << finalExam << "%\n";
std::cout << "-----------------------------------\n";
std::cout << "Final Course Grade :" << weightedFinal << "%\n";
std::cout << std::endl;
std::cout << std::endl;

//swapping int main for void main and commenting out this return 0
//return 0;
}
