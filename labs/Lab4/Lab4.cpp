
//this is a placeholder to ensure that the configuration files (i forget what they're called right now)
//are created properly using Visual Studio
//now we can edit this thing using any tool we want.

// Robert Pace
// Lab 3: Free Fall Distance & Velocity Calculator
// Spring 2026
// COSC-1436-21005

// we're going to be building an array that goes up to 100, arrays only
// something about pressing 0 to exit a loop (also no negatives are allowed)
// no global variables allowed on this one (we were allowed to use them last lab)
// there'll eventually be an option to quit the program this time (maybe it's 0?)
// something about calculating the array with a function and the user not being able to enter the Debugger and change values that way??
// doing some simple rounding of doubles to 4 decimal places
// what's delimiting?

//CONTINUING TO ADD HOW TO NOTES
//"Have the main program call the new function in a loop until the user elects to quit the program." (make sure we understand this)
// doesn't belong in this assignment but don't forget to review "Function Overloading"
// lots of common sense stuff about calculting all these things AFTER the user has entered all their values, not while they're entering them (so we don't have to worry about the user entering a value that causes an error in the middle of the calculations)
// on the part where we display the whole array, it says: "Because the array may have many values show 10 values per line."
// apparently we need a counter variable?: "You will need to ensure that you update the counter variable you are using to track how many elements in the array are being used."


//SAMPLE OUTPUT FROM ASSIGNMENT BELOW:
/*

Enter a value: 50
Enter a value: 45
Enter a value: 75
Enter a value: -1
You must enter a value greater than or equal to 0
Enter a value: 30
Enter a value: 0

Main Menu
---------------
A) dd 
L) argest
M) ean
S) mallest
I) nsert
V) iew
Q) uit
L
Largest = 75

Main Menu
----------------
...
M
Mean = 50.0000

Main Menu
---------------
...
V
50    45    75    30

*/

//Heading is already above, go ahead and start putting the preprocessors and just start
//scribbling what we've got so far

#include <iostream>
#include <iomanip>
#include <limits>

// Constants
const int MAX_SIZE = 100; //reread the prompt, i think i'll have to move this somewhere

// Function prototypes
//it's a lot of arrays...but i think this'll work. if not, i'll just rework it
// don't forget to recheck the syntax on the slots
int getNumbers(int arr[], int maxSize);
void displayMenu(char &choice);
int findLargest(const int arr[], int count);
int findSmallest(const int arr[], int count);
int sumValues(const int arr[], int count);
double calculateMean(const int arr[], int count);
void displayValues(const int arr[], int count);
int insertValues(int arr[], int currentCount, int maxSize);

// Function: getNumbers
// Purpose: Prompts user to enter integers, stores positive values in array until 0 or max
// Parameters: arr - array to store values
//             maxSize - maximum capacity of array
// Returns: number of valid values entered (excluding 0 and negatives)

int getNumbers(int arr[], int maxSize) {
    int count = 0;
    int input;
    
    while (count < maxSize) {
        std::cout << "Enter a value (there's room for 100 values max): ";
        std::cin >> input;
        
        // Validate input
        // going to try a newer version of the cin checking this time, we'll know if it works later
        // something about how i was doing it wrong before? can't remember
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer.\n";
            continue;
        }
        
        if (input == 0) {
            break;
        } else if (input < 0) {
            std::cout << "You must enter a value greater than or equal to 0\n";
            //still have to cross reference the below with the classwork to make sure it matches
        } else {
            arr[count] = input;
            count++;
        }
    }
    
    return count;
}

//that should work 
// test later

// Function: displayMenu
// Purpose: Shows main menu and gets user's choice with validation
// Parameters: choice - reference to char to store user's selection
// Returns: nothing (modifies choice directly)

void displayMenu(char &choice) {
    std::cout << "\nMain Menu\n";
    std::cout << "---------------\n";
    std::cout << "Press A for: Add\n";
    std::cout << "Press L for: Largest\n";
    std::cout << "Press M for: Mean\n";
    std::cout << "Press S for: Smallest\n";
    std::cout << "Press I for: Insert\n";
    std::cout << "Press V for: View\n";
    std::cout << "Press Q for: Quit\n";
    std::cout << "Choice: ";
    std::cin >> choice;
    //it'd be cool if i formatted this nice and neat the first time
    
    // Convert to uppercase for case-insensitivity
    // make sure the below works as well as review what that one thing we tried to use last time, that weird converter
    // if we can't find a cleaner way to do it, just throw in the lower case letters in again
    choice = toupper(choice);
    
    // Validate input
    while (choice != 'A' && choice != 'L' && choice != 'M' && 
           choice != 'S' && choice != 'I' && choice != 'V' && choice != 'Q') {
        std::cout << "Invalid choice. Please enter A, L, M, S, I, V, or Q: ";
        std::cin >> choice;
        choice = toupper(choice);
    }
}

// that should work as a main menu...
// i still need to test these later






//2nd round, most of these functions are actually mostly the same in syntax
//the table is the part that has me worried, double check to make sure it works right and prints the way we want it to
// i'll probably just rewrite all of the Function comments now that i'm looking at them

// Function: findLargest
// Purpose: Finds largest value in array
// Parameters: arr - array of integers
// count - number of valid elements in array
// Returns: largest integer value

int findLargest(const int arr[], int count) {
    if (count <= 0) return 0;
    
    int largest = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

// Function: findSmallest
// Purpose: Finds smallest value in array
// Parameters: arr - array of integers
// count - number of valid elements in array
// Returns: smallest integer value

int findSmallest(const int arr[], int count) {
    if (count <= 0) return 0;
    
    int smallest = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

// Function: sumValues
// Purpose: Calculates sum of all values in array
// Parameters: arr - array of integers
//             count - number of valid elements in array
// Returns: sum of all values

int sumValues(const int arr[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function: calculateMean
// Purpose: Calculates average of values in array
// Parameters: arr - array of integers
//             count - number of valid elements in array
// Returns: mean as double (0.0 if no elements)

double calculateMean(const int arr[], int count) {
    if (count <= 0) return 0.0;
    
    int sum = sumValues(arr, count);
    //not sure if i'll need to format these to two places using that one tool we were using before
    //also not even sure if it wasn't 4 decimal places
    return static_cast<double>(sum) / count;
}

// Function: displayValues
// Purpose: Displays all values in array, 10 per line
// Parameters: arr - array of integers
//             count - number of valid elements in array
// Returns: nothing, always for tables

void displayValues(const int arr[], int count) {
    if (count == 0) {
        std::cout << "No values to display.\n";
        return;
    }
    
    for (int i = 0; i < count; i++) {
        std::cout << arr[i];
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        } else if (i != count - 1) {
            std::cout << "    "; //placeholder, fix this part later
        }
    }
    //still kind of lost on this part here, double check it
    if (count % 10 != 0) {
        std::cout << std::endl;
    }


// the table is for sure gonna need some work


}
