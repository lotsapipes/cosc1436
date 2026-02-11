//
// Chapter 3
// COSC 1436
// Spring 2026
//

#include <iostream>
#include <string>

void main()
{
    std::string name;
    std::cout << "Enter your name: ";

    //philosophy stuff, workarounds for dealing with how cin and getline don't mix well
    //std::cin.ignore(INT32_MAX, '\n');

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