//
// Chapter 3
// COSC 1436
// Spring 2026
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
//setw(#) is used to set the width of the output, it will pad with spaces if the output is shorter than the width
//this is from the iomanip library, which stands for input/output manipulators

//fun facts, C++ is more verbose and kind of easier to read, and it's 'safer'
//some companies will not allow use of C for this reason, because C is more prone to memory leaks and maybe other issues




void main()
{
    
    double mathvalue;
    std::cout << "Enter a math value: ";
    std::cin >> mathvalue;

    //truncating means cutting off the decimal part of a number, so if we have 3.14, truncating it would give us 3
    //it's different from rounding, which would give us 3.1 if we round to 1 decimal place, or 3 if we round to the nearest whole number
    //truncating always rounds off on whole numbers, while rounding can round up or down depending on the decimal part

    std::cout << std::setw(20) << "Function " << "Result" << std::endl;
    std::cout << std::setw(20) << "pow (square) " << std::pow(mathvalue, 2) << std::endl;
    std::cout << std::setw(20) << "pow (cube) " << std::pow(mathvalue, 3) << std::endl;
    //next up we're going to add square root applied to the mathvalue
    std::cout << std::setw(20) << "sqrt " << std::sqrt(mathvalue) << std::endl;
    //next up we're going to add absolute value applied to the mathvalue
    std::cout << std::setw(20) << "abs " << std::abs(mathvalue) << std::endl;
    //next up we're going to add the ceiling function applied to the mathvalue
    std::cout << std::setw(20) << "ceil " << std::ceil(mathvalue) << std::endl;
    //next up we're going to add the floor function applied to the mathvalue
    std::cout << std::setw(20) << "floor " << std::floor(mathvalue) << std::endl;
    //next up we'll add the exponential function applied to the mathvalue
    std::cout << std::setw(20) << "exp " << std::exp(mathvalue) << std::endl;
    //next up we'll add the logarithm function applied to the mathvalue
    std::cout << std::setw(20) << "log " << std::log(mathvalue) << std::endl;
    //next up we'll add the trunc function applied to the mathvalue
    std::cout << std::setw(20) << "trunc " << std::trunc(mathvalue) << std::endl;
    //next up we'll add the round function applied to the mathvalue
    std::cout << std::setw(20) << "round " << std::round(mathvalue) << std::endl;



    int actualPoints, totalPoints;

    std::cout << "Enter the actual points and total points: ";
    std::cin >> actualPoints >> totalPoints;

    //to round to 2 decimal places, we can use the setprecision manipulator from the iomanip library like this:
    //std::cout << std::fixed << std::setprecision(2);
    // same thing as a TI calculator
    //to get around the int divided by int issue, we'll be using TYPE CASTING like this:

    double average = (static_cast<double>(actualPoints) / totalPoints) * 100;
    std::cout << "Your average is: " << average << "%" << std::endl;


    int firstValue, secondValue;
    std::cout << "Enter x and y: ";
    std::cin >> firstValue >> secondValue;

    std::cout << std::left;

    //below we'll be listing x, y, +, -, *, /, and % in a table format using setw to align the columns one line at a time
    std::cout << std::setw(4) << "x"
        << std::setw(4) << "y"
        << std::setw(4) << "+"
        << std::setw(4) << "-"
        << std::setw(4) << "*"
        << std::setw(5) << "/"
        << std::setw(4) << "%"
        << std::endl;

    std::cout << std::setfill('-') << std::setw(27) << "" << std::setfill(' ') << std::endl;






    std::cout << std::setw(4) << firstValue << std::setw(4) << secondValue
        << std::setw(4) << (firstValue + secondValue)
        << std::setw(4) << (firstValue - secondValue)
        << std::setw(4) << (firstValue * secondValue)
        << std::setw(5) << (firstValue / secondValue)
        << std::setw(4) << (firstValue % secondValue)
        << std::endl;





    std::string name;
    std::cout << "Enter your name: ";

    //philosophy stuff, workarounds for dealing with how cin and getline don't mix well
    std::cin.ignore(INT32_MAX, '\n');
    //so, below we're going to fix the std::getline issue by adding this:
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::getline(std::cin, name);

    std::cout << "Hello, " << name << std::endl;


    std::cout << "Enter the length of the rectangle: ";

    int length;
    std::cin >> length;

    std::cout << "Enter the width of the rectangle: ";

    int width;
    std::cin >> width;

    int area = length * width;
    std::cout << "The area of the rectangle is: " << area << std::endl;

    std::cout << "Enter the base and height of the triangle: ";

    int base, height;
    std::cin >> base >> height;

    area = (base * height) / 2;
    std::cout << "The area of the triangle is: " << area << std::endl;

    //namespace, garbage, class, function

    base = base + 10;
    // or we could write it as
    base += 10;

    //type coercion - compiler automatically converts one type to another
    //applies when using 2 different types

    area = (1 / 2) * base * height; // this will output an int type because everything here is an int
    area = 0.5 * base * height; // this will output a double type answer because 0.5 is a double literal
    //the compiler coerces/forces the types into the proper type

    float someValue = 0.2 * 10;

    //Overflow is when you exceed the maximum value of a type
    //Underflow is when you go below the minimum value of a type

    short minValue = -32768;
    short maxValue = 32767;

    maxValue += 1; // this will cause overflow and wrap around to the minimum value
    //wraps around means that it ends up being -32768 instead of 32768





}