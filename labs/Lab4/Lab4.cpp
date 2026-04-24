
// Robert Pace
// Lab 4: Simple Numbers Analyzer
// Spring 2026
// COSC-1436-21005

#include <iostream>
#include <iomanip>
#include <limits>

// Constants
// Globals can be dangerous but in smaller programs like this it's a nice and maintainable way to alter the array size
const int MAX_SIZE = 100;

// Function prototypes
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
        // Trying a different way of input buffer clearing again
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
        } else {
            arr[count] = input;
            count++;
        }
    }
    
    return count;
}

// Function: displayMenu
// Purpose: Shows main menu and gets user's choice with validation
// Parameters: choice - reference to char to store user's selection
// Returns: nothing (modifies choice directly)

void displayMenu(char &choice) {
    std::cout << "\nMain Menu\n";
    std::cout << "---------------\n";
    std::cout << "Press A for: Add all Values\n";
    std::cout << "Press L for: Largest Value\n";
    std::cout << "Press M for: Mean of Values\n";
    std::cout << "Press S for: Smallest Value\n";
    std::cout << "Press I for: Insert More Values\n";
    std::cout << "Press V for: View Table\n";
    std::cout << "Press Q for: Quit\n";
    std::cout << "Choice: ";
    std::cin >> choice;

    //trying a different way to validate Case 
    choice = toupper(choice);
    
    // Validate input
    while (choice != 'A' && choice != 'L' && choice != 'M' && 
           choice != 'S' && choice != 'I' && choice != 'V' && choice != 'Q') {
        std::cout << "Invalid choice. Please enter A, L, M, S, I, V, or Q: ";
        std::cin >> choice;
        choice = toupper(choice);
    }
}

// Function: findLargest
// Purpose: Finds largest value in array
// Parameters: arr - array of integers
//          count - number of valid elements in array
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
//          count - number of valid elements in array
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
//          count - number of valid elements in array
// Returns: mean as double (0.0 if no elements)

double calculateMean(const int arr[], int count) {
    if (count <= 0) return 0.0;
    
    int sum = sumValues(arr, count);
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
            std::cout << "    "; // Just some basic spacing between the numbers
        }
    }
    // This is the part that draws a new line every 10 values for the table
    if (count % 10 != 0) {
        std::cout << std::endl;
    }
}

// Function: insertValues
// Purpose: Adds new positive values to existing array
// Parameters: arr - array to store new values
//             currentCount - current number of valid elements
//             maxSize - maximum capacity of array
// Returns: new count after insertion
int insertValues(int arr[], int currentCount, int maxSize) {
    
    int input;
    int newCount = currentCount;
    
    std::cout << "Enter new values (0 to stop):\n";
    
    while (newCount < maxSize) {
        std::cout << "Enter a value: ";
        std::cin >> input;
        
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
        } else {
            arr[newCount] = input;
            newCount++;
        }
    }
    
    return newCount;
}

// Main function
int main() {
    int numbers[MAX_SIZE];
    int count = 0;
    char choice;
    
    std::cout << "Welcome to Number Analysis Program\n";
    std::cout << "==================================\n\n";
    
    // Story 2: Get initial numbers
    count = getNumbers(numbers, MAX_SIZE);
    
    // Story 3: Main menu loop
    // In this program the MainFunction is also the User GUI but it does a lot more logic this time

    do {
        displayMenu(choice);
        
        switch (choice) {
            case 'A':  // Add All Values (Story 4, "Add all Values" in menu)
                
                if (count > 0) {
                    std::cout << "Sum = " << sumValues(numbers, count) << std::endl;
                } else {
                    std::cout << "No values to calculate sum.\n";
                }
                break;
                
            case 'L':  // Largest (Story 4)
                if (count > 0) {
                    std::cout << "Largest = " << findLargest(numbers, count) << std::endl;
                } else {
                    std::cout << "No values to analyze.\n";
                }
                break;
                
            case 'S':  // Smallest (Story 5)
                if (count > 0) {
                    std::cout << "Smallest = " << findSmallest(numbers, count) << std::endl;
                } else {
                    std::cout << "No values to analyze.\n";
                }
                break;
                
            case 'M':  // Mean (Story 7)
                if (count > 0) {
                    std::cout << std::fixed << std::setprecision(4);
                    std::cout << "Mean = " << calculateMean(numbers, count) << std::endl;
                } else {
                    std::cout << "No values to calculate mean.\n";
                }
                break;
                
            case 'V':  // View Table (Story 8)
                displayValues(numbers, count);
                break;
                
            case 'I':  // Insert More Values (Story 9)
                count = insertValues(numbers, count, MAX_SIZE);
                break;
                
            case 'Q':  // Quit
                std::cout << "Bye! =)\n";
                break;
        }
    } while (choice != 'Q');
    
    return 0;
}
