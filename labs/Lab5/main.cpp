
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

//meh...it keeps coming up. i may just throw it in
//horrible, horrible idea, retype everything.
using namespace std;

// Constants
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
void waitForEnter();

// Story 3 & 4 (Trip array and adding stops)
Stop* createStop(int x, int y);
bool addStopToTrip(Stop* trip[], Stop* newStop);
bool isValidPosition(int x, int y);


// going to stop here and read more about pointers before i start writing a bunch of these


// round 2 as they say on the streets
// since we've got the basic outline for the global variables we're for sure going to use
// and probably most of the function prototypes, we stuck to working on the backend functions
// don't forget to check how to check history on GitHub (if we even can) to study the process we used for later
// if not, it probably doesn't matter anyways since most of this will be from memory like everything else


//everything below this line is functions with pointers. they're not too difficult but...
//after rereading this i'm still a little fuzzy on how it works. study it again later, maybe,
//but...we really need to focus on calculus this late in the semester.
//NOTE: doesn't compile because of a dropped {} somewhere. (i threw one at the very end as a guess, see below)
//-----------------------------------------------------------------------------------------------------

// Story 4 specific
void handleAddStop(Stop* trip[]);

// Story 5 specific
void handleViewTrip(Stop* trip[], int speed);

// Story 6 specific
// double check slots
Stop* findStopByNumber(Stop* trip[], int stopNumber);
void removeStopFromTrip(Stop* trip[], Stop* stopToRemove);
void compactArray(Stop* stops[], int size, int startIndex);
void handleRemoveStop(Stop* trip[]);

// Story 7 specific
void clearTrip(Stop* trip[]);
void handleClearTrip(Stop* trip[]);

// Story 8 specific
int getSpeed();
double calculateDistance(const Stop& point1, const Stop& point2);

int main() {
    // Story 3: Create trip array
    Stop* trip[MAX_STOPS] = {nullptr};  // Initialize all to null pointers, no clue if this was in class
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
    
    cout << "\nExiting " << endl;
    return 0;
}

// Story 2: Display main menu
void displayMainMenu() {
    cout << "\n=== Trip Planner Main Menu ===" << endl;
    cout << "1. Add Stop" << endl;
    cout << "2. View Trip" << endl;
    cout << "3. Remove Stop" << endl;
    cout << "4. Clear Trip" << endl;
    cout << "5. Quit" << endl;
    cout << "================================" << endl;
    cout << "Enter your choice: ";
}

// Story 2: Get and validate menu choice
int getMenuChoice() {
    string input;
    cin >> input;
    
    if (input.length() == 1 && isdigit(input[0])) {
        int choice = input[0] - '0';
        if (choice >= 1 && choice <= 5) {
            return choice;
        }
    }
    
    cout << "Invalid input. Please enter a number between 1 and 5." << endl;
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
            cout << "Invalid choice. Please try again." << endl;
    }
    return true;  // Continue running
}

// Story 2: Confirm quit with user
bool confirmQuit() {
    string response;
    cout << "Are you sure you want to quit? (y/n): ";
    cin >> response;
    
    if (tolower(response[0]) == 'y') {
        return true;
    }
    return false;
}

// Helper function to wait for Enter key
void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}













//---------------------------------------------------------------------------------------------------
// Story 3 & 4: Create a new stop
Stop* createStop(int x, int y) {
    Stop* newStop = new Stop;
    newStop->x = x; //new operators here, double check on these
    newStop->y = y; //new operators here, double check on these
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
    string input;
    
    cout << "\n--- Add New Stop ---" << endl;
    
    // Get X coordinate
    cout << "Enter X coordinate (-100 to 100): ";
    cin >> input;
    x = stoi(input);
    
    // Get Y coordinate
    cout << "Enter Y coordinate (-100 to 100): ";
    cin >> input;
    y = stoi(input);
    
    // Validate coordinates
    if (!isValidPosition(x, y)) {
        cout << "Error: Coordinates must be between -100 and 100." << endl;
        return;
    }
    
    // Create new stop
    Stop* newStop = createStop(x, y);
    
    // Add to trip
    if (addStopToTrip(trip, newStop)) {
        cout << "Stop (" << x << ", " << y << ") added successfully!" << endl;
    } else {
        cout << "Error: Trip is full (maximum " << MAX_STOPS << " stops). Cannot add more stops." << endl;
        delete newStop;  // Clean up allocated memory
    }
}

// Story 8: Get speed from user
int getSpeed() {
    int speed;
    string input;
    
    do {
        cout << "Enter the speed (1-60 miles per hour): ";
        cin >> input;
        speed = stoi(input); //finally the stuff from class starts to match up and we can use it
        
        if (speed < MIN_SPEED || speed > MAX_SPEED) {
            cout << "Error: Speed must be between " << MIN_SPEED << " and " << MAX_SPEED << " mph." << endl;
        }
    } while (speed < MIN_SPEED || speed > MAX_SPEED);
    
    return speed;
}

// Story 8: Calculate distance between two points
double calculateDistance(const Stop& point1, const Stop& point2) {
    int dx = point2.x - point1.x; //not sure if i really like these variable names since dx/dy are real terms...but i can't think of anything else
    int dy = point2.y - point1.y;
    return sqrt(dx*dx + dy*dy);
}

// Story 5 & 8: Handle view trip menu option
void handleViewTrip(Stop* trip[], int speed) {
    cout << "\n--- Current Trip ---" << endl;
    
    // Count stops first
    int stopCount = 0;
    for (int i = 0; i < MAX_STOPS && trip[i] != nullptr; i++) {
        stopCount++;
    }
    
    if (stopCount == 0) {
        cout << "No stops added to the trip yet." << endl;
        return;
    }
    
    // Display table header
    cout << "\nStop\tLocation\tDistance (miles)\tTime (minutes)" << endl;
    cout << "-----------------------------------" << endl;
    
    // Starting point
    Stop startPoint = {0, 0};
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
        cout << setw(4) << (i + 1) << "\t";
        cout << "(" << setw(3) << currentStop.x << ", " << setw(3) << currentStop.y << ")\t";
        cout << fixed << setprecision(2) << setw(14) << distance << "\t\t";
        cout << setw(13) << timeMinutes << endl;
        
        previousPoint = currentStop;
    }


//NOTE:it compiles when i threw this here...i still have no idea if this is even where it goes
//too tired to figure it out now on the small screen
}

