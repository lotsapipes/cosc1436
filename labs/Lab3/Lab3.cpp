
// Robert Pace
// Lab 3: Free Fall Distance & Velocity Calculator
// Spring 2026
// COSC-1436-21005


// Project name should be FallingDistance

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// Constants (usually accepted in CAPS form)
// Using globals like this can be considered bad form but we're practicing anyways
const double GRAVITY = 9.8;  // meters per second squared
const double TERMINAL_VELOCITY = 90.0;  // meters per second
const double METERS_TO_FEET = 3.28084;

// Function Prototypes (Compiler needs them in advance)
int getFallingTime();
char getUnits();
double calculateDistance(int seconds);
double calculateVelocity(int seconds);
double convertToFeet(double meters);
void displayTable(int maxTime, char unit);
void displayProgramInfo();

// Main Function (Entry point, in our case it's user front-end, later on it can get even smaller, sometimes literally just one line)
int main() {
    
    displayProgramInfo();

    // Typing out the table in easy, readable form for this one:
    std::cout << "===============================================" << std::endl;
    std::cout << "     Free Fall Distance & Velocity Calculator" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "This program calculates the distance fallen" << std::endl;
    std::cout << "and velocity reached by an object in free fall." << std::endl;
    std::cout << "Gravity is set to 9.8 m/s^2" << std::endl;
    std::cout << "Terminal velocity is limited to 90 m/s." << std::endl;
    std::cout << "===============================================" << std::endl << std::endl;
    
    // Story 2: Get falling time from the user
    int fallingTime = getFallingTime();
    
    // Story 5: Get units preference from the user
    char units = getUnits();
    
    // Story 4 & 6 & 7: Creation of table, updating table, final table
    displayTable(fallingTime, units);
    
    return 0;
}

// Story 2: Prompt user for falling time (1-60 seconds)
int getFallingTime() {
    int time;
    bool valid = false;
    
    do {
        std::cout << "Please enter the number of seconds: ";

        // Below is likely code from outside of class (I keep seeing it while studying)
        // It basically just says "if 'time' did not cin properly"
        if (!(std::cin >> time)) {
        // Below may be an input buffer clearing method learned from outside of class
        // It seems to work fairly well (I also keep seeing this one while studying)
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "error: Try entering a number between 1-60.\n";
        continue; // restarts current loop (had to study how/why this is a bit)
    }   
        // Validate input is between 1 and 60
        if (time >= 1 && time <= 60) {
            valid = true;
        } else {
            std::cout << "error: Try entering a time must be between 1 and 60 seconds: " << std::endl;
        }
        
      // Loops all of the above until the 'valid' Boolean checking for proper input
      // changes to 'True'  
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
        
        if (units == 'm' || units == 'f'
            || units == 'M' || units == 'F') {
            valid = true;
        } else {
            std::cout << "Error: Please enter 'm' for meters or 'f' for feet." << std::endl;
        }
    } while (!valid);
    
    return units;
}

// Story 3: Calculate falling distance for a given second
double calculateDistance(int seconds) {
    // Formula: d = (1/2) * g * t^2
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

// Simple student name and header
void displayProgramInfo() {
    std::cout << "Robert Pace" << std::endl;
    std::cout << "Lab 3: Free Fall Distance & Velocity Calculator" << std::endl;    
    std::cout << "Spring 2026" << std::endl;
    std::cout << "COSC-1436-21005" << std::endl;
    std::cout << "\n"; 
}


// Story 4, 6, & 7: Display table with all data in selected units
void displayTable(int maxTime, char unit) {
    std::cout << "\n\n";
    
    // Display table header with units
    std::cout << std::left << std::setw(12) << "Seconds";
    std::cout << std::left << std::setw(15) << "Distance";
    std::cout << "Velocity" << std::endl;
    
    // Display separator line (using condensed format)
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
        
        // Display the row (as best we can)
        std::cout << std::left << std::setw(12) << t;
        std::cout << std::left << std::fixed << std::setprecision(1) << distance << " " << distanceUnit;
        std::cout << std::setw(8) << " ";
        std::cout << std::left << std::fixed << std::setprecision(1) << velocity << " " << velocityUnit << std::endl;
    }
    
    std::cout << std::endl;
}