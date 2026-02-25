/*
* Robert Pace
* COSC 1436
* Lab 1 alskdfjsdl
*/



#include <iostream>
#include <iomanip>

//also not allowed to use namespace for good reason

int main() {

std::string studentName;
//rebuild struct or something right here
//because we're not allowed to use vectors yet
//struct (or something) labs
//struct exams
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

//this part below is where i got stuck, it's super important and we need
// to know it when we're creating Strcuts:
labGrades labs;
examGrades exams;
//the part above, pay attention to that

double participation, finalExam;

std::cout << "Enter student name: ";
std::getline(std::cin, studentName);

//also, note below, the part we got stuck on fits right there
//into the first slot thingy of the variable

std::cout << "/nEnter 4 lab grades (1-100, separated by enter/spaces):\n";
std::cout << "Lab 1: ";
std::cin >> labs.labOne;
std::cout << "Lab 2: ";
std::cin >> labs.labTwo;
std::cout << "Lab 3: ";
std::cin >> labs.labThree;
std::cout << "Lab 4: ";
std::cin >> labs.labFour;

std::cout << "Next, enter the 3 exam grades (1-100, separated by enter/spaces):\n";
std::cout << "Exam 1: ";
std::cin >> exams.examOne;
std::cout << "Exam 2: ";
std::cin >> exams.examTwo;
std::cout << "Exam 3: ";
std::cin >> exams.examThree;

std::cout << "Enter the Participation grade: ";
std::cin >> participation;

std::cout << "Enter the final exam grade: ";
std::cin >> finalExam;

std::cout << "\n------------------------------------\n";
std::cout << "Final Results\n";
std::cout << "-------------------------------------";
std::cout << "Student: " << studentName << "\n\n";

std::cout << "Lab Grades:\n";
std::cout << "Lab 1: " << labs.labOne << std::endl; //swap with \n if this don't work
std::cout << "Lab 2: " << labs.labTwo << std::endl;
std::cout << "Lab 3: " << labs.labThree << std::endl;
std::cout << "Lab 4: " << labs.labFour << std::endl;

std::cout << "Exam Grades:\n";
std::cout << "Exam 1: " << exams.examOne << std::endl; //swap with \n if this don't work
std::cout << "Exam 2: " << exams.examTwo << std::endl; //swap with \n if this don't work
std::cout << "Exam 3: " << exams.examThree << std::endl; //swap with \n if this don't work

std::cout << "\nOther Grades: \n";
std::cout << "  Participation: " << participation << "\n";
std::cout << "  Final Exam: " << "\n";


//can't remember if we're allowed to use for loops to do the math here or not
//double check later, if not, just format this a little better
//so it don't look so bad

double labTotal = labs.labTwo + labs.labThree
 + labs.labThree +labs.labFour;
double labAverage = labTotal / 4.0;

double examTotal = exams.examOne + exams.examTwo
 + exams.examThree;
 double examAverage = examTotal / 3.0;


 //IMPORTANT: double check these weights against the stories or whatever
 double weightedFinal = (labAverage * 0.25) +
                        (examAverage * .50) +
                        (participation * 0.10) +
                        (finalExam * 0.15);


//note, there's a typo above somewhere where i forgot to type the %
//marks, add them later
std::cout << std::fixed << std::setprecision(2);
std::cout << "Grade Calculations:\n";
std::cout << "-------------------\n";
std::cout << "Lab Average (25% weight): " << labAverage << "%\n";
std::cout << "Exam Average (50% weight): " << examAverage << "%\n";
std::cout << "Participation (10% weight): " << participation << "%\n";
std::cout << "Final Exam (15% weight): " << finalExam << "%\n";
std::cout << "----------------------------------------------\n";
std::cout << "Final Course Grade :" << weightedFinal << "%\n;";

//don't forget to swap out the int main above for a void main
//as well as removing the return zero below

return 0;
}
















*/