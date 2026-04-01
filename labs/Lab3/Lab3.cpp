//this is a placeholder to ensure that the configuration files (i forget what they're called right now)
//are created properly using Visual Studio
//now we can edit this thing using any tool we want.

// Robert Pace
// Lab 3: Free Fall Distance & Velocity Calculator
// Spring 2026
// COSC-1436-21005




// Things we need to fix:

// Don't forget to check this in class!

// The Unit Measurement on the user's table isn't aligning properly
// Tidying up the stuff we're not allowed to use
// Removing extra comments we have in here for studying

// Go through the canvas module page and format this thing exactly as described
// Don't forget to pay attention to how this stuff is supposed to be named, we may need the Windows VM for this
// mostly done for now though



#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
//#include <cctype>  // it's a converter we're not supposed to be using
//using namespace std; //also not allowed to use, may as well memorize where the std:: things go

// Constants
// gonna get used to reading/writing these in all caps even tho it looks weird:
const double GRAVITY = 9.8;  // meters per second squared
const double TERMINAL_VELOCITY = 90.0;  // meters per second
const double METERS_TO_FEET = 3.28084;

// these are called function prototypes, we can put these on top and define them later
// something about how we want main() to know they exist, more on that later
int getFallingTime();
char getUnits();
// the stuff labeled in the parentheses here are telling the function what it Returns
double calculateDistance(int seconds);
double calculateVelocity(int seconds);
double convertToFeet(double meters);
void displayTable(int maxTime, char unit);


//main is supposed to be as streamlined as possible
//main can be thought of as the 'front-end' for our use cases for now (maybe later too)
int main() {
    // Program information
    // Sometimes it's more readable just to type the whole thing out
    std::cout << "===========================================" << std::endl;
    std::cout << "     Free Fall Distance & Velocity Calculator" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "This program calculates the distance fallen" << std::endl;
    std::cout << "and velocity reached by an object in free fall." << std::endl;
    std::cout << "Gravity is set to 9.8 m/s²" << std::endl;
    std::cout << "Terminal velocity is limited to 90 m/s." << std::endl;
    std::cout << "===========================================" << std::endl << std::endl;
    
    // Story 2: Get falling time with validation
    int fallingTime = getFallingTime();
    
    // Story 5: Get units preference with validation
    char units = getUnits();
    
    // Story 4 & 6 & 7: Display table with all data
    displayTable(fallingTime, units);
    
    return 0;
}

// Story 2: Prompt user for falling time (1-60 seconds)
int getFallingTime() {
    int time;
    bool valid = false;
    
    do {
        std::cout << "Please enter the number of seconds? ";

        // below is the same input buffer fix we keep running into while building these things
        // the part we need to memorize is the first line, but this is the 2nd time i've gotten stuck with these problems
        // i think i used it in lab 2 for a boolean check or something
        // also don't forget to maybe add an explanation for that this time

        //it's this line we keep seeing
        if (!(std::cin >> time)) {
        // extraction failed (user typed a letter)
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "error: Try entering a number between 1-60.\n";
        continue; // restart loop
    }
        //end of stuff we added    


        // Validate input is between 1 and 60
        if (time >= 1 && time <= 60) {
            valid = true;
        } else {
            std::cout << "error: Try entering a time must be between 1 and 60 seconds: " << std::endl;
        }
        // don't forget this easy way to say that something isn't valid:
    } while (!valid);
    
    return time;
}

// Story 5: Get units preference with case-insensitive validation
char getUnits() {
    char units;
    bool valid = false;
    
    do {
        std::cout << "Do you want the results in meters or feet? ";
        std::cin >> units;
        
        // Convert to lowercase for case-insensitive comparison
        // units = tolower(units); //this part is the thing we prolly gotta rework
        
        // i just switched back to writing out a longer form and run OR checks on everything
        if (units == 'm' || units == 'f'
            || units == 'M' || units == 'F') {
            valid = true;
        } else {
            std::cout << "ERROR: Please enter 'm' for meters or 'f' for feet." << std::endl;
        }
    } while (!valid);
    
    return units;
}

// Story 3: Calculate falling distance for a given second
double calculateDistance(int seconds) {
    // Formula: d = (1/2) * g * t²
    return 0.5 * GRAVITY * seconds * seconds;
}

// Story 7: Calculate falling velocity with terminal velocity limit
double calculateVelocity(int seconds) {
    double velocity = GRAVITY * seconds;
    
    // Apply terminal velocity limit (90 m/s)
    if (velocity > TERMINAL_VELOCITY) {
        velocity = TERMINAL_VELOCITY;
    }
    
    return velocity;
}

// Story 6: Convert meters to feet
double convertToFeet(double meters) {
    return meters * METERS_TO_FEET;
}

// Story 4, 6, & 7: Display table with all data in selected units
void displayTable(int maxTime, char unit) {
    std::cout << "\n\n";
    
    // Display table header with units
    std::cout << std::left << std::setw(12) << "Seconds";
    std::cout << std::left << std::setw(15) << "Distance";
    std::cout << "Velocity" << std::endl;
    
    // Display separator line
    std::cout << std::string(40, '=') << std::endl;
    
    // Display data for each second from 1 to maxTime
    for (int t = 1; t <= maxTime; t++) {
        // Calculate distance in meters
        double distanceMeters = calculateDistance(t);
        double velocityMetersPerSec = calculateVelocity(t);
        
        // Convert if needed
        double distance;
        double velocity;
        std::string distanceUnit;
        std::string velocityUnit;
        
        if (unit == 'm') {
            distance = distanceMeters;
            velocity = velocityMetersPerSec;
            distanceUnit = "m";
            velocityUnit = "m/s";
        } else { // feet
            distance = convertToFeet(distanceMeters);
            velocity = convertToFeet(velocityMetersPerSec);
            distanceUnit = "ft";
            velocityUnit = "ft/s";
        }
        
        // Display the row
        std::cout << std::left << std::setw(12) << t;
        std::cout << std::left << std::fixed << std::setprecision(1) << distance << " " << distanceUnit;
        // we had to remove a setw(12) here because it wasn't fitting right for some reason
        // here's a hacky way to do it for now:
        //std::cout << "        ";
        // oh well this works below:
        std::cout << std::setw(8) << " ";
        std::cout << std::left << std::fixed << std::setprecision(1) << velocity << " " << velocityUnit << std::endl;
        // we think at some point we're going to run into:
        // std::ostringstream
        // std::format
        // full blown libraries like fmt, tabulate
        // haven't finished reading about these yet
    }
    
    std::cout << std::endl;
}