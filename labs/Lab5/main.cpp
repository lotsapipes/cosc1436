
// Robert Pace
// Lab 5: Trip Planner
// Spring 2026
// COSC-1436-21005

/*
TAKING NOTES ON HOW TO DO THIS IN CLASS
LAB IS APPARENTLY ABOUT POINTERS
▲▲▲▲▲first thing i noticed is this one looks much more difficult. kind of looks like driving around on the x y axis. There's 5 points on the graph in the example.
yup; so the x y window is +- 100, i think in ints? --yup, ints only on the x and y values
a STRUCT is going to represent a STOP
something about how there could be 50 or 1000 stops?
There's a place where we're supposed to add in SPEED and calculate DISTANCE between the stops
The formula listed is Square root of[(x2 - x1)^2 + (y2 - y1)^2] (this is the distance part.)
Doing stuff on step 6 about deleting pointers to clear memory and stuff

1 Create the C++ project.
2 Display a menu of options to the user to select.
3 Create the trip array.
4 Support adding stops to the trip.
5 Support viewing the trip.
6 Support removing a stop from the trip
7 Support clearing the trip.
8 Support the display of the travel time.

*/


// Robert Pace
// Lab 5: XY Traveler
// Spring 2026
// COSC-1436-21005

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring> //supposed to be a bit trickier, double check on this one
#include <cctype> //easy converter

// Global Constants (I ended up liking using these, though it may be bad form for larger programs)
const int MAX_STOPS = 100;
const int MIN_X = -100;
const int MAX_X = 100;
const int MIN_Y = -100;
const int MAX_Y = 100;
const int MIN_SPEED = 1;
const int MAX_SPEED = 60;

// Struct definitions
struct Stop {
    int x;
    int y;
};

// Function prototypes for Story 2 (Main Menu)
void displayMainMenu();
int getMenuChoice();
bool handleMenuChoice(int choice, Stop* trip[], int& stopCount, int speed);
bool confirmQuit();
void waitForEnter(); //this one was new

// Story 3 & 4 (Trip array and adding stops)
Stop* createStop(int x, int y);
bool addStopToTrip(Stop* trip[], Stop* newStop);
bool isValidPosition(int x, int y);

// Story 4 specifics
void handleAddStop(Stop* trip[]);

// Story 5 specifics
void handleViewTrip(Stop* trip[], int speed);

// Story 6 specifics
Stop* findStopByNumber(Stop* trip[], int stopNumber);
void removeStopFromTrip(Stop* trip[], Stop* stopToRemove);
void compactArray(Stop* stops[], int size, int startIndex);
void handleRemoveStop(Stop* trip[]);

// Story 7 specifics
void clearTrip(Stop* trip[]);
void handleClearTrip(Stop* trip[]);

// Story 8 specifics
int getSpeed();
double calculateDistance(const Stop& point1, const Stop& point2);

int main() {
    // Story 3: Create trip array
    Stop* trip[MAX_STOPS] = {nullptr};  // Initialize all to null pointers, turns out knowing where brackets goes comes in handy later with vectors and other stuff
    int stopCount = 0;  // Track number of stops
    
    // Story 8: Get speed at program start
    int speed = getSpeed();
    
    bool continueRunning = true;
    
    while (continueRunning) {
        displayMainMenu();
        int choice = getMenuChoice();
        continueRunning = handleMenuChoice(choice, trip, stopCount, speed);
        
        if (continueRunning) {
            waitForEnter();
        }
    }
    
    // Clean up any remaining stops before exiting
    clearTrip(trip);
    
    std::cout << "\nExiting Program =)" << std::endl;
    return 0;
}

// Story 2: Display main menu
void displayMainMenu() {
    std::cout << "\n=== Trip Planner Main Menu ===" << std::endl;
    std::cout << "1. Add Stop" << std::endl;
    std::cout << "2. View Trip" << std::endl;
    std::cout << "3. Remove Stop" << std::endl;
    std::cout << "4. Clear Trip" << std::endl;
    std::cout << "5. Quit" << std::endl;
    std::cout << "================================" << std::endl;
    std::cout << "Enter your choice: ";
}

// Story 2: Get and validate menu choice
int getMenuChoice() {
    std::string input;
    std::cin >> input;
    
    if (input.length() == 1 && isdigit(input[0])) {
        int choice = input[0] - '0';
        if (choice >= 1 && choice <= 5) {
            return choice;
        }
    }
    
    std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
    return 0;  // Invalid choice
}

// Story 2: Handle menu selection
// double check slots
bool handleMenuChoice(int choice, Stop* trip[], int& stopCount, int speed) {
    switch (choice) {
        case 1:  // Add Stop
            handleAddStop(trip);
            break;
        case 2:  // View Trip
            handleViewTrip(trip, speed);
            break;
        case 3:  // Remove Stop
            handleRemoveStop(trip);
            break;
        case 4:  // Clear Trip
            handleClearTrip(trip);
            break;
        case 5:  // Quit
            if (confirmQuit()) {
                return false;  // Exit the program
            }
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }
    return true;  // Continue running
}

// Story 2: Confirm quit with user
bool confirmQuit() {
    std::string response;
    std::cout << "Are you sure you want to quit? (y/n): ";
    std::cin >> response;
    
    if (tolower(response[0]) == 'y') {
        return true;
    }
    return false;
}

// Helper function to wait for Enter key
void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get(); 
}

//---------------------------------------------------------------------------------------------------
// Story 3 & 4: Create a new stop
Stop* createStop(int x, int y) {
    Stop* newStop = new Stop;
    // Arrow Operators are used when we have a Pointer to an Object
    // Instead of Dot Operators which are used when we have an Object
    newStop->x = x; //Arrow Operator, this is shorthand for (*newStop).x
    newStop->y = y; //Arrow Operator, this is shorthand for (*newStop).y
    return newStop;
}

// Story 3 & 4: Validate position
bool isValidPosition(int x, int y) {
    return (x >= MIN_X && x <= MAX_X && y >= MIN_Y && y <= MAX_Y);
}

// Story 4: Add stop to trip
bool addStopToTrip(Stop* trip[], Stop* newStop) {
    // Find first null position in array
    for (int i = 0; i < MAX_STOPS; i++) {
        if (trip[i] == nullptr) {
            trip[i] = newStop;
            return true;
        }
    }
    return false;  // Trip is full
}

// Story 4: Handle add stop menu option
void handleAddStop(Stop* trip[]) {
    int x, y;
    std::string input;
    
    std::cout << "\n--- Add New Stop ---" << std::endl;
    
    // Get X coordinate
    std::cout << "Enter X coordinate (-100 to 100): ";
    std::cin >> input;
    x = stoi(input);
    
    // Get Y coordinate
    std::cout << "Enter Y coordinate (-100 to 100): ";
    std::cin >> input;
    y = stoi(input);
    
    // Validate coordinates
    if (!isValidPosition(x, y)) {
        std::cout << "Error: Coordinates must be between -100 and 100." << std::endl;
        return;
    }
    
    // Create new stop
    Stop* newStop = createStop(x, y);
    
    // Add to trip
    if (addStopToTrip(trip, newStop)) {
        std::cout << "Stop (" << x << ", " << y << ") added successfully." << std::endl;
    } else {
        std::cout << "Error: Trip is full (maximum " << MAX_STOPS << " stops). Cannot add more stops." << std::endl;
        delete newStop;  // Clean up allocated memory
    }
}

// Story 8: Get speed from user
int getSpeed() {
    int speed;
    std::string input;
    
    do {
        std::cout << "Enter the speed (1-60 miles per hour): ";
        std::cin >> input;
        speed = std::stoi(input); //finally the stuff from class starts to match up and we can use it
        
        if (speed < MIN_SPEED || speed > MAX_SPEED) {
            std::cout << "Error: Speed must be between " << MIN_SPEED << " and " << MAX_SPEED << " mph." << std::endl;
        }
    } while (speed < MIN_SPEED || speed > MAX_SPEED);
    
    return speed;
}

// Story 8: Calculate distance between two points
double calculateDistance(const Stop& point1, const Stop& point2) {
    int dx = point2.x - point1.x; // It's worth noting that programmer's write Delta X as dx...
    int dy = point2.y - point1.y; // In calculus though dx does not mean Delta X
    // Still though, we're programming so we'll do as programmer's do:
    return sqrt(dx*dx + dy*dy);
}

// Story 5 & 8: Handle view trip menu option
void handleViewTrip(Stop* trip[], int speed) {
    std::cout << "\n--- Current Trip ---" << std::endl;
    
    // Count stops first
    int stopCount = 0;
    for (int i = 0; i < MAX_STOPS && trip[i] != nullptr; i++) {
        stopCount++;
    }
    
    if (stopCount == 0) {
        std::cout << "No stops added to the trip yet." << std::endl;
        return;
    }
    
    // Display table header
    std::cout << "\nStop\tLocation\tDistance (miles, per stop)\tTime (minutes, per stop)" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    
    // Starting point
    Stop startPoint = {0, 0}; // Note the brackets again
    Stop previousPoint = startPoint;
    
    double totalDistance = 0.0;
    int totalTime = 0;
    
    // Display each stop
    for (int i = 0; i < stopCount; i++) {
        Stop currentStop = *(trip[i]);
        
        // Calculate distance from previous point
        double distance = calculateDistance(previousPoint, currentStop);
        
        // Calculate time in minutes and round up
        double timeHours = distance / speed;
        int timeMinutes = static_cast<int>(ceil(timeHours * 60));
        
        // Update totals
        totalDistance += distance;
        totalTime += timeMinutes;
        
        // Display stop information
        std::cout << std::setw(4) << (i + 1) << "\t";
        std::cout << "(" << std::setw(3) << currentStop.x << ", " << std::setw(3) << currentStop.y << ")\t";
        std::cout << std::fixed << std::setprecision(2) << std::setw(14) << distance << "\t\t";
        std::cout << std::setw(13) << timeMinutes << std::endl;
        
        previousPoint = currentStop;
    }

//Display totals
std::cout << "-----------------------------------" << std::endl;
std::cout << std::setw(4) << "Total Stops: " << stopCount << " stops" << std::endl;
std::cout << std::setw(4) << "Total Time: " << totalTime << " minutes" << std::endl;
std::cout << std::setw(4) << "Total Distance :" << totalDistance << " miles" << std::endl;
}

// Story 6: Find stop by number
Stop *findStopByNumber(Stop* trip[], int stopNumber) {
    if (stopNumber <1) {
        return nullptr; // Invalid stop number
    }

int index = stopNumber - 1; // converting to Zero-Based (basically putting the array at 0)

// Checking if the index is within bounds and the stop exists
if (index < MAX_STOPS && trip[index] != nullptr) {

    return trip[index];
}

return nullptr;
}

// Story 6: Compacting the array after removal (copied from Canvas Instructions)
void compactArray(Stop* stops[], int size, int startIndex) {
    int newIndex = startIndex;
    for (int index = startIndex + 1; index < size; ++ index) {
        stops[newIndex] = stops[index];
        ++newIndex;

        if (!stops[index])
        return;
    }
}

//Story 6: Remove specific stop from trip
void removeStopFromTrip(Stop* trip[], Stop* stopToRemove) {
    if (stopToRemove == nullptr) {
        return;
    }

    // Find the stop in the array
    int index = -1;
    for (int i = 0; i < MAX_STOPS; i++) {
        if (trip[i] == stopToRemove){
            index = i;
            break;
        }
    }
    if (index == -1){
        return; //This means the stop wasn't found
    }

    // Deleting the stop pointer
    delete trip[index];
    trip[index] = nullptr;

    // Compacting the array again
    compactArray(trip, MAX_STOPS, index);
}

// Story 6: Handling Stop in the menu

void handleRemoveStop(Stop* trip[]) {
    std::cout << "\n--- Remove Stop ---" << std::endl;

    // First, checking to see if there even are any stops
    int stopCount = 0;
    for (int i = 0; i < MAX_STOPS && trip[i] != nullptr; i++) {
        stopCount++;
    }

    if (stopCount == 0) {
        std::cout << "No stops to remove." << std::endl;
        return;
    }

    // Get stop number from the user
    int stopNumber;
    std::string input;
    std::cout << "Enter stop number to remove (1-" << stopCount << "): "; // let's the user know how many they have
    std::cin >> input;
    stopNumber = std::stoi(input);

    // Find the stop
    Stop* stopToRemove = findStopByNumber(trip, stopNumber);

    if(stopToRemove == nullptr) {
        std::cout << "Error: Stop number " << stopNumber << " does not exist." << std::endl;
        return;
    }

    // Remove the stop
    removeStopFromTrip(trip, stopToRemove);
    std::cout << "Stop " << stopNumber << " removed successfully." << std::endl;
}

// Story 7: Clear all stops from trip
void clearTrip(Stop* trip[]) {
    for (int i = 0; i< MAX_STOPS; i++) {
        if (trip[i] != nullptr) {
            delete trip[i];
            trip[i] = nullptr;
        }
    }
}

// Story 7: Handle clear trip menu option
void handleClearTrip(Stop* trip[]) {
    std::cout << "\n--- Clear Trip ---" << std::endl;

    // Confirming with the user
    std::string response;
    std::cout << "Are you sure you want to clear all stops? (y/n): ";
    std::cin >> response;

    if(tolower(response[0]) == 'y') {
        clearTrip(trip);
        std::cout << "Trip has been sucessfully cleared." << std::endl;
    }
    else {
        std::cout << "Clear trip cancelled." << std::endl;
    }
}
