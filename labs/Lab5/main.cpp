
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


//going to stop here and read more about pointers before i start writing a bunch of these