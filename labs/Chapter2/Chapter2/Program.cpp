/*
 * Chapter 2
 * COSC 1436 Spring 2026
 *
 */
#include <iostream> //preprocessor directive to include the iostream library


//entry point for program execution
void main() //void means this function does not return a value
{
 // Your code goes here

    // these things (double quoted) are called STRING LITERALS
    // new lines are NOT SUPPORTED in string literals
    std::cout << "Hello, World!"; //every line like this is called a STATEMENT
    //S; means STATEMENT
    //E; means EXPRESSION
    std::cout << std::endl; //manipulator that ends the line and flushes the output buffer
    std::cout << "Welcome to COSC 1436" << std::endl;
    std::cout << "This is my first C++ program." << std::endl;

    // ESCAPE SEQUENCES only work inside string literals
    // they start with a BACKSLASH (\)
    // \n means NEW LINE
    // \t means TAB
    // \" means DOUBLE QUOTE
    // \\ means BACKSLASH

    //std::cout << "Hello, "Bob" how are you?" won't work
    std::cout << "When you want to put your words in \"quotes\" do so like this." << std::endl; //this will work

    // an INTEGER LITERAL is a whole number
    // a FLOATING POINT LITERAL is a number with a decimal point

    // a VARIABLE is a named storage location in memory

    std::cout << "Enter your name: ";
    std::string name; //DECLARE a variable of type STRING called name (kind of important)
    std::cin >> name; //get user input and store it in the variable name
    std::cout << "Hello, " << name << "! Welcome to COSC 1436." << std::endl;




}

























