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

    // variable_decl ::= type identifier or T id for short;
    // T - what can be stored (data type)
    //camelCase is going to be what we're using for variable names

    int age;
    double payRate;    

    std::string firstName;
    std::string lastName;

    int length;
    int width;
    int perimeter;

    length = 10; // this is called WRITING to a variable using the ASSIGNMENT OPERATOR (=)
    width = 20;
    
    std::cout << length;

    // Types
    // PRIMATIVE types are understood by the language
    // a bit is either a 0 or a 1
    // a byte is 8 bits, by flipping between 0s and 1s that makes 256 possible values (2^8 = 256) like this 01101010
    // 
    // a short variable is typically 2 bytes (16 bits) which means it can store PLUS OR MINUS 32,768 = 64,536 possible values
    // an int variable is typically 4 bytes (32 bits) which means it can store PLUS OR MINUS 2.1 billion = 4.2 billion possible values
    // a long variable is typically 4 bytes (32 bits) which means it can store PLUS OR MINUS 2.1 billion = 4.2 billion possible values
    // we will only be using SIGNED int variables because we don't need to worry about those 2 bytes.

    //when we look at EXPRESSIONS we need to know its TYPE. it'll make sense later
    
    // a FLOATING POINT float variable is typically 4 bytes (32 bits) which is typically 5-7 digits of precision
    // a FLOATING POINT double variable is typically 8 bytes (64 bits) which is typically 12-15 digits of precision
    // FLOATING POINT variables are victims to ROUNDING ERRORS because of how they are stored in memory
    // IEEE standards define how FLOATING POINT numbers are stored in memory
    // if we have time we'll learn why 2 + 2 can equal 5 later on

    bool isTrue; //1 byte (8 bits) can store either true or false
    char letterGrade; //1 byte (8 bits) can store a single character like 'A' or 'z' or '3' or '$' from -128 to 127
    
    int hoursWorked; //hours worked in a week
    hoursWorked = 25;

    //Store class average on a quiz
    double classAverage;
    classAverage = 78.9;
    letterGrade = 'A';

    bool firstTimeInCollege;
    firstTimeInCollege = true;

    //to declare multiple variables on one line, separate them by commas
    //we do this when the variables are of the same type
    //this is similar to what we learned before when combining multiple std::cout statements (strings)
    std::string city, state; // we have to use std::string instead of just string because we didn't use "using namespace std;" at the top/beginning

    //an assignment statement is made of a left side and a right side like this: E=E;
    //a variable is an EXPRESSION, so the left side is often a variable
    //the left side must be an LVALUE (something that can appear on the left side of an assignment)
    //an LVALUE must be WRITABLE
    //the right side must be an RVALUE (something that can appear on the right side of an assignment)
    //an RVALUE must be READABLE
    length = 50;
    
    //kind of interesting stuff, whenever a variable is assigned a memory address, it's value is whatever was already at that address
    //this is why it's called garbage (if we don't initialize it)
    //the leftover memory is in RAM
    //this is why it's important to initialize variables before using them
    //always set it to 0, this is called zero initialization

    int someVariable = 0; //because of everything we just went over this is how we're going to be doing it every time more likely than not
    std::cin >> someVariable; //reading user input into someVariable 
    int anotherValue = 10, anotherValueAgain = 20; //declaring multiple variables of the same type on one line
    std::cout << someVariable;

    //inserting a breakpoint stops the program execution at a specific line for debugging purposes
    //you do this by clicking in the margin to the left of the line number in Visual Studio
    // a stepover allows you to execute one line of code at a time while debugging
    // to create a stepover, press F10
    //
    // 
    // 
    //toggling the pin status of a window keeps it open while debugging
    //toggling the pin status can also be done in other windows to keep them open but we probably won't be using this



    

















}
