// Robert pace
// Movie Library
// Cosc 1436
// Spring 2026
// 

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

const int maxRows = 10;
const int maxCols = 12;


void multiDimensionalArrayExample() {
// the block below is demonstrating how to initialize a 2D array, this is just for practice and will not be used in the actual movie library program, 
// but it's good to know how to do this for future reference
int multiplication[maxRows][maxCols] {
    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
    { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 },
    { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36 },
    { 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48 },
    {5 ,10 ,15 ,20 ,25 ,30 ,35 ,40 ,45 ,50 ,55 ,60 },
    {6 ,12 ,18 ,24 ,30 ,36 ,42 ,48 ,54 ,60 ,66 ,72 },
    {7 ,14 ,21 ,28 ,35 ,42 ,49 ,56 ,63 ,70 ,77 ,84 },
    {8 ,16 ,24 ,32 ,40 ,48 ,56 ,64 ,72 ,80 ,88 ,96 },
    {9 ,18 ,27 ,36 ,45 ,54 ,63 ,72 ,81 ,90 ,-99 ,-99 }
};
}
// to overload the CPU with the above array, we'd need a table the size of 1000x1000, which would be 1 million integers, which is a lot for a CPU to handle, 
// so we won't be doing that, but it's good to know how to initialize a 2D array like this for future reference
// this is more difficult on modern processors because of the way they handle memory, but it's still good to know how to do this for future reference

//also, Jagged Arrays look like this:
//int* jaggedArray[maxRows] = {
//    new int[3]{1, 2, 3},
//    new int[5]{4, 5, 6, 7, 8},
//    new int[2]{9, 10},
//    etc

//the difference between column major and row major is the order in which the elements of a multi-dimensional array are stored in memory.
// In row-major order, the elements of each row of the array are stored in contiguous memory
// locations, while in column-major order, the elements of each column are stored in contiguous memory locations.



// moving notes to the bottom so we can see what we're doing (fell back to continuing notes at the bottom anyways, trying too hard to refactor and catch up)
// deleting some notes
// it looks like adding an array of 100 movies is required
// beginning typing and following along using near matches for variable names and such

//structs go above function prototypes
struct Movie{
    int id;
    std::string title;
    std::string genres;
    int runLength = 0;
    int releaseYear = 0;
    double userRating = 0;
    char isClassic = false;
    std::string description;
};

// function prototype attempts
int FindMovieById(Movie movies[], int size, int id);
void deleteMovie(Movie& movie);
void deleteMovies(Movie movies[], int size);
void viewMovie(const Movie& movie);

int main()
{

        //we're about to start demonstrating pointers at this point, here goes:
        int someValue = 42;
        // I have no idea why the version i'm working on required me to add the * to the value below, but we had to while the example in class didn't. compiler maybe?
        int* ptrValue; //they may have just added it, something about trying to read this part "backwards" for it to make sense
        // hah okay something about how int* isn't an int itself, it's like a '*pointer' to an int or something like that
        ptrValue = &someValue; // this is how we assign the address of someValue to ptrValue, the & operator is used to get the address of a variable
        //here, the & symbol can be thought of as @, maybe?
        //a dereferenced value is the value that a pointer points to
        std::cout << "Pointer value: " << ptrValue << std::endl; // this will print the address of someValue
        std::cout << "Some Value Adress: " << &someValue << std::endl; // this will also print the address of someValue
        std::cout << "Dereferenced Pointer Value: " << ptrValue << std::endl; // this will print the value of someValue, which is 42,
        // the * operator is used to dereference a pointer and get the value it points to

        // pointers have their own naming convetions, the most popular ones being ptrValue and pvalue.
        // let's just stick with ptr going forward, i think 
        // also, don't forget to always initialize them.
        // nullptr is a special value that can be assigned to a pointer to indicate that it doesn't point to anything, it's like a null value for pointers
        // *ptrValue = NULL is the old way of doing this, but it's not recommended because NULL is typically defined as 0, which can lead to confusion and errors.


        // i'm seeing the example looking like it's saying it's got couts of like:
        // ptrValue
        // *ptrValue
        // &someValue
        // someValue

        //dereferencing a point gives us acces to the value stored at that point
        // dereference_op ::= E
        // *ptrvalue


        std::cout << "Main Menu" << std::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "a) Add Movie" << std::endl;
        std::cout << "e) Edit Movie" << std::endl;
        std::cout << "d) Delete Movie" << std::endl;
        std::cout << "v) View Movie" << std::endl;
        std::cout << "?) Help" << std::endl;
        std::cout << "Pick one of the letters from the menu to continue: ";

        char choice;
        std::cin >> choice;
   
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
        std::cin.clear(); // this is half of the input buffer clear we've learned
        std::cin >> choice;
    }

   Movie movie;

   Movie movies[100];

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the movie title: ";
    std::getline(std::cin, movie.title);
    std::cout << "Enter description: ";
    std::getline(std::cin, movie.description);
    std::cout << "Enter the movie genres: ";
    std::getline(std::cin, movie.genres);
    std::cout << "Enter the movie run length (in minutes): ";
    std::cin >> movie.runLength;

    if (movie.runLength < 0) {
        std::cout << "Invalid run length. Please enter a positive integer: ";
        std::cin >> movie.runLength;
    }

    std::cin.clear();
    std::cout << "Enter the movie release year (1900 - 2100): ";
    std::cin >> movie.releaseYear;

    if (movie.releaseYear < 1900 || movie.releaseYear > 2100) {
        std::cout << "Invalid release year. Please enter a year between 1900 and 2100: ";
        movie.releaseYear = 0;
        std::cin >> movie.releaseYear;
    }

    std::cout << "Enter the movie user rating (0.0 - 5.0): ";
    std::cin >> movie.userRating;
    std::cout << "Is this movie a classic? (Y/N): ";
    std::cin >> movie.isClassic;
    if (movie.isClassic == 'Y' || movie.isClassic == 'y') {
        movie.isClassic = true;
    }
    if (movie.isClassic == 'N' || movie.isClassic == 'n') {
        movie.isClassic = false;

        std::cout << "Movie Title: " << movie.title << std::endl;
        std::cout << "Genres: " << movie.genres << std::endl;
        std::cout << "Run Length: " << movie.runLength << " minutes" << std::endl;
        std::cout << "Release Year: " << movie.releaseYear << std::endl;
        std::cout << "User Rating: " << std::fixed << std::setprecision(1) << movie.userRating << " / 5.0" << std::endl;
        std::cout << "Is Classic: " << (movie.isClassic ? "Yes" : "No") << std::endl;

        std::cout << "Description: " << movie.description << std::endl;
    }
    return 0;











}

/*
4-7-26
learing about how arrays can't be called on by functions
target[] is syntax we need do know
bounds checking has been brought up many, many times in class

for (int index **************
target[index] = source[index] // this is being used in some code

spent some time discussing all the things we can't do with arrays (at this point, it was mentioned that in Fundamentals 3 they'll go over the alternatives that we have
we can't display arrays, we'll have to build one on our own it sounds like

bool compareArray(checking left and right arrays to see if they're equal)

*/

//barely awake, just going to continue stacking notes on here and skipping most of the coding for now
    //std::setw(width) ; i don't remember why we're allowed to type 'width' here
    //we're noting the important differences between PARAMETERS and ARGUMENTS, pay attention because it may be on the quiz
//always DOCUMENT your PARAMETERS using the /// three slash DOXYGEN thingy (still have to look up what this is at some point)
//simply alt + click onto some areas to create lil clones like this
//simply alt + click onto some areas to create lil clones like this
//simply alt + click onto some areas to create lil clones like this
//reading about ARGUMENTS...i think we can remember these as the things inside the () when we CALL it
//reading about PARAMETERS...i think these can be thought of as the VARIABLES inside the guts of the function when we build it (yeah these kind of make sense)
//we're spending time creating functions that can change the color of the fonts using multiple color codes as well as a function that looks like it can work like
//a selector for the colors; this functionality looks like it keeps expanding quite a bit and gets pretty intricate
//also, leaning heavily into these /// @brief things that we were talking about having to understand later, these DOCUMETATION things i think is what we called them
//finished adding the fully functional add/delete movie without the program just ending for no reason. The adding and deleting text is also color coded depending on
//which function we're using
//we're covering the 3 PARAMETER KINDS now, something i read about a little bit earlier already
//Pass-By-Value is the default and the one we're most likely to be using for just about everything
//we may need to spend some time on DEBUGGING options in codespaces, it looks like we can apply it to CALLSTACK stuff, which seems pretty important
//DEBUGGING does kind of seem like a whole thing and we should probably look into it in a decent amount of detail

//====================================================================================================================================================================
//i think i'll just keep bloating this thing with notes
//the wording for things like cin and cout are actually called functions, but so are the actual 'function prototypes' we just studied are too 
// so we'll have to go over vocabulary again; the terms procedure and subroutine are also used in this area
//Important, one of the main reasons why we put functions at the bottom is because it condenses the code we're working on in main to smaller/easier spots
//also cool to know, functions actually slow down code, it's just that they help to make it more maintainable/readable

//so it looks like void is actually a pretty common thing in functions, we use it when the function doesn't need to return anything, but whenever
//a function is supposed to return something, we use int instead. so we'll need both for different things

//IMPORTANT:this preprocessor directive was needed for the thing to compile in Codespaces. Without it, it'd crash.
// this line of code is what it fixed:
//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//#define main() main(void)
//next we'll be trying this to see if it can transplant into codespaces properly

//this is the section that will have everything we need to complete lab 2

//we attempted various compilation things to see if we could get void main() to work for fun.
//g++ main.cpp -o main (this is the standard compile command)
//g++ -std=gnu++17 main.cpp -o main (this bends the rules a little bit)
//g++ -fpermissive main.cpp -o main (this one's even more permissive)

//another new day of notes. looks like we're continuing to cover 'do while' stuff, covering 'break's
//i think there was a part about 'break' philosophy i missed somewhere
//while(!quit)
//'case' (what's case again?)

//new day of notes, talking about how it's usually good practice to keep the variables nearby to where they're being used instead of stacking
//them all at the top like we were doing before

// covering topics such as 
// ENUMERATION, subrange of int, enum id {}
// 

//finally got the assignment in, showing up late to take notes, here goes:
//
//covering prefixes and postfixes with increments and decrements ++x x++ --x -xx (doing x + 1 or x - 1)

//something about doxygen comments below /// @brief
/// @brief displays a horizontal line
//something about how documenting our functions like this is PART OF OUR GRADE (all in only one line of comment)
//something about in the industry we'll be handing off the functions to people and not the full source code
//we can't call a function until we've declared them
//also, don't forget it throws compile errors if you declare it and then don't define or call/implement it

//LOOKS LIKE WE'RE GOING TO BE PUTTING FUNCTIONS ABOVE MAIN INSTEAD OF AT THE BOTTOM


    //don't forget, a Struct is a user-defined data type that can hold multiple values of different types. 
    // It's a way to group related data together. In this case, we have a Movie struct that has several fields: 
    // title, genres, runLength, releaseYear, userRating, isClassic, and description. 
    // Each field has a specific type (string, int, double, bool) that defines what kind of data it can hold.
/*
struct Movie
{
    std::string title;
    std::string genres;

    int runLength = 0;
    int releaseYear = 0;
    double userRating = 0;
    char isClassic = false;
    std::string description;

};
*/






/*
Old main below i guess. i didn't even know i built two of these.









int main()
{
    //THIS IS HOW WE CALL THE FUNCTION WE JUST BUILT ABOVE:
    //DisplayLine();
    //setErrorColor();

    //we also spent time moving variables around including "promoting" some of these variables to a spot outside of 2 or more blocks so multiple
    //blocks could use them.

        std::cout << "Main Menu" << std::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "a) Add Movie" << std::endl;
        std::cout << "e) Edit Movie" << std::endl;
        std::cout << "d) Delete Movie" << std::endl;
        std::cout << "v) View Movie" << std::endl;
        std::cout << "?) Help" << std::endl;
        std::cout << "Pick one of the letters from the menu to continue: ";

        char choice;
        std::cin >> choice;

        //missed some parts talking about something called FALLTHROUGH (which sometimes we actually want for some reason)
        //the fix is apparently to use BREAKS
        //you can stake multiple 'lines' into one as shown below with the breaks (i skipped some)
   
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

    Movie movie;
   // Below is where the array of 100 movies will go
   // Movie movie[100];
   Movie movie[100];
   
    //BELOW IS FINALLY THE LINE THAT FIXED THE INPUT BUFFER
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the movie title: ";
    std::getline(std::cin, movie.title);
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
    








*/








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
     // 
        // the question mark below is a ternary operator, it's a shorthand way of writing an if-else statement. 
        // It takes three operands: a condition, a value if the condition is true, and a value if the condition is false. 
        // In this case, we're checking if movie.isClassic is true, if it is, we return "Yes", otherwise we return "No".
        //NOTE: i actually have no idea why this works.
        //actually, it's because the first slot is the true slot (where yes is) and the second slot is the false slot (where no is),
        // so if movie.isClassic is true, it will return "Yes", otherwise it will return "No".
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

/*void DisplayLine()
{
    std::cout << "---------------------" << std::endl;
}

void setErrorColor()
{
    std::cout << "\033[31m";
};

void resetColor()
{
    std::cout << "\033[0m";   // Resets to default
}
*/