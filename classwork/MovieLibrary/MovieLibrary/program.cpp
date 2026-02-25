//
// Movie Library
// Cosc 1436
// Spring 2026
// 

#include <iostream>
#include <string>
#include <iomanip>

//NOTES: pushing didn't work, error messages saying to pull and then push, also failed, then error messages offering to REBASE or something else.
//figure it out later

struct Movie
    //don't forget, a Struct is a user-defined data type that can hold multiple values of different types. 
    // It's a way to group related data together. In this case, we have a Movie struct that has several fields: 
    // title, genres, runLength, releaseYear, userRating, isClassic, and description. 
    // Each field has a specific type (string, int, double, bool) that defines what kind of data it can hold.

{
    std::string title;
    std::string genres;

    int runLength;
    int releaseYear;
    double userRating;
    char isClassic;
    std::string description;

};

void main()
{
    //we're going to create a menu display showing the following things: main menu, ----, a(dd movie, e)dit movie, d)elete movie, v)iew movie, and ?

    std::cout << "Main Menu" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "a) Add Movie" << std::endl;
    std::cout << "e) Edit Movie" << std::endl;
    std::cout << "d) Delete Movie" << std::endl;
    std::cout << "v) View Movie" << std::endl;
    std::cout << "?) Help" << std::endl;

    char choice;
    std::cin >> choice;

    //NOTE: still need to study how if, else if, else stuff works

    //so, for the code below, it's possible to use something else called a Switch Statement. The general
    //way that a switch statement works is that you have a variable (in this case, choice) and then 
    //you have different cases for each possible value of that variable.

    //missed some parts talking about something called FALLTHROUGH (which sometimes we actually want for some reason)
    //the fix is apparently to use BREAKS
    //you can stake multiple 'lines' into one as shown below with the breaks (i skipped some)
    

    switch (choice) {
        case 'A':
        case 'a':
            std::cout << "You chose to add a movie!" << std::endl;break;
        case 'E':
        case 'e':
            std::cout << "You chose to edit a movie!" << std::endl;break;
        case 'D':
        case 'd':
            std::cout << "You chose to delete a movie!" << std::endl;
            break;
        case 'V':
        case 'v':
            std::cout << "You chose to view a movie!" << std::endl;
            break;
        case '?':
            std::cout << "Help menu coming soon!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
    }


   /*
    if (choice == 'a' || choice == 'A') {
        std::cout << "You chose to add a movie!" << std::endl;
    }
    else if (choice == 'e' || choice == 'E') {
        std::cout << "You chose to edit a movie!" << std::endl;
    }
    else if (choice == 'd' || choice == 'D') {
        std::cout << "You chose to delete a movie!" << std::endl;
    }
    else if (choice == 'v' || choice == 'V') {
        std::cout << "You chose to view a movie!" << std::endl;
    }
    else if (choice == '?') {
        std::cout << "Help menu coming soon!" << std::endl;
    }
    while (choice != 'a' && choice != 'A' && choice != 'e' && choice != 'E' && choice != 'd' && choice != 'D' && choice != 'v' && choice != 'V' && choice != '?') {
        std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        std::cin.clear(); // this clears the error state of the input stream, hopefully, check later
        std::cin >> choice;
    }

    */


    //NOTE: below...
    //if (true)
    // {
    //if (false)
    // }
    //else



    Movie movie;

    std::cout << "Enter the movie title: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, movie.title); // this is how we read in a string with spaces (yup)
    //TODO: validate the movie title to make sure it's not empty or too long (maybe we can use a loop to keep asking until we get a valid title)

    std::cout << "Enter description: ";
    std::getline(std::cin, movie.description);
    std::cout << "Enter the movie genres: ";
    std::getline(std::cin, movie.genres);
    std::cout << "Enter the movie run length (in minutes): ";
    std::cin >> movie.runLength;
    //TODO: validate the run length to make sure it's a positive integer (maybe we can use a loop to keep asking until we get a valid run length)

    //NOTE: bracket placement on these ones below? ah, found it, it's called a BLOCK STATEMENT, notes below:

    if (movie.runLength < 0) {
        std::cout << "Invalid run length. Please enter a positive integer: ";
        std::cin >> movie.runLength;
    }

    //block statement is a group of statements that are enclosed in curly braces {}. 
    // They are used to define the scope of variables and to group related statements together. 
    // In this case, we have an if statement that checks if the run length is less than 0. 
    // If it is, we print an error message and ask the user to enter a valid run length. 
    // The block of code inside the if statement will only be executed if the condition is true.

    //clearing the input buffer below like this:
    std::cin.clear();

    std::cout << "Enter the movie release year (1900 - 2100): ";
    std::cin >> movie.releaseYear;

    //TODO: validate the release year to make sure it's between 1900 and 2100 (maybe we can use a loop to keep asking until we get a valid release year)

    // these || are called logical OR operators, they are used to combine two conditions and return true if either condition is true.
    // technically though, at this point in the class, we'll be using two separate if statements:

    //fixed the stuff below by changing from an "IF" to a "WHILE"
    if (movie.releaseYear < 1900 || movie.releaseYear > 2100) {
        std::cout << "Invalid release year. Please enter a year between 1900 and 2100: ";
        movie.releaseYear = 0;
        std::cin >> movie.releaseYear;
         // this clears the error state of the input stream
        //interestingly, if you put in a char instead of a number, it infinitely loops, this is because when you enter a char, 
        // it fails to read it as an integer and leaves the input stream in a failed state.
        // To fix this, we can clear the input stream and ignore the invalid input before asking for the release year again.
    }

     //spent some time going over && and || operators
     //short circuit evaluation is a concept in programming where the evaluation of a logical expression is instant on the first condition A || B
     // it's default.
     //alternatively to short circuit evaluation, we can use BITWISE operators & and |
     //BITWISE operators are used to perform operations on individual bits of data. They are represented by the symbols &, |, ^, ~, <<, and >>.




    /*if (movie.releaseYear < 1900) {
            std::cout << "Invalid release year. Please enter a year between 1900 and 2100: ";
            std::cin >> movie.releaseYear;
    }
    if (movie.releaseYear > 2100) {
            std::cout << "Invalid release year. Please enter a year between 1900 and 2100: ";
            std::cin >> movie.releaseYear;
    }
    */

     //if else statements are more PERFORMANT than multiple if statements because they only evaluate one condition, 
     // whereas multiple if statements will evaluate all conditions even if one is already true.
     //below we'll rewrite the /**/ commented out code using if, else if, else statements which will cover everything including the invalid input case.





    std::cout << "Enter the movie user rating (0.0 - 5.0): ";
    std::cin >> movie.userRating;
    std::cout << "Is this movie a classic? (Y/N): ";
    std::cin >> movie.isClassic;
    if (movie.isClassic == 'Y' || movie.isClassic == 'y') {
        movie.isClassic = true;
    }
    if (movie.isClassic == 'N' || movie.isClassic == 'n') {
        movie.isClassic = false;





    //NOTE: below is where i got lost in class because i had to fix something newbie
    // i think all we need to do is make sure the if else thingy is working




        std::cout << "Movie Title: " << movie.title << std::endl;
        std::cout << "Genres: " << movie.genres << std::endl;
        std::cout << "Run Length: " << movie.runLength << " minutes" << std::endl;
        std::cout << "Release Year: " << movie.releaseYear << std::endl;
        std::cout << "User Rating: " << std::fixed << std::setprecision(1) << movie.userRating << " / 5.0" << std::endl;
        // the question mark below is a ternary operator, it's a shorthand way of writing an if-else statement. 
        // It takes three operands: a condition, a value if the condition is true, and a value if the condition is false. 
        // In this case, we're checking if movie.isClassic is true, if it is, we return "Yes", otherwise we return "No".
        //NOTE: i actually have no idea why this works.
        //actually, it's because the first slot is the true slot (where yes is) and the second slot is the false slot (where no is),
        // so if movie.isClassic is true, it will return "Yes", otherwise it will return "No".
        std::cout << "Is Classic: " << (movie.isClassic ? "Yes" : "No") << std::endl;
        //it's called the Conditional Operator and it's popular



        std::cout << "Description: " << movie.description << std::endl;



    }
    //this is a nested if method of doing things
    // this is frowned up tho
        //NOTE: this thing's only checking for errors once, also have no idea how to fix it right now.




        //----------------------------------------------------------------------------------------------------------------------------------------------------


        //relational operators are used to compare two values and return a boolean result (true or false)
        // it does this using the operators: ==, !=, <, >, <=, >=

        // to review, Presedence means the order in which operators are evaluated in an expression. It's the same thing as Order of Operations

        //kind of worth noting to see how booleans work
        //int x = 5;
        //int y = 10;
        //bool areEqual = (x == y); // this will be false because 5 is not equal to 10
        //however, we have to be careful we use the = and == carefully because if we:
        //bool isEqual = (x = y); // this will assign the value of y (10) to x and then evaluate to true

        //it's best not to use floating points with relational operators because of precision issues. it's a recurring theme we need to take note of
        //however, we can use them with integers because they are exact values.

        //C++ is a case sensitive language like linux so we probably don't have to pay too much attention to this because it makes sense already
        //still kind of important to note that we're talking about when we're comparing strings or chars in this context


        //NOTE: go ahead and hop on Copilot and figure out how comparing strings below works.
        //NOTE: also make sure to cover how strings only work in C or something like that, whatever it was

        //std::string firstName = "Bob";
        //std::string lastName = "bob";

        //bool isSingularName = firstName == lastName; //

        //int result = _strcmpi("Bob", "bob"); //
        //isSingularName = _strcmpi(firstName.c_str(), lastName.c_str()) == 0; //
}